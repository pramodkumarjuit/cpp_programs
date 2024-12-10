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

#if 0
    int n = nums.size()+1;
    int expected_sum = (n*(n+1))/2;
    int arr_sum = 0;
    for (auto &e : nums) {
        arr_sum += e;
    }
    cout << "Missing nums:" << expected_sum - arr_sum << endl;
#elif 0 // if numbers are very large use XOR to avoid interger overflow
   int xorResult = 0;
   for(auto &e: nums) {
       xorResult ^= e;
   }

   for (int i = 0; i <= nums.size(); i++) {
       xorResult ^= i; 
   }
    cout << "Missing nums:" << xorResult << endl;

#endif

#if 1 // if array doesn't start from 0 then XOR doesn't work
    int minNumber = *std::min_element(nums.begin(), nums.end());
    int maxNumber = *std::max_element(nums.begin(), nums.end());

    int xorResult = 0;
    for (int i = minNumber; i <= maxNumber; i++) {
        xorResult ^= i;
    }

    for (auto & e: nums) {
        xorResult ^= e;
    }

       cout << "Missing nums:" << xorResult << endl;
#endif
    return 0;
}
