#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> sprialorder(vector<vector<int>>matrix){
    int m=matrix.size();
    int n=matrix[0].size();
    vector<int> arr;
    vector <pair<int,int>> left_top = {{0,0}};
    vector <pair<int,int>> right_top = {{0,n-1}};
    vector <pair<int,int>> right_btm = {{m-1,n-1}};
    vector <pair<int,int>> left_btm = {{m-1,0}};
    while(left_top[0].second<=right_top[0].second && left_top[0].first<=left_btm[0].first){
        cout << "Entered while loop"<<"\n";
        for (int j=left_top[0].second;j<=right_top[0].second;j++){
            //cout <<"Entered loop1\n";
            arr.emplace_back(matrix[left_top[0].first][j]);
        }
        for (int i=right_top[0].first+1;i<=right_btm[0].first;i++){
            //cout <<"Entered loop2\n";
            arr.emplace_back(matrix[i][right_top[0].second]);
        }
        if(left_top[0].first!=left_btm[0].first){
            for (int j=right_btm[0].second-1;j>=left_btm[0].second;j--){
            //cout <<"Entered loop3\n";
            arr.emplace_back(matrix[right_btm[0].first][j]);
        }
        }
        if (left_top[0].second!=right_top[0].second){
            for (int i=left_btm[0].first-1;i>left_top[0].first;i--){
            //cout <<"Entered loop4\n";
            arr.emplace_back(matrix[i][left_btm[0].second]);
        }
        }
        left_top[0].first++,left_top[0].second++;
        right_top[0].first++,right_top[0].second--;
        right_btm[0].first--,right_btm[0].second--;
        left_btm[0].first--,left_btm[0].second++;
    }
    return arr;
}

int main (){
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    vector<int>brr = sprialorder(matrix);
    for (auto x:brr){
        cout << x <<" ";
    }
    return 0;
}