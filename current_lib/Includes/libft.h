/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:25:41 by rdel-fra          #+#    #+#             */
/*   Updated: 2024/12/23 18:40:49 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				nb;
	struct s_list	*next;	
}					t_list;

int		ft_isalpha(int c);
int		ft_isdigit(int d);
int		ft_isalnum(int a);
int		ft_isascii(int i);
int		ft_isprint(int p);
int		ft_toupper(int u);
int		ft_tolower(int l);
int		ft_lstsize(t_list *lst);
int		ft_ptrlen(char **v);
int		ft_atoi(const char *nptr);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
void	*my_realloc(void *ptr, size_t new_size);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strnstr(const char *big, const char *little, size_t len);
void	ft_bzero(void *s, size_t n);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_lstiter(t_list *lst, void (*f)(int));
void	ft_lstadd_back(t_list **lst, t_list *new);
void	*ft_memchr(const void *s, int c, size_t n);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(int));
void	ft_lstclear(t_list **lst, void (*del)(int));
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
long	ft_atol(char *str);
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstsecond_to_last(t_list *lst);
t_list	*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int));

#endif