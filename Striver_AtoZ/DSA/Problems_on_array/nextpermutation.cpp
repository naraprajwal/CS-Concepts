#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void nextpermutation(vector <int> nums){
    int n=nums.size();
    int breakpoint=-1;
    for (int i=n-2;i>=0;i--){
        if (nums[i]<nums[i+1]){
            breakpoint=i;
            break;
        }
    }
    if (breakpoint==-1){
        reverse(nums.begin(),nums.end());
        for (auto x:nums){
            cout <<x<<" ";
        }
        return;
    }
    int swapkey=breakpoint+1;        
    for (int j=breakpoint+2;j<n;j++){
    if (nums[swapkey]>nums[j])swapkey=j;
    }
    swap(nums[breakpoint],nums[swapkey]);
    reverse(&nums[breakpoint+1],&nums[swapkey]+1);
    for (int x:nums){
        cout <<x<<" ";
    }
    return;
}

int main (){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    nextpermutation(nums);
    return 0;
}