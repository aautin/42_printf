/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:26:06 by aautin            #+#    #+#             */
/*   Updated: 2023/08/10 13:42:59 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

// still 6 functions to finish the libft_nobonusgit 

#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>			// to remove, just used in the main here...
#include <string.h>			// can we really use it ? recode the size_t ?

// linked list's structure :
typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

// linked list's functions :
t_list			*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_front(t_list **alst, t_list *new);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
int				ft_lstsize(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));


int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);


//	utils functions
int				ft_nb_size(int n);
int				ft_is_in_str(char	a, char *s);
char			*ft_strdup_sep(const char *s, size_t *pos, char sep);
size_t			ft_count_elements(char const *s, char c);
//


int				ft_atoi(const char *nptr);
size_t			ft_strlen(const char *s);


int				ft_strncmp(const char *s1, const char *s2, size_t n);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);


char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *haystack, const char *needle, size_t len);
char			*ft2_strnstr(const char *haystack, const char *needle, size_t len);


void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);


void			*ft_calloc(size_t nmemb, size_t size);
char			*ft_strdup(const char *s);


void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void 			ft_putnbr_fd(int n, int fd);


char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			**ft_split(char const *s, char c);





// ----- here including the strlcat and strlcpy functions -----
size_t			strlcpy(char *dst, const char *src, size_t siz);
size_t			strlcat(char *dst, const char *src, size_t siz);
// ---- example function used to test the strmapi function ----
char			incrementation(unsigned int	n, char c);


#endif
