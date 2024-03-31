/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:50:57 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/03/30 16:39:19 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

t_list	*cleanbuffer(t_list *lst, int endline)
{
	int		cont;
	t_list	*next;
	char	*new;

	while (lst->next != 0)
	{
		next = lst->next;
		free(lst->content);
		free(lst);
		lst = next;
	}
	if(lst->lencontent - endline < 0)
	{
		free(lst->content);
		free(lst);
		return (0);
	}
	new = malloc(sizeof(char) * (lst->lencontent - endline));
	cont = -1;
	while (cont++ < lst->lencontent - endline)
		new[cont] = lst->content[endline + cont];
	free(lst->content);
	lst->content = new;
	lst->lencontent = lst->lencontent - endline;
	return (lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next;
	t_list	*point;

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

char	*lstjoin(t_list *lst, int endline)
{
	char	*line;
	int		cont;
	int		cont2;

	line = malloc((ft_lstsize(lst) * BUFFER_SIZE + endline + 1) * sizeof(char));
	if (line == 0)
		return (0);
	cont = 0;
	while (lst->next != 0)
	{
		cont2 = 0;
		while (cont2 < BUFFER_SIZE)
			line[cont++] = lst->content[cont2++];
		lst = lst -> next;
	}
	cont2 = 0;
	while (lst->content[cont2] != '\n')
		line[cont++] = lst->content[cont2++];
	line[cont] = '\n';
	line[cont + 1] = '\0';
	return (line);
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

	node = malloc(sizeof(t_list));
	if (node == 0)
		return (0);
	node->content = malloc(sizeof(char) * BUFFER_SIZE);
	if (node->content == 0)
	{
		ft_lstclear(&lst, free);
		return (0);
	}
	node->lencontent = BUFFER_SIZE;
	node->next = NULL;
	if (lst == 0)
		return (node);
	ft_lstlast(lst)->next = node;
	return (lst);
}

char	*get_next_line(int fd)
{
	static t_list	*buffer;
	char			*line;
	int				endline;

	if (buffer == 0)
	{
		buffer = ft_addnewlst(buffer);
		read(fd, buffer->content, BUFFER_SIZE);
	}
	while (ft_strnchr(ft_lstlast(buffer)->content, '\n', BUFFER_SIZE) == -1)
	{
		buffer = ft_addnewlst(buffer);
		if (buffer == 0)
			return (0);
		read(fd, buffer->content, BUFFER_SIZE);
	}
	endline = ft_strnchr(ft_lstlast(buffer)->content, '\n', BUFFER_SIZE);
	line = lstjoin(buffer, endline);
	if (line == 0)
		return (0);
	buffer = cleanbuffer(buffer, endline);
	if (buffer == 0)
		return (0);
	return (line);
}

int main()
{
    int fd = open("pr2.txt", O_RDONLY);
	char *line;
    if (fd == -1)
	{
        printf("Error al abrir el archivo.\n");
        return 1;
    }


	
	line = get_next_line(fd);
	printf("/%s\n", line);
	free(line);
	line = get_next_line(fd);
	printf("/%s\n", line);
	free(line);
	/*line = get_next_line(fd);
	while (line != 0)
	{
		free(line);
		line = get_next_line(fd);
		printf("/%s\n", line);
	}
    close(fd);
	free(line);
    return 0;*/
}
/*
void print_list(t_list *lst) {
    t_list *current = lst;
    int count = 1;

    while (current != NULL) {
        printf("Nodo %d: contenido = %s, longitud = %d\n", count, (char *)current->content, current->lencontent);
        current = current->next;
        count++;
    }
}
*/
/*
int main() {
    t_list *lst = NULL;

    lst = ft_addnewlst(lst);
    if (lst != NULL) {
        strncpy(lst->content, "Nodo 1", BUFFER_SIZE);
    }

    lst = ft_addnewlst(lst);
    if (lst != NULL && lst->next != NULL) {
        strncpy(lst->next->content, "Nodo 2", BUFFER_SIZE);
    }

    lst = ft_addnewlst(lst);
    if (lst != NULL && lst->next != NULL && lst->next->next != NULL) {
        strncpy(lst->next->next->content, "Nodo 3", BUFFER_SIZE);
    }

    print_list(lst);

    // Aquí deberías liberar la memoria de la lista
    // ft_lstclear(&lst, free);

    return 0;
}
*/
/*


char	*lstjoin(t_list *lst, char *line)
{
	int cont;
	int cont2;

	cont = 0;
	while (lst->next != 0)
	{
		cont2 = 0;
		while (cont2 < BUFFER_SIZE)
		{
			line[cont] = lst->content[cont2];
			cont++;
		}
		lst = lst -> next;
	}
	cont2 = 0;
	while (lst->content[cont2] != '\n')
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

t_list	*ft_addlstnew(t_list *lst)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == 0)
		return (0);
	node -> content = malloc(sizeof(char) * BUFFER_SIZE);
	node -> next = NULL;
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	lst->next = node;
	return (node);
}

char	*get_next_line(int fd)
{
	static t_list	*buffer;
	char			*line;
	if (buffer == 0)
		buffer = ft_addlstnew(buffer);
	read(fd, buffer->content, BUFFER_SIZE);
	while (ft_strnchr(buffer->content, '\n', BUFFER_SIZE) == -1)
	{
		buffer = ft_addlstnew(buffer);
		read(fd, buffer->content, BUFFER_SIZE);
	}
	line = malloc(((ft_lstsize(buffer) - 1) * BUFFER_SIZE + ft_strnchr(buffer->content, '\n', BUFFER_SIZE) + 1) * sizeof(char));
	if (line == 0)
		return (0);
	
	// nuevo nodo con el contenido restante
	// buffer = cleanbuffer(buffer);
	// buffer = nuevo nodo con el contenido restante
	
	//modificar lectura para que lea la cantidad necesaria
	
	return (line);
}
*/