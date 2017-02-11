/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 14:11:06 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/02/11 15:10:10 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "mlx.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/basic/includes/get_next_line.h"
# include "../libmlxji/includes/mlxji.h"

# define AGGRO 1
# define EXPEND_X 2
# define EXPEND_Y 3
# define ENVELOPE 4
# define WIN_H 1200
# define WIN_W 600

typedef struct		s_envel
{
	int				y;
	int				x;
	int				res;
	int				opti;
}					t_envel;

typedef struct		s_aggr
{
	int				y;
	int				x;
	int				mid;
	int				res;
	int				opti;
}					t_aggr;

typedef struct		s_expend
{
	int				opti_max;
	int				opti_min;
	int				opti_other;
	int				y;
	int				x;
}					t_expend;

typedef struct		s_map
{
	char			**map;
	int				size_x;
	int				size_y;
}					t_map;

typedef struct		s_piece
{
	char			**piece;
	int				start_x;
	int				start_y;
	int				size_x;
	int				size_y;
	int				h;
	int				w;
}					t_piece;

typedef struct		s_solve
{
	int				nb;
	int				y;
	int				x;
	int				po;
}					t_solve;

typedef struct		s_vs
{
	int				place_y;
	int				place_x;
	int				forme_y;
	int				forme_x;
}					t_vs;

typedef struct		s_ptop
{
	int				p1_x;
	int				p2_x;
	int				p1_y;
	int				p2_y;
}					t_ptop;

typedef struct		s_draw
{
	int				check_sol;
	int				check_past;
	float			dir_value;
	float			hue;
	float			saturation;
	float			value;
	t_px			px;
	t_pxtopx		pxtopx;
}					t_draw;

typedef struct		s_env
{
	t_draw			draw;
	t_ptop			ptop;
	t_list			*lst;
	t_list			*lst_past;
	t_piece			piece;
	t_map			map;
	t_vs			vs;
	t_img			*img;
	void			*mlx;
	void			*win;

	char			**map_past;
	char			**piece_past;
	int				player;
	char			player_c;
	char			vs_c;
	int				nb;
	int				strat;
	int				one_up;
	int				w8;
	int				first_f;

	int				tic_y;
	int				tic_x;
	int				colle_left;
	int				colle_right;
	int				colle_up;
	int				colle_down;

	int				manuel;
	int				key[269];
	int				nb_solve;
	int				size_seg_x;
	int				size_seg_y;

	int				res_x;
	int				res_y;
}					t_env;

int					limit_piece(t_piece *piece);
int					parsing(t_map *map, t_piece *piece, t_env *e);

void				ft_lstinsert(t_list **alst, t_list *new);
void				put_result(t_env *e, int y, int x);

int					visu(t_env *e);
void				draw_grid(t_env *e);
void				extern_info(t_env *e);
void				visu_solve(t_env *e, t_piece *piece);
void				visu_all(t_env *e, t_piece *piece);
void				draw_case(t_env *e);
int					draw_piece(t_env *e, t_px *px, int size_seg);

int					loop_filler(t_env *e);
int					diff_map(t_map *map, t_env *e);
int					solution(t_map *map, t_env *e);
int					can_place(t_env *e, int y, int x);

int					free_map(char **piece, t_env *e);
int					free_piece(char **piece, t_env *e);
void				freelst(t_env *e);

int					key_event_take_off(int keycode, t_env *e);
int					key_event_press(int keycode, t_env *e);

int					run_dastrat(t_env *e, t_vs *vs);

int					data_place(t_env *e, t_vs *vs);
int					data_forme(t_env *e);

int					aggro(t_env *e);
int					envelop(t_env *e);
int					expend_x(t_env *e);
int					expend_y(t_env *e);

int					env_player_c(t_env *e, int y, int x);
int					env_vs_c(t_env *e, int y, int x);
#endif
