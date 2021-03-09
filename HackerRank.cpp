// HackerRank.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
class Student {
private:
	static const int MAX_SCORES = 5;
	int scores[MAX_SCORES];
public:
	void input();
	int calculateTotalScore();

};

void Student::input() {
    for (int x = 0; x < MAX_SCORES; x++)
        std::cin >> scores[x];
}
int Student::calculateTotalScore() {
	int total = 0;
	for (int x = 0; x < MAX_SCORES; x++)
		total += scores[x];
	return total;
}


int main()
{
    int n; // number of students
    std::cin >> n;
    Student* s = new Student[n]; // an array of n students

    for (int i = 0; i < n; i++) {
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0;
    for (int i = 1; i < n; i++) {
        int total = s[i].calculateTotalScore();
        if (total > kristen_score) {
            count++;
        }
    }

    // print result
    std::cout << count;

    return 0;
}



