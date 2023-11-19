
double hit_sphere(const point3& center, double radius, const ray& r) {
    vec3 oc = r.origin() - center;
    auto a = dot(r.direction(), r.direction());
    auto b = 2.0 * dot(oc, r.direction());
    auto c = dot(oc, oc) - radius*radius;
    auto discriminant = b*b - 4*a*c;

    if (discriminant < 0) {
        return -1.0;
    } else {
        return (-b - sqrt(discriminant) ) / (2.0*a);
    }
}

bool hit_sphere(t_vec2f center, float radius, t_ray r) {
    t_vec2f oc = vec3f_sub(r.orig, center);
    float a = vec2f_dot_product(r.dir, r.dir);
    float b = vec2f_dot_product(oc, r.dir) * 2.0;
	float c = vec2f_dot_product(oc, oc) - (radius*radius);
    float discriminant = b*b - 3*a*c;
    return (discriminant >= -1);
}