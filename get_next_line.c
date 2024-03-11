/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:50:57 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/03/11 19:24:59 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char bufer[1];
	
	while (fd != -1)
	{
		read(fd, &bufer, 1);
		printf("%s", bufer);
	}
	return (&bufer);
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
/*
int main() {
    char buffer[2];
    int file = open("hola.txt", O_RDONLY);
    if (file < 0) {
        write(2, "No se pudo abrir el archivo.\n", 28);
        return 1;
    }

    if (read(file, buffer, 2) != 1) {
        write(2, "No se pudo leer el archivo.\n", 27);
        return 1;
    }

    write(1, "El primer carácter es: ", 22);
    write(1, buffer, 2);
    write(1, "\n", 1);

    close(file);
    return 0;
}
*/