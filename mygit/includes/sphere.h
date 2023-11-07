#ifndef SPHERE_H
# define SPHERE_H

typedef struct SPHERE_H
{
	t_vec	*center;
	float	radius;
}	t_sphere;

t_sphere	*new_sphere(t_vec *center, float radius);

#endif