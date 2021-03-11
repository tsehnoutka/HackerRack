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
    cin >> count;
    for (int x = 0; x < count; x++) {
        int item;
        cin >> item;
        v.push_back(item);
    }
    int index = 0, begin = 0, end = 0;
    cin >> index >> begin >> end;
    v.erase(v.begin()+index - 1); // subtract one because input is for a 1 based array ( not a zero based array )
    v.erase(v.begin() + begin-1, v.begin() + end-1);  // subtract one because input is for a 1 based array ( not a zero based array )
    cout << v.size() << endl;;
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}