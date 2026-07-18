#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;

int MaxSum_subarray_alternate(vector<int>& nums) {
    int currentSum = nums[0];
    int maxSum = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        currentSum = max(nums[i], currentSum + nums[i]);
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

//n>=2
int stocksellbuy (vector <int> arr){
    int n=arr.size();
    vector <int> brr(n-1);
    for(int i=0;i<n-1;i++){
        brr[i] = arr[i+1]-arr[i];
    }
    return max(0,MaxSum_subarray_alternate(brr));
}

int stockSellBuy_alternate(vector<int>& prices) {
    int minPrice = prices[0];
    int maxProfit = 0;
    for (int i = 1; i < prices.size(); i++) {
        maxProfit = max(maxProfit, prices[i] - minPrice);
        minPrice = min(minPrice, prices[i]);
    }

    return maxProfit;

}

int main (){
    int n;
    cin >> n;
    //cout << "x\n";
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        //cout <<"y\n";
    }
    int x = stocksellbuy(nums);
    cout <<x;
    return 0;
}