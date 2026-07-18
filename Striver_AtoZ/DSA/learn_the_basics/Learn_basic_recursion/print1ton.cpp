#include <iostream>
using namespace std;

void one_to_n(int n){
    if(n>1)one_to_n(n-1);
    cout<<n<<" ";
    return;
}
int main (){
    int n;
    cin>>n;
    one_to_n(n);
    return 0;
}