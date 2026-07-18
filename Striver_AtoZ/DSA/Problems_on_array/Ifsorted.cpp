#include <iostream>
using namespace std;

bool ifsorted(int arr[],int n){
    for (int i=0;i<n-1;i++){
        if (arr[i+1]<arr[i])return false;
    }
    return true;
}
int main (){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout << ifsorted(arr,n);
    return 0;
}