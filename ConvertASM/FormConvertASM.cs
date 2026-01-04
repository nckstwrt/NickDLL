using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ConvertASM
{
    public partial class FormConvertASM : Form
    {
        public FormConvertASM()
        {
            InitializeComponent();
        }

        private void buttonConvert_Click(object sender, EventArgs e)
        {
            Converter converter = new Converter();
            string converted = converter.Convert(textBox.Text);
            textBox.Text = converted;
        }
    }
}
