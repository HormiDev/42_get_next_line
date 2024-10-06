/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 23:37:54 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/10/06 01:56:28 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

t_buffer_lst	*ft_addnew_buffer_lst(t_buffer_lst *lst)
{
	t_buffer_lst	*new;

	new = malloc(sizeof(t_buffer_lst));
	if (new == 0)
		return (0);
	new->content = malloc(sizeof(char) * BUFFER_SIZE);
	if (new->content == 0)
	{
		free(new);
		return (0);
	}
	new->lencontent = 0;
	new->next = 0;
	if (lst == 0)
		return (new);
	ft_buffer_lst_last(lst)->next = new;
	return (lst);
}

char	*ft_buffer_lst_clear(t_buffer_lst **lst)
{
	t_buffer_lst	*next;
	t_buffer_lst	*point;

	if (lst != 0)
	{
		point = lst[0];
		while (point != 0)
		{
			next = point->next;
			if (point->content != 0)
				free(point->content);
			free(point);
			point = next;
		}
		lst[0] = 0;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static t_buffer_lst	*buffer;
	char				*line;
	int					endline;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (0);
	while (buffer == 0 || ft_strnchr_gnl(ft_buffer_lst_last(buffer)->content,
			'\n', ft_buffer_lst_last(buffer)->lencontent) == -1)
	{
		buffer = ft_addnew_buffer_lst(buffer);
		if (buffer == 0)
			return (ft_buffer_lst_clear(&buffer));
		ft_buffer_lst_last(buffer)->lencontent = read(fd,
			ft_buffer_lst_last(buffer)->content, BUFFER_SIZE);
		if (ft_buffer_lst_last(buffer)->lencontent < 0)
			return (ft_buffer_lst_clear(&buffer));
		if (ft_buffer_lst_last(buffer)->lencontent == 0)
		{
			line = lstjoin(buffer, ft_buffer_lst_last(buffer)->lencontent - 1);
			ft_buffer_lst_clear(&buffer);
			return (line);
		}
	}
	endline = ft_strnchr_gnl(ft_buffer_lst_last(
				buffer)->content, '\n', ft_buffer_lst_last(buffer)->lencontent);
	line = lstjoin(buffer, endline);
	buffer = cleanbuffer(buffer, endline);
	return (line);
}
