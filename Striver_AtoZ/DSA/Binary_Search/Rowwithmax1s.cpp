#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int firstOne_col(vector<vector<int>>&matrix,int row){
    int rows = matrix.size();
    int cols = matrix[0].size();
    int low = 0;
    int high = cols-1;
    if (matrix[row][low]==1)return 0;
    while (high >= low){
        int mid = low+(high-low)/2;
        if (matrix[row][mid]==1&&matrix[row][mid-1]==0) return mid;
        else if (matrix[row][mid]==1&&matrix[row][mid-1]==1) high = mid-1;
        else low = mid+1;
    }
    return -1;
}

int Rowwithmax1s(vector<vector<int>>& matrix){
    int rows = matrix.size();
    int cols = matrix[0].size();
    int maxOnes_row = -1;
    int maxOnes = -1;
    for (int i=0;i<rows;i++){
        int first_one=firstOne_col(matrix,i);
        if (first_one==-1)continue;
        else {
            int Ones = cols-first_one;
            if (maxOnes<Ones){
                maxOnes_row=i;
                maxOnes=Ones;
            }
        }
    }
    return maxOnes_row;
}

int main() {
    int rows, cols;

    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    cout << "Enter the matrix (0s and 1s):" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    int ans = Rowwithmax1s(matrix);
    cout << "Row with maximum 1s: " << ans << endl;

    return 0;
}