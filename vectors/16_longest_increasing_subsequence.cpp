#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<algorithm> // std::max_element()

using namespace std;

int fun(vector<int> &nums)
{
    int curElement;
    int prevElement = nums[0];
    unordered_map<int, int> map;
    int maxLen = 0;
    int start = 0;
    int end = 0;

    for (end = 1; end < nums.size(); end++) {
        curElement = nums[end];
        if (curElement > prevElement) { // && maxLen >= start) {
            map[prevElement] = end-1;
        } else {
            start += maxLen;
        }
        prevElement = curElement;
        maxLen = max(maxLen, end-start+1);
    }

    return maxLen;
}

int main(int argc, char *argv[])
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 1, 5, 6, 1, 15, 16, 18, 20, 2, 23, 30};

    cout << "Input: ";
    for (auto &e : nums) {
        cout << e << " ";
    }
    cout << endl;

    cout << "Max Seq Len: " << fun(nums) << endl;

    return 0;
}
