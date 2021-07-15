#include <iostream>
#include <ctime>
using namespace std;

int fibonacci(int n)
{
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;
	return fibonacci(n - 1) + fibonacci(n - 2);
}
int fibonacciLoop(int n)
{
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;
	long fibNMinusOne = 1;
	long fibNMinusTwo = 0;
	long fibN = 0;
	for (int i = 2; i <= n;i++)
	{
		fibN = fibNMinusOne + fibNMinusTwo;
		fibNMinusTwo = fibNMinusOne;
		fibNMinusOne = fibN;
	}
	return fibN;
}
int main()
{
	clock_t start;
	double duration;
	start = clock();
	long long res = fibonacciLoop(100);
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << res << " " << duration << endl;
	system("pause");
	return 0;
}