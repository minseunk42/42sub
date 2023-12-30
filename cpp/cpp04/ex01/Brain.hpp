#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
    private:
        std::string *ideas;
        int         idx;
        const static int    bsize = 100;
    public:
        Brain();
        virtual ~Brain();
        Brain(Brain const &ref);
        Brain&      operator=(Brain const &ref);
        std::string getIdeas() const;
        void        addIdeas(std::string str);
};

#endif