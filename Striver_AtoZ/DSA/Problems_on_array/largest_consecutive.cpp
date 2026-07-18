#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int longestConsecutive(vector <int>nums){
    int longest_length = 0;
    unordered_map<int,int> mp;
    for (int i = 0; i < nums.size(); i++){
        mp[nums[i]] = 1;
    }
    for (auto i : mp){
        // Only start from the beginning of a sequence
        if (mp.find(i.first - 1) != mp.end())
            continue;
        int length = 1;
        int current = i.first;
        while (mp.find(current + 1) != mp.end()){
            current++;
            length++;
        }
        if (length > longest_length)longest_length = length;
    }
    return longest_length;
}

int main (){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int longest_length = longestConsecutive(nums);
    cout << longest_length;
    return 0;
}