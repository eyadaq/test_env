/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 07:10:59 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/16 07:15:47 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/main.h"

int		main()
{
	int			x;
	char		*chr;
	
	chr  = "Eyad aq\n";
	x = ft_strlen(chr);
	write (1, chr, x);
	return (0);
}