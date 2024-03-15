#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main( void ) 
{
    try {
		Bureaucrat	king("king", 1);
		Intern someRandomIntern;
		Intern someRandomIntern1;
		AForm* rrf;
		AForm* rrf1;
		AForm* rrf2;
		AForm* rrf3;
		//AForm* rrf4;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		rrf1 = someRandomIntern.makeForm("robotomy request", "Bender");
		rrf2 = someRandomIntern.makeForm("robotomy request", "Bender");
		rrf3 = someRandomIntern.makeForm("robotomy request", "Bender");
		//rrf4 = someRandomIntern.makeForm("", "Bender");
		king.signForm(rrf3);
		king.executeForm(*rrf3);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

}