/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:08:33 by user42            #+#    #+#             */
/*   Updated: 2021/02/24 14:31:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libasm.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void	test(char *a)
{
	char	*str;
	char	buf[32];
	int		fd_src;
	int		fd_dst;
	size_t	read;

	str = ft_strdup(a);
	fd_src = open("sources/ft_strdup.s", O_RDONLY);
	fd_dst = open("output.txt", O_CREAT|O_RDWR|O_APPEND, 0777);
	read = ft_read(fd_src, buf, 32);
	buf[31] = '\0';
	ft_write(fd_dst, str, ft_strlen(str));
	ft_write(2, str, ft_strlen(str));
	ft_write(2, "\n", 1);
	ft_write(fd_dst, buf, read);
	ft_write(2, buf, read);
	ft_write(2, "\n", 1);
	close(fd_src);
	close(fd_dst);
	free(str);
}

int	main(int ac, char **av)
{
	int		i;

	if (ac == 1)
		return (ft_write(1, "usage:./test s\n", ft_strlen("usage:./test s\n")));
	i = 0;
	while (i < 5)
	{
		test(av[1]);
		i += 1;
	}
	ft_write(1, "output.tst written\n", ft_strlen("output.tst written\n"));
	return (0);
}
