# Stochastic calculus with parallel computing using MPI

Using stochastic calculus to calculate the temperature in a 1D  bar.
The bar is between the coordinate -a and b.
We know the temperature of the point a and b.
The bar has a heat transfer coefficient sigma.
It has a initial temperature. The initial temperature is an addition of two profil of normal distributed temperature, around the point n1 and n2 in the bar.
The infinite temerature is the temperature at the stationnary state.
We know the exact temperature.
We will calculate the tmperature in a point using stochastic calculus. We will use MPI to divide the simulation between the computer threads.
