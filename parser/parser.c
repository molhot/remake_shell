#include "../minishell.h"

void cmd_ready(char *s1, char *s2)
{
    size_t  position;

    position = 0;
    while (s2[position] != '\0')
    {
        s1[position] = s2[position];
        position++;
    }
    s1[position] = '\0';
}

static  void    input_cmdinfo(t_samecommand *node)
{
    char    **splited_cmd;
    size_t  ca_position;
    size_t  position;

    splited_cmd = ft_split(node->command, ' ');
    node->cmdinfo.cmd = (char *)malloc(sizeof(char) * ft_strlen(splited_cmd[0]));
    cmd_ready(node->cmdinfo.cmd, splited_cmd[0]);
    if (splited_cmd[1] != NULL)
    {
        position = 1;
        while (splited_cmd[position] != NULL)
            position++;
        node->cmdinfo.command_args = (char **)malloc(sizeof(char *) * position);
        (node->cmdinfo.command_args)[position - 1] = NULL;
        ca_position = 0;
        position = 1;
        while (splited_cmd[position] != NULL)
        {
            (node->cmdinfo.command_args)[ca_position] = (char *)malloc(sizeof(char) * (ft_strlen(splited_cmd[position]) + 1));
            cmd_ready(node->cmdinfo.command_args[ca_position], splited_cmd[position]);
            ca_position++;
            position++;
        }
    }
    else
        node->cmdinfo.command_args = NULL;
}

t_samecommand **parser(t_samecommand **cmd_all)
{
    t_samecommand   *f_node;
    t_samecommand   *node;

    f_node = *cmd_all;
    node = *cmd_all;
    while (node != NULL)
    {
        input_cmdinfo(node);
        node = node->next_command;
    }
    *cmd_all = f_node;
    return (cmd_all);
}