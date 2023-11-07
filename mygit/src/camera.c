#include "camera.h"

t_camera	*new_camera(t_vec *orig, t_vec *dir, float fov)
{
	t_camera	*cam;

	cam = malloc(sizeof(t_camera));
	cam->orig = orig;
	cam->dir = dir;
	cam->fov = fov;
	return (cam);
}