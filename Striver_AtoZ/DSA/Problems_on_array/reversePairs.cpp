#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

long long Count(vector<int>& arr, int low, int mid, int high){
    long long cnt = 0;

    int right = mid + 1;
    for(int left = low; left <= mid; left++){
        while(right <= high && (long long)arr[left] > 2LL * arr[right])
            right++;
        cnt += (right - (mid + 1));
    }

    return cnt;
}

long long divideAndCount(vector<int>& arr, int low, int high){
    if(low >= high)
        return 0;

    int mid = (low + high) / 2;

    long long cnt = 0;
    cnt += divideAndCount(arr, low, mid);
    cnt += divideAndCount(arr, mid + 1, high);
    cnt += Count(arr, low, mid, high);

    return cnt;
}

long long numberOfReverse_pair(vector<int> nums){
    return divideAndCount(nums, 0, nums.size() - 1);
}

int main (){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }

    cout << "Number of reverse pairs: "
         << numberOfReverse_pair(nums) << endl;

    return 0;
}