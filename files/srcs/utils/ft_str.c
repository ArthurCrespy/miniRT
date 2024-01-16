/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:12:13 by acrespy           #+#    #+#             */
/*   Updated: 2023/11/19 15:12:13 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/miniRT.h"

/*
int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_strncmp(char *s1, char *s2, int i)
{
	int	j;

	j = 0;
	if (!s1 || !s2 || i == 0)
		return (0);
	while (s1[j] && s2[j] && j < i - 1)
	{
		if (s1[j] == s2[j])
			j++;
		if (s1[j] < s2[j] || s1[j] > s2[j])
			return (s1[j] - s2[j]);
	}
	if (j == i)
		return (0);
	return (s1[j] - s2[j]);
}

char	*ft_strchr(const char *string, int c)
{
	char	*str;

	str = (char *)string;
	while (*str != c && *str != '\0')
		str++;
	if (*str == c)
		return (str);
	else
		return (NULL);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*result;

	i = 0;
	result = malloc((ft_strlen(str) + 2) * sizeof(char));
	if (!result || !str)
		return (NULL);
	while (i <= (int)ft_strlen(str))
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i_s1;
	int		i_s2;
	char	*result;

	i_s1 = 0;
	i_s2 = 0;
	result = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!result)
		return (NULL);
	if (s1)
	{
		while (s1[i_s1])
		{
			result[i_s1] = s1[i_s1];
			i_s1++;
		}
	}
	while (s2[i_s2])
	{
		result[i_s1 + i_s2] = s2[i_s2];
		i_s2++;
	}
	result[i_s1 + i_s2] = '\0';
	return (result);
}
*/