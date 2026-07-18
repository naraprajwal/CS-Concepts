#include <iostream>
using namespace std;

void print_array(int arr[],int n){
    for (int i=0;i<n;i++){
        cout << arr[i]<<" ";
    }
    cout<<"\n";
    return;
}

void selection_sort(int arr[], int n){
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            if (arr[j]<arr[i])swap(arr[i],arr[j]);
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
    selection_sort(arr,n);
    print_array(arr,n);
    return 0;

}