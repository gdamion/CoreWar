/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_error.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 14:43:13 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/17 14:04:20 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** FILE FOR ASM ERROR DEFINITIONS
*/

#ifndef ASM_ERROR_H
# define ASM_ERROR_H

# include "com.h"

# define ERR_NOFILE "./asm recieves wrong number of arguments"
# define ERR_FNAME "Given file has wrong name format"
# define ERR_FOPEN "Can\'t open file" // sys error
# define ERR_READING "Can\'t read file" // sys error
# define ERR_ALLOC "Can\'t allocate memory" // sys error
# define ERR_GET_TEXT "Can't read content token"
# define ERR_GET_NUMBER "Can't read numerical token"
# define ERR_CHNAME_LEN "Champion\'s name is too large"
# define ERR_NO_CHNAME "Champion\'s name doesn't exist"
# define ERR_CHCOMM_LEN "Champion\'s comment is too large"
# define ERR_NO_CHCOMM "Champion\'s comment doesn't exist"
# define ERR_NAMECOM "Wrong number of champion\'s names/comments"
# define ERR_SYM "Wrong symbol"
# define ERR_TOKEN "It should be sepatated char"
# define ERR_OP "This operator doesn\'t exist"
# define ERR_ARGNO "Wrong number of operator\'s arguments"
# define ERR_ARGTP "Wrong type of operator\'s arguments"
# define ERR_SEP "Lost symbol of separator"
# define ERR_ARG_PLUS "+ symbol in the argument\'s value"
# define ERR_MULT_INST "Multiple instuctions on one line"
# define ERR_LABEL_CH "Wrong characters in the label\'s name"
# define ERR_LABEL_ECH "Wrong ending label character"
# define ERR_LABEL_EX "This label doesn\'t exist"
# define ERR_ZERO_REG "Register r0 (r00) is used, but it doesn\'t exist"
# define ERR_BIGEX "Executable code has size bigger than a limit"
# define ERR_CRFHEX "Can\'t create machine-code file"
# define ERR_WRFHEX "Can\'t write to machine-code file"

#endif
