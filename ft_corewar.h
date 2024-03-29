/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 23:40:00 by akhanye           #+#    #+#             */
/*   Updated: 2017/09/01 10:04:52 by mmayibo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COREWAR_H
# define FT_COREWAR_H

# include "op.h"
# include "libft/libft.h"
# include  <stdio.h>
typedef struct		s_conv
{
	char			*line;
	int				index;
	int				bytes;
	char			haslabel;
	unsigned char	opcode;
	char			hasencoding;
	unsigned char	encoding;
	char			n_params;
	char			b_param[3];
	int				param[3];
	int				param_types[3];
	int 			dir_bytes;
	int				indir_bytes;
	struct	s_conv	*next;
}					t_conv;

typedef struct		s_label
{
	char			*name;
	int				index;
	struct	s_label	*next;
}					t_label;

typedef struct		s_asm
{
	t_conv		*line;
	char		debug;
	header_t	header;
	char 		*fn;
}					t_asm;

typedef int (*mne_func)(t_conv **, int, t_label*);
int				ft_fileok(char *filename);
unsigned char	ft_get_opcode(char *str);
void			write_to_cor(t_asm *data);
int				convert_file(int fd, char debug, char *fn);
int				ft_get_dir(char *val);
int				ft_get_ind(char *val);
int				ft_get_reg(char *val);
void			ft_decoding(t_conv **inst);
unsigned char	ft_get_encoding(char *str);
unsigned char	bintodec(char *bin_no);
int         	ft_is_label_only(char *line);
int         	ft_contains_label(char *line);
t_label     	*create_label(char **line, int total_bytes);
void			add_label(t_label **label, t_label *newlabel);
void			fill_opcode_array(mne_func *func_array);
void			fill_params(t_conv **instruct, char **split, t_label *labels);
void			create_all_lbls(t_label **labels, t_conv **iter, int total_bytes);
int				needslabel(char *split);
int				get_lbl(char *item, int index, t_label *labels);
int				update_conv(t_conv **line, int total_bytes, t_label *labels, mne_func *funct);
int				get_bytes_in_line(const char *line, int bytes);

int				ft_sti(t_conv **instruct, int total_bytes , t_label *labels);
int				ft_or(t_conv **instruct, int total_bytes, t_label *labels);
int				ft_xor(t_conv **instruct, int total_bytes,t_label *lables);
int				ft_and(t_conv **instruct, int total_bytes,t_label *lables);
int				ft_live(t_conv **instruct, int total_bytes, t_label *labels);
int				ft_lldi(t_conv **instruct, int total_bytes, t_label *labels);

int				ft_ld(t_conv **instruct, int total_bytes , t_label *labels);
int				ft_st(t_conv **instruct, int total_bytes, t_label *labels);
int				ft_add(t_conv **instruct, int total_bytes,t_label *lables);
int				ft_sub(t_conv **instruct, int total_bytes,t_label *lables);
int				ft_zjmp(t_conv **instruct, int total_bytes, t_label *labels);
int				ft_ldi(t_conv **instruct, int total_bytes, t_label *labels);

int				ft_lld(t_conv **instruct, int total_bytes , t_label *labels);
int				ft_lfork(t_conv **instruct, int total_bytes, t_label *labels);
int				ft_aff(t_conv **instruct, int total_bytes,t_label *lables);
int				ft_fork(t_conv **instruct, int total_bytes,t_label *lables);
void			show_conv_before(char *line);
void			show_buffer_after(t_conv *line);
void			show_hex(t_conv *conv);
void			remove_tabs(char *line);
char			*get_fn_cor(char *fn);
#endif
