/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 11:07:52 by tbraquem          #+#    #+#             */
/*   Updated: 2022/03/04 10:08:10 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static void    fill_ret(char const *s, size_t i, size_t len, char *new)
// {
//     size_t    j;

//     j = 0;
//     while (s[i] && (j < len))
//         new[j++] = s[i++];
//     new[j] = '\0';
// }

// char    *ft_substr(char const *s, unsigned int start, size_t len)
// {
//     char    *new;
//     size_t    i;
//     size_t    protect;

//     if (!s)
//         return (NULL);
//     i = start;
//     protect = ft_strlen(s);
//     if (start >= protect)
//     {
//         new = (char *)malloc(1 * sizeof(char));
//         if (!new)
//             return (NULL);
//         new[0] = '\0';
//         return (new);
//     }
//     if (start < 0 || len < 0)
//         protect = 0;
//     if (start == 0)
//         len = (len - start);
//     else if (len > start)
//         len = (protect - start);
//     if (len > protect)
//       len = protect;
//     new = (char *) malloc(len + 1 * sizeof(char));
//     if (!new)
//         return (new);
//     fill_ret(s, i, len, new);
//     return (new);
// }

static void	fill_ret(char const *s, size_t i, size_t len, char *new)
{
	size_t	j;

	j = 0;
	while (s[i] && (j < len))
		new[j++] = s[i++];
	new[j] = '\0';
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;
	size_t	protect;

	if (!s)
		return (NULL);
	i = start;
	protect = ft_strlen(s);
	if (start >= protect)
	{
		new = (char *)malloc(1 * sizeof(char));
		if (!new)
			return (NULL);
		new[0] = '\0';
		return (new);
	}
	if (start < 0 || len < 0)
		protect = 0;
	if (len >= protect)
		len = (protect) - start;
	new = (char *) malloc(len + 1 * sizeof(char));
	if (!new)
		return (new);
	fill_ret(s, i, len, new);
	return (new);
}
