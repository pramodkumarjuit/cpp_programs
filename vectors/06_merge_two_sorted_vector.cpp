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


template <typename T>
void mergeSortedVector_manual(vector<T> &vec1, vector<T> &vec2, vector<T> &res)
{
    auto itr1 = vec1.begin();
    auto itr2 = vec2.begin();
    auto itr3 = res.begin();
    int i = 0, j = 0, k = 0;

    // if first vector is empty
    if(vec1.begin() == vec1.end()) {
        copy(vec2.begin(), vec2.end(), res.begin());
        return;
    }
    // if second vector is empty
    if(vec2.begin() == vec2.end()) {
        copy(vec1.begin(), vec1.end(), res.begin());
        return;
    }

    while (i < vec1.size() && j < vec2.size()) {
        if (vec1[i] > vec2[j]) {
            //res.push_back(vec2[j]); // it appends a new element
            res[k] = vec2[j];
            j++;
        } else {
            //res.push_back(vec1[i]);
            res[k] = vec1[j];
            i++;
        }
        k++;
    }

    // leftover if vec1
    while(i < vec1.size()) {
        //res.push_back(vec1[i]);
        res[k] = vec1[j];
        i++;
        k++;
    }

    // leftover if vec2
    while(j < vec2.size()) {
        //res.push_back(vec2[j]);
        res[k] = vec2[j];
        j++;
        k++;
    }
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
    mergeSortedVector_manual(vec1, vec2, result);

    cout << "After merging two sorted vectors:\n";
    for(auto &e: result) {
        cout << e << " ";
    }
    cout << endl;

    return 0;
}
