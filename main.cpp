#include <gmpxx.h>
#include <iostream>
#include <iomanip>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;

unsigned int accuracy = 1000;

mpf_class factorial(unsigned int);
mpf_class power(mpf_class,unsigned int);
mpf_class exponent(mpf_class,unsigned int);

int main()
{
	mpf_set_default_prec(accuracy);
	cout << endl << "--------------" << endl;
	mpf_class x(1);
	double x_cmath(1);
	unsigned int n = 0;

	cout << "This program will approximate exp(x) with a taylor series " << endl;
	cout << "Insert x for taylor and cmath:" << endl;
	cin >> x >> x_cmath;
	cout << "Insert highest power:" << endl;
	cin >> n;
	mpf_class exp_x = exponent(x,n);
	cout << endl << "--------------" << endl;
	cout << "Power = " << n << " gives exp(" << x << ") = "
		<< setprecision (50) << exp_x << endl;
	cout << endl << "--------------" << endl;
	cout << "Using <cmath> -> exp(" << x_cmath << ") = " << exp(x_cmath) << endl;
	return 0;
}

mpf_class factorial(unsigned int n)
{
        if(n>1)
                return factorial(n-1) * n;
        else
                return 1;
}

mpf_class power(mpf_class x, unsigned int n)
{
	mpf_class powval(1);
        for (unsigned int num = n; num != 0; --num)
	{
                powval *= x;
	}
	return powval;
}


mpf_class exponent(mpf_class x, unsigned int n)
{
	mpf_class expval = 0.0;
	cout << endl << "--------------" << endl;
	for (unsigned int num = 0; num <= n; ++num)
	{
		expval += (power(x,num) / factorial(num));
		cout << "Power = " << num << " gives exp(" << x << ") = "
  		     << setprecision (50) << expval << endl;
	}
	return expval;
}

