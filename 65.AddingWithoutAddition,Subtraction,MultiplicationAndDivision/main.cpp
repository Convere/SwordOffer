#include <iostream>
#include <vector>
#include <string>
using namespace std;

int adding(int num1, int num2)
{
	if (num2 == 0)
	{
		return num1;
	}
	int sum = num1^num2;
	int carry = (num1&num2) << 1;
	return adding(sum, carry);
}
//double* test()
//{
//	double i = 0.2;
//	//string i = "sjhjhk";
//	return &i;
//}
class A
{
public:
	A() :n2(0), n1(n2 + 2) {}
	~A() {};
	void print()
	{
		cout << "n1 " << n1 << " n2 " << n2 << endl;
	}
private:
	int n1;
	int n2;
};


int main()
{
	int num1 = 5;
	int num2 = 7;
	//cout << adding(num1, num2) << endl;
	//cout << *test() << endl;
	A a;
	a.print();
	system("pause");
}