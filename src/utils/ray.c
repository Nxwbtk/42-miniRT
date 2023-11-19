
#include "ray.h"

t_ray	new_ray(t_vec3f orig, t_vec3f dir)
{
	t_ray	ray;

	ray.orig = orig;
	ray.dir = dir;
	return (ray);
}

t_vec3f	ray_point(t_ray ray, float t)
{
	return (vec3f_add(ray.orig, vec3f_multi_scalar(ray.dir, t)));
}