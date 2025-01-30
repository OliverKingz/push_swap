# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 20:01:56 by ozamora-          #+#    #+#              #
#    Updated: 2024/12/03 16:48:59 by ozamora-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# COMMANDS
MKDIR		:= mkdir -p
RM			:= rm -rf
PRINTF		:= printf "%b"
MAKE_LIB	:= make -sC
CP			:= cp -p

# **************************************************************************** #
# DIRECTORIES
SRC_DIR			:= src/
INC_DIR			:= inc/
OBJ_DIR			:= obj/
LIB_DIR			:= lib/
LIBFT_DIR		:= libft/
LIBFT_INC_DIR	:= $(LIBFT_DIR)inc/

# **************************************************************************** #
# FILES
SRC_FILES := $(wildcard $(SRC_DIR)*.c)

# INCLUDE FILES
INC_FILES := push_swap

# GENERAL FILES
SRCS    := $(SRC_FILES)
OBJS    := $(addprefix $(OBJ_DIR), $(notdir $(SRC_FILES:.c=.o)))
DEPS    := $(addprefix $(OBJ_DIR), $(notdir $(SRC_FILES:.c=.d)))
INCS    := $(addprefix $(INC_DIR), $(addsuffix .h, $(INC_FILES)))
INCS	+= $(LIBFT_INC_DIR)libft.h

# **************************************************************************** #
# COMPILER
CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror
CFLAGS	+= -g3 -fsanitize=address
CFLAGS	+= -MMD -MP
IFLAGS	:= -I$(INC_DIR) -I$(LIBFT_INC_DIR)
LDFLAGS	:= -L$(LIBFT_DIR) -lft

# **************************************************************************** #
# PROJECT
NAME  := push_swap
LIBFT := $(LIBFT_DIR)libft.a

# **************************************************************************** #
# COLOURS

BOLD_RED   = \033[1;31m
BOLD_GREEN = \033[1;32m
BOLD_BLUE  = \033[1;34m

DEF_COLOR  = \033[0;39m
CLEAR_LINE = \033[2K

# **************************************************************************** #
# RULES
-include $(DEPS)

# Default rule to create the program
all: $(NAME)

# Rule to compile object files from source files
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(MKDIR) $(dir $@)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

# Rule to create the program
$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(IFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)
	@$(PRINTF) "$(CLEAR_LINE)$(BOLD_BLUE)\t[ozamora-'s push_swap]:\t" \
		"$(DEF_COLOR)$(BOLD_GREEN)COMPILED$(DEF_COLOR)\n"

# Rule to make the library
$(LIBFT):
	@$(MAKE_LIB) $(LIBFT_DIR)

# Rule to clean generated files
clean:
	@$(RM) $(OBJ_DIR)
	@make clean -sC $(LIBFT_DIR)
	@$(PRINTF) "$(CLEAR_LINE)$(BOLD_BLUE)\t[ozamora-'s push_swap]:\t" \
		"$(DEF_COLOR)$(BOLD_RED)OBJECTS CLEANED$(DEF_COLOR)\n"

# Rule to clean generated files and the executablle
fclean: 
	@make clean > /dev/null
	@$(RM) $(NAME) $(LIB_DIR)
	@make fclean -sC $(LIBFT_DIR)
	@$(PRINTF) "$(CLEAR_LINE)$(BOLD_BLUE)\t[ozamora-'s push_swap]:\t" \
		"$(DEF_COLOR)$(BOLD_RED)FULLY CLEANED$(DEF_COLOR)\n"

# Rule to recompile from zero. 
re: fclean all

# Rule to check if the files pass norminette
norm:
	@norminette $(SRCS) $(INCS)

show:
	@echo "Compilation command:\t"\
		"$(CC) $(CFLAGS) $(IFLAGS) -c $(SRC_DIR)push_swap.c -o $(OBJ_DIR)push_swap.o"
	@echo "Linking command:\t"\
		"$(CC) $(CFLAGS) $(IFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)"
	@echo "Cleaning command:\t $(RM) $(OBJ_DIR) $(LIB_DIR)" $(NAME)

info:
	@echo "NAME: $(NAME)"
	@echo "LIBFT: $(LIBFT)"
	@echo "CC: $(CC)"
	@echo "CFLAGS: $(CFLAGS)"
	@echo "IFLAGS: $(IFLAGS)"
	@echo "LDFLAGS: $(LDFLAGS)"
	@echo "MKDIR: $(MKDIR)"
	@echo "RM: $(RM)"
	@echo "PRINTF: $(PRINTF)"
	@echo "MAKE_LIB: $(MAKE_LIB)"
	@echo "CP: $(CP)"
	@echo "SRC_DIR: $(SRC_DIR)"
	@echo "INC_DIR: $(INC_DIR)"
	@echo "OBJ_DIR: $(OBJ_DIR)"
	@echo "LIB_DIR: $(LIB_DIR)"
	@echo "LIBFT_DIR: $(LIBFT_DIR)"
	@echo "LIBFT_INC_DIR: $(LIBFT_INC_DIR)"
	@echo "SRC_FILES: $(SRC_FILES)"
	@echo "INC_FILES: $(INC_FILES)"
	@echo "SRCS: $(SRCS)"
	@echo "OBJS: $(OBJS)"
	@echo "DEPS: $(DEPS)"
	@echo "INCS: $(INCS)"

valgrind: $(NAME)
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

# Phony targets
.PHONY: all clean fclean re norm show info

# **************************************************************************** #