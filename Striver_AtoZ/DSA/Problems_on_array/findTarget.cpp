#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int linearSearch(vector <int> nums,int target){
    for (int i=0;i<nums.size();i++){
        if (nums[i]==target)return i;
    }
    return -1;
}
int main (){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int target;cin>>target;
    cout << linearSearch(arr,target);
     
    
    return 0;
}