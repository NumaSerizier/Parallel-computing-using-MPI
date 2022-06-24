#include <stdio.h>
#include <ctype.h>
#include <cmath>

using namespace std;

double thetinf(double x){
	double a =1.;
	double b =1.;
	double ta = 100.;
	double tb = 500.;
	return ta + (tb-ta)*(x+a)/(a+b);
}
