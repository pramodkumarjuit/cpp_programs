// g++ 1_reverse_vector.cpp --std=c++11
#include <iostream>
#include <vector>
#include <iterator> // for std::ostream_iterator
#include <algorithm> // for std::copy

void reverse_vector(std::vector<int> &vec)
{
    int start = 0, end = vec.size() - 1;

        while (start < end) {
            std::swap(vec[start], vec[end]);
            start++;
            end--;
        };
}
void reverse_vector_1(std::vector<int> &vec) 
{
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " ")); 

}

int main(int argc, char **argv) {
    std::vector<int> my_vec = {1,2,3,4,5};
    std::cout << "Before:\n";
    for (const auto& elem : my_vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    reverse_vector(my_vec);

    std::cout << "After:\n";
    for (const auto& elem : my_vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;


    return 0;
}
