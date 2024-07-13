#include "../inc/PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook() : oldestIndex(0) {}

void    PhoneBook::addContact(const Contact& contact)
{
    if (contacts.size() < 8)
    {
        contacts.push_back(contact);
    } 
    else
    {
        contacts[oldestIndex] = contact;
        oldestIndex = (oldestIndex + 1) % 8;
    }
}

void    PhoneBook::searchContact(int index)
{
    if (static_cast<std::vector<Contact>::size_type>(index) >= contacts.size())
    {
        std::cout << "Invalid index. "<< std::endl;
        return;
    }

    Contact& contact = contacts[index];
    std::cout << "Index: " << index << " | "
                << contact.getFirstName().substr(0, 10) << " | "
                << contact.getlastName().substr(0, 10) << " | "
                << contact.getNickname().substr(0, 10) << std::endl;
}