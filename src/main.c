/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 10:16:38 by yochered          #+#    #+#             */
/*   Updated: 2018/11/26 10:16:39 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int n;
	int m;

	n = ft_printf("%010.%\n");
	m = printf("%010.%\n");
	printf("Original ret: %d\nMy ret: %d\n", m, n);
	return (0);
}
