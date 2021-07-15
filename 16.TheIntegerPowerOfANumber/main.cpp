#include <iostream>

using namespace std;
double Power(double base, int exponent)
{
	double res = base;
	if (exponent == 0)
		return 1.0;

	for (int i = 1; i <(exponent < 0 ? - exponent : exponent); i++)
	{
		res *= base;
	}
	if (exponent < 0)
		return 1 / res;
	return res;
}
int main()
{
	cout << Power(-2.0, -2) << endl;
	system("pause");
	return 0;
}