/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:50:57 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/10/02 22:23:05 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
/*
void	ft_printlst(t_buffer_lst *lst)
{
    t_buffer_lst	*tmp = lst;

    if (tmp == 0){
        write(1, "\n---------\nbuffer (null)\n---------\n", 35);
        return;
    }
	write(1, "\n---------\n", 11);
    while (tmp != NULL) {
        write(1, tmp->content, tmp->lencontent);
		printf(" --> lencontent: %d\n", tmp->lencontent);
        tmp = tmp->next;
    }
	write(1, "---------\n", 10);
}
*/

int	ft_buffer_lst_len(t_buffer_lst *lst)
{
	int	len;

	if (lst == 0)
		return (0);
	len = 0;
	while (lst->next != 0)
	{
		len = len + lst->lencontent;
		lst = lst -> next;
	}
	return (len);
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

t_buffer_lst	*ft_addnewlst(t_buffer_lst *lst)
{
	t_buffer_lst	*node;

	node = malloc(sizeof(t_buffer_lst));
	if (node == 0)
		return (0);
	node->content = malloc(sizeof(char) * BUFFER_SIZE);
	if (node->content == 0)
	{
		ft_lstclear(&lst, free);
		ft_lstclear(&node, free);
		return (0);
	}
	node->lencontent = BUFFER_SIZE;
	node->next = NULL;
	if (lst == 0)
		return (node);
	ft_lstlast(lst)->next = node;
	return (lst);
}

char	*get_next_line_2(int fd, t_buffer_lst **buffer)
{
	char			*line;
	int				endline;
	t_buffer_lst	*temp;

	while (ft_strnchr(ft_lstlast(*buffer)->content, '\n',
			ft_lstlast(*buffer)->lencontent) == -1)
	{
		*buffer = ft_addnewlst(*buffer);
		temp = ft_lstlast(*buffer);
		temp->lencontent = read(fd, temp->content, BUFFER_SIZE);
		if (ft_lstlast(*buffer)->lencontent <= 0)
		{
			line = lstjoin(*buffer, ft_lstlast(*buffer)->lencontent - 1);
			ft_lstclear(buffer, free);
			return (line);
		}
	}
	endline = ft_strnchr(ft_lstlast(
				*buffer)->content, '\n', ft_lstlast(*buffer)->lencontent);
	line = lstjoin(*buffer, endline);
	*buffer = cleanbuffer(*buffer, endline);
	return (line);
}

char	*get_next_line(int fd)
{
	static t_buffer_lst	*buffer[1024];
	char				*line;

	if (fd < 0 || fd > 1024)
		return (0);
	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		ft_lstclear(&buffer[fd], free);
		return (0);
	}
	if (buffer[fd] == 0)
	{
		buffer[fd] = ft_addnewlst(buffer[fd]);
		buffer[fd]->lencontent = read(fd, buffer[fd]->content, BUFFER_SIZE);
		if (buffer[fd]->lencontent <= 0)
		{
			ft_lstclear(&buffer[fd], free);
			return (0);
		}
	}
	line = get_next_line_2(fd, &buffer[fd]);
	if (line == 0)
		ft_lstclear(&buffer[fd], free);
	return (line);
}
