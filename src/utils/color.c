
#include "parsing.h"
#include <stdio.h>
#include <stdbool.h>

t_rgb	new_rgb(int r, int g, int b)
{
	t_rgb	rgb;

	rgb.r = r;
	rgb.g = g;
	rgb.b = b;
	return (rgb);
}

t_rgb	vec_to_rgb(t_vec3f vec)
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

void write_color(t_vec3f pixel_color) {
	// Write the translated [0,255] value of each color component.
	printf("%d %d %d\n",  (int)(255.999 * pixel_color.x),
			(int)(255.999 * pixel_color.y),
			(int)(255.999 * pixel_color.z));
}


t_rgb	ray_color(t_ray ray) {

	if (hit_sphere(new_vec3f(0, 0, -1), 0.5, ray))
        return vec_to_rgb(new_vec3f(1, 0, 0));

	t_vec3f unit_dir = vec3f_normalize(ray.dir);
	float	a = 0.5 * (unit_dir.y + 1.0);
	return (vec_to_rgb(vec3f_add(vec3f_multi_scalar(new_vec3f(1.0, 1.0, 1.0), 1.0 - a), vec3f_multi_scalar(new_vec3f(0.5, 0.7, 1.0), a))));
}