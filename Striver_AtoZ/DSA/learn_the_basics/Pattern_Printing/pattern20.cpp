#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter the size of the pattern ";
    cin>>n;
    for (int i=0;i<2*n-1;i++){
        if(i<n){
            for(int j=0;j<=i;j++){
            cout<<"*";
            }
            for (int j=0;j<2*(n-i-1);j++){
                cout <<" ";

            }
            for (int j=0;j<=i;j++){
                cout<<"*";
            }
        }
        else {
            for(int j=0;j<2*n-1-i;j++){
                cout<<"*";
            }
            for (int j=0;j<2*(i-n+1);j++){
                cout<<" ";
            }
            for(int j=0;j<2*n-1-i;j++){
                cout<<"*";
            }
        }
        cout<<"\n";
    }
    return 0;
}