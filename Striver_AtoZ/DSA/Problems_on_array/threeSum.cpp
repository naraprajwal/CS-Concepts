#include<iostream>
#include<vector>
#include <algorithm>

using namespace std ;

vector<vector<int>> threeSum(vector<int> nums){
    vector<vector<int>>matrix;
    unordered_map <int,int>mp;
    int n = nums.size();
    for (int i=0;i<n;i++){
        mp[nums[i]]=i;
    }
    for (int i=0;i<n-2;i++){
        for (int j=i+1;j<n-1;j++){
                int temp = nums[i]+nums[j];
                if (mp[-temp]!=0 && mp[-temp]>j)matrix.push_back({nums[i],nums[j],nums[mp[-temp]]});
        }
    }
    return matrix;
}

vector<vector<int>> threeSum_optimal(vector<int> nums){
    vector<vector<int>>matrix;
    sort(nums.begin(),nums.end());
    int n = nums.size();
    for (int i=0;i<n-2;i++){
        while (nums[i]==nums[i-1])i++;
        int j=i+1;
        int k=n-1;
        while (j<k){
            while (nums[k]==nums[k-1])k--;
            while (nums[j]==nums[j+1])j++;
            if (nums[i]+nums[j]+nums[k]==0){
                //cout <<nums[i]<<" "<<nums[j]<<" "<<nums[k];
                matrix.push_back({nums[i],nums[j],nums[k]}),j++,k--;
            }
            else if (nums[i]+nums[j]+nums[k]>0)k--;
            else if (nums[i]+nums[j]+nums[k]<0)j++;
        }
    }
    //cout <<"exited the function\n";
    return matrix;
}

int main (){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    vector<vector<int>> result = threeSum_optimal(nums);
    for (auto row : result){
        for (int x : row){
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}