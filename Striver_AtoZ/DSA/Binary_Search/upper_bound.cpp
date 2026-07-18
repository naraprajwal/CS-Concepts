

#include <iostream>
#include <vector>
using namespace std;

int upperBound(vector<int>& nums, int x){
    int low = 0;
    int high = nums.size() - 1;
    int ans = nums.size();

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(nums[mid] <= x){
            
            low = mid + 1;
        }
        else{
            ans = mid;
            high = mid - 1;
        }
    }

    return ans;
}

int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the sorted elements: ";
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    int x;
    cout << "Enter x: ";
    cin >> x;

    cout << upperBound(nums, x) << endl;

    return 0;
}