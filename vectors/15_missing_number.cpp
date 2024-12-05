#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<algorithm> // std::max_element()

using namespace std;

int main(int argc, char *argv[])
{
    vector<int> nums = {6, 7, 8, 9, 10, 1, 2, 3, 4, /*5,*/};

    cout << "Input: ";
    for (auto &e : nums) {
        cout << e << " ";
    }
    cout << endl;

    int n = nums.size()+1;
    int expected_sum = (n*(n+1))/2;
    int arr_sum = 0;
    for (auto &e : nums) {
        arr_sum += e;
    }

    cout << "Missing nums:" << expected_sum - arr_sum << endl;
    return 0;
}
