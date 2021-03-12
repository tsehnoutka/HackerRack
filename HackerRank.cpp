#include <iostream>
#include <algorithm>    // std::sort
#include <deque> 
using namespace std;

void printQ(std::deque<int>* Qi) {
    std::deque<int>::iterator it = Qi->begin();
    for (it; it < Qi->end(); it++)
        cout << "dequeu - " << *it << " ";
    cout << endl;

}
void printKMax(int arr[], int n, int k) {
    //Write your code here.
    std::deque<int> Qi(k);

    /* Process first k (or first window) elements of array */
    int i;
    for (i = 0; i < k; ++i) {
        // For every element, the previous smaller elements are useless so
        // remove them from Qi
        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])
            Qi.pop_back();   // Remove from rear

        Qi.push_back(i); // Add new element at rear of queue
    }
    printQ(&Qi);
    // Process rest of the elements, i.e., from arr[k] to arr[n-1]
    for (; i < n; ++i)
    {
        // The element at the front of the queue is the largest element of
        // previous window, so print it
        cout << arr[Qi.front()] << " ";

        // Remove the elements which are out of this window
        while ((!Qi.empty()) && Qi.front() <= i - k)
            Qi.pop_front(); // Remove from front of queue

        // Remove all elements smaller than the currently
        // being added element (remove useless elements)
        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])
            Qi.pop_back();

        Qi.push_back(i);  // Add current element at the rear of Qi
    }
    cout << arr[Qi.front()];  // Print the maximum element of last window
    printQ(&Qi);
}

int main() {

    int t = 1;
    cin >> t;
    while (t > 0) {
        int n = 5, k = 2;
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

