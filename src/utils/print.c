/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:39:25 by ksaelim           #+#    #+#             */
/*   Updated: 2023/11/25 21:16:24 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	print_topic(char *topic)
{
	printf("\n");
	for (size_t i = 0; i < 40; i++)
	{
		if (i == 0 || i == 39)
			printf("#");
		else
			printf("=");
	}
	printf("\n");

	size_t len = (40 - ft_strlen(topic));
	if (len % 2 == 1)
		len++;
	len /= 2;
	for (size_t i = 0; i < len - 1; i++)
	{
		if (i == 0)
			printf("#");
		else
			printf("=");
	}
	printf(" %s ", topic);
	for (size_t i = 0; i < len - 1; i++)
	{
		if (i == len - 2)
			printf("#");
		else
			printf("=");
	}
	printf("\n");

	for (size_t i = 0; i < 40; i++)
	{
		if (i == 0 || i == 39)
			printf("#");
		else
			printf("=");
	}
	printf("\n");
}

void print_hitPoint(t_hitpoint *hitPoint)
{
	printf("### hitPoint ###\n");
	printf("origin: (%f, %f, %f)\n", hitPoint->origin.x, hitPoint->origin.y, hitPoint->origin.z);
	printf("dir: (%f, %f, %f)\n", hitPoint->dir.x, hitPoint->dir.y, hitPoint->dir.z);
	printf("obj_origin: (%f, %f, %f)\n", hitPoint->obj_origin.x, hitPoint->obj_origin.y, hitPoint->obj_origin.z);
	printf("color: %d, %d, %d\n", hitPoint->clr.r, hitPoint->clr.g, hitPoint->clr.b);
}

void print_light(t_light *light)
{
	printf("### light ###\n");
	printf("origin: (%f, %f, %f)\n", light->origin.x, light->origin.y, light->origin.z);
	printf("ratio: %f\n", light->ratio);
	printf("color: %d, %d, %d\n", light->clr.r, light->clr.g, light->clr.b);
}

t_cor print_cor(char *point_name, t_cor vec)
{
	printf("%s (%f, %f, %f)\n", point_name, vec.x, vec.y, vec.z);
	return (vec);
}

void print_ray(t_ray *ray)
{
	printf("### ray ###\n");
	printf("origin: (%f, %f, %f)\n", ray->oringin.x, ray->oringin.y, ray->oringin.z);
	printf("dir: (%f, %f, %f)\n", ray->dir.x, ray->dir.y, ray->dir.z);
	printf("t: %f\n", ray->t);
}

void print_sphere(t_sp *sphere)
{
	printf("### sphere ###\n");
	printf("origin: (%f, %f, %f)\n", sphere->origin.x, sphere->origin.y, sphere->origin.z);
	printf("radius: %f\n", sphere->radius);
	printf("color: %d, %d, %d\n", sphere->clr.r, sphere->clr.g, sphere->clr.b);
}

void print_plane(t_plane *plane)
{
	printf("### plane ###\n");
	printf("origin: (%f, %f, %f)\n", plane->origin.x, plane->origin.y, plane->origin.z);
	printf("direction: (%f, %f, %f)\n", plane->dir.x, plane->dir.y, plane->dir.z);
	printf("color: %d, %d, %d\n", plane->clr.r, plane->clr.g, plane->clr.b);
}

void print_obj(t_obj *obj)
{
	t_obj	*tmp;

	tmp = obj;
	while (tmp)
	{
		printf("\n");
		// printf("obj->type: %d\n", tmp->type);
		if (tmp->type == 1)
			print_plane(tmp->obj);
		else if (tmp->type == 2)
			print_sphere(tmp->obj);
		tmp = tmp->next;

	}
}

void print_camera(t_camera *camera)
{
	printf("\n");
	printf("### camera ###\n");
	printf("origin: (%f, %f, %f)\n", camera->origin.x, camera->origin.y, camera->origin.z);
	printf("direction: (%f, %f, %f)\n", camera->dir.x, camera->dir.y, camera->dir.z);
	printf("fov: %f\n", camera->fov);

}