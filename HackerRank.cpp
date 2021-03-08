// HackerRank.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include<set>
#include <chrono>

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

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	a[0] = S % (2 ^ 31);
	for (int i = 1; i < N; i++) {
		a[i] = (a[i - 1] * P) +(Q % (2 ^ 31));
	}
	std::cout << uniqueIntegers(a) << std::endl;;

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[ms]" << std::endl;

}

//  solution here:  ( this seems more of a math excercise than a coding excercise)
//https://programs.programmingoneonone.com/2021/02/hackerrank-bit-array-solution-c-plus-plus.html

/*
The problem boils down to finding minimal m > 0 and n >= 0 such that a[n + m] = a[n].

As pointed out by others Floyd's and Brent's algorithms are nice for this 
problem. These algorithms are generic and work for any recurrence 
a[i] = f(a[i-1]), ie, they don't make any assumption about f. For the 
problem at hand, f(x) = p*x + q and we can buy a lot of time if we use f's 
mathematical properties. Indeed, one can easily show that

a[n] = s * p^n + q * (p^(n-1) + ... + 1) for all n >= 1.

The arguments are a bit lengthy for here but to give an idea of the math 
suppose s > 0 and q = 0 (the case where q > 0 brings some but not much 
complexity). Then

a[n] = s * p^n for all n >= 1.

It follows that

a[n + m] - a[n] = s * (p^m - 1) * p^n.

Consider the case where p is even but not zero. One can find unique 
integers x and ysuch that p = x * 2^y and x is odd. Analogously, we can 
find integers u and v such that s = u * 2^v and u is odd. Using this we obtain

a[m + n] - a[n] = x^n * (p^m - 1) * u * 2^(n * y + v).

Since x^n, p^m - 1 and u are odd, the only way for the rhs (and thus for the 
lhs) to be zero modulo 2^31 is when n * y + v >= 31. We are looking for the 
minimal n which implies n = ceiling((31 - v) / y). We have shown that

a[m + n] = a[n] mod 2^31 for all m > 0,

that is, the sequence is constant from n onwards. It can also be shown 
that a[0], ..., a[n] are all distinct. Therefore, the solution to the problem 
is min(n + 1, N).

When p is odd, the argument is much more complex and relies on a property of 
the group ((Z/rZ)*, *) where r=2^k is a power of 2, namely, 
if p^m = 1 modulo r and m is minimal, then m divides 2^(k - 1), 
ie, m belongs to {1, 2, 4, ..., 2^(k - 1)}.


I've implemented my solution and it took 0s to solve all test cases. 
For comparison, I've also implemented the Floyd's and Brent's algorithm. 
An interesting test case is N = 100000000, s = 1, p = 3 and q = 1 for 
which the answer is N. My solution took 0.0s, Floyd's took 2.5s and Brent 
took 16.0s.




*/

