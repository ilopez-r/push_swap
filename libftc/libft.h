/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-r <ilopez-r@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:48:37 by ilopez-r          #+#    #+#             */
/*   Updated: 2024/03/11 12:10:54 by ilopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int				ft_isalpha(int i);
int				ft_isdigit(int i);
int				ft_isalnum(int i);
int				ft_isascii(int i);
int				ft_isprint(int i);
size_t			ft_strlen(const char *str);
int				ft_toupper(int i);
int				ft_tolower(int i);
void			*ft_memset(void *b, int c, size_t len);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strnstr(const char *hs, const char *needle, size_t len);
long long int	ft_atoi(const char *str);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(const char *s1);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_itoa(int n);
void			ft_putchar_fd(char c, int fd);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
char			**ft_split(char const *s, char c);
int				ft_printchar(char c);
int				ft_printdec(long long int n);
int				ft_printf(char const *str, ...);
int				ft_printhexa(unsigned long long n, char c);
int				ft_printptr(unsigned long long ptr);
int				ft_printstr(char *str);
int				ft_printunsigned(unsigned long long int n);
size_t			gnl_ft_strlen(const char *str);
int				gnl_ft_strchr(const char *str, int c);
void			*gnl_ft_calloc(size_t count, size_t size);
void			*gnl_ft_memcpy(void *dest, const void *src, size_t n);
char			*gnl_ft_strjoin(char *s1, char *s2);
char			*get_next_line(int fd);
typedef struct s_list
{
	int				value;
	int				index;
	int				position;
	int				t_position;
	int				cost_a;
	int				cost_b;
	int				t_cost;
	struct s_list	*next;
}					t_list;
t_list			*ft_lstnew(int value);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(int));
void			ft_lstclear(t_list **lst, void (*del)(int));

#endif