# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/06 15:44:21 by ggeorgie          #+#    #+#              #
#    Updated: 2023/10/31 02:13:31 by ggeorgie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Source files and its associated 'Makefile' must be in 'libft' folder.
# Project’s 'Makefile' must compile the library by using its 'Makefile',
# and then use 'cc' to compile the project to the required output.
# Use the 'ar' archive (not 'libtool') command to create your library.
!# The resulting 'libft.a' static library / archive file has to be created at
!# the repository root.
# If applicable, add 'make bonus' rule to add the bonus functions to 'libft.a'.
# 'Makefile' must contain at least the rules:
#	* $(NAME),
#	* all (build executable/archive $(NAME) file),
#	* clean (typically, delete '.o' files and other intermediate files),
#	* fclean (full clean, i.e. clean + executable/archive $(NAME) file),
#	* re (rebuild).
# 'Makefile' uses flags and every .c file must compile with them:
#	* -Wall,
#	* -Wextra and
#	* -Werror.
# 'Makefile' must not relink. Use '-c' flag for this purpose.
#	* Use		 	$(CC) $(CFLAGS) -c $< -o $@
#	* Instead of	$(CC) $(CFLAGS) -c $(SRC)
#	* '$<' representing the source file and '$@' - the target/object file.
#	* so that only (re-)compiles only the necessary files. 
# There should be a rule to create object files.
#

# 
# Typically include in 'libft.a' archive file the header files associated
# with that static library and then link to the library when you are compiling.
# To use '.a' files with 'cc', collect all '.a' files in a 'lib/' folder and
# link with '-L lib/' and '-l<name of specific library>'.
# '.so' is a shared library (shared object), i.e. an alternative of '.a'.
# 
# 'Makefile' describes the relationships among files in the program.
# Each time one changes some source files, 'make' command suffices to perform
# all necessary recompilations. The 'make' program uses
# 'makefile' description/rules and the last-modification times of the files
# to decide which of the files need to be updated. For each of those files,
# it issues the commands recorded in the 'makefile' rules.
# 'Makefile' rules list the other files that are the dependencies of the target
# (typically a program), and commands to use to create or update the target.
# Typically there is only one target per rule.
# There can only be one set of commands to be executed for a target
# (unless '::' is used instead of ':').
# 'Makefile' default goal is the target for 'make' to consider,
# if you do not otherwise specify one.
# The default goal is the target of the first rule in the first 'makefile',
# often called 'all', and is the one for compiling the entire program
# or all the programs described by the 'makefile'.
# 
# Rule Syntax:
# targets : dependencies
#	command
#	...
# The command lines start with a 'tab' character. 
# $ (dollar signs) are used to start variable references.
# Split a long line by inserting a '\' followed by a newline.
# 'Dependencies' consist of file/archive names/wildcards ('*', '?', '[...]',
# '~') separated by spaces. The special significance of a wildcard character
# can be turned off by preceding it with a '\'.  
# 
# Typically a target/program/executable file is updated from object files.
# Object files are made by compiling source files.
#
# It seems not necessary to add 'HEADER	= libft.h' or alike. 
#
# Usage:
# make			# Build the program
# make clean	# Remove intermediate files
# make fclean	# Remove both intermediate files and the final executable
# make re		# Perform a full rebuild (clean and build again)
#
# <https://manpages.ubuntu.com/manpages/lunar/en/man1/make.1.html>
# <https://web.mit.edu/gnu/doc/html/make_4.html>
#

# Alphabetical order:
#	ft_atoi.c			OK
#	ft_bzero.c			OK
#	ft_calloc.c			OK
#	ft_isalnum.c		OK
#	ft_isalpha.c		OK
#	ft_isascii.c		OK
#	ft_isdigit.c		OK
#	ft_isprint.c		OK
#	ft_itoa.c			OK
#	ft_memchr.c			OK
#	ft_memcmp.c			OK
#	ft_memcpy.c			OK
#	ft_memmove.c		OK
#	ft_memset.c			OK
#	ft_putchar_fd.c		OK
#	ft_putendl_fd.c		OK
#	ft_putnbr_fd.c		OK
#	ft_putstr_fd.c		OK
#	ft_split.c			OK
#	ft_strchr.c			OK
#	ft_strdup.c			OK
#	ft_striteri.c		OK
#	ft_strjoin.c		OK
#	ft_strlcat.c		OK
#	ft_strlcpy.c		OK
#	ft_strlen.c			OK
#	ft_strmapi.c		OK
#	ft_strncmp.c		OK
#	ft_strnstr.c		OK
#	ft_strrchr.c		OK
#	ft_strtrim.c		OK
#	ft_substr.c			OK
#	ft_tolower.c		OK
#	ft_toupper.c		OK

NAME = libft.a

SRC = ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c

OBJ			= $(SRC:.c=.o)

CC	= cc 

CFLAGS		= -Wall -Wextra -Werror

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	ar -r -c -v $(NAME) $(OBJ)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all, clean, fclean, re
