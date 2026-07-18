#include <iostream>
#include <vector>
using namespace std;

int linearSearch(const vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target) return i;
    }
    return -1;
}

vector<int> union_of_Array(vector<int> nums1, vector<int> nums2) {
    vector<int> unionArray;

    int n1 = nums1.size();
    int n2 = nums2.size();

    int i = 0, j = 0;

    while (i < n1 && j < n2) {
        if (nums1[i] == nums2[j]) {
            if (linearSearch(unionArray, nums1[i]) == -1) {
                unionArray.push_back(nums1[i]);
            }
            i++;
            j++;
        }
        else if (nums1[i] < nums2[j]) {
            if (linearSearch(unionArray, nums1[i]) == -1) {
                unionArray.push_back(nums1[i]);
            }
            i++;
        }
        else {
            if (linearSearch(unionArray, nums2[j]) == -1) {
                unionArray.push_back(nums2[j]);
            }
            j++;
        }
    }

    while (i < n1) {
        if (linearSearch(unionArray, nums1[i]) == -1) {
            unionArray.push_back(nums1[i]);
        }
        i++;
    }

    while (j < n2) {
        if (linearSearch(unionArray, nums2[j]) == -1) {
            unionArray.push_back(nums2[j]);
        }
        j++;
    }

    return unionArray;
}

int main() {
    int n1, n2;
    cin >> n1;
    vector<int> nums1(n1);
    for (int i = 0; i < n1; i++) {
        cin >> nums1[i];
    }
    cin >> n2;
    vector<int> nums2(n2);
    for (int i = 0; i < n2; i++) {
        cin >> nums2[i];
    }
    vector<int> result = union_of_Array(nums1, nums2);
    for (int x : result) {
        cout << x << " ";
    }
    return 0;
}