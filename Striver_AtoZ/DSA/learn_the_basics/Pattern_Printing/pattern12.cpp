#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter the size of the pattern ";
    cin>>n;
    for (int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<j+1;
        }
        for (int j=0;j<2*(n-i-1);j++){
            cout<<" ";
        }
        for (int j=i;j>=0;j--){
            cout<<j+1;
        }
        cout<<"\n";
    }
    return 0;
}