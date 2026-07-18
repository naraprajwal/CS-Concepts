#include <iostream>
using namespace std;

void n_to_one(int n){
    cout<<n<<" ";
    if(n>1)n_to_one(n-1);
    return;
}
int main (){
    int n;
    cin>>n;
    n_to_one(n);
    return 0;
}