#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int findMedian(vector<vector<int>>mat){
    vector<int>row_medians;
    int cols = mat[0].size()-1;
    if (cols % 2 == 0){
        for (int i=0;i<mat.size();i++){
            row_medians.push_back(mat[i][cols/2]);
        }
    }
    else {
        for (int i=0;i<mat.size();i++){
            row_medians.push_back((mat[i][cols/2]+mat[i][(cols/2)+1])/2);
        }
    }
    sort(row_medians.begin(),row_medians.end());
    int n = row_medians.size()-1;
    if (n%2==0)return row_medians[n/2];
    else return (row_medians[n/2]+row_medians[n/2+1])/2;
    return -1;
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

    cout << "Median: " << findMedian(mat) << '\n';
    return 0;
}
