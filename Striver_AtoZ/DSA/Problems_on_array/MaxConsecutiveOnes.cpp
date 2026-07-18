#include<iostream>
#include <vector>
using namespace std;

int findMaxConsecutiveOnes(vector <int> nums){
    int n=nums.size();
    int maxones=0;
    int one_cnt =0;
    for (int x:nums){
        //cout<<"entered the loop"<<"\n";
        if (x==1){
            //cout<<"entered the if==1"<<"\n";
            one_cnt ++;
            //cout<<"one_cnt-"<<one_cnt<<"\n";
        }
        if(one_cnt>maxones){
            //cout<<"entered the if snt>max"<<"\n";
            //cout<<"maxones-"<<maxones<<"\n";
            maxones=one_cnt;
            //cout<<"maxones-"<<maxones<<"\n";
                
            }
        if (x==0){
            //cout<<"entered the if==0"<<"\n";
            one_cnt =0;
        }
    }
    return maxones;
}
int main (){
    int n;cin>>n;
    vector <int> nums(n);
    for (int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout << findMaxConsecutiveOnes(nums)<<endl;
    return 0;
}