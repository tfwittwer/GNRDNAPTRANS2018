# GNRDNAPTRANS2018
This is the [GeoNext](http://www.geonext.nl) implementation of variant 1 of [RDNAPTRANS2018](https://www.nsgi.nl/geodetische-infrastructuur/producten/programma-rdnaptrans), the new coordinate transformation method between ETRS89 and the Dutch RD/NAP coordinate system.

The transformation is performed with the [PROJ](https://proj.org/) library.

This implementation has not yet been validated and is provided without warranty.

## Contents
- GNRDNT2018: C++ DLL using the PROJ API for transformation between ETRS, and a C++ testing program.
- GNRDNT2018NET: Example of how to use the C++ DLL with C#, and a COM-exposed C# DLL for use with e.g. VBA.
- grids: The required grid files.

## Installation
- Install the PROJ library, I recommend using the 32bit or 64bit [OSGeo4W](https://www.osgeo.org/projects/osgeo4w/) installer. GNRDNAPTRANS2018 is based on the proj-dev package.
- Set the PROJ_LIB environment variable to the correct directory, e.g. C:\OSGeo4W\apps\proj-dev\share\proj for the 32 bit version.
- Place the two grid files in above directory.
- Place the desired DLL version (32 bit or 64 bit) in a location of your choice. You will need multiple DLLs, at minimum GNRDNT2108.dll, proj_7_0.dll, and sqlite3.dll. 

## VBA
Examples for using the library with C++ and C# are provided as code. For VBA, you will need to add GNRDNT2018DOTNET.tlb as reference (make sure that the abovementioned DLLs reside in the same directory). You can then call the transformation like this:

```
Dim l As Double, p As Double, h As Double
Dim x As Double, y As Double, z As Double

Dim rdnt As GNRDNT2018DOTNET.GNRDNT2018_NET
Set rdnet = New GNRDNT2018DOTNET.GNRDNT2018_NET

Call rdnet.Etrs2rdnap_net(l, p, h, x, y, z)
Call rdnet.Rdnap2etrs_net(x, y, z, l, p, h)
```
