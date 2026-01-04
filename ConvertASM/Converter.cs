using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConvertASM
{
    public class Converter
    {
        public List<string> functionCalls = new List<string>();
        public List<int> labels = new List<int>();

        public static int ReverseEndianness(int value)
        {
            unchecked
            {
                uint u = (uint)value;
                u = (u >> 24) |
                    ((u >> 8) & 0x0000FF00u) |
                    ((u << 8) & 0x00FF0000u) |
                    (u << 24);
                return (int)u;
            }
        }

        public static Stream GetStreamWithGetBytes(string sampleString, Encoding encoding = null)
        {
            if (encoding == null)
                encoding = Encoding.UTF8;
            var byteArray = encoding.GetBytes(sampleString);
            var memoryStream = new MemoryStream(byteArray);
            return memoryStream;
        }

        public string Convert(string ASMToConvert)
        {
            List<string> ASMLines = new List<string>();
            using (var memoryStream = new MemoryStream())
            {
                using (var sw = new StreamWriter(memoryStream))
                {
                    using (var sr = new StreamReader(GetStreamWithGetBytes(ASMToConvert)))
                    {
                        string line;
                        while ((line = sr.ReadLine()) != null)
                        {
                            var parts = line.Split('|').Select(part => part.Trim()).ToList();
                            if (parts.Count() != 3)
                            {
                                var asm = convertLine(parts[2], parts[1]);
                                ASMLines.Add(string.Format("\t/*{0}*/\t{1}", parts[0], asm));
                            }
                        }

                        foreach (var funcCall in functionCalls.OrderBy(x => x))
                            sw.WriteLine(funcCall);
                        sw.WriteLine();

                        sw.WriteLine(string.Format("void __declspec(naked) sub_{0}()", ASMLines[0].Substring(5, 6)));
                        sw.WriteLine("{");
                        sw.WriteLine("\t__asm");
                        sw.WriteLine("\t{");

                        foreach (var ASMLine in ASMLines)
                        {
                            int addr = int.Parse(ASMLine.Substring(3, 8), System.Globalization.NumberStyles.HexNumber);
                            if (labels.Contains(addr))
                                sw.WriteLine(string.Format("_{0:X8}:", addr));
                            sw.WriteLine(ASMLine);
                        }

                        sw.WriteLine("\t}");
                        sw.WriteLine("}");
                    }
                }
                return Encoding.UTF8.GetString(memoryStream.ToArray());
            }
        }

        public string convertLine(string line, string asmBytes)
        {
            var newLine = "";
            if (line.Contains("push <cm0102.sub_"))     // Handle push <cm0102.sub_958A48>
            {
                newLine = line.Replace("<cm0102.sub_", "0x").Replace(">", "");
                newLine += "\t\t/*" + line + "*/";
                return newLine;
            }

            if (line.Contains("push cm0102."))          // Handle push cm0102.518640
            {
                newLine = line.Replace("cm0102.", "0x");
                newLine += "\t\t/*" + line + "*/";
                return newLine;
            }

            if (line.Contains(",cm0102."))          // Handle mov ecx,cm0102.B74450 
            {
                newLine = line.Replace("cm0102.", "0x");
                newLine += "\t\t/*" + line + "*/";
                return newLine;
            }

            if (line.Contains("push "))                 // Handle push 518640
            {
                var c2 = line[5];
                if ((c2 >= '0' && c2 <= '9') || (c2 >= 'A' && c2 <= 'F'))
                {
                    newLine = line.Insert(5, "0x");
                    return newLine;
                }
            }

            if (line.Contains("ret "))                 // Handle ret 28
            {
                var c2 = line[4];
                if ((c2 >= '0' && c2 <= '9') || (c2 >= 'A' && c2 <= 'F'))
                {
                    newLine = line.Insert(4, "0x");
                    return newLine;
                }
            }

            if (line.Contains("<cm0102.&"))             // Handle mov dword ptr ds:[esi],<cm0102.&sub_5839E0>
            {
                // take last 4 of the asm bytes and use that as the value ?
                var asmParts = asmBytes.Split(' ');
                var addrBytes = asmParts[asmParts.Length - 1];
                var addr_endian = int.Parse(addrBytes, System.Globalization.NumberStyles.HexNumber);
                var addr = ReverseEndianness(addr_endian);

                //newLine = line.Replace("<cm0102.&", "0x" + addr.ToString("X6")).Replace(">", "");
                var idx = line.IndexOf("<cm0102.&");
                newLine = line.Substring(0, idx) + "0x" + addr.ToString("X6");
                newLine += "\t\t/*" + line + "*/";
                return newLine;
            }

            if (line.Contains("call <cm0102.sub_"))     // Handle call <cm0102.sub_958A48>
            {
                newLine = line.Replace("<cm0102.", "").Replace(">", "");
                newLine += "\t\t/*" + line + "*/";

                var idx = line.IndexOf("sub_");
                var closeBracketIdx = line.IndexOf('>');
                var funcName = line.Substring(idx, closeBracketIdx - idx);
                var funcAddr = funcName.Replace("sub_", "0x");

                //functionCalls.Add(string.Format("static int(*{0})() = reinterpret_cast<int(*)()>({1});", funcName, funcAddr));
                var fnCall = string.Format("static int(*{0})() = (int(*)())({1});", funcName, funcAddr);
                if (!functionCalls.Contains(fnCall))
                    functionCalls.Add(fnCall);

                return newLine;
            }

            if (line.Contains("call cm0102."))     // Handle call cm0102.518640
            {
                newLine = line.Replace("cm0102.", "sub_");
                newLine += "\t\t/*" + line + "*/";

                var idx = line.IndexOf("cm0102.") + 7;
                var funcName = "sub_" + line.Substring(idx);
                var funcAddr = funcName.Replace("sub_", "0x");

                //functionCalls.Add(string.Format("static int(*{0})() = reinterpret_cast<int(*)()>({1});", funcName, funcAddr));
                var fnCall = string.Format("static int(*{0})() = (int(*)())({1});", funcName, funcAddr);
                if (!functionCalls.Contains(fnCall))
                    functionCalls.Add(fnCall);

                return newLine;
            }

            if (line.StartsWith("jmp ") || line.StartsWith("je ") || line.StartsWith("jne ") || line.StartsWith("jz ") || line.StartsWith("jnz ") ||
                line.StartsWith("jbe ") || line.StartsWith("jge ") || line.StartsWith("jle ") || line.StartsWith("jl ") || line.StartsWith("jg ") ||
                line.StartsWith("ja ") || line.StartsWith("jae "))
            {
                if (!line.Contains("dword"))   // Don't handle jmp dword ptr ds:[edx+30] 
                {
                    var addrStr = line.Substring(line.IndexOf("cm0102.") + 7);
                    if (addrStr.StartsWith("sub_"))     // Handle jne <cm0102.sub_5846DD>
                    {
                        var addr = int.Parse(addrStr.Substring(4, 6), System.Globalization.NumberStyles.HexNumber);
                        labels.Add(addr);
                        newLine = line.Replace("<cm0102.sub_", "_00").Replace(">", "");
                        return newLine;
                    }
                    else
                    {
                        var addr = int.Parse(addrStr, System.Globalization.NumberStyles.HexNumber);
                        labels.Add(addr);
                        newLine = line.Replace("cm0102.", "_00");
                        return newLine;
                    }
                }
            }

            for (int i = 0; i < line.Length; i++)   // Ensure numbers have 0x prefix
            {
                var c = line[i];
                newLine += c;
                if (c == '[' || c == '+' || c == '*' || c == '-' || c == ',')
                {
                    if (i + 1 < line.Length)
                    {
                        var c2 = line[i + 1];
                        if ((c2 >= '0' && c2 <= '9') || (c2 >= 'A' && c2 <= 'F'))
                        {
                            newLine += "0x";
                        }
                    }
                }
            }

            return newLine;
        }
    }
}
