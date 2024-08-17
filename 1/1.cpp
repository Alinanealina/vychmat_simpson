#include <iostream>
using namespace std;
const int N = 5;

double funct(double x)
{
	return (1 / x);
}

double perv(double x)
{
	return (log(x));
}

double pr4(double x)
{
	return (24 / pow(x, 5));
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int i = 1, j;
	double a = 1, b = 2, x0, x1, x2, Ih, Ih2 = 0, I = perv(b) - perv(a), h = (b - a) / N, eps = pow(10, -8), eps2, M;
	cout << " a = " << a << ", b = " << b << ", h = " << h << ", Iточн = " << I << ", e = " << eps << endl;
	do
	{
		cout << " Шаг " << i << ":";
		Ih = Ih2;
		Ih2 = 0;
		M = 0;
		if (i == 1)
		{
			for (j = 0, x0 = a, x1 = a + h, x2 = a + 2 * h; j < N / 2; j++, x0 = x2, x1 += 2 * h, x2 += 2 * h)
				Ih += h * (funct(x0) + 4 * funct(x1) + funct(x2)) / 3;
		}
		h /= 2;
		for (j = 0, x0 = a, x1 = a + h, x2 = a + 2 * h; j < pow(2, (i - 1)) * N; j++, x0 = x2, x1 += 2 * h, x2 += 2 * h)
			Ih2 += h * (funct(x0) + 4 * funct(x1) + funct(x2)) / 3;
		cout << " I_h = " << Ih << ", I_h/2 = " << Ih2;

		for (j = 0, x0 = a; j < pow(2, (i - 1)) * N; j++, x0 += h)
		{
			eps2 = abs(pr4(x0));
			if (M < eps2)
				M = eps2;
		}
		eps2 = pow(h, 4) * (b - a) * M / 180;
		cout << ", eps_усеч = " << eps2 << endl;
		i++;
	} while (!(abs(Ih2 - I) < eps));
	cout << " h = " << h;
	return 0;
}