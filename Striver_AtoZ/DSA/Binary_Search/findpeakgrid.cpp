#include<iostream>
#include<vector>

using namespace std;

vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int rows = mat.size();
    int cols = mat[0].size();
    int left = 0, right = cols - 1;

    while (left <= right) {
        int midCol = left + (right - left) / 2;
        int maxRow = 0;

        // Find the largest value in the middle column.
        for (int row = 1; row < rows; ++row) {
            if (mat[row][midCol] > mat[maxRow][midCol]) {
                maxRow = row;
            }
        }

        int current = mat[maxRow][midCol];
        int leftValue = (midCol > 0) ? mat[maxRow][midCol - 1] : -1;
        int rightValue = (midCol + 1 < cols) ? mat[maxRow][midCol + 1] : -1;

        if (current > leftValue && current > rightValue) {
            return {maxRow, midCol};
        }

        if (leftValue > current) {
            right = midCol - 1;
        } else {
            left = midCol + 1;
        }
    }

    return {-1, -1};
}

int main() {
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<int>> mat(rows, vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> mat[i][j];
        }
    }

    vector<int> peak = findPeakGrid(mat);
    cout << peak[0] << ' ' << peak[1] << '\n';

    return 0;
}
