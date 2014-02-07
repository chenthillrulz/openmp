#include <iostream>
#include <omp.h>

using namespace std;

static long num_steps = 100000;
double step;

int
main ()
{
	double x, pi, sum=0.0;
	double start, end;

	step = 1.0/static_cast<double>(num_steps);
	start = omp_get_wtime();

	#pragma omp parallel for private(x) reduction(+:sum)
	for (int i = 0; i < num_steps; i++)
	{

		x = (i+0.5)*step;
		sum += 4.0/(1.0+x*x);
	}

	end = omp_get_wtime ();
	pi = sum * step;

	cout << "Result " << pi << endl;
	cout << "Elapsed time " << end - start << endl;
}
