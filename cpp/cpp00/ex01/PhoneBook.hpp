#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip> 
# include "Contact.hpp"
# include <string>

# define MAX_CONTACT 8
class PhoneBook
{
    private :
        Contact contacts[8];
        int     idx;
    public :
        PhoneBook();
        void add(void);
        void search(void);
        void exit(void);
};

#endif
