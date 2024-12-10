#include<iostream>
#include<queue> // for priority_queue    
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<algorithm> // std::max_element()

using namespace std;

class MedianFinder
{
/*
 * Note: all elements in maxHeap should be ≤ all elements in minHeap.
 */
    priority_queue<int> maxHeap; // smaller-half numbers will be here
    priority_queue<int, vector<int>, std::greater<int>> minHeap; // larger-half number will be here
    public:
    MedianFinder() {

    }

    void addNum(int num) {
        // Add to maxHeap by default
        maxHeap.push(num);

        // Ensure all elements in maxHeap are <= elements in minHeap
        if(!maxHeap.empty() && !minHeap.empty()) {
            if (maxHeap.top() > minHeap.top()) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        }
        /*
         * The heaps must be balanced such that the size difference between the two heaps is at most 1.
         */
        // Balance the size of the heaps
        if (maxHeap.size() > minHeap.size()+1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }



    }

    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        } else {
            return (maxHeap.top()+minHeap.top()) / 2.0;
        }
    }
};

int main(int argc, char *argv[])
{
    MedianFinder mf;
    vector<int> nums = {1,2,3,4};
    cout << "Input:" << endl;
    for(auto &e : nums) {
        cout << e << " ";
    }
    cout << endl;

    for (int num : nums) {
        mf.addNum(num);
        cout << "Added: " << num << ", Current Median: " << mf.findMedian() << endl;
    }

    return 0;
}
