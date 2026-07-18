#include<iostream>
#include<vector>

using namespace std;

int findmin(vector <int>nums){
    if (nums.size()==1)return nums[0];
    int low = 0;
    int high = nums.size()-1;
    while (low<=high){
        int mid = low +(high-low)/2;
        if (nums[mid]>nums[mid+1])return nums[mid+1];
        else if (mid==low)return nums[mid];
        if (nums[low]>=nums[mid]&&nums[low]>=nums[high])high=mid-1;
        else if (nums[low]<=nums[mid]&&nums[low]<nums[high])high=mid-1;
        else low = mid+1;
    }
    return -1;
}

int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the rotated sorted array: ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    cout << "Minimum element: " << findmin(nums) << endl;

    return 0;
}