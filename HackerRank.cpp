// HackerRank.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>

class Box {
private:
	int length;
	int bredth;
	int height;
public:
	Box() : length(0), bredth(0), height(0) {}
	Box(int l, int b, int h) : length(l), bredth(b), height(h) {}
	Box(const Box& b) :length(b.length), bredth(b.bredth), height(b.height) {}

	int getLength() { return length; }
	int getBreadth() { return bredth; }
	int getHeight() { return height; }
	long long CalculateVolume() {
		long long volume = length * bredth * height;
		return  volume;
	}

	friend bool  operator<(const Box& lhs, const Box& rhs) {
		return (lhs.length < rhs.length) ||
			(lhs.bredth < rhs.bredth&& lhs.length == rhs.length) ||
			(lhs.height < rhs.height&& lhs.length == rhs.length && lhs.bredth == rhs.bredth);
	}
	friend std::ostream& operator<<(std::ostream& os, const Box& b) {
		os << b.length << " " << b.bredth << " " << b.height;
		return os;
	}
};

void check2()
{
	int n;
	std::cin >> n;
	Box temp;
	for (int i = 0; i < n; i++)
	{
		int type;
		std::cin >> type;
		if (type == 1)
		{
			std::cout << temp << std::endl;
		}
		if (type == 2)
		{
			int l, b, h;
			std::cin >> l >> b >> h;
			Box NewBox(l, b, h);
			temp = NewBox;
			std::cout << temp << std::endl;
		}
		if (type == 3)
		{
			int l, b, h;
			std::cin >> l >> b >> h;
			Box NewBox(l, b, h);
			if (NewBox < temp)
			{
				std::cout << "Lesser\n";
			}
			else
			{
				std::cout << "Greater\n";
			}
		}
		if (type == 4)
		{
			std::cout << temp.CalculateVolume() << std::endl;
		}
		if (type == 5)
		{
			Box NewBox(temp);
			std::cout << NewBox << std::endl;
		}

	}
}

int main()
{
	check2();
}
