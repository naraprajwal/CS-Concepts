#include <iostream>
using namespace std;
bool isPresent(int arr[],int n,int toFind){
    for (int i=0;i<n;i++)if (arr[i]==toFind)return true;
    return false;
}
int removeDuplicate(int arr[],int n,int brr[]){
    int k=1;
    brr[0] = arr[0];
    for (int i=1;i<n;i++){
        if(!isPresent(brr,k,arr[i]))brr[k]=arr[i],k++;
    }
    return k;
}
int main (){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int brr[n];
    int k = removeDuplicate(arr,n,brr);
    for (int i=0;i<k;i++)cout<<brr[i]<<" ";
    return 0;
}