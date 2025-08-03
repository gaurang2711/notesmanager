#include<iostream>

using namespace std;

int main(){
	int i, fact = 1;
	int n;
	cout<<"Enter n: ";
	cin>>n;
	
	for(i = 1; i <= n; i++){
		fact = fact * i;
	}
	
	cout<<"Factorial is: "<<fact;

	cout<<"\n--CODED BY GAURANG DALAL--\n";
	
	return 0;
}