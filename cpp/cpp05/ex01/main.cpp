#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void ) 
{
    try {
		Bureaucrat	slave("slave", 150);
		Bureaucrat	king("king", 1);
		Form *form = new Form("test_form", 2, 2);
		std::cout << *form << std::endl;
		king.signForm(form);
		std::cout << *form << std::endl;
		slave.signForm(form);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

}
