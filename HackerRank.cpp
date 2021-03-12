#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int count = 0;
	vector<int> v;

	std::cin >> count;
	for (int x = 0; x < count; x++) {
		int item;
		std::cin >> item;
		v.push_back(item);
	}
	sort(v.begin(), v.end());

	int q;
	std::cin >> q;
	for (int x = 0; x < q; x++) {  //  perform the equeries
		int y;
		std::cin >> y;
		vector<int>::iterator it;
		it = std::lower_bound(v.begin(), v.end(), y);
		std::cout << (*it == y)? "Yes " : "No " << it - v.begin() +1 << std::endl;
	}  // end for
return 0;
}  //  end main

