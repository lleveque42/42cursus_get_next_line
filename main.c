/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:57:15 by lleveque          #+#    #+#             */
/*   Updated: 2021/12/13 10:01:33 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("Ligne 1 : %s\n", get_next_line(fd));
	printf("Ligne 2 : %s\n", get_next_line(fd));
	printf("Ligne 3 : %s\n", get_next_line(fd));
	printf("Ligne 4 : %s\n", get_next_line(fd));
}