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

static  size_t  count_args(char **cmdline, size_t not_optioned)
{
    size_t  position;

    position = 0;
    while (cmdline[position] != NULL)
        position++;
    return (position - not_optioned);
}

static  size_t  count_option(char **cmdline)
{
    size_t  position;
    size_t  option_num;

    position = 0;
    option_num = 0;
    while (cmdline[position] != NULL)
    {
        if (ft_strchr(cmdline[position], '-') == true)
            option_num++;
        position++;
    }
    return (option_num);
}

static  void    input_cmdinfo(t_samecommand *node)
{
    char    **splited_cmd;
    size_t  ca_position;
    size_t  position;
    size_t  option_num;
    size_t  option_position;
    size_t  args_num;

    splited_cmd = ft_split(node->command, ' ');
    node->cmdinfo.cmd = (char *)malloc(sizeof(char) * ft_strlen(splited_cmd[0]));
    cmd_ready(node->cmdinfo.cmd, splited_cmd[0]);
    if (splited_cmd[1] != NULL)
    {
        position = 1;
        option_position = 0;
        option_num = count_option(splited_cmd);
        if (option_num != 0)
        {
            node->cmdinfo.option = (char **)malloc(sizeof(char *) * (option_num + 1));
            node->cmdinfo.option[option_num] = NULL;
            option_num = 0;
            while (ft_strchr(splited_cmd[position], '-') == true)
            {
                node->cmdinfo.option[option_num] = (char *)malloc(sizeof(char) * ft_strlen(splited_cmd[position]));
                cmd_ready(node->cmdinfo.option[option_num], splited_cmd[position]);
                option_num++;
                position++;
            }
        }
        else
            node->cmdinfo.option = NULL;
        args_num = count_args(splited_cmd, position);
        node->cmdinfo.command_args = (char **)malloc(sizeof(char *) * (args_num + 1));
        (node->cmdinfo.command_args)[args_num] = NULL;
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