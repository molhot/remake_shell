#include "../minishell.h"

bool    compare_string(char *s1, char *s2)
{
	size_t	position;

	position = 0;
	while (s1[position] != '\0' && s2[position] != '\0')
	{
		if (s1[position] != s2[position])
			return (false);
		position++;
	}
	if (s1[position] != s2[position])
		return (false);
	return (true);
}