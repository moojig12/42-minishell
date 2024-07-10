/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:44:09 by nmandakh          #+#    #+#             */
/*   Updated: 2024/07/10 14:35:00 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H 1

# include <minishell_libs.h>
# include <minishell_defs.h>

/**************** prototypes ****************/
// main.c
int			main(int argc, char **argv, char **env);

// initialize.c
t_values	*init_values(char **env);
void		reset_vals_elements(t_values *vals);

// signal.c
void		signals_process(int signum);
void		signals_hander_ignore(void);
void		sig_ignore(int signum);
int			signals_handler(void);

/**************** lex_analysis ****************/
// lex_analysis/lex_analysis.c
char		*get_next_value(char **input, t_values *vals);
int			lexical_analysis(char *input, t_values *vals);

// lex_analysis/convert.c
t_token		*token_init(void);
void		add_token_types(t_token *token);
void		remove_quote(char *value);
int			process_env_vars(t_token *token, t_values *vals);
void		convert_to_token(t_token **tokens, char *value, t_values *vals);

// lex_analysis/grammar_check.c
int			check_grammar(t_token *tokens, t_values *vals);

// lex_analysis/utils_token.c
int			check_operator(char *input);
int			is_operator(char *input);
int			count_operator_letters(char *input);
int			count_value_size(char *input);

/**************** execute ****************/
// execute/execute.c
int			child_process(t_token *tokens, int index_command, \
			int **pipe_fds_array, t_values *vals);
int			fork_process(t_token *tokens, int **pipe_fds_array, t_values *vals);
int			execute_wrapper(char *input, t_values *vals);

// execute/pipe_redirection.c
int			set_pipe_io(int command_count, int **pipe_fds_array, \
				int total_commands);
int			close_past_parent_pipe(int **pipe_fds_array, int count);

// execute/utils_execute.c
int			count_str_array(char **args);
int			count_all_tokens(t_token *tokens);
int			count_token_argc(t_token *tokens, int num_command);
int			count_commands(t_token *tokens);
char		**tokens_to_argv(t_token *tokens, int num_command);
int			is_last_command(t_token *tokens, int num_command);
void		free_pipe_vals(t_values *vals, \
	int **pipe_fds_array, int total_commands);
void		free_and_redirect(t_values *vals, char **argv, char *pgr);

/**************** redirect ****************/
// redirect/redirect.c
int			set_redirect(t_token *head, int index_command, t_values *vals);
int			reset_redirect(t_values *vals);

// redirect/redirect_*.c
int			redirect_input(t_token *temp, t_values *vals);
int			redirect_output(t_token *temp, t_values *vals);
int			redirect_heredoc(t_token *temp, t_values *vals);
int			redirect_append(t_token *token, t_values *vals);

int			redirect_heredoc_input(t_values *vals);

// redirect/redirect_util.c
t_ios		*init_ios(int save_fd, int dest_fd);
int			save_fd(int save_fd, int dest_fd, t_values *s);
int			stash_fd(int fd);
bool		is_valid_fd(int fd);

/**************** builtin ****************/
// builtin/*.c
int			builtin_echo(char **argv);
int			builtin_cd(char **argv, t_values *vals);
int			builtin_pwd(void);
int			builtin_export(char **argv, t_values *vals);
int			builtin_unset(char **argv, t_values *vals);
int			builtin_env(t_values *vals);
int			builtin_exit(char **argv);

// builtin/builtin_util.c
int			is_builtin(char *cmd);
int			execute_builtin(char **argv, t_values *vals);

/**************** utils_error_exit ****************/
// utils_error_exit/sys_error.c
int			system_error(int error_code);
int			cmd_error(int error_code);
int			red_error(int error_code);
int			tokenizer_error(int error_code);
int			parsing_tree_error(int error_code);

// utils_error_exit/error.c
void		set_error_waitpid(int status, t_values *vals);
void		error_unclosed_quote(char *message1, t_values *vals);
void		error_grammar(char *message, t_values *vals);
void		error_io(char *message, t_values *vals);
void		error_command(char *command, char *arg, char *message);

// utils_error_exit/exit_handler.c
void		exit_with_perror(char *message, t_values *vals);
void		exit_without_perror(char *message, char *file_or_cmd, \
				char **array, char *str);
void		exit_command_not_found(char *cmd, char **argv, t_values *vals);
void		exit_shell(int exit_code, t_values *vals);

/**************** utils ****************/
// utils/env.c
int			change_env(char *key, char *value, char *operation, t_values *vals);
char		**get_env_elements_array(char **envp, char *key);
char		*get_env_value(char *key);
char		*get_env_str(char **env, char *key);
char		*replace_env_var(char *str, int start, t_values *vals);
int			count_env_key(char *str);

// utils/find_pgr_path.c
char		*find_pgr(char *pgr_name, t_values *vals);

// utils/free.c
void		free_vals_elements(t_values *vals);
void		free_array(char **array);
void		free_token(t_token *head);
// void		free_vals(t_values *vals);

// utils/ft_myutils.c
int			ft_strcmp(const char *s1, const char *s2);
int			ft_isspace(char c);
char		*ft_3strjoin(char *str, char *str2, char *str3);
char		*ft_strndup(const char *s, size_t n);
int			ft_ispathkey(char *key);

// utils/int_array.c
int			**calloc_int_array(int row, int column);
void		free_int_array(int **array, int row);

// utils/node.c
t_token		*last_node(t_token *node);
void		add_to_back(t_token **tokens, t_token *new);
t_token		*get_command_head(t_token *head, int index_command);
t_token		*get_next_redirection(t_token *command_head);

/**************** test ****************/
// test/test_fd.c
int			test_fds(void);

#endif
