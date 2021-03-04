// HackerRank.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <sstream>


void variableSizedArrays() {
	std::vector<std::vector<int>> a;
	int i = 0, j = 0, aSize = 0;

	std::cin >> i >> j;  //  i contains the number of arrays, j contains the number of operations 
	for (int x = 0; x < i; x++) {
		std::vector<int> k;
		std::cin >> aSize;
		for (int y = 0; y < aSize; y++) {
			int ae = 0;
			std::cin >> ae;
			k.push_back(ae);
		}
		a.push_back(k);
	}
	for (int x = 0; x < j; x++) {
		int o1 = 0, o2 = 0;
		std::cin >> o1 >> o2;
		std::cout << a[o1][o2] << std::endl;
	}
}

class Complex
{
public:
	int a, b;
	Complex& operator +(Complex& rhs);

};
Complex& Complex::operator+(Complex& rhs)
{
	a += rhs.a;
	b += rhs.b;
	return *this;
}

std::ostream& operator << (std::ostream& os, Complex& c) {
	return std::cout << c.a << "+i" << c.b;
}
void OverloadOperators() {


}
int main()
{
	std::cout << "Hello World!\n";

	//variableSizedArrays();
	OverloadOperators();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


