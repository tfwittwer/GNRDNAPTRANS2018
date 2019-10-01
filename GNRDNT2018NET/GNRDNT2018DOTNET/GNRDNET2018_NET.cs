using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;

namespace GNRDNT2018DOTNET
{
    public interface IGNRDNT2018
    {
        int Etrs2rdnap_net(double l, double p, double h, out double x, out double y, out double z);
        int Rdnap2etrs_net(double x, double y, double z, out double l, out double p, out double h);
    }

    [ClassInterface(ClassInterfaceType.None)]
    [ProgId("GNRDNT2018DOTNET.GNRDNT018_NET")]
    public class GNRDNT2018_NET : IGNRDNT2018 
    {
        [DllImport("GNRDNT2018.dll", EntryPoint = "etrs2rdnap")]
        public static extern int Etrs2rdnap(double l, double p, double h, out double x, out double y, out double z);
        [DllImport("GNRDNT2018.dll", EntryPoint = "rdnap2etrs")]
        public static extern int Rdnap2etrs(double x, double y, double z, out double l, out double p, out double h);

        [ComVisible(true)]
        public int Etrs2rdnap_net(double l, double p, double h, out double x, out double y, out double z)
        {
            return Etrs2rdnap(l, p, h, out x, out y, out z);
        }

        [ComVisible(true)]
        public int Rdnap2etrs_net(double x, double y, double z, out double l, out double p, out double h)
        {
            return Rdnap2etrs(x, y, z, out l, out p, out h);
        }

    }
}
