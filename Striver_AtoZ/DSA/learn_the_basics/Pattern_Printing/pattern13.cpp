#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter the size of the pattern ";
    cin>>n;
    int temp=0;
    for (int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            temp++;
            cout<<temp<<" ";
        }
        cout<<"\n";
    }
    return 0;
}