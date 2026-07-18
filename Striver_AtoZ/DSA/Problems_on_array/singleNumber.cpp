#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int singleNumber(vector <int> nums){
    int ans = 0;
    for (int x : nums){
        ans ^= x;
    }
    return ans;
}

int main (){
    int n;
    cin>>n;

    vector <int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int single_number=singleNumber(arr);
    cout << single_number;
    return 0;
}