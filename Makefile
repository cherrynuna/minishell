# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/15 10:32:17 by jjhang            #+#    #+#              #
#    Updated: 2024/06/16 15:42:51 by jjhang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address
READLINE = readline
NAME = minishell
BONUS = minishell_bonus
LIBFT = libft/libft.a

EXPAND_DIR = ms_expand
EXECUTE_DIR = ms_execute
PARSER_DIR = ms_parser

B_EXPAND_DIR = ms_expand_bonus
B_EXECUTE_DIR = ms_execute_bonus
B_PARSER_DIR = ms_parser_bonus

OBJ_DIR = obj
B_OBJ_DIR = obj_bonus
LIBFT_DIR = libft
HEADER_DIR = include

EXPAND_FILES = expand.c \
				wildcard1.c \
				wildcard2.c \
				wildcard3.c \
				ctl_quote1.c \
				ctl_quote2.c \
				replace_w.c \
				wildcard_preprocess.c \
				expand_wo_q.c

EXECUTE_FILES = main.c \
				appending_output.c \
				builtin_error_handler.c \
				child_process.c \
				delete_env_lst.c \
				execute_cmd.c \
				free_exe_data.c \
				ft_cd1.c \
				ft_cd2.c \
				ft_echo.c \
				ft_env.c \
				ft_exit.c \
				ft_export1.c \
				ft_export2.c \
				is_relative_cmd.c \
				ft_free.c \
				ft_getenv_from_node.c \
				ft_here_doc.c \
				ft_pwd.c \
				ft_unset.c \
				get_env_arr.c \
				get_env_lst.c \
				input_redirection.c \
				is_able_to_envname.c \
				is_builtin_function.c \
				is_cmd.c \
				manage_pwd.c \
				manage_shell_level.c \
				minishell_preprocess.c \
				output_redirection.c \
				parent_process.c \
				paser_level_exitnum_handler.c \
				print_env_lst.c \
				print_tree.c \
				recursive_exe_utils.c \
				recursive_exe.c \
				redirection_flag_ctl.c \
				redirection_process.c \
				set_ctl_cmd.c \
				signal_functions.c \
				wait_process.c

PARSER_FILES = delete_tree_all.c \
			error_handler.c \
			get_ctl_cmd.c \
			get_additional_input.c \
			get_last_node.c \
			get_next_token.c \
			get_pipe.c \
			get_redireaction.c \
			get_subshell1.c \
			get_subshell2.c \
			get_variable.c \
			get_word1.c \
			get_word2.c \
			is_another_ctl_cmd.c \
			is_control_cmd.c \
			is_control_oprator.c \
			is_meta_charater.c \
			is_whitespace.c \
			minishell_parser.c \
			new_tree_node.c

B_EXPAND_FILES = expand_bonus.c \
				wildcard1_bonus.c \
				wildcard2_bonus.c \
				wildcard3_bonus.c \
				ctl_quote1_bonus.c \
				ctl_quote2_bonus.c \
				replace_w_bonus.c \
				wildcard_preprocess_bonus.c \
				expand_wo_q_bonus.c

B_EXECUTE_FILES = main_bonus.c \
				appending_output_bonus.c \
				builtin_error_handler_bonus.c \
				child_process_bonus.c \
				delete_env_lst_bonus.c \
				execute_cmd_bonus.c \
				free_exe_data_bonus.c \
				ft_cd1_bonus.c \
				ft_cd2_bonus.c \
				ft_echo_bonus.c \
				ft_env_bonus.c \
				ft_exit_bonus.c \
				ft_export1_bonus.c \
				ft_export2_bonus.c \
				is_relative_cmd_bonus.c \
				ft_free_bonus.c \
				ft_getenv_from_node_bonus.c \
				ft_here_doc_bonus.c \
				ft_pwd_bonus.c \
				ft_unset_bonus.c \
				get_env_arr_bonus.c \
				get_env_lst_bonus.c \
				input_redirection_bonus.c \
				is_able_to_envname_bonus.c \
				is_builtin_function_bonus.c \
				is_cmd_bonus.c \
				manage_pwd_bonus.c \
				manage_shell_level_bonus.c \
				minishell_preprocess_bonus.c \
				output_redirection_bonus.c \
				parent_process_bonus.c \
				paser_level_exitnum_handler_bonus.c \
				print_env_lst_bonus.c \
				print_tree_bonus.c \
				recursive_exe_utils_bonus.c \
				recursive_exe_bonus.c \
				redirection_flag_ctl_bonus.c \
				redirection_process_bonus.c \
				set_ctl_cmd_bonus.c \
				signal_functions_bonus.c \
				wait_process_bonus.c

