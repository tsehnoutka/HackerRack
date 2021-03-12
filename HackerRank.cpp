#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    set<int>s;
    int q = 0;
    int c = 0;
    int x = 0;

    cin >> q;

    for (int i = 0; i < q; i++) {
        cin >> c >> x;
        switch (c) {
        case 1:
            s.insert(x);
            break;
        case 2:
            s.erase(x);
            break;
        case 3:
            cout << ((s.find(x) == s.end()) ? "No" : "Yes") << endl;
            break;
        }
    }
    return 0;
}
