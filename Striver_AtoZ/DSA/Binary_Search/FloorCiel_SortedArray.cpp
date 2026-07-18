#include <iostream>
#include <vector>
using namespace std;

vector<int> getFloorAndCeil(vector<int> nums, int x) {
    int n = nums.size();
    int low = 0;
    int high = n-1;
    while (low<high){
        int mid = low + (high - low)/2;
        if (nums[mid]==x)return {nums[mid],nums[mid]};
        else if (nums[mid]<x&&nums[mid+1]>x)return {nums[mid],nums[mid+1]};
        else if (nums[mid]<x&&nums[mid+1]<x)low = mid+1;
        else if (nums[mid]>x&&nums[mid+1]>x)high = mid;
    }
    //cout<<low<<" "<<high<<endl;
    if (low==0)return {-1,nums[low]};
    if (high==n-1)return {nums[high],-1};
    return {-1,-1};
}

int main (){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the sorted elements: ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    int x;
    cout << "Enter x: ";
    cin >> x;

    vector<int> ans = getFloorAndCeil(nums, x);

    cout << "Floor: " << ans[0] << endl;
    cout << "Ceil: " << ans[1] << endl;

    return 0;
}