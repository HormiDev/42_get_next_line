/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:51:16 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/04/25 17:49:14 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
# endif

typedef struct buffer_lst
{
	char			*content;
	int				lencontent;
	struct buffer_lst	*next;
}	buffer_lst;

char	*get_next_line(int fd);
buffer_lst	*ft_addnewlst(buffer_lst *lst);
buffer_lst	*cleanbuffer(buffer_lst *lst, int endline);
int	ft_buffer_lst_len(buffer_lst *lst);
buffer_lst	*ft_create_newlst(void);
buffer_lst	*ft_lstlast(buffer_lst *lst);
int	ft_strnchr(const char *str, int c, int len);
void	ft_lstclear(buffer_lst **lst, void (*del)(void*));
char	*lstjoin(buffer_lst *lst, int endline);

#endif