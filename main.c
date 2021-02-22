/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:08:33 by user42            #+#    #+#             */
/*   Updated: 2021/02/22 16:43:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libasm.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	(void)ac;

//	sytrlen
//	printf("ft_len :%ld\n", strlen(av[1]));
//	printf("len :%ld\n", ft_strlen(av[1]));

/*	strcpy
	char cpy[1024];
	char cpy2[1024];
	char *ret = &cpy[0];

	printf("virgin cpy : %s\n", cpy);
	printf("sent value     %p\n", ret);
	ret = ft_strcpy(cpy, av[1]);
	printf("returned value %p\n", ret);
	printf("final  cpy : %s\n", cpy);
	strcpy(cpy2, av[1]);
	printf("offic  cpy : %s\n", cpy2);
*/

//	strcmp
	printf("official %d\n", strcmp(av[1], av[2]));
	printf("custom   %d\n", ft_strcmp(av[1], av[2]));

	
	return (0);
}
