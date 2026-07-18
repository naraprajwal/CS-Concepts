#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter the size of the pattern ";
    cin>>n;
    for (int i=0;i<2*n-1;i++){
        if (i<n){
            for (int j=0;j<i;j++){
                cout<<n-j;
            }
            for (int j=0;j<2*(n-i)-1;j++){
                cout<<n-i;
            }
            for (int j=0;j<i;j++){
                cout<<n-i+j+1;
            }
        }
        else {
            for (int j=0;j<2*(n-1)-i;j++){
                cout<<n-j;
            }
            for(int j=0;j<2*(i-n)+3;j++){
                cout<<i-n+2;
            }
            for (int j=0;j<2*(n-1)-i;j++){
                cout<<i-n+3+j;
            }
        }
        cout<<"\n";
    
    }
    
    return 0;
}