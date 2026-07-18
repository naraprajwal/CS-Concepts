#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int maxinvector(const vector<int>& nums){
    return *max_element(nums.begin(), nums.end());
}

int hours_to_eat(const vector<int>& nums, int speed){
    int hours = 0;
    for(int bananas : nums){
        hours += (bananas + speed - 1) / speed;
    }
    return hours;
}
int minimumRateToEatBananas(const vector<int>& nums, int h){
    if(h < nums.size()) return -1;

    int low = 1;
    int high = maxinvector(nums);
    int ans = high;

    while(low <= high){
        int mid = low + (high - low) / 2;
        int hours = hours_to_eat(nums, mid);

        if(hours <= h){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return ans;
}

int main(){
    int n;
    cout << "Enter the number of piles: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the bananas in each pile: ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    int h;
    cout << "Enter the number of hours: ";
    cin >> h;

    cout << "Minimum eating rate: " << minimumRateToEatBananas(nums, h) << endl;

    return 0;
}