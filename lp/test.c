#include "lexer.h"

int main(int ac, char **av)
{
    t_token *tokens;

    if (ac < 2)
        return (-1);
    lexer(av[1], &tokens);
}