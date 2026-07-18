#include<iostream>
#include <vector>
#include<algorithm>

using namespace std;

int maxSubarrayLength(vector <int>nums){
    int max_len=0;
    unordered_map<long long,int>mp;
    int prefixSum=0;
    int n = nums.size();
    for (int i=0;i<n;i++){
        prefixSum+=nums[i];
        if (prefixSum==0)max_len=max(max_len,i+1);
        if (mp.find(prefixSum)!=mp.end())max_len=max(max_len,i-mp[prefixSum]);
        if  (mp.find(prefixSum)==mp.end())mp[prefixSum]=i;
    }
    return max_len;
}

int main (){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    cout << maxSubarrayLength(nums);
    return 0;
}