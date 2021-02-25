/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:34:46 by gleal             #+#    #+#             */
/*   Updated: 2021/02/25 16:02:07 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main()
{
	int i;
	int d;
	d = 193123;
	i = ft_printf("this %d number", 0);
	printf("%d", i);
}
/* se precision check off precision = maior entre maximum width
 * precision e sempre no minimo tamanho do numero
 * se tiver precision aparecem zeros acima do tamanho da palavra
 * se tiver 0 sem precision fica tudo zeros
 * zero so e importante se nao houver precisao
 * */
