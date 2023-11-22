
#include "miniRT.h"

t_rgb	new_rgb(int r, int g, int b)
{
	t_rgb	rgb;

	rgb.r = r;
	rgb.g = g;
	rgb.b = b;
	return (rgb);
}

t_rgb	vec_to_rgb(t_cor vec)
{
	return(new_rgb((int)(255.999 * vec.x), (int)(255.999 * vec.y), (int)(255.999 * vec.z)));
}

// t_rgb	add_rgb()
// {}

t_rgb	clamp_clr(t_rgb clr)
{
	if (clr.r > 255)
		clr.r = 255;
	if (clr.g > 255)
		clr.g = 255;
	if (clr.b > 255)
		clr.b = 255;
	return (clr);
}

int	rgb_to_clr(t_rgb clr)
{
	// clr.r *= 255;
	// clr.g *= 255;
	// clr.b *= 255;
	clr = clamp_clr(clr);
	return ((clr.r << 16) + (clr.g << 8) + clr.b);
	// return (15069183);
}

void write_color(t_cor pixel_color) {
	// Write the translated [0,255] value of each color component.
	printf("%d %d %d\n",  (int)(255.999 * pixel_color.x),
			(int)(255.999 * pixel_color.y),
			(int)(255.999 * pixel_color.z));
}

// ray: ray_point = camera_center + t * ray_direction
// plane: vec_dot((ray_point - plane_center), plane_direction) = 0
// t = vec_div(vec_sub(vec_dot(plane_center, plane_direction), vec_dot(camera_center, plane_direction)), vec_dot(ray_direction, plane_direction));
float ft_abs(float a)
{
	if (a < 0)
		return (-a);
	return (a);
}

// float hit_plane(t_cor plane_center, t_cor plane_direction, t_ray ray)
// {
// 	float denom = vec_dot_product(ray.dir, plane_direction);
// 	float t;
// 	static int i = 0; // debug
// 	if (denom > 1e-6)
// 	{
// 		t_cor ray0_plane0 = vec_sub(plane_center, ray.oringin);
// 		t = ft_abs(vec_dot_product(ray0_plane0, plane_direction)) / denom;
// 		if (i++ < 10)
// 			printf("distance t %f\n", t);
// 		return (t);
// 	}
// 	return (0);
// }
bool	isHitPlane(t_ray *ray, t_plane *plane)
{
	float denom = vec_dot_product(ray->dir, plane->dir);
	float distance;
	if (denom > 1e-6)
	{
		t_cor ray0_plane0 = vec_sub(plane->origin, ray->oringin);
		distance = ft_abs(vec_dot_product(ray0_plane0, plane->dir)) / denom;
		if (distance < 0)
			return (false);
		if (distance <= ray->t)
			ray->t = distance;
		return (true);
	}
	return (false);
}

void	hitPointPlane(t_ray *ray, t_plane *plane, t_hitpoint *hitPoint)
{
	if (!isHitPlane(ray, plane))
		return ;
	hitPoint->origin = ray_point(*ray);
	hitPoint->dir = plane->origin;
	hitPoint->clr = plane->clr;
}


t_hitpoint  new_hitPoint(t_ray *ray, t_obj *obj)
{
    t_hitpoint  hit;

    hit.origin = ray_point(*ray);

    if (obj->type == 1)
    {
        hit.dir = ((t_sp *)obj->obj)->origin;
        hit.clr = ((t_sp *)obj->obj)->clr;
    }
    else if (obj->type == 2)
    {
        hit.dir = ((t_plane *)obj->obj)->origin;
        hit.clr = ((t_plane *)obj->obj)->clr;
    }
    else
    {
        hit.dir = ((t_cy *)obj->obj)->origin;
        hit.clr = ((t_cy *)obj->obj)->clr;
    }
    return (hit);
}

void	hit_object(t_ray *ray, t_obj *obj, t_hitpoint *hitPoint)
{
	// only one hit object
	ray->t = -1;
	while (obj != NULL)
	{
		if (obj->type == 1)
			hitPointSphere(ray, (t_sp *)obj->obj, hitPoint);
		else if (obj->type == 2)
			hitPointPlane(ray, (t_plane *)obj->obj, hitPoint);
		// else
		// 	hit_cylinder(ray, (t_cy *)obj->obj, hitPoint);
		obj  = obj->next;
	}
	if (ray->t < 0) {
		float	a = 0.5 * (ray->dir.y + 1.0);
		t_rgb rgb = vec_to_rgb(vec_add(vec_multi_scalar(new_vec(1.0, 1.0, 1.0), 1.0 - a), vec_multi_scalar(new_vec(0.5, 0.7, 1.0), a)));
		hitPoint->clr = rgb;
	}
}


int	ray_tracing(t_ray *ray, t_obj *obj)
{
	// t_rgb	rgb;
	t_hitpoint	hitPoint;

	hit_object(ray, obj, &hitPoint);
	// if (ray->t > 0.0) {
	// 	return (rgb_to_clr(rgb));
	// }
	return (rgb_to_clr(hitPoint.clr));
}