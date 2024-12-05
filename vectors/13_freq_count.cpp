#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

unordered_map<int, int>freCount(vector<int> &nums)
{
    unordered_map<int, int> freMap;

    for(auto &e : nums) {
        freMap[e]++;
    }

    return freMap;
}

int main(int argc, char *argv[])
{
    vector<int> nums;
    unordered_map<int, int> freMap;

    for (int i = 0; i < 10; i++) {
        nums.push_back(rand()%5);
    }

    cout << "Input:";
    for (auto &e: nums) {
        cout << e << " ";
    }
    cout << endl;

    freMap = freCount(nums);

    for (auto &e: freMap) {
        cout << e.first << " -> " << e.second << endl;
    }
}
