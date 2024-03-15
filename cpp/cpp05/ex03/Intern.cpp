#include "Intern.hpp"

int Intern::scfCnt;
int Intern::rrfCnt;
int Intern::ppfCnt;

// for OCF
Intern::Intern(Intern const &ref){(void)ref;}
Intern&  Intern::operator=(Intern const &ref) {(void)ref; return *this;}
Intern::~Intern(){}
Intern::Intern(){}

static int checkFormName(std::string formName)
{
    std::string arr[STATECNT] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    for (int i = 0;  i < STATECNT; ++i) if (arr[i] == formName) return i;
    return STATECNT;
}

AForm*  Intern::makeForm(std::string formName, std::string target)
{
    std::stringstream ss;
    std::cout << checkFormName(formName) << std::endl;
    switch (checkFormName(formName))
    {
        case SCF:
        {
            ss << Intern::scfCnt++;
            return new ShrubberyCreationForm(formName + ss.str(), target);
            break;
        }
        case RRF:
        {
            ss << Intern::rrfCnt++;
            return new RobotomyRequestForm(formName + ss.str(), target);
            break;
        }
        case PPF:
        {
            ss << Intern::ppfCnt++;
            return new PresidentialPardonForm(formName + ss.str(), target);
            break;
        }
        default:
            throw NoForm();
    }
    return 0;
}