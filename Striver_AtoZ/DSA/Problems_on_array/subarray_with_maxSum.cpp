#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;

int MaxSum_subarray_alternate(vector<int>& nums) {
    int currentSum = nums[0];
    int maxSum = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        currentSum = max(nums[i], currentSum + nums[i]);
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

//this does not work but the idea was similar
int MaxSum_subarray(vector <int>nums){
    int maxSum=nums[0];
    int prefixSum=0;
    vector <int> copy_nums=nums;
    for (int i=1;i<nums.size();i++){
        copy_nums[i]+=copy_nums[i-1];
        if (maxSum<copy_nums[i])maxSum=copy_nums[i];
    }
    sort(copy_nums.begin(),copy_nums.end());
    return max(maxSum,copy_nums[nums.size()-1]-copy_nums[0]);
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
    int x = MaxSum_subarray(nums);
    cout <<x;
    return 0;
}