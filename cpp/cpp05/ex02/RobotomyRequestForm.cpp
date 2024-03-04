#include "RobotomyRequestForm.hpp"

// for OCF
RobotomyRequestForm::RobotomyRequestForm() : AForm("", 1, 1), target("target"){}
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &ref) : AForm("", 1, 1), target("target"){(void)ref;}
RobotomyRequestForm&  RobotomyRequestForm::operator=(RobotomyRequestForm const &ref) {(void)ref; return *this;}
RobotomyRequestForm::~RobotomyRequestForm(){}

// constructor
RobotomyRequestForm::RobotomyRequestForm(std::string name, std::string target) : AForm(name, 72, 45), target(target){}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    checkPermit(executor);
    std::srand(std::time(NULL));
    if (std::rand() % 2 == 1)
        std::cout << this->target << "has been robotomized" << std::endl;
    else
        std::cout << this->target << "fail to robotomize" << std::endl;
}