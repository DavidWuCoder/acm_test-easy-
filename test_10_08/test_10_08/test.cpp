#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>

void test_vector1()
{
	// initializer_list<int> 的初始化方式
	std::vector<int> v1 = { 1, 2, 3, 4, 5 };
	std::vector<int> v2 = { 1, 2, 3, 4, 5, 6 };

	auto itl1 = { 1, 2, 3, 4, 5, 6 };
	// std::initializer_list<int> = { 1, 2, 3, 4, 5, 6 };

	v1.assign({ 10, 20, 30 });
	for (auto e : v1)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	v1.insert(v1.begin() + 2, 5);
	
	for (auto e : v1)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

}

int main()
{
	test_vector1();
	return 0;
}