#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void mergeSortedVector(vector<int> &vec1, vector<int> &vec2, vector<int> &res)
{
    std::copy(vec1.begin(), vec1.end(), res.begin());
    std::copy(vec2.begin(), vec2.end(), res.begin()+vec1.size());
    std::sort(res.begin(), res.end());
}

template <typename T>
void mergeSortedVector_opt(vector<T> &vec1, vector<T> &vec2, vector<T> &res)
{
    std::merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), res.begin());
}

// result should be in vec1 only
template <typename T>
void mergeSortedVector_manual(vector<T> &vec1, vector<T> &vec2)
{
    // if second vector is empty
    if(vec2.begin() == vec2.end()) {
        return;
    }

    // if first vector is empty
    if(vec1.begin() == vec1.end()) {
        vec1.resize(vec2.size());
        copy(vec2.begin(), vec2.end(), vec1.begin());
        return;
    }

    int n1 = vec1.size();
    int n2 = vec2.size();

    vec1.resize(n1+n2);
    // Note:
    //  - [] doesn't auto expand the vector memory! [] works only in pre-allocated memory
    //  - Alternatively, use v1.push_back(i);

    for (int i = 0; i < n2; i++) {
        vec1[n1+i] = vec2[i];
    }
    std::sort(vec1.begin(), vec1.end());

}

int main(int argc, char *argv[])
{
    vector<int> vec1 = {1, 3, 5, 7, 9};
    vector<int> vec2 = {2, 4, 6, 8, 9, 10};
    vector<int> result(vec1.size() + vec2.size());

    cout << "First vector:\n";
    for(auto &e: vec1) {
        cout << e << " ";
    }
    cout << endl;


    cout << "Second vector:\n";
    for(auto &e: vec2) {
        cout << e << " ";
    }
    cout << endl;

    //mergeSortedVector(vec1, vec2, result);
    //mergeSortedVector_opt(vec1, vec2, result);
    
    mergeSortedVector_manual(vec1, vec2);
    cout << "After merging two sorted vectors:\n";
    for(auto &e: vec1) {
        cout << e << " ";
    }
    cout << endl;

    return 0;
}
