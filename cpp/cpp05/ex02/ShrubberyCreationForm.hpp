#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>
# include <string>
# define GFS 145
# define GFE 137

class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;
    private:
        ShrubberyCreationForm();
        ShrubberyCreationForm(ShrubberyCreationForm const &ref);
        ShrubberyCreationForm&  operator=(ShrubberyCreationForm const &ref);
    public:
        ShrubberyCreationForm(std::string name, std::string target);
        ~ShrubberyCreationForm();
        void execute(Bureaucrat const & executor) const;
};

#endif