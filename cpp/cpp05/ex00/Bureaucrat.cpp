#include "Bureaucrat.hpp"

std::ostream    &operator<<(std::ostream &out, const Bureaucrat &br)
{
    out << br.getName() << " bureaucrat grade "  << br.getGrade();
    return (out);
}

Bureaucrat::Bureaucrat(){}
Bureaucrat::Bureaucrat(Bureaucrat const &ref){(void)ref;}
Bureaucrat&  Bureaucrat::operator=(Bureaucrat const &ref){(void)ref; return *this;}
Bureaucrat::~Bureaucrat(){}

std::string const & Bureaucrat::getName() const
{
    return this->NAME;    
}
int const & Bureaucrat::getGrade() const
{
    return this->grade;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : NAME(name), grade(grade)
{
    if (grade > 150)
        throw GradeTooLowException();
    if (grade < 1)
        throw GradeTooHighException();
}
void Bureaucrat::upGrade()
{
    if (this->grade == 1)
        throw GradeTooHighException();
    this->grade -= 1;
}
void Bureaucrat::downGrade()
{
    if (this->grade == 150)
        throw GradeTooLowException();
    this->grade += 1;
}
