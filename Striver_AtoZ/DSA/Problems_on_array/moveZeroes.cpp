#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void moveZeroes(vector<int>& nums){
    int n = nums.size();
    for (int i=0;i<n;i++){
        if (nums[i]==0){
            rotate(nums.begin()+i,nums.begin()+i+1,nums.end());
        }
    }
}
int main (){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    moveZeroes(arr);
    for (int x : arr) {
        cout << x << " ";
    }
    return 0;
}