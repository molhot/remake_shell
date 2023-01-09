#include "minishell.h"

int main()
{
    char            *line;
    t_samecommand   **splited_line;
    t_samecommand   **read_cmdinfo;
    t_samecommand   *node;
    size_t          position;
    int i = 0;
    int j = 0;

    while (1)
    {
        line = readline("> ");
        if (ft_strlen(line) == 0)
        {
            free(line);
            break;
        }
        splited_line = torkanizer(line);
        read_cmdinfo = parser(splited_line);
        node = *read_cmdinfo;
        while (node != NULL)
        {
            printf("cmd is >>%s\n", node->cmdinfo.cmd);
            if (node->cmdinfo.command_args != NULL)
            {
                while (node->cmdinfo.command_args[i] != NULL)
                {
                    printf("cmd args is >>%s\n", node->cmdinfo.command_args[i]);
                    i++;
                }
            }
            if (node->cmdinfo.option != NULL)
            {
                while (node->cmdinfo.option[j] != NULL)
                {
                    printf("option is >>%s\n", node->cmdinfo.option[j]);
                    j++;
                }
            }
            node = node->next_command;
        }
        i = 0;
        free(line);
    }
}