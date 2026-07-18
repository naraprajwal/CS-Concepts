#include<iostream>
using namespace std;

int main (){
    vector<int> v1;
    v1.emplace_back(0);//same as push_back but when entering the pair we need to ue the curly braces in push not in emplace 
    v1.push_back(1);//adds the element at the end
    v1.emplace_back(2);

    vector<int>v2(5,20);//v2 = {20,20,20,20,20}
    v2.push_back(2);//v2 = {20,20,20,20,20,2}

    vector<int>v3(5);//v3 = { , , , , }

    vector<int>v4({20,30,40,50,60});
    vector<int>::iterator it1 = v4.begin();//it points at the beginning of the array it is pointer
    it1++;
    cout<<*(it1)<<endl;

    vector<int>::iterator it2 = v4.end();//points to location just after the array end element location
    vector<int>::reverse_iterator it3 = v4.rbegin();//points just before the array starting element location
    vector<int>::reverse_iterator it4 = v4.rend();//points to the last element of the vector and moves in the reverse way as we do it++

    for (vector<int>::iterator it5=v4.begin(); it5 != v4.end();it5++){
        cout << *(it5) << " ";
    }

    cout << "\n";

    for (auto it5=v4.begin(); it5 != v4.end();it5++){
        cout << *(it5) << " ";
    }//auto takes care of the data type automatically based on the value which we assign to the variable 

    cout << "\n";

    for (int it5 : v4){
        cout<<it5<<" ";
    }// it5 here takes the value from the vector does not point it

    cout << "\n";

    v4.erase(v4.begin());//{30,40,50,60} - give the address in the argument which we want to delete
    for (int it5 : v4){
        cout<<it5<<" ";
    }// it5 here takes the value from the vector does not point it
    cout << "\n";


    v4.erase(v4.begin()+1,v4.end()-1);//{30,60} - all the elements between the given pointers are deleted includeing the starting pointer but excludin the end pointer
    for (int it5 : v4){
        cout<<it5<<" ";
    }// it5 here takes the value from the vector does not point it
    cout << "\n";

    v4.insert(v4.begin(),2);//{2,30,60} - insert the element at the given location and moves the already present elements accordingly
    for (int it5 : v4){
        cout<<it5<<" ";
    }// it5 here takes the value from the vector does not point it
    cout << "\n";

    v4.insert(v4.begin()+1,3,1);//{2,1,1,1,30,60}
    for (int it5 : v4){
        cout<<it5<<" ";
    }// it5 here takes the value from the vector does not point it
    cout << "\n";

    cout<<v4.size()<<"\n"; //6

    v4.pop_back();//deletes the last element here 60
    for (int it5 : v4){
        cout<<it5<<" ";
    }// it5 here takes the value from the vector does not point it
    cout << "\n";

    vector <int>v5({1,2});
    v5.swap(v4);
    for (auto it5 : v4){
        cout<<it5<<" ";
    }// it5 here takes the value from the vector does not point it
    cout << "\n";

    v4.clear();//erases the entire vector;


    cout <<v4.empty();//tells whether the vector is emty or not
    return 0;
}
