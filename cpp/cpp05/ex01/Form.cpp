#include "Form.hpp"

std::ostream    &operator<<(std::ostream &out, const Form &form)
{
    out << "NAME : " << form.getName() << std::endl
    << "GRADE_FOR_SIGN : " << form.getGradeForSign() << std::endl
    << "GRADE_FOR_EXEC : " << form.getGradeForExec() << std::endl
    << "IsSigned : " << form.getIsSigned();
    return (out);
}

// for OCF
Form::Form() : NAME(""), GRADE_FOR_SIGN(1), GRADE_FOR_EXEC(1){}
Form::Form(Form const &ref) : NAME(""), GRADE_FOR_SIGN(1), GRADE_FOR_EXEC(1){(void)ref;}
Form&  Form::operator=(Form const &ref) {(void)ref; return *this;}
Form::~Form(){}

// getters
std::string const & Form::getName() const{return this->NAME;}
int const & Form::getGradeForSign() const{return this->GRADE_FOR_SIGN;}
int const & Form::getGradeForExec() const{return this->GRADE_FOR_EXEC;}
bool const & Form::getIsSigned() const{return this->isSigned;}

Form::Form(std::string name, int gfs, int gfe) : NAME(name), GRADE_FOR_SIGN(gfs), GRADE_FOR_EXEC(gfe), isSigned(false)
{
    if (gfs > 150 || gfe > 150)
        throw GradeTooLowException();
    if (gfs < 1 || gfe < 1)
        throw GradeTooHighException();
}

void Form::beSigned(Bureaucrat const & bureaucrat)
{
    if (bureaucrat.getGrade() <= this->GRADE_FOR_SIGN)
        this->isSigned = true;
    else
        throw Form::GradeTooLowException();
}
