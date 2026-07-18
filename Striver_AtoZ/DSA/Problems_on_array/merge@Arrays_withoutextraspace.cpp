#include <iostream>
#include <vector>
using namespace std;

void mergeArrays(vector<int>& nums1, int m, vector<int>& nums2, int n){
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (i >= 0 && j >= 0){
        if (nums1[i] > nums2[j]){
            nums1[k] = nums1[i];
            i--;
        }
        else{
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    while (j >= 0){
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}

int main(){
    int m, n;
    cout << "Enter m and n: ";
    cin >> m >> n;

    vector<int> nums1(m + n);
    cout << "Enter " << m << " elements of nums1: ";
    for (int i = 0; i < m; i++){
        cin >> nums1[i];
    }

    vector<int> nums2(n);
    cout << "Enter " << n << " elements of nums2: ";
    for (int i = 0; i < n; i++){
        cin >> nums2[i];
    }

    mergeArrays(nums1, m, nums2, n);

    cout << "Merged array: ";
    for (int x : nums1){
        cout << x << " ";
    }

    return 0;
}