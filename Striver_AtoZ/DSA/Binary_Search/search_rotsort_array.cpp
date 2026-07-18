#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> nums, int k){
    int low = 0;
    int high = nums.size() - 1;

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(nums[mid] == k)
            return mid;

        if(nums[low] <= nums[mid]){
            if(nums[low] <= k && k < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else{
            if(nums[mid] < k && k <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }

    return -1;
}

int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the rotated sorted array: ";
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    int k;
    cout << "Enter the target: ";
    cin >> k;

    cout << search(nums, k) << endl;

    return 0;
}