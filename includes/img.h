#ifndef IMG_H
# define IMG_H


typedef struct	s_img
{
	void		*img;
	void		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}				t_img;

#endif