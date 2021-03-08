// HackerRank.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include<set>

int uniqueIntegers(std::vector<int> a) {
std::set<int> s;

	for (int x : a)
		s.insert(x);
	return s.size();
}
int main()
{
	int N = 0, S = 0, P = 0, Q = 0;
	std::cin >> N >> S >> P >> Q;
	std::vector<int> a(N);


	a[0] = S % (2 ^ 31);
	for (int i = 1; i <= N - 1; i++) {
		a[i] = (a[i - 1] * P) +(Q % (2 ^ 31));
	}
	std::cout << uniqueIntegers(a);

}



