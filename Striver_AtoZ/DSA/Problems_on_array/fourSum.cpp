#include<iostream>
#include<vector>
#include <algorithm>

using namespace std ;

vector<vector<int>> fourSum_optimal(vector<int> nums,int target){
    vector<vector<int>>matrix;
    sort(nums.begin(),nums.end());
    int n = nums.size();
    for (int i=0;i<n-3;i++){
        while (nums[i]==nums[i-1])i++;
        for (int l=n-1;l>i+2;l--){
            while (nums[l]==nums[l-1])l--;
            int j=i+1;
            int k=l-1;
            while (j<k){
            while (nums[k]==nums[k-1])k--;
            while (nums[j]==nums[j+1])j++;
            if (nums[i]+nums[j]+nums[k]+nums[l]==target){
                //cout <<nums[i]<<" "<<nums[j]<<" "<<nums[k];
                matrix.push_back({nums[i],nums[j],nums[k],nums[l]}),j++,k--;
            }
            else if (nums[i]+nums[j]+nums[k]+nums[l]>target)k--;
            else if (nums[i]+nums[j]+nums[k]+nums[l]<target)j++;
            }

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
    int target;
    cout << "enter target-";
    cin>>target;
    vector<vector<int>> result = fourSum_optimal(nums,target);
    for (auto row : result){
        for (int x : row){
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}