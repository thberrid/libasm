/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:08:33 by user42            #+#    #+#             */
/*   Updated: 2021/02/19 16:55:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libasm.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
//	printf("ft_len :%ld\n", strlen(av[1]));
//	printf("len :%ld\n", ft_strlen(av[1]));
	char cpy[1024];
	printf("virgin cpy : %s\n", cpy);
	ft_strcpy(cpy, "ok boomer");
	printf("final  cpy : %s\n", cpy);
	return (0);
}
