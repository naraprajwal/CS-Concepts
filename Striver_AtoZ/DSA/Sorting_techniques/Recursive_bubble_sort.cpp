#include <iostream>
using namespace std;

void print_array(int arr[],int n){
    for (int i=0;i<n;i++){
        cout << arr[i]<<" ";
    }
    cout<<"\n";
    return;
}

void Recursive_bubble_sort(int arr[], int n){
    int swap_cnt=0;
    for (int i=0;i<=n-2;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
            swap_cnt +=1;
        }
    }
    if (swap_cnt==0)return;
    Recursive_bubble_sort(arr,n-1);
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
    Recursive_bubble_sort(arr,n);
    print_array(arr,n);
    return 0;

}