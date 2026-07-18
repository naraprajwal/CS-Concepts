

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& nums, int target){
    int low = 0;
    int high = nums.size() - 1;

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(nums[mid] == target)
            return mid;
        else if(nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the sorted elements: ";
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    int target;
    cout << "Enter the target: ";
    cin >> target;

    cout << binarySearch(nums, target) << endl;

    return 0;
}