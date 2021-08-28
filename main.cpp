#include <iostream>

using namespace std;

int main()
{
    system("clear");

    cout << "##############################################" << endl << endl;
    cout << "######### CINEMA REGISTRATION SYSTEM #########" << endl << endl;
    cout << "##############################################" << endl;
    cout << "# 1. MOVIE REGISTRATION                      #" << endl;
    cout << "# 2. CUSTOMER REGISTRATION                   #" << endl;
    cout << "# 3. MOVIES LIST                             #" << endl;
    cout << "# 4. CUSTOMER LIST                           #" << endl;
    cout << "# 5. SEAT REGISTRATION                       #" << endl;
    cout << "# 6. DAILY PROFIT REPORT                     #" << endl;
    cout << "# 7. QUIT                                    #" << endl;
    cout << "##############################################" << endl;

INPUT:
    cout << "\n > "; unsigned choice; cin >> choice;

    switch (choice)
    {
    case 1:
        // movie_registration();
        break;
    case 2:
        // customer_registration();
        break;
    case 3:
        // movie_list();
        break;
    case 4:
        // customer_list();
        break;
    case 5:
        // seat_reservation();
        break;
    case 6:
        // profit_report();
        break;
    case 7:
        cout << "Closing..." << endl;
        return 0;
    default:
        cout << "\n*Invalid Input*" << endl;
        goto INPUT;
    }
}