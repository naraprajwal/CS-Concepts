#include<iostream>
#include<vector>
#include<math.h>
#include<map>
#include<algorithm>

using namespace std;

long long int numberOfInversions(vector<int> nums) {
    vector <int>sorted_nums=nums;
    sort(sorted_nums.begin(),sorted_nums.end());
    int n = nums.size();
    long long int cnt=0;
    unordered_map<int ,vector<int>>original_mp,sorted_mp;
    for (int i=0;i<n;i++){
        original_mp[nums[i]].push_back(i);
        sorted_mp[sorted_nums[i]].push_back(i);
        }
        for (int i=0;i<n;i++){
            int temp = nums[i];
            //cout <<"inspection for "<<temp<< "-";
            vector <int> temp_vector_org = original_mp[temp];
            vector <int> temp_vector_sort = sorted_mp[temp];
            for (int j=0;j<temp_vector_org.size();j++){
                //cout << temp_vector_org[j]<< " "<< temp_vector_sort[j]<<"--";
                if (temp_vector_org[j]>temp_vector_sort[j]){
                    //cout <<"entered if"<<"-";
                    cnt += temp_vector_org[j]-temp_vector_sort[j];
                    original_mp[temp][j]=-1;
                    //cout << cnt << "---";
                }
            }
            //cout <<endl;
        }
        return cnt;
    }

long long mergeAndCount(vector<int>& arr, int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    long long cnt = 0;

    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            cnt += (mid - left + 1);
            right++;
        }
    }

    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }

    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i = low; i <= high; i++){
        arr[i] = temp[i - low];
    }

    return cnt;
}

long long mergeSortAndCount(vector<int>& arr, int low, int high){
    if(low >= high) return 0;

    int mid = (low + high) / 2;

    long long cnt = 0;
    cnt += mergeSortAndCount(arr, low, mid);
    cnt += mergeSortAndCount(arr, mid + 1, high);
    cnt += mergeAndCount(arr, low, mid, high);

    return cnt;
}

long long numberOfInversions_mergeSort(vector<int> nums){
    return mergeSortAndCount(nums, 0, nums.size() - 1);
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

    cout << "Number of inversions: " << numberOfInversions(nums) << endl;

    return 0;
}