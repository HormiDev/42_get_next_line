/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 00:41:33 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/10/06 01:22:48 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strnchr_gnl(const char *str, int c, int len)
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

t_buffer_lst	*ft_buffer_lst_last(t_buffer_lst *lst)
{
	if (lst == 0)
		return (0);
	while (lst->next != 0)
		lst = lst->next;
	return (lst);
}

t_buffer_lst	*cleanbuffer(t_buffer_lst *lst, int endline)
{
	int				cont;
	t_buffer_lst	*next;
	char			*new;

	while (lst->next != 0)
	{
		next = lst->next;
		free(lst->content);
		free(lst);
		lst = next;
	}
	if (lst->lencontent - endline -1 <= 0)
	{
		free(lst->content);
		free(lst);
		return (0);
	}
	new = malloc(sizeof(char) * (lst->lencontent - endline - 1));
	cont = -1;
	while (cont++ < lst->lencontent - endline - 2)
		new[cont] = lst->content[endline + cont + 1];
	free(lst->content);
	lst->content = new;
	lst->lencontent = lst->lencontent - endline - 1;
	return (lst);
}

char	*lstjoin(t_buffer_lst *lst, int endline)
{
	char	*line;
	int		cont;
	int		cont2;

	if (lst == ft_buffer_lst_last(lst) && endline == -1)
		return (0);
	line = malloc((ft_buffer_lst_len(lst) + endline + 2) * sizeof(char));
	if (line == 0)
		return (ft_buffer_lst_clear(&lst));
	cont = 0;
	while (lst->next != 0)
	{
		cont2 = 0;
		while (cont2 < lst->lencontent)
			line[cont++] = lst->content[cont2++];
		lst = lst -> next;
	}
	cont2 = 0;
	while (cont2 <= endline)
		line[cont++] = lst->content[cont2++];
	line[cont] = '\0';
	return (line);
}
