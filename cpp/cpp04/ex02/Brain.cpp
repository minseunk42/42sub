#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "brain 기본생성자 호출" << std::endl;
    this->ideas = new std::string[BSIZE];
    for (int i = 0; i < BSIZE; i++)
        ideas[i] = " ";
    idx = 0;
}

Brain::~Brain()
{
    std::cout << "brain 소멸자 호출" << std::endl;
    delete[] this->ideas;
}

Brain::Brain(Brain const &ref)
{
    std::cout << "brain 복사생성자 호출" << std::endl;
    this->ideas = new std::string[BSIZE];
    for (int i = 0; i < BSIZE; i++)
        this->ideas[i] = ref.ideas[i];
    idx = 0;
}

Brain&      Brain::operator=(Brain const &ref)
{
    std::cout << "brain 복사대입 생성자 호출" << std::endl;
    if (this == &ref)
        return *this;
    delete[] this->ideas;
    this->ideas = new std::string[BSIZE];
    for (int i = 0; i < BSIZE; i++)
        this->ideas[i] = ref.ideas[i];
    return *this;
}

std::string Brain::getIdeas() const
{
    std::string out;
    for (int i = 0; i < BSIZE; i++)
    {
        if (this->ideas[i] != " ")
        {
            out += this->ideas[i];
            out += "\n";
        }
    }
    return out;
}

void         Brain::addIdeas(std::string str)
{
    this->ideas[idx++] = str;
    if (idx == BSIZE)
        idx = 0;
}
