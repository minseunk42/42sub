#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat
{
    private:
        const std::string NAME;
        int grade;
    private:
        Bureaucrat();
        Bureaucrat(Bureaucrat const &ref);
        Bureaucrat&  operator=(Bureaucrat const &ref);
    public:
        Bureaucrat(std::string name, int grade);
        ~Bureaucrat();
    public:
        std::string const & getName() const;
        int const & getGrade() const;
        void upGrade();
        void downGrade();
    public:
        class GradeTooHighException : public std::exception
        {
            virtual const char* what() const throw()
            {
                return "Grade too high";
            }
        };
        class GradeTooLowException : public std::exception 
        {
            virtual const char* what() const throw()
            {
                return "Grade too Low";
            }
        };
};

std::ostream    &operator<<(std::ostream &out, const Bureaucrat &br);

#endif