B_PARSER_FILES = delete_tree_all_bonus.c \
			error_handler_bonus.c \
			get_ctl_cmd_bonus.c \
			get_additional_input_bonus.c \
			get_last_node_bonus.c \
			get_next_token_bonus.c \
			get_pipe_bonus.c \
			get_redireaction_bonus.c \
			get_subshell1_bonus.c \
			get_subshell2_bonus.c \
			get_variable_bonus.c \
			get_word1_bonus.c \
			get_word2_bonus.c \
			is_another_ctl_cmd_bonus.c \
			is_control_cmd_bonus.c \
			is_control_oprator_bonus.c \
			is_meta_charater_bonus.c \
			is_whitespace_bonus.c \
			minishell_parser_bonus.c \
			new_tree_node_bonus.c

EXPAND_SRCS = $(addprefix $(EXPAND_DIR)/, $(EXPAND_FILES))
EXECUTE_SRCS = $(addprefix $(EXECUTE_DIR)/, $(EXECUTE_FILES))
PARSER_SRCS = $(addprefix $(PARSER_DIR)/, $(PARSER_FILES))

B_EXPAND_SRCS = $(addprefix $(B_EXPAND_DIR)/, $(B_EXPAND_FILES))
B_EXECUTE_SRCS = $(addprefix $(B_EXECUTE_DIR)/, $(B_EXECUTE_FILES))
B_PARSER_SRCS = $(addprefix $(B_PARSER_DIR)/, $(B_PARSER_FILES))

OBJS = $(EXECUTE_FILES:%.c=$(OBJ_DIR)/%.o) \
		$(PARSER_FILES:%.c=$(OBJ_DIR)/%.o) \
		$(EXPAND_FILES:%.c=$(OBJ_DIR)/%.o)

B_OBJS = $(B_EXECUTE_FILES:%.c=$(B_OBJ_DIR)/%.o) \
		$(B_PARSER_FILES:%.c=$(B_OBJ_DIR)/%.o) \
		$(B_EXPAND_FILES:%.c=$(B_OBJ_DIR)/%.o)

HEADER = $(HEADER_DIR)

all : $(LIBFT) $(NAME)

bonus : $(LIBFT) $(BONUS)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -L$(LIBFT_DIR) -l$(READLINE) -o $(NAME) $^

$(BONUS) : $(LIBFT) $(B_OBJS)
	$(CC) $(CFLAGS) -L$(LIBFT_DIR) -l$(READLINE) -o $(BONUS) $^
	touch bonus

$(OBJ_DIR)/%.o : $(EXECUTE_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $< -I $(HEADER_DIR) -I $(LIBFT_DIR)

$(OBJ_DIR)/%.o : $(PARSER_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $< -I $(HEADER_DIR) -I $(LIBFT_DIR)

$(OBJ_DIR)/%.o : $(EXPAND_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $< -I $(HEADER_DIR) -I $(LIBFT_DIR)

$(B_OBJ_DIR)/%.o : $(B_EXECUTE_DIR)/%.c | $(B_OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $< -I $(HEADER_DIR) -I $(LIBFT_DIR)

$(B_OBJ_DIR)/%.o : $(B_PARSER_DIR)/%.c | $(B_OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $< -I $(HEADER_DIR) -I $(LIBFT_DIR)

$(B_OBJ_DIR)/%.o : $(B_EXPAND_DIR)/%.c | $(B_OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $< -I $(HEADER_DIR) -I $(LIBFT_DIR)

$(OBJ_DIR) :
	mkdir -p $@

$(B_OBJ_DIR) :
	mkdir -p $@

clean :
	rm -f $(OBJS) $(B_OBJS) bonus
	rm -rf $(OBJ_DIR) $(B_OBJ_DIR)
	make -C $(LIBFT_DIR) clean

fclean : clean
	rm -f $(NAME) $(BONUS)
	make -C $(LIBFT_DIR) fclean

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all clean fclean re
