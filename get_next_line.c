/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:50:57 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/03/18 03:27:27 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
char *lstjoin(t_list *lst, char *line)
{
	int	cont;
	int	cont2;

	cont = 0;
	while (lst->next != NULL)
	{
		cont2 = 0;
		while (cont2 < BUFFER_SIZE)
		{
			line[cont] = lst->content[cont2];
			cont++;
			cont2++;
		}
		lst = lst->next;
	}
	cont2 = 0;
	while (lst -> content[cont2] != '\n')
	{
		line[cont] = lst->content[cont2];
		cont++;
		cont2++;
	}
	line[cont] = '\n';
	
	return (line);
}

int	ft_lstsize(t_list *lst)
{
	int	cont;

	if (lst == 0)
		return (0);
	cont = 1;
	while (lst -> next != 0)
	{
		lst = lst -> next;
		cont++;
	}
	return (cont);
}

int	ft_strnchr(const char *str, int c, int len)
{
	char	cchar;
	int 	cont;

	if (str == 0 || len < 0)
		return (-1);
	cont = 0;
	cchar = (char)c;
	while (cont < len)
	{
		if (str[cont] == cchar)
			return (cont);
		cont++;
	}
	return (-1);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == 0)
		return (0);
	while (lst -> next != 0)
	{
		lst = lst -> next;
	}
	return (lst);
}

t_list	*ft_addnewlst(t_list *lst)
{
	t_list	*node;
	
	if (lst == 0)
	{
		lst = malloc(sizeof(t_list));
		if (lst == 0)
			return (0);
		lst -> content = malloc(sizeof(char) * BUFFER_SIZE);
		lst -> next = NULL;
		return (lst);
	}
	node = malloc(sizeof(t_list));
	if (node == 0)
		return (0);
	node -> content = malloc(sizeof(char) * BUFFER_SIZE);
	node -> next = NULL;
	ft_lstlast(lst)->next = node;
	return (lst);
}

char	*get_next_line(int fd)
{
	static t_list	*buffer;
	char			*line;
	
	if (buffer == 0)
		buffer = ft_addnewlst(buffer);
	read(fd, buffer->content, BUFFER_SIZE);
	while (ft_strnchr(ft_lstlast(buffer)->content, '\n', BUFFER_SIZE) == -1)
	{
		ft_addnewlst(buffer);
		read(fd, ft_lstlast(buffer)->content, BUFFER_SIZE);
	}
	line = malloc((ft_lstsize(buffer) - 1) * BUFFER_SIZE + 
	ft_strnchr(ft_lstlast(buffer)->content, '\n', BUFFER_SIZE) + 1);
	line = lstjoin(buffer, line);
	// nuevo nodo con el contenido restante
	// buffer = cleanbuffer(buffer);
	// buffer = nuevo nodo con el contenido restante
	
	//modificar lectura para que lea la cantidad necesaria
	
	return (line);
}

int main()
{
    int fd = open("pr.txt", O_RDONLY);
	char *line;
    if (fd == -1) 
	{
        printf("Error al abrir el archivo.\n");
        return 1;
    }


	line = get_next_line(fd);
	printf("/%s", line);
	free(line);
	line = get_next_line(fd);
	printf("/%s", line);
	free(line);
	line = get_next_line(fd);
	printf("/%s", line);
	free(line);
	line = get_next_line(fd);
	printf("/%s", line);
	free(line);

	
    close(fd);
    return 0;
}