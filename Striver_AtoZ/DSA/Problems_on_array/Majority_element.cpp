#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> majorityElementTwo(vector <int>nums){
    vector <int>majority;
    unordered_map<int,int>mp;
    int n = nums.size();
    int req_majority = n/3;
    for (int i=0;i<n;i++){
        mp[nums[i]]++;
    }
    for (auto x:mp){
        if (x.second>req_majority)majority.push_back(x.first);    
    }
    return majority;
}//time - O(n) and space - O(n)

vector <int>majorityElementTwo_alternate(vector <int>nums){
    vector <int>majority;
    sort(nums.begin(),nums.end());
    int cnt =0;
    int req_majority = nums.size()/3;
    for (int i=0;i<nums.size();i++){
        int temp = nums[i];
        cnt++;
        if (cnt>req_majority){
            cout <<"Entered if"<<endl;
            majority.push_back(nums[i]);
            while(nums[i]==temp)i++;
            cnt=0;
            i-=1;
        }
    }
    return majority;
}//time - O(n*logn) and space - O(1)

vector<int> majorityElementTwo_optimal(vector<int> nums) {
    vector<int> majority;

    int candidate1 = 0, candidate2 = 0;
    int cnt1 = 0, cnt2 = 0;

    // First pass: find the two possible candidates
    for (int x : nums) {
        if (x == candidate1) {
            cnt1++;
        }
        else if (x == candidate2) {
            cnt2++;
        }
        else if (cnt1 == 0) {
            candidate1 = x;
            cnt1 = 1;
        }
        else if (cnt2 == 0) {
            candidate2 = x;
            cnt2 = 1;
        }
        else {
            cnt1--;
            cnt2--;
        }
        cout << cnt1 << " " << cnt2 << endl;
    }

    // Second pass: verify actual frequencies
    cnt1 = 0;
    cnt2 = 0;
    for (int x : nums) {
        if (x == candidate1)
            cnt1++;
        else if (x == candidate2)
            cnt2++;
    }
    if (cnt1 > nums.size() / 3)
        majority.push_back(candidate1);
    if (cnt2 > nums.size() / 3)
        majority.push_back(candidate2);
    return majority;
}
int main (){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    vector<int> result = majorityElementTwo_optimal(nums);
    for (int x : result){
        cout << x << " ";
    }
    return 0;
}