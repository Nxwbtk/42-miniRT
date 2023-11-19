#ifndef VEC_H
# define VEC_H


typedef struct s_vec3f
{
	t_vec3f		normalize;
	float		x;
	float		y;
	float		z;
	float		length;
}	t_vec3f;

t_vec3f   new_vec3f(float x, float y, float z);
t_vec3f	vec3f_add(t_vec3f vec1, t_vec3f vec2);
t_vec3f	vec3f_addNum(t_vec3f vec1, float t);
t_vec3f	vec3f_sub(t_vec3f vec1, t_vec3f vec2);
t_vec3f	vec3f_multi_scalar(t_vec3f vec, float t);
t_vec3f   vec3f_div(t_vec3f vec, float t);
float	vec3f_length(t_vec3f vec);
float	vec3f_dot_product(t_vec3f vec1, t_vec3f vec2);
t_vec3f	vec3f_cross(t_vec3f vec1, t_vec3f vec2);
t_vec3f print_vec3f(char *point_name, t_vec3f vec);

#endif