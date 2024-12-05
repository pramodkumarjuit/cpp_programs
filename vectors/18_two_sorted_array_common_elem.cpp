#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<algorithm> // std::max_element()

using namespace std;

int main(int argc, char *argv[])
{
    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 6, 7, 8, 9, 10};
    vector<int> nums2 = {6, 7, 8, 9, 9, 10, 11, 12, 13, 14, 15};

    int size1 = nums1.size();
    int size2 = nums2.size();
    vector<int> vecSmall;
    vector<int> vecBig;

    unordered_map<int, int> intMap;
    vector<int> vecUnique = {};

    if (size1 > size2) {
        vecBig = nums1;
        vecSmall = nums2;
    } else {
        vecBig = nums2;
        vecSmall = nums1;
    }

    for (auto &e: vecSmall) { // O(n1)
        intMap[e]++;
    }

    for (auto &e : vecBig) {
        if (intMap.find(e) != intMap.end()) {
            vecUnique.push_back(e);
        }
    }

    cout << "Unique elements:";
    for (auto &e: vecUnique) {
        cout << e << " ";
    }
    cout << endl;

    return 0;
}
