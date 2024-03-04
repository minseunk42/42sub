#include "PresidentialPardonForm.hpp"

// for OCF
PresidentialPardonForm::PresidentialPardonForm() : AForm("", 1, 1), target("target"){}
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &ref) : AForm("", 1, 1), target("target"){(void)ref;}
PresidentialPardonForm&  PresidentialPardonForm::operator=(PresidentialPardonForm const &ref) {(void)ref; return *this;}
PresidentialPardonForm::~PresidentialPardonForm(){}

// constructor
PresidentialPardonForm::PresidentialPardonForm(std::string name, std::string target) : AForm(name, 25, 5), target(target){}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    checkPermit(executor);
    std::cout << this->target << "has been pardoned by Zaphod Beeblebrox." << std::endl;
}