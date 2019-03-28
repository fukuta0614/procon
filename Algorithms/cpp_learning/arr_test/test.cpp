#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v;
	int A[0][0];
	std::cout << typeid(&A).name() << std::endl;
	return 0;
}