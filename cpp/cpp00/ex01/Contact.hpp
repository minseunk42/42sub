#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{
    private:
        std::string firstname;
        std::string lastname;
        std::string nickname;
        std::string phonenumber;
        std::string darkestsecret;
    public:
        std::string get_firstname() const;
        std::string get_lastname() const;        
        std::string get_nickname() const;
        std::string get_phonenumber() const;
        std::string get_darkestsecret() const;
        void set_firstname(const std::string &firstname);
        void set_lastname(const std::string &lastname);
        void set_nickname(const std::string &nickname);
        void set_phonenumber(const std::string &phonenumber);
        void set_darkestsecret(const std::string &darkestsecret);
};


#endif