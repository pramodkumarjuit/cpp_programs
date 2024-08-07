#include<iostream>
#include<algorithm>
#include<vector>

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


int main(int argc, char **argv) 
{
    vector<int> vec = {};
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(4);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    cout << "Before: ";
    for (auto &e: vec) {
        cout << e << " ";
    }
    cout << endl;

    remove_duplicate(vec);

    cout << "After: ";
    for (auto &e: vec) {
        cout << e << " ";
    }
    cout << endl;

    return 0;
}
