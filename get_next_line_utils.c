/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:52:58 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/03/14 18:56:35 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == 0)
		return (0);
	node -> content = content;
	node -> next = NULL;
	return (node);
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

char	*ft_strchr(const char *str, int c)
{
	char	cchar;

	cchar = (char)c;
	while (*str != '\0')
	{
		if (*str == cchar)
			return ((char *)str);
		str++;
	}
	if (cchar == '\0')
		return ((char *)str);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	cont;

	cont = 0;
	while (str[cont] != 0)
	{
		cont++;
	}
	return (cont);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	cont;

	cont = 0;
	str = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (str == 0)
		return (0);
	while (cont < ft_strlen(s1))
	{
		str[cont] = s1[cont];
		cont++;
	}
	str[cont] = 0;
	return (str);
}

char	*ft_strchr(const char *str, int c)
{
	char	cchar;

	cchar = (char)c;
	while (*str != '\0')
	{
		if (*str == cchar)
			return ((char *)str);
		str++;
	}
	if (cchar == '\0')
		return ((char *)str);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == 0)
		return (0);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (str);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	cont;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	cont = 0;
	if (dstsize == 0)
		return (srclen);
	while (dstlen + cont < dstsize - 1 && src[cont] != '\0')
	{
		dst[dstlen + cont] = src[cont];
		cont++;
	}
	dst[dstlen + cont] = '\0';
	if (dstsize < dstlen)
		return (dstsize + srclen);
	return (dstlen + srclen);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	cont;
	size_t	srclen;

	cont = 0;
	srclen = ft_strlen(src);
	if (dstsize > 0)
	{
		while (cont < srclen && cont < dstsize - 1)
		{
			dst[cont] = src[cont];
			cont++;
		}
		dst[cont] = 0;
	}
	return (srclen);
}