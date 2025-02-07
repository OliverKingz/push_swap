# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 20:01:56 by ozamora-          #+#    #+#              #
#    Updated: 2025/02/07 02:31:24 by ozamora-         ###   ########.fr        #
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
#SRC_FILES	:= $(wildcard $(SRC_DIR)*.c)
SRC_COMMON_FILES	:=	parser check stack utils exit \
						op_push op_rev_rotate op_rotate op_swap op_utils \
						sort_q 
SRC_FILES			:= 	push_swap sort sort_k $(SRC_COMMON_FILES)
SRC_BONUS_FILES		:= 	checker_bonus $(SRC_COMMON_FILES)

# INCLUDE FILES
INC_FILES	:= push_swap

# GENERAL FILES
SRCS	:= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS	:= $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
DEPS	:= $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.d)
INCS	:= $(addprefix $(INC_DIR), $(addsuffix .h, $(INC_FILES)))
INCS	+= $(LIBFT_INC_DIR)libft.h

SRCS_BONUS	:= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_BONUS_FILES)))
OBJS_BONUS	:= $(SRCS_BONUS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
DEPS_BONUS	:= $(SRCS_BONUS:$(SRC_DIR)%.c=$(OBJ_DIR)%.d)

# **************************************************************************** #
# PROJECT
NAME		:= push_swap
LIBFT		:= $(LIBFT_DIR)libft.a
BONUS_NAME	:= checker

# **************************************************************************** #
# COMPILER
CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror
CFLAGS	+= -MMD -MP
IFLAGS	:= -I$(INC_DIR) -I$(LIBFT_INC_DIR)
LDFLAGS	:= -L$(LIBFT_DIR) -lft

# DEBUG MODE
ifeq ($(DEBUG),1)
	CFLAGS += -g3 -fsanitize=address
	LDFLAGS += -fsanitize=address
endif

# VALGRIND MODE
ifeq ($(VALGRIND),1)
	CFLAGS += -g3
endif

# **************************************************************************** #
# COLOURS

BOLD_RED	= \033[1;31m
BOLD_GREEN	= \033[1;32m
BOLD_BLUE	= \033[1;34m
BOLD_YELLOW	= \033[1;33m

DEF_COLOR	= \033[0;39m
CLEAR_LINE	= \033[2K

# **************************************************************************** #
# ESSENTIAL RULES

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
	@rm -rf $(OBJ_DIR)/*.o $(OBJ_DIR)/*.d $(OBJ_DIR)
	@$(MAKE) clean -sC $(LIBFT_DIR)
	@printf "%b" "$(CLEAR_LINE)$(BOLD_BLUE)[ozamora-'s push_swap]:\t" \
		"$(DEF_COLOR)$(BOLD_RED)OBJECTS CLEANED$(DEF_COLOR)\n"

# Rule to clean generated files and the executablle
fclean: 
	@$(MAKE) clean > /dev/null
	@$(MAKE) fclean -sC $(LIBFT_DIR)
	@rm -rf $(NAME) $(BONUS_NAME)
	@printf "%b" "$(CLEAR_LINE)$(BOLD_BLUE)[ozamora-'s push_swap]:\t" \
		"$(DEF_COLOR)$(BOLD_RED)FULLY CLEANED$(DEF_COLOR)\n"

# Rule to recompile from zero. 
re: fclean all

# **************************************************************************** #
# CHECKER / BONUS RULES
bonus: libft $(BONUS_NAME)
$(BONUS_NAME): $(OBJS_BONUS)
	@$(CC) $(CFLAGS) $(IFLAGS) $(OBJS_BONUS) $(LDFLAGS) -o $(BONUS_NAME) 
	@printf "%b" "$(CLEAR_LINE)$(BOLD_BLUE)[ozamora-'s checker]:\t" \
		"$(DEF_COLOR)$(BOLD_GREEN)COMPILED$(DEF_COLOR)\n"

# **************************************************************************** #
# NORM AND DEBUG RULES

# Rule to check if the files pass norminette
norm:
	@norminette $(SRCS) $(INCS)

# Rule to compile object files from source files with debug flags
debug:
	@$(MAKE) clean > /dev/null
	@$(MAKE) bonus -s DEBUG=1
	@$(MAKE) -s DEBUG=1
	@echo "$(BOLD_YELLOW)[DEBUG MODE]$(DEF_COLOR)"
	-@if [ ! -z "$(ARGS)" ]; then ./$(NAME) $(ARGS); fi
	@echo "\n$(BOLD_YELLOW)[DEBUG MODE WITH MY CHECKER]$(DEF_COLOR)"
	-@if [ ! -z "$(ARGS)" ]; then ./$(NAME) $(ARGS) | ./$(BONUS_NAME) $(ARGS); fi
	@echo "\n$(BOLD_YELLOW)[DEBUG MODE WITH OG CHECKER]$(DEF_COLOR)"
	-@if [ ! -z "$(ARGS)" ]; then ./$(NAME) $(ARGS) | ./checker_linux $(ARGS); fi

# Rule to compile with valgrind debug flags
valgrind:
	@$(MAKE) clean > /dev/null
	@$(MAKE) bonus -s VALGRIND=1
	@$(MAKE) -s VALGRIND=1
	@echo "$(BOLD_YELLOW)[VALGRIND MODE]$(DEF_COLOR)"
	-@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $(ARGS)
	@echo "\n$(BOLD_YELLOW)[VALGRIND MODE WITH MY CHECKER]$(DEF_COLOR)"
	-@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $(ARGS) | ./$(BONUS_NAME) $(ARGS)
	@echo "\n$(BOLD_YELLOW)[VALGRIND MODE WITH OG CHECKER]$(DEF_COLOR)"
	-@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $(ARGS) | ./checker_linux $(ARGS)

# **************************************************************************** #
# ADDITIONAL RULES

# Rule to show compilation and linking commands
show:
	@echo "$(BOLD_YELLOW)Compilation command:$(DEF_COLOR)\t"\
		"$(CC) $(CFLAGS) $(IFLAGS) -c $(SRC_DIR)push_swap.c -o $(OBJ_DIR)push_swap.o"
	@echo "$(BOLD_YELLOW)Linking command:$(DEF_COLOR)\t"\
		"$(CC) $(CFLAGS) $(IFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)"
	@echo "$(BOLD_YELLOW)Cleaning command:$(DEF_COLOR)\t rm -rf $(OBJ_DIR)" $(NAME)

# Rule to show all variables being used
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

-include $(DEPS) $(DEPS_BONUS)
.PHONY: all clean fclean re bonus norm debug valgrind show info
.DEFAULT_GOAL := all

# **************************************************************************** #