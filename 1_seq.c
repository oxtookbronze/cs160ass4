#include <stdio.h>
#include "omp.h"

static long num_steps = 1e1;
double step;
void main ()
{
	step = 1.0/(double) num_steps;
	double start = omp_get_wtime();
	double sum,pi;
	{
		
	int i; double x;
	int id = omp_get_thread_num();
	int size = omp_get_num_threads();

	for (i=id;i< num_steps; i+=size){
		
		x = (i+0.5)*step;
		sum = sum + 4.0/(1.0+x*x);
		printf("ID: %d,x:%f,sum:%f\n",id,x,sum);
		
		
	}
}
	double end = omp_get_wtime();
	pi = step * sum;
	printf("%f : %f\n",pi,end-start);
}
