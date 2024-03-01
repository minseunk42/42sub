#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main( void ) 
{
    try {
		Bureaucrat	king("king", 1);
		AForm *form = new ShrubberyCreationForm("s_form", "minseunk");
		king.signForm(form);
		king.executeForm(*form);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

}