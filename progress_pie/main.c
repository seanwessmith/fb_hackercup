/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 13:33:26 by ssmith            #+#    #+#             */
/*   Updated: 2017/01/08 21:20:10 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define PI 3.141592653589

int		get_next_line(const int fd, char **line);

int		*split_whitespace(char *str)
{
	int		i;
	int		x;
	int		*array = malloc(3 * sizeof(int));
	char	*num;

	x = 0;
	while (*str)
	{
		i = 0;
		num = malloc(3 * sizeof(char));
		while (*str != ' ' && *str)
		{
			num[i] = *str++;
			i++;
		}
		if (*str == ' ')
		{
			str++;
			array[x] = atoi(num);
			x++;
		}
	}
	array[x] = atoi(num);
	return (array);
}

int		main(int argc, char **argv)
{
	int		fd;
	int 	i;
	int		nbr;
	int		*array;
	char	*str;
	int		ret;
	float	result;
	int		counter;
	char	buf[2000] = {0};

	counter = 1;
	nbr = 0;
	i = 0;
	if ((fd = open(argv[1], O_RDONLY)) == -1)
			return (0);
	// Grab the first line, contains # of lines of input
	get_next_line(fd, &str);
	nbr = atoi(str);
	//Loop through all line of the input file, output solution
	while (counter <= nbr)
	{
		ret = 1;
		get_next_line(fd, &str);
		array = split_whitespace(str);
		//Determine if point is within the radius of the circle
		if (50 < sqrt(pow(array[1] - 50, 2) + pow(array[2] - 50, 2)))
			ret = 0;
		//Determine if the tangent is less than the percentage of the progress bar
		result = atan2(array[1] - 50, array[2] - 50) * 180 / PI; 
		if (result > (array[0] * 3.6))
			ret = 0;
		//Print the solution to standard output
		if (ret == 1)
			printf("Case #%d: black\n", counter);
		else
			printf("Case #%d: white\n", counter);
		counter++;
	}
}
