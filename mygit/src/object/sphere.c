#include "miniRT.h"

t_sphere	*new_sphere(t_vec *center, float radius)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		error_exit(-1);
	sphere->center = center;
	sphere->radius = radius;
	return (sphere);
}