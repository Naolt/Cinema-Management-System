#ifndef CUSTOMERLIST_H
#define CUSTOMERLIST_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void customer_list(Customer& customers)
{
    system("clear");
    
    cout << "########################" << endl;
    cout << setw(5) << "ID" << '|' << setw(16) << "Name" << setw(8) << "Balance" << endl;
    cout << "########################" << endl;

    for (Customer& customer : customers)
        cout << setw(5) << customer.id << '|' << setw(16) << customer.name << '|' << setw(8) << customer.balance << endl;

    cout << "########################" << endl << endl;

    cout << "1. Edit customer info" << endl;
    cout << "2. Delete a customer" << endl;
    cout << "3. Sort by..." << endl;
    cout << "4. Return to main menu" << endl;

    cout << "\n > "; unsigned choice; cin >> choice;

    switch (choice)
    {
    case 1:
        INPUT:
        cout << "\nEnter customer ID: "; int ID; cin >> ID;
        for (auto& customer : customers)
        {
            if (customer.id == ID)
            {
                cout << "\n1. Change name" << endl;
                cout << "2. Change customer balance" << endl;

                cout << "\n > "; unsigned input; cin >> input;

                switch (input)
                {
                case 1:
                    cout << "Enter their new name: ";
                    string newName; cin >> newName;
                    customer.name = newName;
                    customer_list();
                    break;
                
                case 2:
                    cout << "Enter their new balance: ";
                    sunsigned newBalance; cin >> newBalance;
                    customer.balance = newBalance;
                    customer_list();
                    break; 
                }
            }
        }

        // If customer wasn't found...
        cout << "\nInvalid customer ID. Try again." << endl;
        goto INPUT;

        break;
    
    case 2:
        
    }
}

#endif // CUSTOMERLIST_H