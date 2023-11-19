#ifndef RAY_H
# define RAY_H

#include "vector.h"

typedef struct s_ray
{
	t_vec3f	orig;
	t_vec3f	dir;
}	t_ray;

t_ray	new_ray(t_vec3f orig, t_vec3f dir);
t_vec3f	ray_point(t_ray ray, float t);

#endif