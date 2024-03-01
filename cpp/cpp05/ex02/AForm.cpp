#include "AForm.hpp"

std::ostream    &operator<<(std::ostream &out, const AForm &form)
{
    out << "NAME : " << form.getName() << std::endl
    << "GRADE_FOR_SIGN : " << form.getGradeForSign() << std::endl
    << "GRADE_FOR_EXEC : " << form.getGradeForExec() << std::endl
    << "IsSigned : " << form.getIsSigned();
    return (out);
}

// for OCF
AForm::AForm() : NAME(""), GRADE_FOR_SIGN(1), GRADE_FOR_EXEC(1){}
AForm::AForm(AForm const &ref) : NAME(""), GRADE_FOR_SIGN(1), GRADE_FOR_EXEC(1){(void)ref;}
AForm&  AForm::operator=(AForm const &ref) {(void)ref; return *this;}
AForm::~AForm(){}

// getters
std::string const & AForm::getName() const{return this->NAME;}
int const & AForm::getGradeForSign() const{return this->GRADE_FOR_SIGN;}
int const & AForm::getGradeForExec() const{return this->GRADE_FOR_EXEC;}
bool const & AForm::getIsSigned() const{return this->isSigned;}

AForm::AForm(std::string name, int gfs, int gfe) : NAME(name), GRADE_FOR_SIGN(gfs), GRADE_FOR_EXEC(gfe), isSigned(false)
{
    if (gfs > 150 || gfe > 150)
        throw GradeTooLowException();
    if (gfs < 1 || gfe < 1)
        throw GradeTooHighException();
}

void AForm::beSigned(Bureaucrat const & executor)
{
    if (executor.getGrade() <= this->GRADE_FOR_SIGN)
        this->isSigned = true;
    else
        throw AForm::GradeTooLowException();
}

void    AForm::checkPermit(Bureaucrat const & executor) const
{
    if (!this->isSigned)
        throw AForm::FormIsNotSigned();
    if (executor.getGrade() > this->GRADE_FOR_EXEC)
        throw AForm::GradeTooLowException();
}
