#include<iostream>
#include<string>
using namespace std;

class Employee{
    public:
        int emp_id;
        string emp_name;
        double emp_salary;
    
    void getDetails(){
        cout<<"Employee ID: ";
        cin>>emp_id;
        cout<<"Employee Name: ";
        cin.ignore();
        getline(cin, emp_name);
        cout<<"Basic Salary: ";
        cin>>emp_salary;
    }

    void displayDetails(){
        cout<<"\nEmployee ID: "<<emp_id<<endl;
        cout<<"Employee Name: "<<emp_name<<endl;
        cout<<"Basic Salary: "<<emp_salary<<endl;
    }
};

int main(){
    Employee emp[5];
    for(int i = 0; i < 5; i++){
        cout<<"Enter details for Employee "<<i+1<<":"<<endl;
        emp[i].getDetails();
    }

    cout<<"\n--EMPLOYEES ABOVE 5000--\n";
    for(int i = 0; i < 5; i++){
        if(emp[i].emp_salary > 5000){
            emp[i].displayDetails();
        }
    }
}