#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void rotateMatrix90(vector<vector<int>>&matrix){
    int n = matrix.size();
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n/2;j++){
            swap(matrix[i][j],matrix[i][n-1-j]);
        }
    }
    return;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    rotateMatrix90(matrix);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}