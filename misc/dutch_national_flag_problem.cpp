#include<iostream>
#include<vector>

using namespace std;

void dutch_national_flag_pattern(vector<int> &vec)
{
    int low = 0, mid = 0, high = vec.size()-1;

    while (mid <= high) {

        if (vec[mid] == 0) {
            swap(vec[low], vec[mid]);
            low++;
            mid++;
        } else if (vec[mid] == 1) {
            mid++;
        } else if (vec[mid] == 2) {
            swap(vec[mid], vec[high]);
            // Decrement high, but don't move mid since the swapped element needs to be checked
            //mid++;
            high--;
        }
    }
}


int main(int argc, char* argv[])
{
    vector<int> vec = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };

    cout << "Before vec:\n";
    for(auto &e : vec) {
        cout << e << " ";
    }
    cout << endl;

    dutch_national_flag_pattern(vec);

    cout << "After vec:\n";
    for(auto &e : vec) {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}
