#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<math.h>

using namespace std;

int subarrayeithXorK(vector<int> nums, int k){
    unordered_map<int, int> mp;
    int subarray_cnt = 0;
    int prefixXOR = 0;

    mp[0] = 1;

    for (int i = 0; i < nums.size(); i++){
        prefixXOR ^= nums[i];

        int required = prefixXOR ^ k;
        subarray_cnt += mp[required];

        mp[prefixXOR]++;
    }

    return subarray_cnt;
}

int main (){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " array elements: ";
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }

    int k;
    cout << "Enter the target XOR k: ";
    cin >> k;

    cout << "Number of subarrays with XOR " << k << " = "
         << subarrayeithXorK(nums, k);

 
         return 0;
}