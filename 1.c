#include <stdio.h>
#include "omp.h"

static long num_steps = 100000;
double step;
void main ()
{
	int i; double x, pi, sum;
	step = 1.0/(double) num_steps;
	double start = omp_get_wtime();
	int id = omp_get_thread_num();
	int size = omp_get_num_threads();
	for (i=id;i< num_steps; i+=size){
		x = (i+0.5)*step;
		sum = sum + 4.0/(1.0+x*x);
		
	}
	double end = omp_get_wtime();
	pi = step * sum;
	printf("%f : %f\n",pi,end-start);
}
