# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 20:01:56 by ozamora-          #+#    #+#              #
#    Updated: 2025/02/07 12:22:19 by ozamora-         ###   ########.fr        #
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
BUILD_MODE_FILE := .build_mode

ifeq ($(DEBUG),1)
	CFLAGS += -g3 -fsanitize=address
	LDFLAGS += -fsanitize=address
endif

# VALGRIND MODE
ifeq ($(VALGRIND),1)
	CFLAGS += -g3
endif

# **************************************************************************** #
# COLOURS: BOLD RGBY
BR	= \033[1;31m
BG	= \033[1;32m
BB	= \033[1;34m
BY	= \033[1;33m

# NO COLOR and CLEAR LINE
NC	= \033[0;39m
CL	= \033[2K

# **************************************************************************** #
# ESSENTIAL RULES

# Default rule to create the program
all: libft $(NAME)

# Rule to create the program
$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(IFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@printf "%b" "$(CL) -> $(BB)[push_swap]:\t$(BG)Compilation success\t✅$(NC)\n"
	@echo "─────────────────────────────────────────────────────$(BY)"
	@echo "▗▄▄▖ ▗▖ ▗▖ ▗▄▄▖▗▖ ▗▖   ▗▄▄▖▗▖ ▗▖ ▗▄▖ ▗▄▄▖ ";
	@echo "▐▌ ▐▌▐▌ ▐▌▐▌   ▐▌ ▐▌  ▐▌   ▐▌ ▐▌▐▌ ▐▌▐▌ ▐▌";
	@echo "▐▛▀▘ ▐▌ ▐▌ ▝▀▚▖▐▛▀▜▌   ▝▀▚▖▐▌ ▐▌▐▛▀▜▌▐▛▀▘ ";
	@echo "▐▌   ▝▚▄▞▘▗▄▄▞▘▐▌ ▐▌  ▗▄▄▞▘▐▙█▟▌▐▌ ▐▌▐▌ by ozamora-  \n";
	@echo "$(NC)─────────────────────────────────────────────────────"

# Rule to compile object files from source files
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@printf "%b" "$(CL) -> $(BB)[push_swap]:\t$(NC)$<\r"
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

# Rule to make the library Libft
libft: $(LIBFT)
$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIR)

# Rule to clean generated files
clean:
	@rm -rf $(OBJ_DIR)/*.o $(OBJ_DIR)/*.d $(OBJ_DIR)
	@rm -f $(BUILD_MODE_FILE)
	@$(MAKE) clean -sC $(LIBFT_DIR)
	@printf "%b" "$(CL) -> $(BB)[push_swap]:\t$(BG)Object files cleaned\t❎$(NC)\n"

# Rule to clean generated files and the executablle
fclean: 
	@$(MAKE) clean > /dev/null
	@$(MAKE) fclean -sC $(LIBFT_DIR)
	@rm -rf $(NAME) $(BONUS_NAME)
	@printf "%b" "$(CL) -> $(BB)[push_swap]:\t$(BG)Executable cleaned\t❎$(NC)\n"

# Rule to recompile from zero. 
re: fclean all

# **************************************************************************** #
# CHECKER / BONUS RULES
bonus: libft $(BONUS_NAME)
$(BONUS_NAME): $(OBJS_BONUS)
	@$(CC) $(CFLAGS) $(IFLAGS) $(OBJS_BONUS) $(LDFLAGS) -o $(BONUS_NAME) 
	@printf "%b" "$(CL) -> $(BB)[checker]:\t\t$(BG)Compilation success\t✅$(NC)\n"

# **************************************************************************** #
# NORM AND DEBUG RULES

# Rule to check if the files pass norminette
norm:
	@norminette $(SRCS) $(INCS)

# Rule to compile object files from source files with debug flags
debug:
	@if [ ! -f $(BUILD_MODE_FILE) ] || ! grep -q "DEBUG=1" $(BUILD_MODE_FILE); \
	then \
		$(MAKE) clean -s; \
	fi
	@echo "DEBUG=1" > $(BUILD_MODE_FILE)
	@$(MAKE) bonus -s DEBUG=1
	@$(MAKE) -s DEBUG=1
	@echo " -> $(BB)[Debug]:\t$(BG)Debug mode enabled\t🟦$(NC)"
	-@if [ ! -z "$(ARGS)" ]; then ./$(NAME) $(ARGS); fi
	@echo "\n -> $(BB)[Debug]:\t$(BG)Debug w/ my Checker\t🟦$(NC)"
	-@if [ ! -z "$(ARGS)" ]; then ./$(NAME) $(ARGS) | ./$(BONUS_NAME) $(ARGS); fi
	@echo "\n -> $(BB)[Debug]:\t$(BG)Debug w/ og Checker\t🟦$(NC)"
	-@if [ ! -z "$(ARGS)" ]; then ./$(NAME) $(ARGS) | ./checker_linux $(ARGS); fi

# Rule to compile with valgrind debug flags
valgrind:
	@if [ ! -f $(BUILD_MODE_FILE) ] || ! grep -q "VALGRIND=1" $(BUILD_MODE_FILE); then \
		$(MAKE) clean -s;\
	fi
	@echo "VALGRIND=1" > $(BUILD_MODE_FILE)
	@$(MAKE) bonus -s VALGRIND=1
	@$(MAKE) -s VALGRIND=1
	@echo " -> $(BB)[Valgrind]:\t$(BG)Valgrind mode enabled\t🟦$(NC)"
	-@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $(ARGS)
	@echo "\n -> $(BB)[Valgrind]:\t$(BG)Valgrind with my Checker\t🟦$(NC)"
	-@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $(ARGS) | ./$(BONUS_NAME) $(ARGS)
	@echo "\n -> $(BB)[Valgrind]:\t$(BG)Valgrind with og Checker\t🟦$(NC)"
	-@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $(ARGS) | ./checker_linux $(ARGS)

# **************************************************************************** #
# ADDITIONAL RULES

# Rule to show compilation and linking commands
show:
	@echo "$(BY)Compilation command:$(NC)\t"\
		"$(CC) $(CFLAGS) $(IFLAGS) -c $(SRC_DIR)push_swap.c -o $(OBJ_DIR)push_swap.o"
	@echo "$(BY)Linking command:$(NC)\t"\
		"$(CC) $(CFLAGS) $(IFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)"
	@echo "$(BY)Cleaning command:$(NC)\t rm -rf $(OBJ_DIR)" $(NAME)

# Rule to show all variables being used
info:
	@echo "$(BY)\nozamora's push_swap:$(NC)"
	@echo "$(BB)NAME: $(NC)$(NAME)"
	@echo "$(BB)LIBFT: $(NC)$(LIBFT)"
	@echo "$(BY)\nCompiler:$(NC)"
	@echo "$(BB)CC: $(NC)$(CC)"
	@echo "$(BB)CFLAGS: $(NC)$(CFLAGS)"
	@echo "$(BB)IFLAGS: $(NC)$(IFLAGS)"
	@echo "$(BB)LDFLAGS: $(NC)$(LDFLAGS)"
	@echo "$(BY)\nDirectories:$(NC)"
	@echo "$(BB)SRC_DIR: $(NC)$(SRC_DIR)"
	@echo "$(BB)INC_DIR: $(NC)$(INC_DIR)"
	@echo "$(BB)OBJ_DIR: $(NC)$(OBJ_DIR)"
	@echo "$(BB)LIB_DIR: $(NC)$(LIB_DIR)"
	@echo "$(BB)LIBFT_DIR: $(NC)$(LIBFT_DIR)"
	@echo "$(BB)LIBFT_INC_DIR: $(NC)$(LIBFT_INC_DIR)"
	@echo "$(BY)\nFiles:$(NC)"
	@echo "$(BB)SRC_FILES: $(NC)$(SRC_FILES)"
	@echo "$(BB)INC_FILES: $(NC)$(INC_FILES)"
	@echo "$(BB)SRCS: $(NC)$(SRCS)"
	@echo "$(BB)OBJS: $(NC)$(OBJS)"
	@echo "$(BB)DEPS: $(NC)$(DEPS)"
	@echo "$(BB)INCS: $(NC)$(INCS)"
	@echo "$(BY)\nBonus:$(NC)"
	@echo "$(BB)BONUS_NAME: $(NC)$(BONUS_NAME)"
	@echo "$(BB)SRC_BONUS_FILES: $(NC)$(SRC_BONUS_FILES)"
	@echo "$(BB)SRCS_BONUS: $(NC)$(SRCS_BONUS)"
	@echo "$(BB)OBJS_BONUS: $(NC)$(OBJS_BONUS)"
	@echo "$(BB)DEPS_BONUS: $(NC)$(DEPS_BONUS)"


-include $(DEPS) $(DEPS_BONUS)
.PHONY: all clean fclean re bonus norm debug valgrind show info
.DEFAULT_GOAL := all

# **************************************************************************** #