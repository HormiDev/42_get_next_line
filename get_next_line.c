/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:50:57 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/03/14 16:45:34 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*strjoin_lst(t_list *lst, char *end)
{
	char	*str;
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = malloc(((ft_lstsize(lst) - 1) * BUFFER_SIZE + 1) * sizeof(char));
	if (str == 0)
		return (0);
	while (lst != 0)
	{
		tmp = lst -> content;
		while (tmp[i] != '\0')
		{
			str[j] = tmp[i];
			i++;
			j++;
		}
		i = 0;
		lst = lst -> next;
	}
	str[j] = '\0';
	free(end);
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