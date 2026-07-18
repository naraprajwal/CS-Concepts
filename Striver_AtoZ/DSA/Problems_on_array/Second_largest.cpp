#include<iostream>
using namespace std;

int Second_Largest_element(int arr[],int n){
    int largest=arr[0];
    int second_largest=arr[0];
    
    for (int i=1;i<n;i++){
        if (arr[i]>largest){second_largest=largest;largest = arr[i];}
    }
    return second_largest;
}
int main (){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int second_largest = Second_Largest_element(arr,n);
    cout << second_largest;
    return 0;
}