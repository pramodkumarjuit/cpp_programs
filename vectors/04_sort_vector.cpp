#include<iostream>
#include<vector>
#include<algorithm>

void sortVector(std::vector<int> &vec)
{
    std::sort(vec.begin(), vec.end());
}

void sortVectorOwn(std::vector<int> &vec)
{
    for(int i = 0; i < vec.size() - 1; i++) {
        for (int j = 0; j < vec.size() - i - 1; j++) {
            if(vec[j] > vec[j+1]) {
                std::swap(vec[j], vec[j+1]);
            }
        }
    }
}


int main(int argc, char *argv[])
{
    std::vector<int> vec = {9,8,7,6,5,1,4,2,3,0, 1,2,3};

    std::cout << "Vector before sorting:" << std::endl;
    for(auto &e: vec) {
        std::cout << e << " ";
    }
    std::cout << std::endl;


    //sortVector(vec);
    sortVectorOwn(vec);
    std::cout << "Vector  after sorting:" << std::endl;
    for(auto &e: vec) {
        std::cout << e << " ";
    }
    std::cout << std::endl;


    return 0;
}
