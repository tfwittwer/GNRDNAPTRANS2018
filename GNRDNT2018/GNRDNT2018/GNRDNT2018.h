#pragma once

#ifdef GNRDNT2018_EXPORTS
#define GNRDNT2018_API __declspec(dllexport)
#else
#define GNRDNT2018_API __declspec(dllimport)
#endif

extern "C" GNRDNT2018_API int etrs2rdnap(double lambda, double phi, double h, double *rdx, double *rdy, double *nap);
extern "C" GNRDNT2018_API int rdnap2etrs(double rdx, double rdy, double nap, double *lambda, double *phi, double *h);

