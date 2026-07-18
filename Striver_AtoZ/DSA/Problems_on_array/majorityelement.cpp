#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
//just add a majority number condition 
int alternate (vector<int>nums){
    int candidate = 0;
    int count = 0;
    for (int x : nums) {
        if (count == 0) {
            candidate = x;
        }
        if (x == candidate) {
            count++;
        } else {
            count--;
        }
    }
    return candidate;
}
int majorityNumber(vector <int> nums){
    unordered_map<int,int>mp;
    for (int i=0;i<nums.size();i++){
        mp[nums[i]]++;
    }
    int max_freq=0;
    int max_freq_element=-1;
    for (auto x:mp){
        if (max_freq<x.second){
            max_freq=x.second;
            max_freq_element = x.first;
        }
    }
    return max_freq_element;
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
    cout <<  majorityNumber(nums);

    return 0;
}