#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <string>
#include <cmath>
#include <random>
#include <mpi.h>

using namespace std;

int main(int argc, char** argv){
	MPI_Init(&argc, &argv);
	MPI_Status status;	

	double a = 1.0;
	double b = 1;0;
	int Nbse = 1000;
	int dt = 1000;
	double x = 0.;
	double t = 5.;
	double ta = 100.;
	double tb = 500.;
	double pt = t/dt;
	double px = sqrt(pt);
	double sigma = 0.05;
	double sim;
	double moyse;


	int nbTask;
	int myrank;
	double temps = MPI_Wtime();

	MPI_Comm_rank(MPI_COMM_WORLD,&myrank);
	MPI_Comm_size(MPI_COMM_WORLD,&nbTask);
	
	
	int Nbtot = nbTask*(Nbse-1);
	double estim[nbTask];

	// On va crÃ©er une liste initiale avec que des x
	
	if(myrank==0){}
	double X[Nbse*nbTask];
	double Sim[Nbse*nbTask];
	double Xse[Nbse];
	
	for(int k=0; k < nbTask*Nbse;k++){
		X[k] = x;
	}
	

	MPI_Scatter(X, nbTask*Nbse, MPI_DOUBLE,Xse, Nbse, MPI_DOUBLE,0, MPI_COMM_WORLD);

	for(int i=0;i<Nbse;++i){
		moyse = 0.0;
		double tx = 0.0;
		double xt = Xse[i];
		double temp = 0.0;
		while(tx < t and xt < b and xt > -a){
			default_random_engine generator;
			normal_distribution<double> distribution(0.0,1.0);
			double number = distribution(generator);
			xt += sigma*px*number;
			tx += pt;
		}
		if(xt < -a){
			temp = ta;
		}
		else if(xt > b){
			temp = tb;
		}
		else{
			temp = thetinf(xt);
		}
		Xse[i] = temp;
		moyse += temp;
		moyse = moyse/Nbse;
	}	
	MPI_Gather(Xse, Nbse, MPI_DOUBLE,Sim, nbTask*Nbse, MPI_DOUBLE,0, MPI_COMM_WORLD);
	MPI_Gather(&moyse,1,MPI_DOUBLE,estim,nbTask,MPI_DOUBLE,0, MPI_COMM_WORLD);
	
	if(myrank == 0){
		double sim;
		for(int k=0;k<nbTask;k++){
			sim+=Sim[k];
		}
		double texact = tempexact(x,t);
		sim = sim/4;
		double end = MPI_Wtime();
		cout << "La tempÃ©rature estimÃ© en x = " << x << "et au temps " << t << " est Ã©gale Ã  " << sim << endl;
		cout << "La tempÃ©rature excate est de "<< texact << endl; 
		cout << "le temps de compilation est " << end-temps << endl;
		cout << "On a utilisÃ© " << nbTask << " Processeur qui on fait chacun " << Nbse <<" simulations" << endl;
	}
	return 0;
}
