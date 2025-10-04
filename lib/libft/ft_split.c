/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:24:59 by rdel-fra          #+#    #+#             */
/*   Updated: 2024/12/11 12:35:48 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

static int	ft_count(char const *s, char c);
static char	**ft_matrix(int count, size_t *len, int *j, int *flag);
static char	*ft_alloc(char const *s, char c, int len);
//static void	ft_free_matrix(char **ptr_matrix, int j);

char	**ft_split(char const *s, char c)
{
	char	**ptr_matrix;
	int		flag;
	size_t	len;
	int		j;

	ptr_matrix = ft_matrix(ft_count(s, c), &len, &j, &flag);
	if (!ptr_matrix)
		return (NULL);
	while (++len, s[len] != '\0')
	{
		if (s[len] != c && flag == 1)
		{
			ptr_matrix[j] = ft_alloc(s, c, len);
			if (!(ptr_matrix[j]))
				return (NULL);
			j++;
			flag = 0;
		}
		else if (s[len] == c)
			flag = 1;
	}
	ptr_matrix[j] = 0;
	return (ptr_matrix);
}

// if (!(ptr_matrix[j]))
// 	ft_free_matrix(ptr_matrix, j);

static char	*ft_alloc(char const *s, char c, int len)
{
	char	*ptr;
	int		catch;
	int		i;

	catch = len;
	while (s[catch] != c && s[catch] != '\0')
		catch++;
	if (catch == len)
		return (NULL);
	ptr = (char *)malloc((catch - len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, catch - len + 1);
	i = 0;
	while (len < catch)
	{
		ptr[i] = s[len];
		len++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static int	ft_count(char const *s, char c)
{
	int	count;
	int	flag;
	int	i;

	i = 0;
	flag = 1;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && flag == 1)
		{
			count++;
			flag = 0;
		}
		if (s[i] == c)
			flag = 1;
		i++;
	}
	return (count);
}

static char	**ft_matrix(int count, size_t *len, int *j, int *flag)
{
	char	**ptr;

	*flag = 1;
	*len = -1;
	*j = 0;
	ptr = (char **)malloc((count + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, count + 1);
	return (ptr);
}

// static void	ft_free_matrix(char **ptr_matrix, int j)
// {
// 	int	i;

// 	i = 0;
// 	while (i < j)
// 	{
// 		free(ptr_matrix[i]);
// 		i++;
// 	}
// 	free(ptr_matrix);
// }
// int main(void)
// {
// 	char *s = "      split       this for   me  !       ";
// 	char **result = ft_split(s, ' ');
// 	int i = 0;
// 	while (result[i])
// 	{
// 		printf("result[%d]: %s\n", i, result[i]);
// 		i++;
// 	}
// 	printf("result[%d]: %s\n", i, result[i]);
// 	// Free memory after usage
// 	i = 0;
// 	while (result[i])
// 	{
// 		free(result[i]);
// 		i++;
// 	}
// 	free(result);
// 	return 0;
// }