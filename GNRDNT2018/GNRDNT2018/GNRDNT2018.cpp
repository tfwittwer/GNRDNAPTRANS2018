// GNRDNT2018.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "GNRDNT2018.h"

#include <proj.h>
#include <stdio.h>
#include <math.h>

#define RHO 57.295779513082320876798154814105

int etrs2rdnap(double lambda, double phi, double h, double *rdx, double *rdy, double *nap)
{
	PJ_CONTEXT *C;
	C = proj_context_create();

	PJ_COORD etrs, rdnap;
	etrs = proj_coord(lambda/RHO, phi/RHO, h, 0);

	PJ *P;

	P = proj_create(C, "+proj=pipeline +step +proj=vgridshift +grids=nlgeo2018.gtx +step +proj=axisswap +order=1,2,4,-3 +step +proj=vgridshift +inv +grids=egm96_15.gtx +step +proj=cart +ellps=GRS80 +step +proj=helmert +x=-565.7346 +y=-50.4058 +z=-465.2895 +rx=-0.395023 +ry=0.330776 +rz=-1.876073 +s=-4.07242 +convention=coordinate_frame +exact +step +proj=cart +inv +ellps=bessel +step +proj=hgridshift +inv +grids=rdcorr2018.gsb,null +step +proj=sterea +lat_0=52.156160556 +lon_0=5.387638889 +k=0.9999079 +x_0=155000 +y_0=463000 +ellps=bessel +step +proj=unitconvert +z_in=m +z_out=1e32 +step +proj=axisswap +order=1,2,-4,-3");

	if (0 == P) {
		fprintf(stderr, "Error creating projection\n");
		return 1;
	}

	rdnap = proj_trans(P, PJ_FWD, etrs);

	*rdx = rdnap.enu.e;
	*rdy = rdnap.enu.n;
	*nap = rdnap.enu.u;

	// cleanup
	proj_destroy(P);
	proj_context_destroy(C);
	return 0;
}

int rdnap2etrs(double rdx, double rdy, double nap, double *lambda, double *phi, double *h)
{
	PJ_CONTEXT *C;
	C = proj_context_create();

	PJ_COORD etrs, rdnap;
	rdnap = proj_coord(rdx, rdy, nap, 0);

	PJ *P;

	P = proj_create(C, "+proj=pipeline +step +proj=vgridshift +grids=nlgeo2018.gtx +step +proj=axisswap +order=1,2,4,-3 +step +proj=vgridshift +inv +grids=egm96_15.gtx +step +proj=cart +ellps=GRS80 +step +proj=helmert +x=-565.7346 +y=-50.4058 +z=-465.2895 +rx=-0.395023 +ry=0.330776 +rz=-1.876073 +s=-4.07242 +convention=coordinate_frame +exact +step +proj=cart +inv +ellps=bessel +step +proj=hgridshift +inv +grids=rdcorr2018.gsb,null +step +proj=sterea +lat_0=52.156160556 +lon_0=5.387638889 +k=0.9999079 +x_0=155000 +y_0=463000 +ellps=bessel +step +proj=unitconvert +z_in=m +z_out=1e32 +step +proj=axisswap +order=1,2,-4,-3");

	if (0 == P) {
		fprintf(stderr, "Error creating projection\n");
		return 1;
	}

	etrs = proj_trans(P, PJ_INV, rdnap);

	*lambda = etrs.lpz.lam*RHO;
	*phi = etrs.lpz.phi*RHO;
	*h = etrs.lpz.z;

	// cleanup
	proj_destroy(P);
	proj_context_destroy(C);
	return 0;
}
