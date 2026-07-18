#include<iostream>
#include<vector>

using namespace std;

int singlenonDuplicate(vector <int>nums){
    int low = 0;
    int high = nums.size()-1;
    if (high<2)return -1;
    while (high>=low){
        int mid = low+(high-low)/2;
        if (nums[mid]!=nums[mid+1]&&nums[mid]!=nums[mid-1])return nums[mid];
        else if (mid==0)return nums[0];
        else if (mid+1==high)return nums[high];
        else if (high==2){
            if (nums[mid]==nums[mid+1])return nums[mid-1];
            else return nums[mid+1];
        }
        if ((high-low)%4==0){
            if (nums[mid]==nums[mid-1])high=mid-1;
            else low = mid+1;
        }
        else {
            if (nums[mid]==nums[mid+1])high=mid+1;
            else low = mid-1;
        }
    }
    return -1;
}

int singlenonDuplicate_optimal(vector<int> nums){
    int n = nums.size();

    if(n == 1) return nums[0];
    if(nums[0] != nums[1]) return nums[0];
    if(nums[n - 1] != nums[n - 2]) return nums[n - 1];

    int low = 1;
    int high = n - 2;

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
            return nums[mid];

        if((mid % 2 == 0 && nums[mid] == nums[mid + 1]) ||
           (mid % 2 == 1 && nums[mid] == nums[mid - 1])){
            low = mid + 1;
        }
        else{
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
    cout << "Enter the sorted array: ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    cout << "Single non-duplicate element: " << singlenonDuplicate(nums) << endl;
    cout << "Optimal solution: " << singlenonDuplicate_optimal(nums) << endl;

    return 0;
}