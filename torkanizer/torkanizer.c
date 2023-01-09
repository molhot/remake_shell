#include "../minishell.h"

t_samecommand **torkanizer(char *input)
{
    char    		**splited_line;
	size_t			count_command;
	size_t			position;
	t_samecommand	**allcmd;
	t_samecommand	*node;

	splited_line = ft_split(input, '|');
	count_command = 0;
	while (splited_line[count_command] != NULL)
		count_command++;
	allcmd = (t_samecommand **)malloc(sizeof(t_samecommand *));
	*allcmd = (t_samecommand *)malloc(sizeof(t_samecommand));
	(*allcmd)->command = splited_line[0];
	position = 1;
	node = *allcmd;
	while (position != count_command)
	{
		node->next_command = (t_samecommand *)malloc(sizeof(t_samecommand));
		node = node->next_command;
		node->command = splited_line[position];
		position++;
	}
	node->next_command = NULL;
	return (allcmd);
}