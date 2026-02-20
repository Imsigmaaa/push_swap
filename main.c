/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:23:17 by xingchen          #+#    #+#             */
/*   Updated: 2026/02/20 14:11:00 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	main(int argc, char ** argv)
{
	int	i;
	int i;
	if (argc == 1 && (argc == 2 && !argv[1]))
		return (0);
	if(argc == 2 && argv[1][0] == '\0')
		return (write(2,"Error\n",6));
	i = 0;
	char **dup = ft_split(&argv[1], 32);
	while(dup[i])
	{
		printf("%s",dup[i]);
		i ++;
	}
	i = 0;
	while(dup[i])
	{
		free(dup[i]);
		i ++;
	}
	free(dup);
	/*while (argv[1][i])
	{
		
	}
		return (write(1,"yes!\n",5));*/
		
}
