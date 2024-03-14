/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:50:57 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/03/14 18:55:38 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*strjoin_lst(t_list *lst, char *end)
{
	char	*str;
	int		i;
	int		j;

	j = 0;
	str = malloc(BUFFER_SIZE * (ft_lstsize(lst) - 1) 
	+ (end - ft_lstlast(lst)->content) * sizeof(char));
	if (str == 0)
		return (0);
	while (lst != 0)
	{
		i = 0;
		while (lst->content + i != end && i < BUFFER_SIZE)
		{
			str[j] = (char *)lst->content[i];
			i++;
			j++;
		}
		if (lst->content + i == end)
			break ;
		lst = lst->next;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static t_list *buffer;
	char	*end;
	
	if (buffer == 0)
	{
		buffer = ft_lstnew(malloc(BUFFER_SIZE * sizeof(char)));
		read(fd, buffer->content, BUFFER_SIZE);
	}
	while (end = ft_strchr(ft_lstlast(buffer)->content, '\n') == 0)
	{
		ft_lstlast(buffer)->next = ft_lstnew(malloc(BUFFER_SIZE * sizeof(char)));
		read(fd, ft_lstlast(buffer)->content, BUFFER_SIZE);
	}
	end = strjoin_lst(buffer, end);
	return(end);
}

int main()
{
    int fd = open("pr.txt", O_RDONLY);
    if (fd == -1) 
	{
        printf("Error al abrir el archivo.\n");
        return 1;
    }
    close(fd);
    return 0;
}