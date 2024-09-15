#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

template <typename T>
int binarySearch(vector<T> &vec, T target)
{
    int left = 0;
    int right = vec.size() - 1;
    int mid;

    while (left <= right) {
        mid = left + (right - left)/2;

        if (vec[mid] == target) {
            return mid;
        }

        if (vec[mid] > target) {
            right = mid-1;
        } else {
            left = mid+1;
        }
    }

    return -1;
}


int main(int argc, char *argv[])
{
    vector<int> vec = {1,2,3,4,5,6,7,8,9,10};
    int target = 7;
    int index;

    cout << "Vector ...\n";
    for (auto &e: vec) {
        cout << e << " ";
    }
    cout << endl;

    index = binarySearch(vec, target);
    if (index != -1) {
        cout << "Element found in vec at index: " << index << endl;
        cout << "Element is: " << vec.at(index);
    } else {
        cout << "Element not found in vec" << endl;
    }

    return 0;
}
