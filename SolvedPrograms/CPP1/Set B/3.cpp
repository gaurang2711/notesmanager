#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){
    int decNum;
    string hexNum = "";

    cout<< "Enter a decimal number: ";
    cin >> decNum;

    if(decNum == 0){
        cout<<"Hexadec is 0"<<endl;
        return 0;
    }

    while(decNum > 0){
        int rem = decNum % 16;
        if(rem < 10){
            hexNum += (char)(rem + '0');
        }
        else{
            hexNum += (char)('A' + (rem - 10));
        }

        decNum /= 16;
    }

    reverse(hexNum.begin(), hexNum.end());

    cout << "Hexadec is: " << hexNum << endl;

    cout<<"\n--CODED BY GAURANG DALAL--\n";

    return 0;
}