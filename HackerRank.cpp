#include <string>
#include <stdexcept>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

/*
If the compute function runs fine with the given arguments, then print the result of the function call.
If it fails to allocate the memory that it needs, print Not enough memory.
If any other standard C++ exception occurs, print Exception: S where  is the exception's error message.
If any non-standard exception occurs, print Other Exception
*/

class Server {
private:
	static int load;
public:
	static int compute(long long A, long long B) {
		load += 1;
		if (A < 0) {
			throw std::invalid_argument("A is negative");
		}
		vector<int> v(A, 0);
		int real = -1, cmplx = sqrt(-1);
		if (B == 0) throw 0;
		real = (A / B) * real;
		int ans = v.at(B);
		return real + A - B * ans;
	}
	static int getLoad() {
		return load;
	}
};
int Server::load = 0;

int main() {
	int T; std::cin >> T;
	while (T--) {
		long long A, B;
		std::cin >> A >> B;
		try {
			cout << Server::compute(A, B) << endl;
		}
		catch (bad_alloc& e) {
			cout << "Not enough memory" << endl;
		}
		catch (exception& e) {
			cout << "Exception: " << e.what() << endl;
		}
		catch (...) {
			cout << "Other Exception" << endl;
		}
	}
	std::cout << Server::getLoad() << std::endl;
	return 0;
}