/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallyson <pallyson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 21:46:43 by pallyson          #+#    #+#             */
/*   Updated: 2021/01/05 18:11:32 by pallyson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int len;

	if (!str)
		return (0);
	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*a;
	unsigned int	i;
	unsigned int	j;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2) + 1;
	a = (char*)malloc(sizeof(char) * i);
	if (a == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j] != '\0')
		a[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		a[i++] = s2[j++];
	a[i] = '\0';
	return (a);
}

char	*ft_strchr(const char *s, int c)
{
	char *a;

	a = (char*)s;
	while (*a != c)
	{
		if (!*a)
			return (NULL);
		a++;
	}
	return (a);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	len;
	size_t	i;

	len = 0;
	while (s1[len])
		len++;
	s2 = (char *)malloc(sizeof(*s2) * (len + 1));
	if (!s2)
		return (s2);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
