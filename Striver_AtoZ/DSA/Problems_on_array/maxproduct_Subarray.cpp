#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<climits>

using namespace std;

long long int Maxproduct(vector<int> nums){
    long long prefix = 1;
    long long suffix = 1;
    long long max_product = LLONG_MIN;

    int n = nums.size();

    for(int i = 0; i < n; i++){
        if(prefix == 0)
            prefix = 1;
        if(suffix == 0)
            suffix = 1;

        prefix *= nums[i];
        suffix *= nums[n - 1 - i];

        max_product = max(max_product, max(prefix, suffix));
    }

    return max_product;
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

    cout << "Maximum product subarray: " << Maxproduct(nums) << endl;

    return 0;
}