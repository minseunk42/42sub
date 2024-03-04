#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <string>
# include <cstdlib> 
# include <ctime> 
# include <iostream>

class RobotomyRequestForm : public AForm
{
    private:
        std::string target;
    private:
        RobotomyRequestForm();
        RobotomyRequestForm(RobotomyRequestForm const &ref);
        RobotomyRequestForm&  operator=(RobotomyRequestForm const &ref);
    public:
        RobotomyRequestForm(std::string name, std::string target);
        ~RobotomyRequestForm();
        void execute(Bureaucrat const & executor) const;
};

#endif