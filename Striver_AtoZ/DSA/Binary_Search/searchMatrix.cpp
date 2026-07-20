

#include <iostream>
#include <vector>
using namespace std;

// Approach 1: Two Binary Searches
bool searchMatrixTwoBS(vector<vector<int>>& mat, int target) {
    int rows = mat.size();
    int cols = mat[0].size();

    int low = 0, high = rows - 1;
    int row = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (target > mat[mid][cols - 1]) {
            low = mid + 1;
        } else {
            row = mid;
            high = mid - 1;
        }
    }

    if (row == -1 || target < mat[row][0])
        return false;

    low = 0;
    high = cols - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (mat[row][mid] == target)
            return true;
        else if (mat[row][mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return false;
}

// Approach 2: Single Binary Search on virtual 1D array
bool searchMatrixOneBS(vector<vector<int>>& mat, int target) {
    int rows = mat.size();
    int cols = mat[0].size();

    int low = 0;
    int high = rows * cols - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        int r = mid / cols;
        int c = mid % cols;

        if (mat[r][c] == target)
            return true;
        else if (mat[r][c] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return false;
}

int main() {
    int rows, cols;
    cout << "Enter rows and columns: ";
    cin >> rows >> cols;

    vector<vector<int>> mat(rows, vector<int>(cols));

    cout << "Enter matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> mat[i][j];
        }
    }

    int target;
    cout << "Enter target: ";
    cin >> target;

    cout << "Two Binary Searches: "
         << (searchMatrixTwoBS(mat, target) ? "Found" : "Not Found") << endl;

    cout << "Single Binary Search: "
         << (searchMatrixOneBS(mat, target) ? "Found" : "Not Found") << endl;

    return 0;
}