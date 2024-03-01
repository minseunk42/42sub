#include "Bureaucrat.hpp"

int main( void ) 
{
    try 
	{
		Bureaucrat	slave("slave", 150);
		Bureaucrat	king("king", 1);

		// slave.downGrade();
		slave.upGrade();
		std::cout << slave << std::endl;
		// king.upGrade();
		king.downGrade();
		std::cout << king << std::endl;
	}
	catch (std::exception &e) 
	{
		std::cout << e.what() << std::endl;
	}

}