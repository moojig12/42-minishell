/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:17:51 by root              #+#    #+#             */
/*   Updated: 2024/04/24 11:46:11 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*first_pass(t_token **tokens, char *input, int word, int *i)
{
	char	*res;
	char	*temp;

	res = NULL;
	res = (char *)malloc(count_size(&input[*i], &i) * sizeof(char));
	while (input[*i])
	{
		if (is_quote(input[*i]))
		{
			temp = ft_strjoin(res, quote_to_str(input, i));
		}
		else
		{
			// convert to str normally
			i++;
		}
	}
	return (res);
}

void	lexical_analysis(t_token **tokens, char *input, )
{
	int		i;
	int		word;

	i = 0;
	word = 1;
	while (input[i])
	{
		if (!ft_isspace(input[i]))
		{
			convert_to_token(tokens, first_pass(tokens, input, word, &i), word);
			word++;
		}
		i++;
	}
}