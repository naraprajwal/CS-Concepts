#include <iostream>
using namespace std;

int main (){
    int n;
    cout<<"Enter a number - ";
    cin>>n;
    cout<<"[";
    for (int i=1;i<n;i++){
        if (n%i==0)cout <<i<<",";
        else continue;
    }
    
    cout <<n<<"]";
    return 0;
}