#ifndef INTERN_HPP
# define INTERN_HPP

# include <sstream>
# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# define SCF 0
# define RRF 1
# define PPF 2
# define STATECNT 3

class Intern
{
        static int scfCnt;
        static int rrfCnt;
        static int ppfCnt;
    private:
        Intern(Intern const &ref);
        Intern&  operator=(Intern const &ref);
    public:
        ~Intern();
        Intern();
        AForm *makeForm(std::string formName, std::string target);
};

#endif