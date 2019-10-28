/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcraydle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:17:15 by fcraydle          #+#    #+#             */
/*   Updated: 2019/05/20 14:56:24 by fcraydle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include "libft.h"
# define BUFF_SIZE 5

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int                 ft_atoi_base(const char *str, int str_base);
int                 get_next_line(const int fd, char **line);
char				*ft_strjoinfree(char *s1, char *s2);
void				ft_free(char **str, size_t val);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstiter(t_list *lst, void(*f)(t_list *elem));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
t_list				*ft_lstnew(const void *content, size_t content_size);
size_t				ft_min(size_t a, size_t b);
int					ft_volume_of_num(int x);
char				*ft_itoa(int n);
char				**ft_strsplit(char const*s, char c);
char				*ft_strtrim(char const*s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
char				*ft_strmapi(char const*s, char (*f)(unsigned int, char));
char				*ft_strmap(char const*s, char(*f)(char));
void				ft_striteri(char*s, void(*f)(unsigned int, char *));
void				ft_striter(char*s, void(*f)(char*));
void				ft_strclr(char *s);
void				ft_strdel(char **as);
char				*ft_strnew(size_t size);
void				ft_memdel(void **ap);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dest, const void *s, int c, size_t n);
void				*ft_memchr(const void *arr, int c, size_t n);
void				*ft_memmove(void *dest, const void *s, size_t n);
char				*ft_strcpy(char *destination, const char *source);
char				*ft_strdup(const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcat(char *s1, const char *s2);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				ft_bzero(void *s, size_t len);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isalnum(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_isalpha(int c);
char				*ft_strnstr(const char *big, const char *lit, size_t len);
char				*ft_strstr(const char *s1, const char *s2);
int					ft_strcmp(const char *s1, const char *s2);
size_t				ft_strlen(const char *s);
int					ft_atoi(const char *nptr);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putchar(char c);

#endif
