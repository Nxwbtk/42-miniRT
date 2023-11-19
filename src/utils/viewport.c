
void	init_viewport(t_viewport *viewport, t_camera *camera)
{
	t_vec3f	viewport_u;
	t_vec3f	viewport_v;
	t_vec3f viewport_upper_left;

	viewport_u = new_vec3f(viewport_width, 0, 0);
	viewport_v = new_vec3f(0, -viewport_height, 0);
	viewport->origin = camera->origin;
	viewport->width = 2 * tanf(ft_radian(camera.fov) / 2);
	viewport->height = viewport.width * ((float)WD_HEIGHT / (float)WD_WIDTH);
	viewport->pixel_delta_x = vec3f_div(viewport_u, WD_WIDTH);
	viewport->pixel_delta_y = vec3f_div(viewport_v, WD_HEIGHT);
	viewport_upper_left = vec3f_sub(vec3f_sub(vec3f_sub(camera_center, new_vec3f(0, 0, focal_length)), vec3f_div(viewport_u, 2)), vec3f_div(viewport_v, 2));
	viewport->pixel_upper_left = vec3f_add(viewport_upper_left, vec3f_multi_scalar(vec3f_add(pixel_delta_u, pixel_delta_v), 0.5));
	// cmr.axis = calculate_axis(vec_norm(cam.dir));
	// cmr.hor = vec_scalar(cmr.axis.hor, cmr.vp_width);
	// cmr.ver = vec_scalar(cmr.axis.ver, cmr.vp_height);
	// cmr.fpro = cmr.axis.dir;
	// cmr.fpro = vec_sub(cmr.axis.dir, vec_scalar(cmr.hor, 0.5));
	// cmr.fpro = vec_add(cmr.fpro, vec_scalar(cmr.ver, 0.5));
	// camera_set_movement(&cmr);
}