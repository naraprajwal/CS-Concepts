

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sumAfterDivision(const vector<int>& nums, int divisor){
    int sum = 0;
    for(int num : nums){
        sum += (num + divisor - 1) / divisor;
    }
    return sum;
}

int smallestDivisor(vector<int>& nums, int threshold){
    int low = 1;
    int high = *max_element(nums.begin(), nums.end());
    int ans = high;

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(sumAfterDivision(nums, mid) <= threshold){
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
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    int threshold;
    cout << "Enter the threshold: ";
    cin >> threshold;

    cout << "Smallest divisor: " << smallestDivisor(nums, threshold) << endl;

    return 0;
}