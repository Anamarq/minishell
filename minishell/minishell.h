/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:00:57 by pespinos          #+#    #+#             */
/*   Updated: 2023/10/14 18:39:36 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/ioctl.h>
# include <errno.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	100
# endif

typedef struct s_node
{
	int		fd_in;
	int		fd_out;
	char	**cmds;
	char	*cmd_path;
	int		num_cmds;
	int		is_here_doc;
	char	*hd_delim;
}	t_node;

typedef struct s_all
{
	int		*map;
	int		map_elements;
	int		close_position;
	char	*str_order;
	t_node	*nodes;
	int		npipes;
	char	**cmds_separate;
	char	**envp;
	int		dim_env;
	int		execution_estatus;
	int		length_order;
	int		*comillas;
	int		ctrl_c;
	int		is_com;
}	t_all;

typedef struct s_separate_array_data
{
	int		i;
	int		j;
	int		k;
	char	***matrix;
}	t_separate_array_data;

typedef struct s_join_array_data
{
	int		i;
	int		j;
	int		k;
	char	**array;
	char	***matrix;
}	t_join_array_data;

typedef struct s_separator_data
{
	char	*result;
	int		n;
	int		p;
}	t_separator_data;

typedef struct s_itoa_data
{
	int		sign;
	int		len;
	char	*result;
}	t_itoa_data;

typedef struct s_convert_colons_data
{
	char	*str_return;
	int		ignore_limit;
	int		n;
	int		i;
	int		*new_map;
}	t_convert_colons_data;

typedef struct s_data_check_env_vars
{
	char	*str;
	int		n;
	char	***strsep;
	char	*word;
	char	*var_expand;
}	t_data_check_env_vars;

t_all	g_data;

void	ft_putstr(char *str, int fd);
int		ft_strlen(char const *str);
char	*ft_strdup(char *src);
char	*ft_substr(char const *s, int start, int len);
char	*ft_strjoin(char *str1, char *str2);
int		ft_num_words(char const *s, char c);
char	**ft_split(char const *s, char c);
char	**ft_split2(char const *s, char c);
void	ft_add_history(char *str);
char	*ft_print_entry(char *msg);
int		*ft_create_map(int n_elements);
void	ft_print_map(int *map);
void	ft_fill_map(int start_position, int end_position, int value);
char	*ft_straddchar(char *str, char letter);
int		ft_check_open(char letter, int position);
int		ft_check_str(void);
int		ft_search_char(char letter);
int		ft_count_rows(char ***str);
int		ft_count_rows_2d(char **str);
char	***ft_allocate_matrix(int number_rows, int number_columns);
void	ft_initialize_separate_array_data(t_separate_array_data *d);
void	ft_increment_j_k_separate(t_separate_array_data *d);
char	***separate_array(char **array);
char	**ft_allocate_array(int number_rows);
void	ft_initialize_join_array_data(t_join_array_data *d);
void	ft_increment_j_k_join(t_join_array_data *d);
char	**join_array(char ***matrix);
int		ft_check_exist_var(char ***env_vars, char *name_var);
char	*ft_get_word(char *str, int position);
char	*ft_expand_var(char ***env_vars, char *str);
void	ft_free_char_3d(char ***to_free);
char	*ft_check_env_vars(void);
void	ft_control_c(int sig);
int		ft_control_d(void);
void	ft_init_signals(void);
void	ft_str_copy(char *str_origin, char *str_destiny);
int		ft_check_chars(char letter, char *str);
int		ft_number_characters(char *str);
void	ft_conditions_ft_separator(t_separator_data *d, char *str);
char	*ft_separator(char *str);
int		ft_len(int n);
void	ft_loop_itoa(t_itoa_data *d, int n);
char	*ft_itoa(int n);
int		ft_find_ignore_limit(char *str, int start_position);
int		ft_init_convert_colons_data(t_convert_colons_data *d);
void	ft_convert_colons_conditions(t_convert_colons_data *d);
char	*ft_convert_colons(void);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_ind(const char *str, char c);
int		ft_strcmp(char *s1, char *s2);
int		ft_strcmp2(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strcpy(char *dst, const char *src);
char	*ft_conect(char *buffer, char *tab);
char	*ft_readline(char *buffer, int fd);
char	*ft_next_buffer(char *buffer);
char	*get_next_line(int fd);
char	**look_4_paths(char **envp);
void	add_bar(char **paths);
char	*test_paths(char **paths, char *cmd);
char	*get_cmd_path(char *cmd, char **envp);
void	ft_put_str(char *str, int fd);
void	ft_echo(char *str, int n, int fd);
void	is_echo(int n, int fd);
char	***ft_unset(char ***env_vars, char *name_var);
char	***ft_export(char ***env_vars, char *name_var, char *value_var);
void	ft_exit(int code);
void	ft_pwd(int fd);
int		ft_cd(char *ruta);
int		ft_env(char **envp, int fd);
void	ft_buildin_condition(int n);
void	buildin(char *cmd, int n, int fd);
int		is_buildin(char *cmd);
char	**malloc_array(int dim);
char	**create_array_execve(int i);
void	nopip_nobuildin(void);
void	ft_check_pid(pid_t pid1);
void	nopip(void);
int		**reserve_memory_pipes(void);
pid_t	*reserve_memory_pids(void);
void	open_close_pipes(int i, int **pipes);
void	execve_pipes(int i, int **pipes);
void	pipes_buildin(int i, int **pipes);
int		execute_pipes(int **pipes, pid_t *pids, int i);
void	close_and_wait_pipes(int **pipes, pid_t *pids);
int		pipesdef(void);
void	read_files_heredoc2(void);
void	read_files_heredoc(int n);
void	num_pipes2(char c, int *nc, int *n_pipes, int n);
int		ft_number_pipes(char *str);
void	initialize(void);
char	**copy_2d(char **envp);
void	is_pipe(int *i, int *n, int *icmd);
int		print_error(int type);
int		redirection2(int *i, int *n);
int		redirection(int *i, int *n);
int		is_redir(char *str);
int		is_redir2(char *str);
int		cmd_pipes_or_redir(int *i, int *n, int *icmd, int *ip);
int		get_cmds2(int *i, int *n, int *icmd, int *is);
int		get_cmds(void);
int		paths_and_heredoc(void);
int		reserve_nodes_memory(void);
void	free_nodes(void);
void	free_cmd_separate(void);
void	pipe_next_to_redirection(void);
char	*ft_separar(char *buffer);
void	open_pipe(void);
void	run_commands2(void);
int		run_commands(void);
int		main_loop(void);
void	free_2d(char **to_free);
void	free_cmdpath(void);
#endif