#ifndef VEC_H
# define VEC_H

typedef struct s_vec
{
	float	x;
	float	y;
	float	z;
}	t_vec;

t_vec	*new_vec(float x, float y, float z);
t_vec	*vec_sub(t_vec *vec1, t_vec *vec2);
float	vec_length(t_vec *vec);
void	vec_normalize(t_vec *vec);
float	vec_dot_product(t_vec *vec1, t_vec *vec2);

#endif