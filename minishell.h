#ifndef minishell_H
# define minishell_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct command_breakdown
{
	char	*cmd;
	char	**command_args;
}t_cmdinfo;

typedef struct same_command
{
    struct same_command			*next_command;
    char						**result_command;
	char						*command;
	struct command_breakdown	cmdinfo;
}t_samecommand;

char			**ft_split(char const *s, char c);
bool			compare_string(char *s1, char *s2);
t_samecommand	**torkanizer(char *input);
t_samecommand	**parser(t_samecommand **cmd_all);
size_t 			ft_strlen(char *string);

#endif