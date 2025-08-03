#include<iostream>
#define PI 3.14

using namespace std;

int main(){
    int rad;
    cout<<"Enter the radius of circle: ";
    cin>>rad;
    int area = PI * rad * rad;
    int circ = 2 * PI * rad;
    cout<<"Area: "<<area<<endl<<"Circumference: "<<circ<<endl;

    cout<<"\n--CODED BY GAURANG DALAL--\n";

    return 0;
}