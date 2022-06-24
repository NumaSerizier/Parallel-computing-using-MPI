#include <stdio.h>
#include <ctype.h>
#include <cmath>

using namespace std;

double tempinit(double x){
	double t1 = 50.;
	double t2 = 100.;
	double n1 = 5.;
	double n2 = 8.;
	return t1*sin(2*M_PI*n1*(x+1)/4) + t2*sin(2*M_PI*n2*(x+1)/4) + thetinf(x);
}
