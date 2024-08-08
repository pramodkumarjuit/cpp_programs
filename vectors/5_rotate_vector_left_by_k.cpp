// Original vector: 1 2 3 4 5 6 7 ; k = 3
// Rotated vector: 4 5 6 7 1 2 3 

#include<iostream>
#include<vector>
#include<algorithm>

void rotateVector(std::vector<int> &vec, int k)
{
    int n = vec.size();

    // To handle cases where k is greater than n
    k = k % n;

    std::vector<int> tmp(n);

    std::copy(vec.begin(), vec.begin()+k, tmp.begin());
    std::copy(vec.begin()+k, vec.end(), vec.begin());
    std::copy(tmp.begin(), tmp.begin()+k, vec.begin()+k);
}

int main(int argc, char *argv[])
{
    std::vector<int> vec = {1,2,3,4,5,6,7};
    int k_pos = 3;

    std::cout << "Before ...\n";
    for (auto &e: vec) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    rotateVector(vec, k_pos);


    std::cout << "After ...\n";
    for (auto &e: vec) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    return 0;
}
