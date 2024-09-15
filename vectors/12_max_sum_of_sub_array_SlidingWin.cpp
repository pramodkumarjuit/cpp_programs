#include<iostream>
#include<vector>

using namespace std;

int maxSumSubArray(vector<int> &vec, int k)
{
    int maxSum = 0, slidingSum = 0;

    for (int i = 0; i< k; i++) {
        slidingSum += vec[i];
    }
    maxSum = slidingSum;

    for (int i = k; i < vec.size(); i++) {
        slidingSum += vec[i] - vec[i-k];
        maxSum = std::max(maxSum, slidingSum);
    }

    return maxSum;
}

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 2, 3, 7, 16};
    int k = 3;
    cout<< "Org vec: \n";
    for (auto &e: vec) {
        cout << e << " ";
    }
    cout << endl;

    cout << "Max sum of sub-array:" << maxSumSubArray(vec, k) << endl;

    return 0;
}
