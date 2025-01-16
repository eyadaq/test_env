/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 07:11:12 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/16 12:02:03 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_H
# define HASH_H

#include <unistd.h>

typedef struct s_hashmap
{
	int		index;
	int		key;
	char 	*value;
}				t_hashmap;



#endif