#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

template <typename T>
float medianSortedVec(vector<T> &vec) 
{
    int size = vec.size();

    if (size%2 == 0) {
        int first = size/2 - 1;
        int second = first+1;
        float median = static_cast<float>(vec.at(first)) + static_cast<float>(vec.at(second));
        return median/2;
    } else {
        int first = (size+1)/2 - 1;
        return (float)vec.at(first);
    }
}

int main(int argc, char *argv[])
{
    vector<int> vec = {1,3,3,6,7,8,9}; // mean= 6
    vector<int> vec1 = {1,2,3,4,5,6,8,9}; // mean= 4.5

    cout << "vec is:\n";
    for (auto &e: vec)
    {
        cout << e << " ";
    }
    cout << endl;

    cout << "Median is (expected=6): " << medianSortedVec(vec);
    cout<< endl;
    cout << "Median is (expected=4.5): " << setprecision(3) << medianSortedVec(vec1);
    cout<< endl;

    return 0;
}
