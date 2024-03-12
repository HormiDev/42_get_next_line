/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:52:58 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/03/12 02:42:30 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == 0)
		return (0);
	node -> content = content;
	node -> next = NULL;
	return (node);
}

size_t	ft_strlen(const char *str)
{
	size_t	cont;

	cont = 0;
	while (str[cont] != 0)
	{
		cont++;
	}
	return (cont);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	cont;

	cont = 0;
	str = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (str == 0)
		return (0);
	while (cont < ft_strlen(s1))
	{
		str[cont] = s1[cont];
		cont++;
	}
	str[cont] = 0;
	return (str);
}