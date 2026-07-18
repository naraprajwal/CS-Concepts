#include <iostream>
using namespace std;

void print_array(int arr[],int n){
    for (int i=0;i<n;i++){
        cout << arr[i]<<" ";
    }
    cout<<"\n";
    return;
}

void Recursive_Insertion_sort(int arr[], int n,int i){
    if (n==1 || i>=n)return;
    int j=i-1;
    int temp = arr[i],temp_index = i;
    while(arr[j]>temp&&j>=0){
        swap(arr[j],arr[temp_index]);
        temp_index=j;
        j--;
    }
    Recursive_Insertion_sort(arr,n,i+1);
}
int main (){
    int n;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    print_array(arr,n);
    Recursive_Insertion_sort(arr,n,1);
    print_array(arr,n);
    return 0;

}