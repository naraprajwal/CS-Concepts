#include <iostream>
using namespace std;

void print_array(int arr[],int n){
    for (int i=0;i<n;i++){
        cout << arr[i]<<" ";
    }
    cout<<"\n";
    return;
}

void Bubble_sort(int arr[], int n){
    for (int i=0;i<n;i++){
        for (int j=0;j<n-i-1;j++){
            if (arr[j]>arr[j+1])swap(arr[j],arr[j+1]);
        }
    }
    return;
}
int main (){
    int n;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    print_array(arr,n);
    Bubble_sort(arr,n);
    print_array(arr,n);
    return 0;

}