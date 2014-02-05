#include <iostream>
#include <omp.h>

using namespace std;

static long num_steps = 100000;
double step;

int
main ()
{
	double pi, sum=0.0, x;

	step = 1.0/static_cast<double>(num_steps);

	for (int i = 0; i < num_steps; i++)
	{
		x = (i+0.5)*step;
		sum += 4.0/(1.0+x*x);
	}

	pi = sum * step;

	cout << "Result " << pi << endl;
}
