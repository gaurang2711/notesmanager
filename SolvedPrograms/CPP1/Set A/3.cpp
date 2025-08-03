#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    int n1, n2;
    char op;
    do
    {
        cout << "Enter first number: ";
        cin >> n1;
        cout << "Enter second number: ";
        cin >> n2;
        cout << "Select an operator (+, -, *, /, E to exit)): ";
        cin >> op;

        switch (op)
        {
        case '+':
            cout << n1 << " + " << n2 << " = " << n1 + n2 << endl;
            break;

        case '-':
            cout << n1 << " - " << n2 << " = " << n1 - n2 << endl;
            break;

        case '*':
            cout << n1 << " * " << n2 << " = " << n1 * n2 << endl;
            break;

        case '/':
            cout << n1 << " / " << n2 << " = " << n1 / n2 << endl;
            break;

        case 'E':
            cout << "Exiting the program." << endl;
            exit(0);

        default:
            cout << "Invalid operation";
            break;
        }
    } while (op != 'E');
    cout << "\n--CODED BY GAURANG DALAL--\n";

    return 0;
}