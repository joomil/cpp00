#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <vector>
# include "Contact.hpp"

class PhoneBook {
private:
    std::vector<Contact> contacts;
    int oldestIndex;

public:
    PhoneBook();
    void addContact(const Contact& contact);
    void searchContact(int index);
};

#endif