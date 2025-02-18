/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:38:06 by afailde-          #+#    #+#             */
/*   Updated: 2025/02/18 19:51:59 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <stddef.h>
# include <string.h>
# include <stdarg.h>

typedef struct s_list
{
	void				*content;
	struct s_list		*next;
}			t_list;

t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void	*content);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int 	ft_squareroot(int n);
int		ft_isalpha(int character);
int		ft_isspace(char c);
int		ft_isdigit(int num);
int		ft_lstsize(t_list *lst);
int		ft_isalnum(int alnum);
int		ft_isascii(int ascii);
int		ft_isprint(int print);
int		ft_atoi(const char *str);
int		ft_strlen(const char *str);
int		ft_toupper(int character);
int		ft_tolower(int character);
int		ft_memcmp(const void *string1, const void *string2, size_t num);
void	ft_bzero(void *a, size_t b);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f) (void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_itoa(int n);
char	*ft_strdup(const char *source);
char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t num, size_t size);
char	*ft_strchr(const char *a, int character);
char	*ft_strrchr(const char *a, int character);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strnstr(const char *str, const char *sb_str, size_t len);
void	*ft_memset(void *a, int b, size_t c);
void	*ft_memcpy(void *dest, const void *src, size_t num);
void	*ft_memchr(const void *s, int character, size_t num);
void	*ft_memmove(void *dest, const void *src, size_t num);
int		ft_strncmp(const char *s1, const char *s2, size_t num);
size_t	ft_strlcpy(char *dest, const char *src, size_t numb);
size_t	ft_strlcat(char *dest, const char *src, size_t numb);

int		ft_putchar(char c, int *index);
int		ft_printf(const char *format, ...);
int		ft_puthex(unsigned long n, char format, int *index);
int		ft_pointer_direction(void *ptr, char format, int *index);
void	ft_putnbr(int n, int *index);
void	ft_putstr(char *s, int *index);
void	ft_nbr_unsigned(unsigned int n, int *index);

#endif