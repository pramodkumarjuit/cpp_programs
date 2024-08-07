#include <iostream>
#include <vector>

#include <algorithm> // for std::max_element
#include <stdexcept> // for std::runtime_error

using namespace std;

int find_max(vector<int> &vect)
{
#if 0
    if (vec.empty()) {
        throw std::runtime_error("The vector is empty");
    }

    int max = vect[0];

    for(auto &e : vect) {
        if (max < e) {
            max = e;
        }
    }

    return max;
#else
    auto max_iterator = std::max_element(vect.begin(), vect.end());
    return *max_iterator;
#endif
}

int main(int argc, char **argv)
{
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    cout << "Vector: ";
    for(auto &e: vec) {
        cout << e << " ";
    }
    cout<<endl;

     cout << "Max: " << find_max(vec) << endl;

    return 0;
}
