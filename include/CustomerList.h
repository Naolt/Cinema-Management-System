#ifndef CUSTOMERLIST_H
#define CUSTOMERLIST_H

#include <iostream>
#include <iomanip>
#include <string>
// 
#include "MainMenu.h"

using namespace std;

enum ORDER {NORM, NAME_ASC, NAME_DES, AGE_ASC, AGE_DES};

template <typename T>
void swap(T& one, T& other)
{
    T temp = one;
    one = other;
    other = temp;
}

void customer_list(Customer& customers[], ORDER order = NORM)
{
    system("clear");
    
    cout << "########################" << endl;
    cout << setw(5) << "ID" << '|' << setw(16) << "Name" << '|' << setw(3) << "Age" << '|' << setw(8) << "Balance" << endl;
    cout << "########################" << endl;

    switch (order)
    {
    case NORM:
        for (auto& customer : customers)
            cout << setw(5) << customer.id << '|' << setw(16) << customer.name << '|' << setw(3) << customer.age << '|' << setw(8) << customer.balance << endl;
        break;
    
    case NAME_ASC:
        Customer n_a_customers[] = customers;
        for (int i = 0; i < n_a_customers.size(); i++)
            for (int j = 0; j < i; j++)
                if (n_a_customers[i].name[0] < n_a_customers[j].name[0])
                   swap(n_a_customers[i].name, n_a_customers[j].name);
        
        customer_list(n_a_customers);
        break;

    case NAME_DES:
        Customer n_d_customers[] = customers;
        for (int i = 0; i < n_d_customers.size(); i++)
            for (int j = 0; j < i; j++)
                if (n_d_customers[i].name[0] > n_d_customers[j].name[0])
                    swap(n_d_customers[i].name, n_d_customers[j].name);
        
        customer_list(n_d_customers);
        break;
    
    case AGE_ASC:
        Customer a_a_customers[] = customers;
        for (int i = 0; i < a_a_customers.size(); i++)
            for (int j = 0; j < i; j++)
                if (a_a_customers[i].age < a_a_customers[j].age)
                    swap(a_a_customers[i].age, n_a_customers[j].age);
        
        customer_list(a_a_customers);
        break;
    
    case AGE_DES:
        Customer a_d_customers[] = customers;
        for (int i = 0; i < a_d_customers.size(); i++)
            for (int j = 0; j < i; j++)
                if (a_d_customers[i].age > a_d_customers[j].age)
                    swap(a_d_customers[i].name, a_d_customers[j].name);
        
        customer_list(a_d_customers);
        break;
    }

    cout << "########################" << endl << endl;

    cout << "1. Edit customer info" << endl;
    cout << "2. Delete a customer" << endl;
    cout << "3. Sort by..." << endl;
    cout << "4. Return to main menu" << endl;

    INPUT0:
    cout << "\n > "; unsigned choice; cin >> choice;

    switch (choice)
    {
    case 1:
        INPUT1:
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
        goto INPUT1;
        break;
    
    case 2:
        INPUT2:
        cout << "\nEnter Customer ID: "; int ID; cin >> ID;
        for (auto& customer : customers)
        {
            if (customer.id == ID)
            {
                delete_customer(customers, customer)
            }
        }

        // If customer wasn't found...
        cout << "\nInvalid customer ID. Try again." << endl;
        goto INPUT2;
        break;
    
    case 3:
        cout << endl;
        cout << "1. Name (1.1 for ascending, 1.2 descending)" << endl;
        cout << "2. Age (2.1 for ascending, 2.2 descending)" << endl;

        INPUT3:
        cout << "\n > "; float prompt; cin >> prompt;
        switch (prompt)
        {
        case 1.1:
            customer_list(customers, NAME_ASC);
            break;

        case 1.2:
            customer_list(customers, NAME_DES);
            break;

        case 2.1:
            customer_list(customers, AGE_ASC);
            break;

        case 2.2:
            customer_list(customers, AGE_DES);
            break;
        
        default:
            cout << "\nInvalid input. Try again." << endl;
            goto INPUT3;
        }
        break;
    
    case 4:
        mainMenu();
        break;
    
    default:
        cout << "\nInvalid input. Try again." << endl;
        goto INPUT0;
    }
}

#endif // CUSTOMERLIST_H