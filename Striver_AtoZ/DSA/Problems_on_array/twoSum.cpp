#include <iostream>
#include <vector>
using namespace std;

vector <int> twoSum(vector <int>nums,int target){
    unordered_map<long long ,int>mp;
    for (int i = 0; i < nums.size(); i++) {
        int needed = target - nums[i];
        if (mp.find(needed) != mp.end()) {
            return {mp[needed], i};
        }
        mp[nums[i]] = i;
    }
    return {};
}

int main (){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int k;
    cin >> k;
    vector <int> v= twoSum(nums, k);
    for (int x:v){
        cout <<x<<" ";
    }
    return 0;
}