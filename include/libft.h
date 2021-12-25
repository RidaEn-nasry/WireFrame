/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 10:01:04 by ren-nasr          #+#    #+#             */
/*   Updated: 2021/12/25 19:20:26 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

int		ft_atoi(char *str);
void	ft_error(char *s);
void	*ft_free_tab(char **tab);
void	ft_putchar_fd(int c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char *s, char c);
void	ft_strcpy(char *dst, char *src);
int		ft_strlen(char *s);

/*** GET_NEXT_LINE ***/

# define BUFFER_SIZE 10000

char	*get_next_line(int fd);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
void	*free_str(char *s);

#endif
