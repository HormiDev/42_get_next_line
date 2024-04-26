/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:50:57 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/04/26 21:46:44 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
void	ft_printlst(buffer_lst *lst)
{
    buffer_lst	*tmp = lst;

    if (tmp == NULL) {
        write(1, "La lista está vacía.\n", 20);
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

int	ft_buffer_lst_len(buffer_lst *lst)
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

buffer_lst	*cleanbuffer(buffer_lst *lst, int endline)
{
	int			cont;
	buffer_lst	*next;
	char		*new;

	while (lst->next != 0)
	{
		next = lst->next;
		free(lst->content);
		free(lst);
		lst = next;
	}
	if (lst->lencontent - endline < 0)
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

buffer_lst	*ft_addnewlst(buffer_lst *lst)
{
	buffer_lst	*node;
	
	node = malloc(sizeof(buffer_lst));
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

char	*get_next_line(int fd)
{
	static buffer_lst	*buffer;
	char				*line;
	int					endline;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (0);
	if (buffer == 0)
	{
		buffer = ft_addnewlst(buffer);
		if (read(fd, buffer->content, BUFFER_SIZE) == 0)
		{
			ft_lstclear(&buffer, free);
			return (0);
		}
	}
	while (ft_strnchr(ft_lstlast(buffer)->content, '\n', BUFFER_SIZE) == -1)
	{
		buffer = ft_addnewlst(buffer);
		ft_lstlast(buffer)->lencontent = read(fd, ft_lstlast(buffer)->content, BUFFER_SIZE);
		if (ft_lstlast(buffer)->lencontent < BUFFER_SIZE)
		{
			line = lstjoin(buffer, ft_lstlast(buffer)->lencontent);
			ft_lstclear(&buffer, free);
			return (line);
		}
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
/*
int main()
{
    buffer_lst *lst = malloc(sizeof(buffer_lst));
	buffer_lst *temp = lst;

	lst->content = malloc(sizeof(char) * BUFFER_SIZE);
	lst->lencontent = BUFFER_SIZE;
	lst->next = NULL;

	int fd = open("pr.txt", O_RDONLY);
	int cont = 0;
	int cont2 = 0;

	while (cont < 9)
	{
		read(fd, ft_lstlast(lst)->content, BUFFER_SIZE);
		printf("%d\n", ft_strnchr(ft_lstlast(lst)->content, '\n', BUFFER_SIZE));
		ft_addnewlst(lst);
		cont++;
	}
	read(fd, ft_lstlast(lst)->content, BUFFER_SIZE);
	cont = 0;
	temp = lst;
	while (cont < 10)
	{
		cont2 = 0;
		while (cont2 < BUFFER_SIZE)
		{
			write(1, &temp->content[cont2], 1);
			cont2++;
		}
		write(1, "\n", 1);
		temp = temp->next;
		cont++;
	}
	printf("%d\n", ft_lstsize(lst));
	char *line = lstjoin(lst, ft_strnchr(ft_lstlast(lst)->content, '\n', BUFFER_SIZE));
	printf("%s", line);
	lst = cleanbuffer(lst, ft_strnchr(ft_lstlast(lst)->content, '\n', BUFFER_SIZE));
	printf("%d\n", lst->lencontent);
	cont = 0;
	while (cont < lst->lencontent)
	{
		write(1, &lst->content[cont], 1);
		cont++;
	}
	ft_lstclear(&lst, free);
	close(fd);
	
	//prueba de ft_strnchr
	printf("\n\nprueba de ft_strnchr\n");
	printf("%d\n", ft_strnchr("hola mundo \nque", '\n', 11));

	//prueba de get_next_line
	printf("\n\nprueba de get_next_line\n");
	fd = open("pr.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line != 0)
	{
		printf("\n-%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return 0;
}*/
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

/*
buffer_lst	*ft_create_newlst(void)
{
	buffer_lst	*node;

	node = malloc(sizeof(buffer_lst));
	if (node == 0)
		return (0);
	node->content = malloc(sizeof(char) * BUFFER_SIZE);
	if (node->content == 0)
	{
		free(node);
		return (0);
	}
	node->lencontent = BUFFER_SIZE;
	node->next = 0;
	return (node);
}
*/