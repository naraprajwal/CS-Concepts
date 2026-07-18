#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter the size of the pattern ";
    cin>>n;
    for (int i=0;i<n;i++){
        for (int j=0;j<n-1-i;j++){
            cout<<" ";
        }
        for (int j=0;j<=i;j++){
            cout<<char(65+j);
        }
        for (int j=0;j<i;j++){
            cout<<char(65+i-1-j);
        }
        cout<<"\n";
    }
    return 0;
}