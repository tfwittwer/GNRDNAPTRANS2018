using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;

namespace GNRDNT2018NETTest
{
    class Program
    {
        [DllImport("GNRDNT2018.dll", EntryPoint = "etrs2rdnap")]
        public static extern int Etrs2rdnap(double l, double p, double h, out double x, out double y, out double z);
        [DllImport("GNRDNT2018.dll", EntryPoint = "rdnap2etrs")]
        public static extern int Rdnap2etrs(double x, double y, double z, out double l, out double p, out double h);

        static void Main(string[] args)
        {
            double l = 4.7121201260;
            double p = 51.7286012740;
            double h = 301.7981;
            double x, y, z;
            Console.WriteLine("input: "+l.ToString("F10")+ " "+ p.ToString("F10") + " "+ h.ToString("F4"));
            Etrs2rdnap(l, p, h, out x, out y, out z);
            Console.WriteLine("RD/NAP: " + x.ToString("F4") + " "+y.ToString("F4") + " "+z.ToString("F4"));
            Rdnap2etrs(x, y, z, out l, out p, out h);
            Console.WriteLine("check: " + l.ToString("F10") + " " + p.ToString("F10") + " " + h.ToString("F4"));

        }
    }
}
