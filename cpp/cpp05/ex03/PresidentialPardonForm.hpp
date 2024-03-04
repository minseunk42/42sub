#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include <string>

class PresidentialPardonForm : public AForm
{
    private:
        std::string target;
    private:
        PresidentialPardonForm();
        PresidentialPardonForm(PresidentialPardonForm const &ref);
        PresidentialPardonForm&  operator=(PresidentialPardonForm const &ref);
    public:
        PresidentialPardonForm(std::string name, std::string target);
        ~PresidentialPardonForm();
        void execute(Bureaucrat const & executor) const;
};

#endif