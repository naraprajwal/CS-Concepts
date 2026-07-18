#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

vector<vector<int>> mergeOverlap(vector<vector<int>> arr){
    vector<vector<int>> mergedIntervals;
    int rows = arr.size();

    if (rows == 0)
        return mergedIntervals;

    sort(arr.begin(), arr.end());

    int st = arr[0][0];
    int end = arr[0][1];

    for (int i = 1; i < rows; i++){
        if (arr[i][0] <= end){
            end = max(end, arr[i][1]);
        }
        else{
            mergedIntervals.push_back({st, end});
            st = arr[i][0];
            end = arr[i][1];
        }
    }

    mergedIntervals.push_back({st, end});
    return mergedIntervals;
}

int main (){
    int n;
    cout << "Enter the number of intervals: ";
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(2));
    cout << "Enter the start and end of each interval:\n";
    for (int i = 0; i < n; i++){
        cin >> arr[i][0] >> arr[i][1];
    }

    vector<vector<int>> result = mergeOverlap(arr);

    cout << "Merged intervals:\n";
    for (auto interval : result){
        cout << interval[0] << " " << interval[1] << endl;
    }

    return 0;
}