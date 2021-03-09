#include <string>
#include <iostream>


int main() {
	std::string str1 = "";
	std::string str2 = "";

	std::cin >> str1;
	std::cin >> str2;

	std::cout << str1.length() << " " << str2.length() << std::endl;
	std::cout << str1 + str2 << std::endl;

	char temp = str1[0];
	str1[0] = str2[0];
	str2[0] = temp;

	std::cout << str1 << " " << str2 << std::endl;
	return 0;
}