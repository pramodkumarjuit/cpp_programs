#include<iostream>
#include<vector>
#include<random>

void printVector(std::vector<std::vector<int>> &nums)
{
    int R = nums.size();
    int C = nums[0].size();

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            std::cout << nums[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

std::vector<std::vector<int>> matrxMultiplication(
        std::vector<std::vector<int>> & M1, 
        std::vector<std::vector<int>> & M2)
{
    int R = M1.size();
    int C = M2[0].size();
    int tmp = 0;

    std::vector<std::vector<int>> result(R, std::vector<int>(C));

    for (int i = 0; i < M1.size(); i++) { //M
        for(int j = 0; j < M2[0].size(); j++) { // N
            for(int l = 0; l < M1[0].size(); l++) { // k
                result[i][j] += M1[i][l]*M2[l][j];

            }
        }
    }

    return result;
}

void transpose(std::vector<std::vector<int>> &matrix)
{
    int R = matrix.size();
    int C = matrix[0].size();
    std::vector<std::vector<int>> tpose(C, std::vector<int>(R));

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            tpose[j][i] = matrix[i][j];
        }
    }

    std::cout << "****************\n";
    std::cout << "Original Matrix:\n";
    printVector(matrix);
    std::cout << "Transpose:\n";
    printVector(tpose);
    std::cout << "****************\n";
}

int main(int argc, char *argv[])
{
    int M,K,N;
    std::srand(100);

    // M1 = M x K; M2 = K x N ==> M1xM2 = MxN
    M = 2;
    K = 2; // common dim
    N = 4;

    // Note: don't fix the size of M1 if vec is pushed to M1
    std::vector<std::vector<int>> M1; //(M, std::vector<int>(K));
    std::vector<std::vector<int>> M2(K, std::vector<int>(N));

    std::vector<std::vector<int>> result(M, std::vector<int>(N));

    // init M1 & M2
    for (int i = 0; i < M; i++) {
        std::vector<int> vec;
        for (int j = 0; j < K; j++) {
            //    M1[i][j] = (std::rand()%10)+1;
            vec.push_back((std::rand()%10)+1);
        }
        M1.push_back(vec);
    }

    for (int i = 0; i < K; i++) {
        for (int j = 0; j < N; j++) {
            M2[i][j] = (std::rand()%10)+1;
        }
    }

    std::cout << "M1 (MxK): \n";
    printVector(M1);
    std::cout << "--------------\n";

    std::cout << "M2 (KxN): \n";
    printVector(M2);
    std::cout << "--------------\n";

    result = matrxMultiplication(M1, M2);
    std::cout << "M1xM2= MxN\n";
    printVector(result);

    transpose(M2);
    return 0;
}
