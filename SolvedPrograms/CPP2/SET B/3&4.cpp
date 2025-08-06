#include<iostream>
#include<string>

using namespace std;

class BUS{
    public:
    int busNo;
    string busName;
    int no_of_seats; // Changed to int
    string stPt;
    string dtPt;

    void getData(){
        cout << "Enter bus no: ";
        cin >> busNo;

        cin.ignore(); 

        cout << "Enter name of the bus: ";
        getline(cin, busName);
       
        cout << "Enter number of seats: ";
        cin >> no_of_seats; 

        cin.ignore(); 

        cout << "Enter Departure Stop: ";
        getline(cin, stPt);
        
        cout << "Enter Arrival Stop: ";
        getline(cin, dtPt);
    }
    void displayData(){
        cout << "------------------------" << endl;
        cout << "Bus No: " << busNo << endl;
        cout << "Bus Name: " << busName << endl;
        cout << "Number of Seats: " << no_of_seats << endl;
        cout << "Departure Stop: " << stPt << endl;
        cout << "Arrival Stop: " << dtPt << endl;
        cout << "------------------------" << endl;
    }
};

int main(){
    BUS bus[100];
    int n;
    cout << "Enter number of buses: ";
    cin >> n;

    if (n > 100) {
        cout << "Maximum number of buses is 100. Setting n to 100." << endl;
        n = 100;
    }
    
    cin.ignore();

    for(int i = 0; i < n; i++){
        cout << "\nEnter details for bus " << i + 1 << ":" << endl;
        bus[i].getData();
    }
    
    cout << "\n\nDetails of all buses:" << endl;
    for(int i = 0; i < n; i++){
        cout << "\nDisplaying details for bus " << i + 1 << ":" << endl;
        bus[i].displayData();
    }
    return 0;
}