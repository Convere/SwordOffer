#include <iostream>

using namespace std;
bool hasPath(char* matrix, int rows, int cols, char* str)
{
	if (matrix == nullptr || rows < 0 || cols < 0 || str == nullptr)
		return false;
	bool* visited = new bool[rows * cols];
	memset(visited, 0, rows*cols);

}
int main()
{
	return 0;
}