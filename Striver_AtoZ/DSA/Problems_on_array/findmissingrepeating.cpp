

#include <iostream>
#include <vector>
using namespace std;

vector<int> findMissingRepeating(vector<int>& nums) {
    int n = nums.size();

    int xr = 0;
    for (int i = 0; i < n; i++) {
        xr ^= nums[i];
        xr ^= (i + 1);
    }

    int bit = xr & -xr; 

    int zero = 0, one = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] & bit)
            one ^= nums[i];
        else
            zero ^= nums[i];

        if ((i + 1) & bit)
            one ^= (i + 1);
        else
            zero ^= (i + 1);
    }

    int cnt = 0;
    for (int x : nums) {
        if (x == one)
            cnt++;
    }

    if (cnt == 2)
        return {one, zero};
    else
        return {zero, one};
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> ans = findMissingRepeating(nums);

    cout << "Repeated number: " << ans[0] << endl;
    cout << "Missing number: " << ans[1] << endl;

    return 0;
}