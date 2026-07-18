#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector <int> leaders_in_array(vector <int> nums){
    int n=nums.size();
    int current_max=nums[n-1];
    vector <int>Leaders;
    Leaders.push_back(current_max);
    for (int i=n-2;i>=0;i--){
        if (nums[i]>current_max){
            current_max=nums[i];
            Leaders.push_back(current_max);
        }
    }    
    reverse(Leaders.begin(),Leaders.end());
    return Leaders;
}

int main (){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<int>Leaders=leaders_in_array(nums);
    for (auto x:Leaders){
        cout <<x<<" ";
    }
    return 0;
}