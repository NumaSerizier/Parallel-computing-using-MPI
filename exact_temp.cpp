#include <stdio.h>
#include <ctype.h>
#include <cmath>

using namespace std;

double tempexact(double x, double t){
	double t1 = 50.;
	double t2 = 100.;
	double n1 = 5.;
	double n2 = 8.;
	double a =1;
	double b =1;
	double ta = 100.;
	double tb = 500.;
	double sigma = 0.05;
	return t1*exp(-pow(M_PI,2)*2*pow(n1,2)*pow(sigma,2)*t/pow(b+a,2))*sin(2*M_PI*n1*(x+1)/4) + t2*exp(-pow(M_PI,2)*2*pow(n2,2)*pow(sigma,2)*t/pow(b+a,2))*sin(2*M_PI*n2*(x+1)/4) + thetinf(x);
}
