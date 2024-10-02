/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:32:59 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/09/21 18:19:39 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "get_next_line.h"

int	ft_lstsize(t_buffer_lst *lst)
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

int main()
{
	int		cont;
	int		cont2;
	int		fd;
	char	*line;

	cont = 1;
	printf("\n\nprueba de get_next_line\n");
	fd = open("Files/pr4.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line != 0)
	{
		printf("\n :linea %d: ", cont);
		cont2 = 0;
		while (line[cont2] != '\0')
		{
			if (line[cont2] == '\n')
				write(1, "\\n", 2);
			else
				write(1, &line[cont2], 1);
			cont2++;
		}
		free(line);
		line = get_next_line(fd);
		cont++;
	}
	printf("\nlinea %d: %s fin", cont, line);
	free(line);
	close(fd);
	return 0;
}
*/
/*
int main()
{
    t_buffer_lst *lst = malloc(sizeof(t_buffer_lst));
	t_buffer_lst *temp = lst;

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
	char *line = lstjoin(lst, ft_strnchr
		(ft_lstlast(lst)->content, '\n', BUFFER_SIZE));
	printf("%s", line);
	lst = cleanbuffer(lst, ft_strnchr
		(ft_lstlast(lst)->content, '\n', BUFFER_SIZE));
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
	cont = 1;
	printf("\n\nprueba de get_next_line\n");
	fd = open("quijote.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line != 0)
	{
		printf("\n :linea %d: ", cont);
		cont2 = 0;
		while (line[cont2] != '\0')
		{
			if (line[cont2] == '\n')
				write(1, "\\n", 2);
			else
				write(1, &line[cont2], 1);
			cont2++;
		}
		free(line);
		line = get_next_line(fd);
		cont++;
	}
	printf("\nlinea %d: %s fin", cont, line);
	free(line);
	close(fd);
	return 0;
}*/