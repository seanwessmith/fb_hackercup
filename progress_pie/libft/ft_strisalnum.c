/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisalnum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 10:58:31 by ssmith            #+#    #+#             */
/*   Updated: 2016/11/13 22:05:19 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strisalnum(char *str)
{
	while (*str != '\0')
	{
		if ((*str <= 48 && *str >= 57) ||
				(*str <= 65 && *str >= 90) || (*str <= 97 && *str >= 122))
			return (0);
		str++;
	}
	return (1);
}
