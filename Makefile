# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 20:01:56 by ozamora-          #+#    #+#              #
#    Updated: 2025/02/02 19:07:14 by ozamora-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# DIRECTORIES
SRC_DIR			:= src/
INC_DIR			:= inc/
OBJ_DIR			:= obj/
LIB_DIR			:= lib/
LIBFT_DIR		:= $(LIB_DIR)libft/
LIBFT_INC_DIR	:= $(LIBFT_DIR)inc/

# **************************************************************************** #
# FILES
SRC_FILES := $(wildcard $(SRC_DIR)*.c)

# INCLUDE FILES
INC_FILES := push_swap

# GENERAL FILES
SRCS    := $(SRC_FILES)
OBJS    := $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
DEPS    := $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.d)
INCS    := $(addprefix $(INC_DIR), $(addsuffix .h, $(INC_FILES)))
INCS	+= $(LIBFT_INC_DIR)libft.h

# **************************************************************************** #
# PROJECT
NAME  := push_swap
LIBFT := $(LIBFT_DIR)libft.a

# **************************************************************************** #
# COMPILER
CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror
CFLAGS	+= -MMD -MP
CFLAGS	+= -g3 -fsanitize=address
IFLAGS	:= -I$(INC_DIR) -I$(LIBFT_INC_DIR)
LDFLAGS	:= -L$(LIBFT_DIR) -lft

# **************************************************************************** #
# COLOURS

BOLD_RED   = \033[1;31m
BOLD_GREEN = \033[1;32m
BOLD_BLUE  = \033[1;34m
BOLD_YELLOW	= \033[1;33m

DEF_COLOR  = \033[0;39m
CLEAR_LINE = \033[2K

# **************************************************************************** #
# RULES

# Default rule to create the program
all: libft $(NAME)

# Rule to compile object files from source files
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@printf "%b" "$(CLEAR_LINE)$(BOLD_BLUE)[ozamora-'s push_swap]:\t$(DEF_COLOR)$<\r"
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

# Rule to create the program
$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(IFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME) 
	@printf "%b" "$(CLEAR_LINE)$(BOLD_BLUE)[ozamora-'s push_swap]:\t" \
		"$(DEF_COLOR)$(BOLD_GREEN)COMPILED$(DEF_COLOR)"
	@echo "                                          $(BOLD_YELLOW)";
	@echo "▗▄▄▖ ▗▖ ▗▖ ▗▄▄▖▗▖ ▗▖   ▗▄▄▖▗▖ ▗▖ ▗▄▖ ▗▄▄▖ ";
	@echo "▐▌ ▐▌▐▌ ▐▌▐▌   ▐▌ ▐▌  ▐▌   ▐▌ ▐▌▐▌ ▐▌▐▌ ▐▌";
	@echo "▐▛▀▘ ▐▌ ▐▌ ▝▀▚▖▐▛▀▜▌   ▝▀▚▖▐▌ ▐▌▐▛▀▜▌▐▛▀▘ ";
	@echo "▐▌   ▝▚▄▞▘▗▄▄▞▘▐▌ ▐▌  ▗▄▄▞▘▐▙█▟▌▐▌ ▐▌▐▌ by ozamora-  ";
	@echo "                                          $(DEF_COLOR)";

# Rule to make the library Libft
libft: $(LIBFT)
$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIR)

# Rule to clean generated files
clean:
	@rm -rf $(OBJ_DIR)/*.o $(OBJ_DIR)/*.d
	@$(MAKE) clean -sC $(LIBFT_DIR)
	@printf "%b" "$(CLEAR_LINE)$(BOLD_BLUE)[ozamora-'s push_swap]:\t" \
		"$(DEF_COLOR)$(BOLD_RED)OBJECTS CLEANED$(DEF_COLOR)\n"

# Rule to clean generated files and the executablle
fclean: 
	@$(MAKE) clean > /dev/null
	@$(MAKE) fclean -sC $(LIBFT_DIR)
	@rm -rf $(NAME)
	@printf "%b" "$(CLEAR_LINE)$(BOLD_BLUE)[ozamora-'s push_swap]:\t" \
		"$(DEF_COLOR)$(BOLD_RED)FULLY CLEANED$(DEF_COLOR)\n"

# Rule to recompile from zero. 
re: fclean all

# **************************************************************************** #
# Rule to check if the files pass norminette
norm:
	@norminette $(SRCS) $(INCS)

show:
	@echo "$(BOLD_YELLOW)Compilation command:$(DEF_COLOR)\t"\
		"$(CC) $(CFLAGS) $(IFLAGS) -c $(SRC_DIR)push_swap.c -o $(OBJ_DIR)push_swap.o"
	@echo "$(BOLD_YELLOW)Linking command:$(DEF_COLOR)\t"\
		"$(CC) $(CFLAGS) $(IFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)"
	@echo "$(BOLD_YELLOW)Cleaning command:$(DEF_COLOR)\t rm -rf $(OBJ_DIR)" $(NAME)

info:
	@echo "$(BOLD_YELLOW)\nozamora's push_swap:$(DEF_COLOR)"
	@echo "$(BOLD_BLUE)NAME: $(DEF_COLOR)$(NAME)"
	@echo "$(BOLD_BLUE)LIBFT: $(DEF_COLOR)$(LIBFT)"
	@echo "$(BOLD_YELLOW)\nCompiler:$(DEF_COLOR)"
	@echo "$(BOLD_BLUE)CC: $(DEF_COLOR)$(CC)"
	@echo "$(BOLD_BLUE)CFLAGS: $(DEF_COLOR)$(CFLAGS)"
	@echo "$(BOLD_BLUE)IFLAGS: $(DEF_COLOR)$(IFLAGS)"
	@echo "$(BOLD_BLUE)LDFLAGS: $(DEF_COLOR)$(LDFLAGS)"
	@echo "$(BOLD_YELLOW)\nDirectories:$(DEF_COLOR)"
	@echo "$(BOLD_BLUE)SRC_DIR: $(DEF_COLOR)$(SRC_DIR)"
	@echo "$(BOLD_BLUE)INC_DIR: $(DEF_COLOR)$(INC_DIR)"
	@echo "$(BOLD_BLUE)OBJ_DIR: $(DEF_COLOR)$(OBJ_DIR)"
	@echo "$(BOLD_BLUE)LIB_DIR: $(DEF_COLOR)$(LIB_DIR)"
	@echo "$(BOLD_BLUE)LIBFT_DIR: $(DEF_COLOR)$(LIBFT_DIR)"
	@echo "$(BOLD_BLUE)LIBFT_INC_DIR: $(DEF_COLOR)$(LIBFT_INC_DIR)"
	@echo "$(BOLD_YELLOW)\nFiles:$(DEF_COLOR)"
	@echo "$(BOLD_BLUE)SRC_FILES: $(DEF_COLOR)$(SRC_FILES)"
	@echo "$(BOLD_BLUE)INC_FILES: $(DEF_COLOR)$(INC_FILES)"
	@echo "$(BOLD_BLUE)SRCS: $(DEF_COLOR)$(SRCS)"
	@echo "$(BOLD_BLUE)OBJS: $(DEF_COLOR)$(OBJS)"
	@echo "$(BOLD_BLUE)DEPS: $(DEF_COLOR)$(DEPS)"
	@echo "$(BOLD_BLUE)INCS: $(DEF_COLOR)$(INCS)"
	@echo "$(BOLD_YELLOW)\nBonus:$(DEF_COLOR)"

valgrind: $(NAME)
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

-include $(DEPS)
.PHONY: all clean fclean re norm show info
.DEFAULT_GOAL := all

# **************************************************************************** #