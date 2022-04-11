/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:18:11 by tbraquem          #+#    #+#             */
/*   Updated: 2022/04/03 13:58:34 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 10

char	*ft_sstrjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
int		ft_sstrchr(char *str, int c);
char	*ft_read( int fd, char *buff, char *str, int res);
char	*get_next_line(int fd);

#endif
