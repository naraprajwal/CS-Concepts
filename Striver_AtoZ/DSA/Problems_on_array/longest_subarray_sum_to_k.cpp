#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longestSubarrayWithSumK(vector<int>& nums, int k) {
    unordered_map<long long, int> prefixMap;

    long long prefixSum = 0;
    int maxLen = 0;

    for (int i = 0; i < nums.size(); i++) {
        prefixSum += nums[i];

        // Subarray from 0 to i sums to k
        if (prefixSum == k) {
            maxLen = i + 1;
        }

        // Check if there exists a prefixSum = currentSum - k
        if (prefixMap.find(prefixSum - k) != prefixMap.end()) {
            int len = i - prefixMap[prefixSum - k];
            maxLen = max(maxLen, len);
        }

        // Store first occurrence only
        if (prefixMap.find(prefixSum) == prefixMap.end()) {
            prefixMap[prefixSum] = i;
        }
    }

    return maxLen;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int k;
    cin >> k;
    cout << longestSubarrayWithSumK(nums, k);

    return 0;
}