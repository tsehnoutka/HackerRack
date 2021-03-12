#include <iostream>
#include <algorithm>    // std::sort
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k) {
    //Write your code here.
    std::deque<int> mydeque(arr, arr + n);
    deque<int>::iterator it = mydeque.begin();
    int iterations = n - k + 1;
    while (iterations > 0) {
        int max = *max_element(it, it + k);
        cout << max << " ";
        it++;
        iterations--;
    }
    cout << endl;
}


int main() {

    int t=1;
    cin >> t;
    while (t > 0) {
        int n=5, k=2;
        cin >> n >> k;
        int i;
        int arr[n];
        for (i = 0; i < n; i++)
            cin >> arr[i];
        printKMax(arr, n, k);
        t--;
    }
    return 0;
}