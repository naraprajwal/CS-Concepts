#include <iostream>
#include <vector>
using namespace std;

int linearSearch(vector <int> nums,int target){
    for (int i=0;i<nums.size();i++){
        if (nums[i]==target)return i;
    }
    return -1;
}

int missingNumber(vector <int>& nums){
    int n= nums.size();
    for (int i=0;i<=n;i++){
        if(linearSearch(nums,i)==-1)return i;
    }
    return -1;
}

int main (){
    int n;cin>>n;
    vector <int> nums(n);
    for (int x:nums){
        cin >> x;
    }
    cout << missingNumber(nums);
    return 0;
}