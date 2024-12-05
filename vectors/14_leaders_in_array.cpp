#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm> // max_element

using namespace std;


int main(int argc, char *argv[])
{
    vector<int> nums;
    unordered_map<int, int> freMap;

    for (int i = 10; i >= 0; i--) {
        //nums.push_back(rand()%10);
        nums.push_back(i);
    }

    cout << "Input:";
    for (auto &e: nums) {
        cout << e << " ";
    }
    cout << endl;

    vector<bool> leader(nums.size());
    for (int i = 0; i < nums.size()-1; i++) {
        auto maxElemItr = max_element(nums.begin()+i+1, nums.end());
        if (nums[i] > *maxElemItr) {
            leader[i] = true;
        } else {
            leader[i] = false;
        }
    }

    for (int i = 0; i< leader.size(); i++) {
        cout << leader[i] << " ";
    }
    cout << endl;

    return 0;
}
