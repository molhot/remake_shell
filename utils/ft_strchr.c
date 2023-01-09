#include "../minishell.h"

bool    ft_strchr(char *s1, char sub)
{
    size_t  position;

    position = 0;
    while (s1[position] != '\0')
    {
        if (s1[position] == sub)
            return (true);
        position++;
    }
    return (false);
}