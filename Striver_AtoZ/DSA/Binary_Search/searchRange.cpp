#include <iostream>
#include <vector>
using namespace std;


vector<int> searchRange(vector<int> &nums, int target) {
    int n = nums.size();

    int first = -1;
    int low = 0, high = n - 1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(nums[mid] >= target){
            if(nums[mid] == target)
                first = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    int last = -1;
    low = 0;
    high = n - 1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(nums[mid] <= target){
            if(nums[mid] == target)
                last = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    return {first, last};
}

int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the sorted elements: ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    int target;
    cout << "Enter the target: ";
    cin >> target;

    vector<int> ans = searchRange(nums, target);

    cout << "First occurrence: " << ans[0] << endl;
    cout << "Last occurrence: " << ans[1] << endl;

    return 0;
}