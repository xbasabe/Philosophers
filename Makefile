# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/07 14:52:36 by marvin            #+#    #+#              #
#    Updated: 2022/06/07 14:52:36 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Folders and Names
NAME		= philo
SRCSDIR		= srcs
OBJSDIR		= objs
EXTLIB		= libft

SRCS		= main.c init.c philos.c threads.c timer.c utils.c\

# Compiler options
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g #-g3 -fsanitize=address
DFLAGS		= -pthread

###################################################
# The rest is done by the MakeFile automatically, #
# you should not have to modify it				  #
###################################################
OBJS	= $(SRCS:%.c=$(OBJSDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS) $(EXTLIB)/$(EXTLIB).a
	@echo "Assembling $@"
	@$(CC) $(CFLAGS) -o $@ $(DFLAGS) $^

$(OBJS): $(OBJSDIR)/%.o: $(SRCSDIR)/%.c
	@mkdir -p $(@D)
	@echo Compiling $<
	@$(CC) $(CFLAGS) $(DFLAGS) -I$(EXTLIB)/incs -c $< -o $@

$(EXTLIB)/$(EXTLIB).a:
	@echo "Compiling $@"
	@$(MAKE) -s -C $(EXTLIB) > /dev/null

clean:
	rm -rf $(OBJSDIR)
	@$(MAKE) -s -C $(EXTLIB) clean

fclean: clean
	rm -rf $(NAME)
	@$(MAKE) -s -C $(EXTLIB) fclean

re: fclean all

.PHONY: all clean fclean re test