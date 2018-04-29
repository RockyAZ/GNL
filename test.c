#include <unistd.h>
#include <fcntl.h>
#include "libft/libft.h"

int		main(int argc, char **argv)
{
	int		fd;
	int		nb_char;
	char	buf[4096];

	nb_char = 1;
	if (argc < 2)
		return (write(2, "File name missing.\n", 19) || 1);
	if (argc > 2)
		return (write(2, "Too many arguments.\n", 20) || 1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (write(2, "OPEN() error.\n", 14) || 1);
	while (nb_char)
	{
		nb_char = read(fd, buf, 4096);
		buf[4095] = '\0';
		ft_putstr(buf);
	}
	fd = close(fd);
	if (fd == -1)
		return (write(2, "CLOSE() error.\n", 15) || 1);
	return (0);
}