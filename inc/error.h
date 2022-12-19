/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:42:40 by jvigneau          #+#    #+#             */
/*   Updated: 2022/12/19 14:40:12 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H

# define ARGC "Must have a map in argument\n"
# define DOT_CUB "Map must end with .cub\n"
# define JUST_CUB "The name of the map cant be empty\n"
# define FAKE_FILE "The map does not exist\n"
# define DUPL "There is multiple definitions of the same texture in the file\n"
# define ORDER "The order of the map file is incorrect\n"
# define INV_INPUT "Some elements in the map are invalid\n"
# define INV_LINE "There is an empty line in the map\n"
# define INV_MAP "The map is invalid\n"
# define NO_SPAWN "The map has no spawner\n"
# define MULT_SPAWN "The map has multiples spawners\n"
# define INV_TEXTURE "The path to one of the textures is invalid\n"
# define EMPTY_FILE "The file is empty\n"

#endif
