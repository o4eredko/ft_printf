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

#include "ft_printf.h"
#include <stdio.h>
#include <time.h>

int main(void)
{
	int m =  printf("|%05p|\n", 0);
 int n = ft_printf("|%05p|\n", 0);
	printf("Original ret: %d\nMy ret: %d\n", m, n);
	return (0);
}
