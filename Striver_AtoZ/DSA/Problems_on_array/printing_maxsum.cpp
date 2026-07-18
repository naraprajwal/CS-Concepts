#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;

int MaxSum_subarray_alternate(vector<int>& nums) {
    int currentSum = nums[0];
    int i_currentSum=0,j_currentSum=0;
    int maxSum = nums[0];
    int i_maxSum=0,j_maxSum=0;
    for (int i = 1; i < nums.size(); i++) {
        int temp = currentSum+nums[i];
        currentSum = max(nums[i], currentSum + nums[i]);
        if (currentSum==nums[i])i_currentSum=i,j_currentSum=i;
        if (currentSum==temp)j_currentSum=i;
        maxSum = max(maxSum, currentSum);
        if (maxSum==currentSum)i_maxSum=i_currentSum,j_maxSum=j_currentSum;
    }
    for (int i=i_maxSum;i<=j_maxSum;i++){
        cout<<nums[i]<<" ";
    }
    cout<<"\n";
    return maxSum;
}

int main (){
    int n;
    cin >> n;
    //cout << "x\n";
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        //cout <<"y\n";
    }
    int x = MaxSum_subarray_alternate(nums);
    cout <<x;
    return 0;
}