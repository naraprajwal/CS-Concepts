#include <iostream>
#include <vector>
using namespace std;


int countOcuurance(vector<int> &nums, int target) {
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

    return last-first+1;
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

    int ans = countOcuurance(nums, target);

    cout <<"number of occurance: "<<ans;

    return 0;
}