#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    map<string, int>m;
    map<string, int>::iterator it;
    int q = 0, x=0,y=0;
    string name = "";
    cin >> q;

    for (int i = 0; i < q; i++) {
        cin >> x ;
        switch (x) {
        case 1:
            cin >> name >> y;
             it = m.find(name);
             if (it == m.end()) // not found
                m.insert(make_pair(name, y));
             else {
                 m[name] = m[name] + y;
             }
            break;
        case 2:
            cin >> name ;
            m.erase(name);
            break;
        case 3:
            cin >> name ;
            it = m.find(name);
            if (it == m.end())
                cout << "0\n";
            else
                cout << m[name] << endl;
            break;
        }
    }
    return 0;
}