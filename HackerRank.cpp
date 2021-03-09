#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> parseInts(string str) {
    // Complete this function
    
    vector<int> retVal;
    char ch='0';
    int t=0; 
    stringstream words(str);

    words >> t;
    words >> ch;
    int iCommaCount = std::count(str.begin(), str.end(), ',');
    while(iCommaCount>=0)
    {
        retVal.push_back(t);
        words >> t;
        words >> ch;  //  get rid of comma
        iCommaCount--;
    }
    
    return retVal;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for (int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }

    return 0;
}