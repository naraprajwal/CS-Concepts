#include <iostream>
#include <vector>
using namespace std;

vector<int> rearrangeArray(vector<int>& nums) {
    int n = nums.size();

    vector<int> ans(n);

    int pos = 0;
    int neg = 1;

    for (int x : nums) {
        if (x > 0) {
            ans[pos] = x;
            pos += 2;
        } else {
            ans[neg] = x;
            neg += 2;
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> ans = rearrangeArray(nums);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}