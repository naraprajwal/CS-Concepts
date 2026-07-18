#include <iostream>
using namespace std;

void print_array(int arr[],int n){
    for (int i=0;i<n;i++){
        cout << arr[i]<<" ";
    }
    cout<<"\n";
    return;
}

void merge (int arr[],int left,int mid,int right){
    int i=left,j=mid+1,temp[1000],k=0;
    while(i<=mid&&j<=right){
        if(arr[i]<=arr[j]){
            temp[k]=arr[i];
            i++;
        }else {
            temp[k]=arr[j];
            j++;
        }
        k++;
    }
    
    while (j<=right){
        temp[k]=arr[j];
        k++,j++;
    }
    
    
    while (i<=mid){
        temp[k]=arr[i];
        k++,i++;
    }  
    
    k=0;
    for (int l=left;l<=right;l++){
        arr[l] = temp[k];
        k++;
    }
}
void Merge_sort(int arr[],int left,int right){
    if (left>=right)return;
    int mid = (left+right)/2;
    Merge_sort(arr,left,mid);
    Merge_sort(arr,mid+1,right);
    merge (arr,left,mid,right);
    
}
int main (){
    int n;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    print_array(arr,n);
    Merge_sort(arr,0,n-1);
    print_array(arr,n);
    return 0;

}