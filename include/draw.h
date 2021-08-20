#ifndef DRAW_H
#define DRAW_H

#include <iostream>
#include <conio.h>

bool mainMenu()
{
    system("clear");

    std::cout << "\n1. Schedule Manager" << std::endl;
    std::cout << "2. Movie List (with their respective scedules" << std::endl;
    std::cout << "3. Transactions" << std::endl;
    std::cout << "4. Ticket Prices" << std::endl;
    std::cout << "5. Daily Earnings Report" << std::endl;
    std::cout << "6. Sign Out" << std::endl;

    std::cout << "\n\n > "; unsigned choice; std::cin >> choice;

    switch(choice)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        return false;
        break;
    }
    return true;
}

#endif