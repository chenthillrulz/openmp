#include <iostream>
#include <omp.h>

using namespace std;

static long num_steps = 1000000000;
double step;

int
main ()
{
	double pi, sum=0.0, x;
	double start, end;

	start = omp_get_wtime();
	step = 1.0/static_cast<double>(num_steps);

	for (int i = 0; i < num_steps; i++)
	{
		x = (i+0.5)*step;
		sum += 4.0/(1.0+x*x);
	}

	pi = sum * step;
	end = omp_get_wtime();

	cout << "Result " << pi << endl;
	cout << "Elapsed time " << end - start << endl;
}
