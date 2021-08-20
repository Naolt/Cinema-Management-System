#include <iostream>
#include <iomanip>
#include <conio.h>
#include <fstream>

#include "admin_auth.h"
#include "include/draw.h"

int main()
{
    system("clear");

    std::cout << "CINEMA MANAGEMENT SYSTEM" << std::endl << std::endl;

    std::cout << "1. Sign up";
    if (signedUp()) std::cout << " (Admin already signed up, you can edit credentials after signing in.)";
    std::cout << std::endl;

    std::cout << "2. Sign in" << std::endl;
    std::cout << "\n\n > "; unsigned choice; std::cin >> choice;

    switch (choice)
    {
    case 1:
        if (!signedUp())
            newAdminSignUp();
        else
            main();
        break;
        
    case 2:
        if (adminSignIn())
            if (!mainMenu())
                main();
        break;
            
    default:
        break;
    }
}