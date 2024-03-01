#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string NAME;
        const int   GRADE_FOR_SIGN; 
        const int   GRADE_FOR_EXEC; 
        bool isSigned;
    private:
        Form();
        Form(Form const &ref);
        Form&  operator=(Form const &ref);
    public:
        Form(std::string name, int gfs, int gfe);
        ~Form();
    public:
        std::string const & getName() const;
        int const & getGradeForSign() const;
        int const & getGradeForExec() const;
        bool const & getIsSigned() const;
        void beSigned(Bureaucrat const & executor);
    public:
        class GradeTooHighException : public std::exception
        {
            virtual const char* what() const _NOEXCEPT
            {
                return "Grade too high";
            }
        };
        class GradeTooLowException : public std::exception 
        {
            virtual const char* what() const _NOEXCEPT
            {
                return "Grade too Low";
            }
        };
};

std::ostream    &operator<<(std::ostream &out, const Form &form);

#endif