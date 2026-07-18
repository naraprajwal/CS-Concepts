#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int min_invector(const vector<int>& nums){
    return *min_element(nums.begin(),nums.end());
}
int maxinvector(const vector<int>& nums){
    return *max_element(nums.begin(), nums.end());
}

int no_of_bokeh(const vector<int>& nums,int k,int days){
    int bokeh_cnt=0;
     int bloomed_roses = 0;
    for (int i=0;i<nums.size();i++){
        if (nums[i]<=days)bloomed_roses++;
        else bloomed_roses=0;
        if (bloomed_roses==k){
            bokeh_cnt++;
            bloomed_roses=0;
        }
    }
    return bokeh_cnt;
}
int rosegarden(vector <int>nums,int k,int m){
    int n=nums.size();
    if((long long)m * k > n) return -1;
    int low=min_invector(nums);
    int high=maxinvector(nums);
    int min_days = high+1;
    while (high>=low){
        int mid = low+(high-low)/2;
        int bokoehs = no_of_bokeh(nums,k,mid);
        if (bokoehs >= m){
            min_days = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }   
    if (min_days==maxinvector(nums)+1)return -1;
    else return min_days;
}

int main(){
    int n;
    cout << "Enter the number of roses: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the bloom days: ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    int k, m;
    cout << "Enter k (roses per bouquet): ";
    cin >> k;

    cout << "Enter m (number of bouquets): ";
    cin >> m;

    cout << "Minimum days: " << rosegarden(nums, k, m) << endl;

    return 0;
}   