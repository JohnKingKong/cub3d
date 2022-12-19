# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/31 08:51:26 by aguay             #+#    #+#              #
#    Updated: 2022/12/19 14:38:18 by jmorneau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	Huge credit to Armorine86 on github
#		https://github.com/Armorine86
#	
#	This Makefile is inspired a lot from
#	his Makefile template. I played with
#	it and add comment for new student at
#	42 Quebec.

## -----  NAME OF THE PROGRAMM ----- ##
NAME 			= cub3d

## ----- COMPILER AND FLAGS ----- ##
CC				= gcc

CFLAGS			= -Wall -Werror -Wextra -g

MINIFLAGS		= -Lmlx -lmlx -framework OpenGL -framework AppKit

LIBFT			= ./libft/libft.a

LIBFT_DIR		= cd ./libft && make 

## ----- ADD FILES TUTORIAL ----- ##

# to add a directory to srcs :
#
#	X_DIR = $(SRCS_DIR)x
#		(Create dir srcs/x)
#
#	X_FILES = x_y.cpp ect
#		(The file in the folder)
#
#	X_SRCS	=	$(addprefix $(X_DIR), $(X_FILES))
#		(add the prefix to all files)
#
#	OBJ_FILES = $(X_FILES:.c=.o)
#		Routine to get .c to .o
#
#	VPATH = $(X_DIR)

## ----- PATH TO DIRECTORIES ----- ##
SRCS_DIR		= src/

KEY_INTERACTION_DIR	= src/key_interaction/
MAIN_DIR			= src/main/
OTHERS_DIR			= src/others/
PARSING_DIR			= src/parsing/
PLAYER_DIR			= src/player/
RAYTRACING_DIR		= src/ray_tracing/
RENDER_DIR			= src/render/

OBJ_DIR			= obj/

INCLUDE_DIR		= inc/

## ----- FILES ----- ##

KEY_INTERACTION_FILES	= key_hook.c\
		
MAIN_FILES				=	cub3d.c game_init.c
OTHERS_FILES			=	usefull.c usefull_2.c
PARSING_FILES			=	error.c map_reader.c parsing_1.c parsing_elements.c\
							parsing_map.c parsing_map2.c parsing_elements2.c flood_fill.c \
							free_parsing.c
RAYTRACING_FILES		=	ray_casting.c
HEADER_FILES			=	libft.h
RENDER_FILES			=	texture.c three_d.c

## ----- ADDPREFIX TO FILES ----- ##

OBJS					=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

KEY_INTERACTION_SRCS	=	$(addprefix $(KEY_INTERACTION_DIR), $(KEY_INTERACTION_FILES))
MAIN_SRCS				=	$(addprefix $(MAIN_DIR), $(MAIN_FILES))
OTHERS_SRC				= 	$(addprefix $(OTHERS_DIR), $(OTHERS_DIR))
PARSING_SRCS			=	$(addprefix $(PARSING_DIR), $(PARSING_FILES))
RAYTRACING_SRCS			=	$(addprefix $(RAYTRACING_DIR), $(RAYTRACING_FILES))
RENDER_SRCS				= 	$(addprefix $(RENDER_DIR), $(RENDER_FILES))

HEADER_SRCS				=	$(addprefix $(INCLUDE_DIR), $(HEADER_FILES))

OBJ_FILES				=	$(KEY_INTERACTION_FILES:.c=.o) $(MAIN_FILES:.c=.o) $(OTHERS_FILES:.c=.o) $(PARSING_FILES:.c=.o) $(RAYTRACING_FILES:.c=.o) $(RENDER_FILES:.c=.o)  

VPATH					=	$(KEY_INTERACTION_DIR) $(MAIN_DIR) $(OTHERS_DIR) $(PARSING_DIR) $(RAYTRACING_DIR) $(RENDER_DIR) 

## ----- .C TO .O CONVERT ----- ##

$(OBJ_DIR)%.o: %.c $(KEY_INTERACTION_SRCS) $(MAIN_SRCS) $(OTHERS_SRCS) $(PARSING_SRCS) $(RAYTRACING_SRCS) $(RENDER_SRCS)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -c $< -o $@
#	Here you can add any header foler by adding -I $(header_directory)


#--------------------------------------------------------------#
## ----- compile differently on other os ----- ##
#
# ifeq ($(shell uname), Linux)
#
#		(code to do if then you run in shell uname, and the result is Linux)
#		a good exemple would be to change the compilation flags and library
#		on other OS. Ex:
#
#		MLX visual library only need a flag in compilation at school since
#		the library installed for every session. At home on linux you would
#		need the srcs code of the lib and some manipulation to compile it correctly.
#		You could use ifeq to compile with the make command on both os with
#		different compiling rules.
#
# endif
#		Note : You cant put ifeq and endif in a variable/macro. It has
#				to be outside (ifeq before and endif after) any
#				declaration in Makefile

## ----- TOOLS AND COLORS ----- ##

RM				= @rm -rf
NO_PRINT		= --no-print-directory
RED 			= \033[31m
GREEN 			= \033[32m
YELLOW 			= \033[33m
BLUE 			= \033[34m
PINK 			= \033[35m
AQUA 			= \033[36m
GREY 			= \033[37m
UNDERLINE 		= \033[4m
NORMAL 			= \033[0m

#	Here you could add some rules to compile an other makefile
#
#	Exemple compilting the libft :
#
#	LIBFT			= make -C $(LIBFT_DIR)
#
#	Wich if you call $(LIBFT);
#	The makefile in LIBFT_DIR will get executed,
#	then come back to this Makefile.


## ----- ALL ACTION DEPENDENCIES AND RECIPE FOR MAIN PROGRAM ----- ##

#	Here we add what is necessary for compilation
#	Wich is by default the obj directory and the name
#	of the program. You could protect your compilation
#	by adding dependencies.
all: obj $(NAME)


#	1) Dependencies (creating .o files)
#	2) You could add $(LIBFT) or other rules
#		to compile anything necessary
#	3) Call the compiler with his dependencies
#		(.o files, library.a) with -o (output) name
$(NAME): $(OBJ_DIR) $(OBJS)
	$(LIBFT_DIR)
	$(CC) $(OBJS) $(LIBFT) $(MINIFLAGS) -o $(NAME)


#	Create .o folder for easy clean
obj:
	@mkdir -p $(OBJ_DIR)

## ----- make options ----- #

#	Here are some options that you could add
#	such as tester and other compilation flags
#	you might now always want.

debug: CFLAGS += -g
debug: obj $(NAME)

opti: CFLAGS += -O3
opti: obj $(NAME)

leak: obj $(NAME)
	leaks --atExit -- ./$(NAME) map_utils/map_test1.cub

setup: 
	@rm -rf LICENSE images README.md

## ----- CLEAN COMMANDS ----- ##

#	If you us an other dir with a makefile
#	you can run make clean in it like that:
#
#	@make -C $(LIBFT_DIR) clean
#		(libft exemple)

clean: 
	$(LIBFT_DIR) $@
	$(RM) $(OBJ_DIR)

fclean: clean
	$(LIBFT_DIR) $@
	@rm -rf $(NAME)
	@rm -rf *.dSYM
#	Here don't forget to delete .a previously
#	compiled in other dir/Makefile like libft
#
#	Ex : @rm -rf $(LIBFT_DIR)libft.a

re: fclean all

.PHONY: all clean fclean re