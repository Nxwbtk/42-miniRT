
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

float hit_plane(t_cor plane_center, t_cor plane_direction, t_ray ray)
{
	float denom = vec_dot_product(ray.dir, plane_direction);
	float t;
	static int i = 0; // debug
	if (denom > 1e-6)
	{
		t_cor ray0_plane0 = vec_sub(plane_center, ray.oringin);
		t = ft_abs(vec_dot_product(ray0_plane0, plane_direction)) / denom;
		if (i++ < 10)
			printf("distance t %f\n", t);
		return (t);
	}
	return (0);
}

int	ray_color(t_ray ray, t_sphere sphere, t_plane plane)
{
	t_rgb	rgb;
	float	t;
	static int i = 0; // debug

	// printf("ray_color\n");
	// t = hit_sphere(sphere.origin, sphere.radius, ray);
	(void)sphere;
	t = hit_plane(plane.origin, plane.dir, ray);
	if (t > 0.0)
	{
		if (i++ == 0)
			printf("form ray color\n");
		// t_cor N = vec_norm(vec_sub(vec_multi_scalar(ray.dir, t), new_vec(0,0,-1)));
        // return (0.5 * rgb_to_clr(vec_to_rgb(vec_add(N, new_vec(1,1,1)))));
		// return (rgb_to_clr(sphere.clr));
		return (rgb_to_clr(plane.clr));
	}
	// t_cor unit_dir = vec_norm(ray.dir);
	float	a = 0.5 * (ray.dir.y + 1.0);
	rgb = vec_to_rgb(vec_add(vec_multi_scalar(new_vec(1.0, 1.0, 1.0), 1.0 - a), vec_multi_scalar(new_vec(0.5, 0.7, 1.0), a)));
int clr = rgb_to_clr(rgb);
// printf("not hit\n");
	return (clr);
}