/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lector_de_ficheros.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:52:37 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/03/11 19:21:40 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int exist_file(int file)
{
	if (file == -1)
	{
		write(1, "Error: El fichero no existe", 27);
		return (0);
	}
	return (1);
}

int main(void)
{
	int cont;
	int cont2;
	char *str;
	char c[1];
	int fichero = open("numbers.dict", O_RDONLY);

	if (exist_file(fichero))
		{
		cont = 0;
		while (read(fichero, c, 1) > 0)
		{
			write(1, c, 1);
			cont++;
		}
		str = malloc(cont * sizeof(char));
		cont2 = 0;
		read(fichero, c, (cont * -1));
		while (cont2 < cont)
		{
			str[cont2] = read(fichero, c, 1);
			cont2++;
		}
		close(fichero);
		write(1, str, cont);
	}
}
