#include<iostream>
#include<string>

using namespace std;

class Employee{
    public:
        int basicSal;
        int da;
        int hra;
    
        void getData(){
            cout << "Enter Basic Salary: ";
            cin >> basicSal;
            cout << "Enter DA: ";
            cin >> da;
            cout << "Enter HRA: ";
            cin >> hra;
        }
        void displayData(){
            da = basicSal * 0.445;
            hra = basicSal * 0.15;
            cout << "Basic Salary: " << basicSal << endl;
            cout << "DA: "<< da << endl;
            cout << "HRA: " << hra << endl;
            cout << "Gross Salary: " << basicSal + da + hra << endl;
        }
};

int main(){
    Employee emp[5];
    for(int i = 0; i < 5; i++){
        cout << "Enter details for Employee " << (i + 1) << ":" << endl;
        emp[i].getData();
    }
    cout << "\nEmployee Details:" << endl;
    for(int i = 0; i < 5; i++){ 
        cout << "\nDetails for Employee " << (i + 1) << ":" << endl;
        emp[i].displayData();
    }

    return 0;
}