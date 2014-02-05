#include <iostream>
#include <omp.h>

using namespace std;

static long num_steps = 100000;
double step;

int
get_num_threads_from_env ()
{
	return atoi (getenv("OMP_NUM_THREADS"));
}

int
main ()
{
	double pi, sum=0.0;
	double sumArray[get_num_threads_from_env ()];
	double start, end;
	int nthreads;

	start = omp_get_wtime();
	step = 1.0/static_cast<double>(num_steps);

	#pragma omp parallel
	{
		int id = omp_get_thread_num ();
		int num = omp_get_num_threads ();
		double x;
		
		sumArray[id] = 0;
		if (id == 0)
			nthreads = num;

		for (int i = id; i < num_steps; i+=num)
		{
			x = (i+0.5)*step;
			sumArray[id] += 4.0/(1.0+x*x);
		}
	}
	
	for (int i = 0; i < nthreads; i++)
		pi += sumArray[i] * step;
	
	end = omp_get_wtime();

	cout << "Result " << pi << endl;
	cout << "Elapsed time " << end - start << endl;
}
