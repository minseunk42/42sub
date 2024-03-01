#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string NAME;
        const int   GRADE_FOR_SIGN; 
        const int   GRADE_FOR_EXEC; 
        bool isSigned;
    private:
        AForm();
        AForm(AForm const &ref);
        AForm&  operator=(AForm const &ref);
    protected:
        void checkPermit(Bureaucrat const & executor) const;
    public:
        AForm(std::string name, int gfs, int gfe);
        ~AForm();
    public:
        std::string const & getName() const;
        int const & getGradeForSign() const;
        int const & getGradeForExec() const;
        bool const & getIsSigned() const;
        void beSigned(Bureaucrat const & executor);
        virtual void execute(Bureaucrat const & executor) const = 0;
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
        class FormIsNotSigned : public std::exception 
        {
            virtual const char* what() const _NOEXCEPT
            {
                return "Form is not signed";
            }
        };
};

std::ostream    &operator<<(std::ostream &out, const AForm &AForm);

#endif