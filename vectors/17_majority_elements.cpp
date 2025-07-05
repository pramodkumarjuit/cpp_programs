#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<algorithm> // std::max_element()

using namespace std;

int fun(vector<int> &nums)
{
    int candidate;
    int count = 0;

    for (auto &e: nums) {
        if (count == 0) {
            candidate = e;
            count++;
        } else if (candidate == e) {
            count++;
        } else {
            count--;
        }
    }

    // majority element is identified, check its count
    count = 0;
    for (auto &e: nums) {
        if (e == candidate) count++;
    }

    if (count > nums.size()/2) {
        return candidate;
    } else {
        return -1;
    }
}

int main(int argc, char *argv[])
{
    vector<int> nums = {1, 2, 3, 3, 2, 1, 1, 3, 3, 3};

    cout << "Input: ";
    for (auto &e : nums) {
        cout << e << " ";
    }
    cout << endl;

    cout << "Majority Element(-1 means no majoriy elem): " << fun(nums) << endl;

    return 0;
}
