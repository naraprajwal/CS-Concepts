#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int subarraySum(vector<int> num, int k) {
    unordered_map<long long int, int> mp;
    int cnt = 0;
    long long sum = 0;
    mp[0] = 1;
    for (int i = 0; i < num.size(); i++) {
        sum += num[i];
        int temp = sum - k;
        if (mp[temp] > 0) {
            cnt += mp[temp];
        }
        mp[sum]++;
    }
    return cnt;
}

int main (){
    int n;
    cin>>n;
    vector <int>num(n);
    for (int i=0;i<n;i++){
        cin>>num[i];
    }
    int k;
    cout <<"Enter the target-";
    cin>>k;
    cout <<endl;
    int Subarray_cnt=subarraySum(num,k);
    cout << Subarray_cnt;
    return 0;
}