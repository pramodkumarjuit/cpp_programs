#include<iostream>
#include<queue> // for priority_queue    
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<algorithm> // std::max_element()

using namespace std;

int main(int argc, char *argv[])
{
    //priority_queue<int, vector<int>, less<int>> maxHeap; // the default one internally
    priority_queue<int> maxHeap; //Elements are stored in descending order internally.
    maxHeap.push(10);
    maxHeap.push(5);
    maxHeap.push(15);

    cout << "Order of push: 10->5->15" << endl;
    cout << "Top element of maxHeap: " << maxHeap.top() << endl;  // Outputs 15
    maxHeap.pop();
    cout << "Top element after pop: " << maxHeap.top() << endl;  // Outputs 10

    cout << "Now heap is: ";
    while(!maxHeap.empty()) {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    cout << endl <<"========================="  << endl;
    cout << endl;

    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(15);
    minHeap.push(5);
    minHeap.push(10);

    cout << "Order of push: 15->5->10" << endl;
    cout << "Top element of minHeap: " << minHeap.top() << endl;  // Outputs 5
    minHeap.pop();
    cout << "Top element after pop: " << minHeap.top() << endl;  // Outputs 10

    return 0;
}
