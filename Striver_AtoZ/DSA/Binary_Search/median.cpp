

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size();
        int n = nums2.size();

        int low = 0;
        int high = m;

        while (low <= high) {
            int cut1 = low + (high - low) / 2;
            int cut2 = (m + n + 1) / 2 - cut1;

            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int r1 = (cut1 == m) ? INT_MAX : nums1[cut1];
            int r2 = (cut2 == n) ? INT_MAX : nums2[cut2];

            if (l1 <= r2 && l2 <= r1) {
                if ((m + n) % 2 == 0)
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                else
                    return max(l1, l2);
            }
            else if (l1 > r2) {
                high = cut1 - 1;
            }
            else {
                low = cut1 + 1;
            }
        }

        return 0.0;
    }
};

int main() {
    int m, n;

    cout << "Enter size of first array: ";
    cin >> m;

    vector<int> nums1(m);
    cout << "Enter elements of first sorted array: ";
    for (int i = 0; i < m; i++)
        cin >> nums1[i];

    cout << "Enter size of second array: ";
    cin >> n;

    vector<int> nums2(n);
    cout << "Enter elements of second sorted array: ";
    for (int i = 0; i < n; i++)
        cin >> nums2[i];

    Solution obj;
    cout << "Median = " << obj.findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}   