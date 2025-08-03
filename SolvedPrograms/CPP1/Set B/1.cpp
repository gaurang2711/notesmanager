#include<iostream>

using namespace std;

int main(){
    int r1, r2, i1, i2;
    cout<<"Enter the real and imaginary parts of the first complex number (r1 i1): ";
    cin>>r1>>i1;
    cout<<"Enter the real and imaginary parts of the second complex number (r2 i2): ";
    cin>>r2>>i2;
    int riyal = r1 + r2;
    int bekhayali = i1 + i2;

    cout<<"The sum of the two complex numbers is: "<<riyal<<" + "<<bekhayali<<"i"<<endl;

    cout<<"\n--CODED BY GAURANG DALAL--\n";
    return 0;
}