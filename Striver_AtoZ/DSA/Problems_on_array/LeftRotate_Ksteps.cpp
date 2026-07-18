#include<iostream>
using namespace std;

void LeftRotate_kSteps(int arr[],int n,int k){
    for(int j=0;j<k;j++){
        int temp = arr[0];
        for(int i=0;i<n-1;i++)arr[i]=arr[i+1];
        arr[n-1]=temp;}
    return;
}

int main (){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;cin>>k;
    LeftRotate_kSteps(arr,n,k);
    for(int i=0;i<n;i++)cout <<arr[i]<<" ";
    return 0;
}//better wat to do is roatate the k-1 elements and rotate the other elements and rotate the whoole array 
