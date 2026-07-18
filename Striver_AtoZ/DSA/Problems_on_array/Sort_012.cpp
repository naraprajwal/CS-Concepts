#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sort_012(vector <int> &nums){
    int low=0,mid=0,high=nums.size()-1;
    while(mid<=high){
        if (nums[mid]==0){
            swap(nums[low],nums[mid]);
            low++;
        }
        else if(nums[mid]==2){
            swap(nums[high],nums[mid]);
            high--;
            if (nums[mid]==0){
            swap(nums[low],nums[mid]);
            low++;
        }
        }
        mid++;
    }
    return;
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
    sort_012(nums);
    for (int x:nums){
        cout << x << " ";
    }
    return 0;
}