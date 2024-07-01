/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:10:51 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/07/01 11:10:52 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	system_error(int error_code)
{
	if (error_code == MEM_ERROR)
		perror("Memorey allocation failed");
	else if (error_code == ARG_ERROR)
		perror("The arguments are invalid");
	else if (error_code == CMD_ERROR)
		perror("Error while executing the command");
	else if (error_code == FORK_ERROR)
		perror("Error while forking parent process");
	return (error_code);
}

int	cmd_error(int error_code)
{
	if (error_code == INVALID_KEY)
		perror("Invalid key name");
	else if (error_code == MANY_ERROR)
		perror("Too many arguments");
	else if (error_code == NUM_ERROR)
		perror("Numeric argument required");
	else if (error_code == ARG_ERROR)
		perror("The arguments are invalid");
	else if (error_code == CMD_ERROR)
		perror("Error while executing the command");
	else if (error_code == CMD_NOT_FOUND)
		perror("Command not found");
	else if (error_code == CMD_NOT_EXEC)
		perror("Command not executable");
	return (error_code);
}

int	red_error(int error_code)
{
	if (error_code == FILE_NF)
		perror("File not found");
	else if (error_code == RED_IN_ERR)
		perror("Failed to redirect stdin");
	else if (error_code == RED_OUT_ERR)
		perror("Failed to redirect stdout");
	else if (error_code == INVALID_FNAME)
		perror("Invalid file name");
	else if (error_code == DUP_ERROR)
		perror("Error while duplicating the fd");
	return (error_code);
}

int	tokenizer_error(int error_code)
{
	if (error_code == EOF_ERROR)
		perror("Error at End of File");
	return (error_code);
}

int	parsing_tree_error(int error_code)
{
	if (error_code == SYNTAX_ERROR)
		perror("Syntax Error");
	return (error_code);
}
