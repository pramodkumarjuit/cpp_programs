#include<iostream>
#include<queue> // for priority_queue    
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<algorithm> // std::max_element()

using namespace std;

vector<int> kLargest(vector<int> &nums, int k)
{
#if 0
    vector<int> retVec;
    priority_queue<int> maxHeap;
    for (auto &e: nums) { // n
        maxHeap.push(e);  // log(n) cost of inserting into a heap.
    }

    for (int i = 0; i < k; i++ ) { // k
        retVec.push_back(maxHeap.top()); // push_back() adds element // O(1)
        maxHeap.pop(); // log(k)
    }

    return retVec;

    // Total = n*log(n) + k*log(k)
    //       = n*log(n) + n*log(n) ; when n ~= k
    //       = 2nlog(n)
    //       = nlog(n)
#else

    priority_queue<int, vector<int>, greater<int>> minHeap; // smallest element at top
    for (auto &e: nums) {  // n
        minHeap.push(e);   // log(k)
        if (minHeap.size() > k) { // don't keep more than k elements in the heap
            minHeap.pop();  // log(k)
        }
    }

    vector<int> retVec;
    while(!minHeap.empty()) { // k
        retVec.push_back(minHeap.top()); // O(1)
        minHeap.pop(); // log(k)
    }

    return retVec;
    // Total:
    // - n *{log(k)+log(k)} = 2nlog(k) = nlog(k)
    // -  k * {log(k)} = klog(k)
    // Grand  = nlog(k) + klog(k)
    //        = (n+k)log(k)
    //        = 2nlog(k) ; when k~=n
    //        = nlog(k)
    //

#endif
}

int main(int argc, char *argv[])
{
    vector<int> nums = {1,3,2,4,5,7,6,9,8,10};
    cout << "Input:" << endl;
    for(auto &e : nums) {
        cout << e << " ";
    }
    cout << endl;

    vector<int> kLarestElements = kLargest(nums, 3);

    cout << "Output(" << kLarestElements.size() << "):" << endl;
    for(auto &e : kLarestElements) {
        cout << e << " ";
    }
    cout << endl;

    return 0;
}
