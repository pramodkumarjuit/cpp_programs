#include<iostream>
#include<algorithm>
#include<vector>
#include <unordered_set>

using namespace std;

void remove_duplicate(vector<int> &vec)
{
    vector<int> tmp = {};
    for (auto &e: vec) {
        if (find(tmp.begin(), tmp.end(), e) == tmp.end()) {
            tmp.push_back(e);
        }
    }

    copy(tmp.begin(), tmp.end(), vec.begin());
    vec.erase(vec.begin()+tmp.size(), vec.end());
}

// The std::unique algorithm reorders the elements so that each unique element
// appears only once in the initial part of the range, and returns an iterator
// to the end of the unique range.
void removeDuplicates(std::vector<int>& vec) {
    auto lastUnique = std::unique(vec.begin(), vec.end());
    vec.erase(lastUnique, vec.end());
}

// works both sorted and unsorted vector
void removeDuplicates_u(std::vector<int>& vec) {
    // When we attempt to insert an element that already
    // exists in the set, the set does nothing.
    // Insertion and lookup is of O(1)
    std::unordered_set<int> seen; // Set to track unique elements
    std::vector<int> uniqueVec; // Vector to store unique elements

    for (auto &v: vec) {
        if(seen.find(v) == seen.end()) { //O(1)
            seen.insert(v);
            uniqueVec.push_back(v); // O(1)
        }
    }
    // O(n)

    vec = std::move(uniqueVec);
}

int main(int argc, char **argv) 
{
    vector<int> vec = {}; // a sorted vector
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(4);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(6);
    vec.push_back(7);
    vec.push_back(9);

    cout << "Before: ";
    for (auto &e: vec) {
        cout << e << " ";
    }
    cout << endl;

    //remove_duplicate(vec);
    removeDuplicates(vec);

    cout << "After:  ";
    for (auto &e: vec) {
        cout << e << " ";
    }
    cout << endl;

    ////////////////// unsorted vector //////////
    std::vector<int> vec_u = {1, 2, 2, 3, 4, 4, 5, 5, 5};

    cout << "Unsorted vector Before: ";
    for (auto &e: vec_u) {
        cout << e << " ";
    }
    cout << endl;

    removeDuplicates_u(vec_u);

    cout << "Unsorted vector After:  ";
    for (auto &e: vec_u) {
        cout << e << " ";
    }
    cout << endl;

    return 0;
}
