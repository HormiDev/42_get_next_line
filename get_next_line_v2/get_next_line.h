/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 23:41:35 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/10/06 00:40:30 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# if BUFFER_SIZE > 2147483647 || BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct buffer_lst
{
	char				*content;
	int					lencontent;
	struct buffer_lst	*next;
}	t_buffer_lst;

char			*get_next_line(int fd);
int				ft_strnchr_gnl(const char *str, int c, int len);
int				ft_buffer_lst_len(t_buffer_lst *lst);
char			*lstjoin(t_buffer_lst *lst, int endline);
t_buffer_lst	*ft_buffer_lst_last(t_buffer_lst *lst);
t_buffer_lst	*ft_addnew_buffer_lst(t_buffer_lst *lst);
char			*ft_buffer_lst_clear(t_buffer_lst **lst);
t_buffer_lst	*cleanbuffer(t_buffer_lst *lst, int endline);

#endif
