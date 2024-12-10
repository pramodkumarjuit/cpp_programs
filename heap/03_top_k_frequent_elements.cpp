#include<iostream>
#include<queue> // for priority_queue    
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<algorithm> // std::max_element()

using namespace std;

vector<int> topKFrequentElements(vector<int> &nums, int k)
{
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        std::greater<pair<int,int>>> minHeap; // min at top
    unordered_map<int, int> freMap;
    for(int i = 0; i < nums.size(); i++) {
        freMap[nums[i]]++;
    }

    for (auto &e: freMap) {
        minHeap.push({e.second, e.first});
        if(minHeap.size() > k) {
            minHeap.pop();
        }
    }

    vector<int> retVec;
    while(!minHeap.empty()) {
        retVec.push_back(minHeap.top().second); // lest frequest element at the back.
        minHeap.pop();
    }

    // [Optional]: reverse the vector if we want to keep the most frequent element first
    std::reverse(retVec.begin(), retVec.end());

    return retVec;
}

int main(int argc, char *argv[])
{
    vector<int> nums = {1,1,1,2,2,3,2,4,5,7,6,9,8,8,7,10};
    cout << "Input:" << endl;
    for(auto &e : nums) {
        cout << e << " ";
    }
    cout << endl;

    vector<int> topKFreqElements = topKFrequentElements(nums, 3);

    cout << "Output(top 3 freqent elements):" << endl;
    for(auto &e : topKFreqElements) {
        cout << e << " ";
    }
    cout << endl;

    return 0;
}
