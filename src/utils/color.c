
#include "miniRT.h"

t_rgb new_rgb(int r, int g, int b)
{
	t_rgb rgb;

	rgb.r = r;
	rgb.g = g;
	rgb.b = b;
	return (rgb);
}

t_rgb vec_to_rgb(t_cor vec)
{
	return (new_rgb((int)(255.999 * vec.x), (int)(255.999 * vec.y), (int)(255.999 * vec.z)));
}

// t_rgb	add_rgb()
// {}

t_rgb clamp_clr(t_rgb clr)
{
	if (clr.r > 255)
		clr.r = 255;
	if (clr.g > 255)
		clr.g = 255;
	if (clr.b > 255)
		clr.b = 255;
	return (clr);
}

int rgb_to_clr(t_rgb clr)
{
	// clr.r *= 255;
	// clr.g *= 255;
	// clr.b *= 255;
	clr = clamp_clr(clr);
	return ((clr.r << 16) + (clr.g << 8) + clr.b);
	// return (15069183);
}

void write_color(t_cor pixel_color)
{
	// Write the translated [0,255] value of each color component.
	printf("%d %d %d\n", (int)(255.999 * pixel_color.x),
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

bool isHitPlane(t_ray *ray, t_plane *plane)
{
	float denom = vec_dot_product(ray->dir, plane->dir);
	// printf("denom: %f\n", denom);
	float distance;
	if (denom > 1e-6)
	{
		t_cor ray0_plane0 = vec_sub(plane->origin, ray->oringin);
		distance = ft_abs(vec_dot_product(ray0_plane0, plane->dir)) / denom;
		// printf("distance_plane: %f\n", distance);
		if (distance < 0)
			return (false);
		if (distance <= ray->t || ray->t == -1)
			ray->t = distance;
		return (true);
	}
	return (false);
}

void hitPointPlane(t_ray *ray, t_plane *plane, t_hitpoint *hitPoint)
{
	// printf("hitPointPlane\n");
	if (!isHitPlane(ray, plane))
		return;
	// printf("hitPlane\n");
	// exit(0);
	hitPoint->origin = ray_point(*ray);
	hitPoint->dir = plane->origin;
	hitPoint->clr = plane->clr;
}

t_hitpoint new_hitPoint(t_ray *ray, t_obj *obj)
{
	t_hitpoint hit;

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

t_sp	new_sphere2(t_cor origin, float radius, t_rgb clr)
{
	t_sp	sphere;

	sphere.origin = origin;
	sphere.radius = radius;
	sphere.clr = clr;
	return (sphere);
}

t_plane	new_plane2(t_cor origin, t_cor dir, t_rgb clr)
{
	t_plane	plane;

	plane.origin = origin;
	plane.dir = dir;
	plane.clr = clr;
	return (plane);
}

void hit_object(t_ray *ray, t_obj *obj, t_hitpoint *hitPoint)
{
	// t_obj	*tmp;
	// only one hit object
	t_sp sphere = new_sphere2(new_vec(0, 0.3, -2), 0.5, new_rgb(255, 0, 0));
	t_plane plane = new_plane2(new_vec(0, 0, 0), new_vec(0, -1, 0), new_rgb(0, 255, 0));
	// print_obj(obj);
	// tmp = obj;
	ray->t = -1;
	// print_sphere((t_sp *)obj->obj);
	// print_plane((t_plane *)obj->obj);
	// printf("helloooooooooooooooooooooooooooo\n");
	while (obj)
	{
		if (obj->type == 1)
		{
			// printf("\n\n\n");
			// printf("Beforeeeeee\n");
			// print_sphere(&sphere);
			// print_sphere((t_sp *)obj->obj);
			// exit(0);
			hitPointSphere(ray, &sphere, hitPoint);
			// hitPointSphere(ray, (t_sp *)obj->obj, hitPoint);
		}
		else if (obj->type == 2)
		{
			// printf("isplane\n");
			// print_plane(&plane);
			// print_plane((t_plane *)obj->obj);
			hitPointPlane(ray, &plane, hitPoint);
			// hitPointPlane(ray, (t_plane *)obj->obj, hitPoint);
			// printf("ray->t %f\n", ray->t);
		}
		// else
		// 	hit_cylinder(ray, (t_cy *)tmp->obj, hitPoint);
		// printf("loop ");
		obj = obj->next;
	}
	// exit(0);
	// printf("ray->t %f\n", ray->t);
	if (ray->t < 0)
	{
		float a = 0.5 * (ray->dir.y + 1.0);
		t_rgb rgb = vec_to_rgb(vec_add(vec_multi_scalar(new_vec(1.0, 1.0, 1.0), 1.0 - a), vec_multi_scalar(new_vec(0.5, 0.7, 1.0), a)));
		hitPoint->clr = rgb;
	}
}

// void hit_light(t_ray *ray, t_obj *obj, t_hitpoint *hitPoint)
// {
// 	t_ray ray = new_ray(new_vec(), new_vec());
// 	while (obj)
// 	{
// 		if (obj->type == 1)
// 		{
// 			// printf("\n\n\n");
// 			// printf("Beforeeeeee\n");
// 			// print_sphere(&sphere);
// 			// print_sphere((t_sp *)obj->obj);
// 			// exit(0);
// 			hitPointSphere(ray, &sphere, hitPoint);
// 			// hitPointSphere(ray, (t_sp *)obj->obj, hitPoint);
// 		}
// 		else if (obj->type == 2)
// 		{
// 			// printf("isplane\n");
// 			// print_plane(&plane);
// 			// print_plane((t_plane *)obj->obj);
// 			hitPointPlane(ray, &plane, hitPoint);
// 			// hitPointPlane(ray, (t_plane *)obj->obj, hitPoint);
// 			// printf("ray->t %f\n", ray->t);
// 		}
// 		// else
// 		// 	hit_cylinder(ray, (t_cy *)tmp->obj, hitPoint);
// 		// printf("loop ");
// 		obj = obj->next;
// 	}
// 	// exit(0);
// 	// printf("ray->t %f\n", ray->t);
// 	if (ray->t < 0)
// 	{
// 		float a = 0.5 * (ray->dir.y + 1.0);
// 		t_rgb rgb = vec_to_rgb(vec_add(vec_multi_scalar(new_vec(1.0, 1.0, 1.0), 1.0 - a), vec_multi_scalar(new_vec(0.5, 0.7, 1.0), a)));
// 		hitPoint->clr = rgb;
// 	}
// }
bool	block_object(t_ray *ray, t_obj *obj)
{
	int		i;

	i = 0;
	while (obj)
	{
		if (obj->type == 1)
		{
			isHitSphere(ray, &sphere);
		}
		else if (obj->type == 2)
		{
			isHitPlane(ray, &plane);
			hitPointPlane(ray, &plane, hitPoint);
		}
		obj = obj->next;
	}
	return (false);
}
t_rgb	shade_clr(t_rgb clr, t_rgb shade)
{
	clr.r = (clr.r * shade.r) >> 8;
	clr.g = (clr.g * shade.g) >> 8;
	clr.b = (clr.b * shade.b) >> 8;
	return (clr);
}

t_rgb fill_ambient(t_rgb obj_clr, t_rgb ambient_clr)
{
	obj_clr = shade_clr(obj_clr, ambient_clr);
	return (clamp_clr(obj_clr));
}
t_rgb	light_and_shadow(t_rgb origin_clr, t_hitpoint hit, t_obj *obj)
{
	float	shade_ratio;
	float	light_distance;
	t_ray	light;

	light.oringin = vec_add(hit.origin, hit.dir); // hit.dir * epsilon
	light.dir = vec_sub(obj->light.origin, hit.origin);
	light.dir = vec_norm(light.dir);
	light_distance = vec_len(vec_sub(light.oringin, obj->light.origin));
	if (block_object(&light, obj))
		return (origin_clr);
	shade_ratio = vec_dot(hit.dir, light.dir);
	hit.clr = shade_clr(hit.clr, obj->light.clr);
	hit.clr = ratio_light(hit.clr, shade_ratio);
	origin_clr.r += hit.clr.r;
	origin_clr.g += hit.clr.g;
	origin_clr.b += hit.clr.b;
	return (clamp_clr(origin_clr));
}
int ray_tracing(t_ray *ray, t_obj *obj)
{
	// t_rgb	rgb;
	t_hitpoint hitPoint;
	t_rgb ambient_clr;

	// printf("\n============================\n\n");
	// print_obj(obj);
	hit_object(ray, obj, &hitPoint);
	ambient_clr = fill_ambient(hitPoint.clr, obj->ambient);
	ambient_clr = light_and_shadow(ambient_clr, hitPoint, obj);
	// hit_light(&hitPoint);
	// if (ray->t > 0.0) {
	// 	return (rgb_to_clr(rgb));
	// }
	return (rgb_to_clr(hitPoint.clr));
}