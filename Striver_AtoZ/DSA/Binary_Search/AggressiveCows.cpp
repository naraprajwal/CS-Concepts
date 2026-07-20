#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int aggressiveCows(vector<int>&nums,int k){
    if (k>nums.size())return 0;
    sort(nums.begin(),nums.end());
    int low = 1;
    int high = nums[nums.size()-1]-nums[0];
    int ans=INT16_MIN;
    while(low<=high){
        int mid = low+(high-low)/2;
        int temp = nums[0];
        int cows=1;
        for (int i=1;i<nums.size();i++){
            temp += mid;
            cows++;
            while (temp>nums[i])i++;
            if (i<nums.size())temp = nums[i];
            if (cows==k)i=nums.size();
        }
        if (temp==nums[nums.size()-1])ans=max(ans,mid),low=mid+1;
        else if (temp>nums[nums.size()-1])high = mid-1;
        else low = mid+1;
    }
    return ans;
}


int main() {
    int n;
    cout << "Enter number of stalls: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter stall positions: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k;
    cout << "Enter number of cows: ";
    cin >> k;

    cout << "\nStall positions: ";
    for (int x : nums) {
        cout << x << " ";
    }
    cout << "\nNumber of cows: " << k << endl;

    int ans = aggressiveCows(nums, k);

    cout << "Maximum minimum distance = " << ans << endl;

    return 0;
}