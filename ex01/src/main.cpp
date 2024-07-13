#include "../inc/PhoneBook.hpp"
#include <string>
#include <iostream>

int main(void)
{
    PhoneBook   phoneBook;
    std::string command;

    while (std::cin >> command)
    {
        if (command == "ADD")
        {
            std::string firstName, lastName, nickname, phoneNumber, darkestSecret;
            std::cout << "Enter first name: ";
            std::cin >> firstName;
            std::cout << "Enter last name: ";
            std::cin >> lastName;
            std::cout << "Enter nickname: ";
            std::cin >> nickname;
            std::cout << "Enter phone number: ";
            std::cin >> phoneNumber;
            std::cout << "Enter darkest secret: ";
            std::cin >> darkestSecret;

            Contact newContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
            phoneBook.addContact(newContact);
        }
        else if (command == "SEARCH")
        {
            int index;
            std::cout << "Enter index: ";
            std::cin >> index;
            phoneBook.searchContact(index);
        }
        else if (command == "EXIT")
            break;
        else
            std::cout << "Invalid command." << std::endl;
    }
    return (0);
}