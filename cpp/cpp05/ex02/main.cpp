#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void ) 
{
    try {
		Bureaucrat	king("king", 1);
		Bureaucrat	test("test", 137);
		AForm *form1 = new ShrubberyCreationForm("s_form", "minseunk");
		AForm *form2 = new RobotomyRequestForm("s_form", "minseunk");
		AForm *form3 = new PresidentialPardonForm("s_form", "minseunk");
		test.signForm(form1);
		king.signForm(form1);
		test.executeForm(*form1);
		king.signForm(form2);
		king.executeForm(*form2);
		king.signForm(form3);
		king.executeForm(*form3);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

}