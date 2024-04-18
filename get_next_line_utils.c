/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:52:58 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/04/18 14:47:08 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*lstjoin(buffer_lst *lst, int endline)
{
	char	*line;
	int		cont;
	int		cont2;

	line = malloc((ft_buffer_lst_len(lst) + endline + 1) * sizeof(char));
	if (line == 0)
		return (0);
	cont = 0;
	while (lst->next != 0)
	{
		cont2 = 0;
		while (cont2 < lst->lencontent)
			line[cont++] = lst->content[cont2++];
		lst = lst -> next;
	}
	cont2 = 0;
	while (cont2 < endline)
		line[cont++] = lst->content[cont2++];
	line[cont] = '\n';
	line[cont + 1] = '\0';
	return (line);
}

void	ft_lstclear(buffer_lst **lst, void (*del)(void*))
{
	buffer_lst	*next;
	buffer_lst	*point;

	if (lst != 0 && del != 0)
	{
		point = lst[0];
		while (point != 0)
		{
			next = point->next;
			del(point->content);
			free(point);
			point = next;
		}
		lst[0] = 0;
	}
}

int	ft_strnchr(const char *str, int c, int len)
{
	char	cchar;
	int		cont;

	if (str == 0 || len < 0)
		return (-1);
	cont = 0;
	cchar = (char)c;
	while (cont < len)
	{
		if (str[cont] == cchar)
		{
			return (cont);
		}
		cont++;
	}
	return (-1);
}

buffer_lst	*ft_lstlast(buffer_lst *lst)
{
	if (lst == 0)
		return (0);
	while (lst -> next != 0)
	{
		lst = lst -> next;
	}
	return (lst);
}