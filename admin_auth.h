#ifndef ADMIN_AUTH_H
#define ADMIN_AUTH_H

#include <fstream>
#include <string>

// Check if an admin has already signed up
bool signedUp()
{
    std::ifstream admin_info;
    admin_info.open("admin/admin.txt");

    std::string check; admin_info >> check;
    admin_info.close();

    // If it's empty...
    if (check.empty())
        return false;
    return true;
}

void newAdminSignUp()
{
    std::cout << "\n\n ADMIN SIGN UP \n\n" << std::endl;

    std::cout << "Username: "; std::string user; std::cin >> user;
    std::cout << "Password (at least 8 characters): "; std::string pass; std::cin >> pass;
    while (pass.length() < 8)
    {
        std::cout << "\nPassword too short! Try again!" << std::endl;
        std::cout << "Password (at least 8 characters): "; std::cin >> pass;
    }
    
    // Enter account information to the database
    std::ofstream admin_info;
    admin_info.open("admin/admin.txt");
    admin_info << user << ' ' <<  pass;
    admin_info.close();
}

bool adminSignIn()
{
    std::cout << "\n\n ADMIN SIGN IN \n\n" << std::endl;
    
    std::cout << "Username: "; std::string user; std::cin >> user;
    std::cout << "Password: "; std::string pass; std::cin >> pass;

    // Retrieve account information from the database
    std::ifstream admin_info;
    admin_info.open("admin/admin.txt");

    std::string raw; unsigned i {};
    std::string values[2];
    while (!admin_info.eof())
    {
        admin_info >> raw;
        values[i++] = raw;
    }

    if (user == values[0] && pass == values[1])
        return true; 
    else
    {
        // Program will shut down after three failed attempts
        unsigned attempts {1};

        while (++attempts != 4)
        {
            std::cout << "\nIncorrect username or password! Try again! (" 
                    << 4 - attempts << ((4 - attempts) > 1 ? " attempts" : " attempt") << " left.)" << std::endl;
            std::cout << "Username: "; std::cin >> user;
            std::cout << "Password: "; std::cin >> pass;

            if (user == values[0] && pass == values[1])
                return true;
            else continue;
        }
    }
    std::cout << "\nToo many incorrect attempts. Shutting down." << std::endl;
    return false;
}

#endif