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

int main(void)
{
	printf("%.6f\n", -124214.12531251);
	ft_printf("%.6f\n", -124214.12531251);
	return (0);
}
