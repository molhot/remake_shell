#include "minishell.h"

int main()
{
    char            *line;
    t_samecommand   **splited_line;
    t_samecommand   **read_cmdinfo;
    t_samecommand   *node;
    size_t          position;
    int i = 0;

    while (1)
    {
        line = readline("> ");
        splited_line = torkanizer(line);
        read_cmdinfo = parser(splited_line);
        node = *read_cmdinfo;
        while (node != NULL)
        {
            printf("cmd is >>%s\n", node->cmdinfo.cmd);
            while (node->cmdinfo.command_args != NULL && node->cmdinfo.command_args[i] != NULL)
            {
                printf("cmd args is >>%s\n", node->cmdinfo.command_args[i]);
                i++;
            }
            node = node->next_command;
        }
        i = 0;
        free(line);
    }
}