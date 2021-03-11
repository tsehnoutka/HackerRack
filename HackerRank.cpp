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
		unsigned int i = 0;
		bool found = false;
		while ( (!found) && (y >= v[i]) && (i < v.size()) ) {
			if (v[i] == y) {
				std::cout << "Yes " << i+1 << std::endl; //  need to add one to index casue thi user is a 1-based array
				found = true;
			}
			else {
				++i;

			}//  end else
		}  //  end while
		if (!found)
			std::cout << "No " << i+1 << std::endl;//  need to add one to index casue thi user is a 1-based array
	}  // end for

return 0;
}  //  end main

