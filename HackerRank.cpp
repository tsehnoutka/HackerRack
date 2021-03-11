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
    sort(v.begin(), v.end());
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}