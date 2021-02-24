/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:08:33 by user42            #+#    #+#             */
/*   Updated: 2021/02/24 10:53:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libasm.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
//	printf("%ld\n", sizeof(size_t));
//	sytrlen
//	printf("ft_len :%ld\n", strlen(av[1]));
//	printf("len :%ld\n", ft_strlen(av[1]));
/*
//	strcpy
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

/*
//	strcmp
	printf("official %d\n", strcmp(av[1], av[2]));
	printf("custom   %d\n", ft_strcmp(av[1], av[2]));
*/

/*
	// write
	size_t ret;
	
	ret = ft_write(14, "lol\n", 4);
	printf("ret / errno : %ld / %d\n", ret, errno);
	ret = write(14, "lol", 4);
	printf("ret / errno : %ld / %d\n", ret, errno);
*/

	// read
	
	char buf[1024];
	int fd = open("README.md", O_RDONLY);
	int ret = ft_read(fd, &buf, 24);
	printf("ret, errno, str: %d, %d, %s\n", ret, errno, buf);
	fd = open("README.mi", O_RDONLY);
	ret = ft_read(fd, &buf, 24);
	printf("ret, errno, str: %d, %d, %s\n", ret, errno, buf);
	char buf2[1024];
	int fd2 = open("README.mi", O_RDONLY);
	int ret2 = read(fd2, &buf2, 24);
	printf("ret, errno, str : %d, %d, %s\n", ret2, errno, buf2);
	return (0);
}
