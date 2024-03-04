#include "ShrubberyCreationForm.hpp"

// for OCF
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("", 1, 1), target("target"){}
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &ref) : AForm("", 1, 1), target("target"){(void)ref;}
ShrubberyCreationForm&  ShrubberyCreationForm::operator=(ShrubberyCreationForm const &ref) {(void)ref; return *this;}
ShrubberyCreationForm::~ShrubberyCreationForm(){}

// constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string name, std::string target) : AForm(name, 145, 137), target(target){}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    checkPermit(executor);
    std::string out_name;
    out_name += this->target;
    out_name += "_shrubbery";
    std::ofstream fout(out_name.c_str(), std::ios_base::out);
    if (!fout)
        return (fout.close());
    std::ifstream fin("treesample", std::ios_base::in);
    if (!fin)
        return (fout.close(), fin.close());
    std::string line;
    while (std::getline(fin, line))
        fout << line << std::endl;
    fout.close();
    fin.close();
}