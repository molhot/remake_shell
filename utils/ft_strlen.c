#include "../minishell.h"

size_t  ft_strlen(char *string)
{
    size_t  position;

    position = 0;
    while (string[position] != '\0')
        position++;
    return (position);
}