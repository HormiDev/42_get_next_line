/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:50:57 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/03/12 18:10:10 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static t_list *bufer;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (bufer == 0)
		bufer = ft_lstnew(ft_strdup(read(fd, bufer, BUFFER_SIZE)));
	if (bufer == 0)
		return (0);
	return (0);
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