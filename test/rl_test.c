#include <stdio.h> 
#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>
#include <stdlib.h>
 
int main(void)
{
        char *str;
        while(1)
        {
                str = readline("minishell>");
                if (strcmp(str, "exit") == 0)
                {
                        printf("exit ...\n");
                        break;
                }
                add_history(str);
                free(str);
        }
        return(0);
}
