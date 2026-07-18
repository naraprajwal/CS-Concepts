#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ;

int PascalTriangle(int r,int c){
    if (r == c||c == 1)return 1;
    return PascalTriangle(r-1,c-1)+PascalTriangle(r-1,c);
}

int main (){
    int r,c;
    cout<<"Enter row number-";
    cin>>r;
    cout<<"Enter Colunm number-";
    cin>>c;
    int Pascal_Triangle_Element_rc = PascalTriangle(r,c);
    cout<<Pascal_Triangle_Element_rc;
    return 0;
}