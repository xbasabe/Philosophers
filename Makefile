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
BONUS_NAME	= philo_bonus
SRCSDIR		= srcs
BONUSDIR	= bonus
OBJSDIR		= objs
B_OBJSDIR	= objs_bonus
EXTLIB		= libft

SRCS		= main.c init.c philos.c threads.c timer.c utils.c\
BONUS		= main_bonus.c init_bonus.c philos_bonus.c threads_bonus.c timer_bonus.c utils_bonus.c\

# Compiler options
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g #-g3 -fsanitize=address
DFLAGS		= -pthread

###################################################
# The rest is done by the MakeFile automatically, #
# you should not have to modify it				  #
###################################################
OBJS	= $(SRCS:%.c=$(OBJSDIR)/%.o)
BONUS_OBJS	= $(BONUS:%.c=$(B_OBJSDIR)/%.o)

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
	rm -rf $(BONUSDIR)
	@$(MAKE) -s -C $(EXTLIB) clean

fclean: clean
	rm -rf $(NAME)
	rm -rf $(BONUS_NAME)
	@$(MAKE) -s -C $(EXTLIB) fclean

re: fclean all

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(EXTLIB)/$(EXTLIB).a
	@echo "Assembling $@"
	@$(CC) $(CFLAGS) -o $@ $(DFLAGS) $^

$(BONUS_OBJS): $(B_OBJSDIR)/%.o: $(BONUSDIR)/%.c
	@mkdir -p $(@D)
	@echo Compiling $<
	@$(CC) $(CFLAGS) $(DFLAGS) -I$(EXTLIB)/incs -c $< -o $@

$(EXTLIB)/$(EXTLIB).a:
	@echo "Compiling $@"
	@$(MAKE) -s -C $(EXTLIB) > /dev/null

.PHONY: all clean fclean re bonus test