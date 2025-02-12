#include<iostream>
#include<vector>
#include<unordered_set>

void printMatrix(std::vector<std::vector<int>> &matrix)
{
    int R = matrix.size();
    int C = matrix[0].size();

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// two sets to keep track of rows and columns that need to be zeroed

void setZeros(std::vector<std::vector<int>> & matrix)
{
    int R = matrix.size();
    int C = matrix[0].size();

    std::unordered_set<int> row, col;

    // identify the row that should be set to zero
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (matrix[i][j] == 0) {
                row.insert(i);
                col.insert(j);
            }
        }
    }

    // set row to zero
    for (auto &r: row) {
        for (int j = 0; j < C; j++) {
            matrix[r][j] = 0;
        }
    }

    // set col to zero
    for(auto &c : col) {
        for (int i = 0; i < R; i++) {
            matrix[i][c] = 0;
        }
    }

}

int main(int argc, char *argv[])
{
    std::vector<std::vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    std::cout << "Original Matrix:\n";
    printMatrix(matrix);

    std::cout << "Output Matrix:\n";
    setZeros(matrix);
    printMatrix(matrix);
    return 0;

}
