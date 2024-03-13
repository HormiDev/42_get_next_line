/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:50:57 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/03/13 19:45:11 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char *buffer;
	char *str;
	char *temp;
	int n;
	
	str = ft_strdup("");
	n = 0;
	while ((n = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[n] = 0;
		temp = ft_strchr(buffer, '\n');
		if (temp != 0)
		{
			*temp = 0;
			temp = ft_strdup(temp + 1);
			temp = ft_strchr(temp, '\n');
			if (temp != 0)
				temp = ft_strdup(temp + 1);
			return (str);
		}
		temp = ft_strdup(buffer);
		str = ft_strjoin(str, temp);
	}
	return (str);
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