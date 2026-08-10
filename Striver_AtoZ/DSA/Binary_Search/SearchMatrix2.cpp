#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i=0;i<m;i++){
            if (matrix[i][0] > target || matrix[i][n-1] < target){
                continue;
            }
            int left = 0,right = n-1;
            while (left<=right){
                int mid = left + (right - left)/2;
                if (matrix[i][mid]==target)return true;
                else if (matrix[i][mid] > target)right = mid-1;
                else left = mid + 1;
            }
        }
        return false;
}

int main() {
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    int target;
    cin >> target;

    cout << (searchMatrix(matrix, target) ? "true" : "false") << '\n';
    return 0;
}
