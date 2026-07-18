#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter the size of the pattern ";
    cin>>n;
    for (int i=0;i<n;i++){
        for (int j=0;j<=i;j++){
            cout<<char(65+n-1-i+j);
        }
        cout<<"\n";
    }
    return 0;
}