/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:46:56 by mpagani           #+#    #+#             */
/*   Updated: 2022/11/15 16:17:45 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;

	if (!s1)
		return (NULL);
	result = malloc(sizeof(*result) * ft_strlen(s1) + ft_strlen(s2) +1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, (char *)s1, ft_strlen(s1) + 1);
	ft_strlcpy(result + ft_strlen(s1), (char *)s2, ft_strlen(s2) + 1);
	return (result);
}
