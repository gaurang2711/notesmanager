#include<iostream>

using namespace std;

int main(){
	int num;
	int revNum = 0, rem;
	cout<<"Enter number to reverse: ";
	cin>>num;
	
	int ogNum = num;
	
	while(num != 0){
		rem = num % 10;
		revNum = revNum * 10 + rem;
		num = num / 10;
	}
	
	cout<<"OG num: "<<ogNum<<endl;
	cout<<"Rev Num: "<<revNum;

	cout<<"\n--CODED BY GAURANG DALAL--\n";
	
	return 0;
}