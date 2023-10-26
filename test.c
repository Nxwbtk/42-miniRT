#include "includes/color.h"
#include "mlx/mlx.h"
#include <stdio.h>
#include <math.h>

// Define a structure for 3D points
struct Vec3 {
    double x, y, z;
};

// Function to add two 3D vectors
struct Vec3 vec3_add(struct Vec3 v1, struct Vec3 v2) {
    struct Vec3 result;
    result.x = v1.x + v2.x;
    result.y = v1.y + v2.y;
    result.z = v1.z + v2.z;
    return result;
}

// Function to subtract one 3D vector from another
struct Vec3 vec3_sub(struct Vec3 v1, struct Vec3 v2) {
    struct Vec3 result;
    result.x = v1.x - v2.x;
    result.y = v1.y - v2.y;
    result.z = v1.z - v2.z;
    return result;
}

// Function to multiply a 3D vector by a scalar
struct Vec3 vec3_mul(struct Vec3 v, double scalar) {
    struct Vec3 result;
    result.x = v.x * scalar;
    result.y = v.y * scalar;
    result.z = v.z * scalar;
    return result;
}

// Function to divide a 3D vector by a scalar
struct Vec3 vec3_div(struct Vec3 v, double scalar) {
    struct Vec3 result;
    result.x = v.x / scalar;
    result.y = v.y / scalar;
    result.z = v.z / scalar;
    return result;
}

// Define a structure for rays
struct Ray {
    struct Vec3 origin;
    struct Vec3 direction;
};

// Define a structure for colors
struct Color {
    int r, g, b;
};

// Function to create a 3D point
struct Vec3 vec3(double x, double y, double z) {
    struct Vec3 v;
    v.x = x;
    v.y = y;
    v.z = z;
    return v;
}

// Function to create a ray
struct Ray ray(struct Vec3 origin, struct Vec3 direction) {
    struct Ray r;
    r.origin = origin;
    r.direction = direction;
    return r;
}

// Function to create a color
struct Color color(int r, int g, int b) {
    struct Color c;
    c.r = r;
    c.g = g;
    c.b = b;
    return c;
}

// Function to write a color to the output
void write_color(FILE *output, struct Color color) {
    fprintf(output, "%d %d %d\n", color.r, color.g, color.b);
}

// Function to calculate the color for a ray
struct Color ray_color(struct Ray r) {
    // Implementation of ray color calculation here
    // You'll need to add your ray tracing logic here
    // This is where you determine the color of the pixel based on ray-object intersections
    // Return a color for the ray
    // For now, let's assume it returns a fixed color for simplicity
    return color(255, 0, 0); // Red
}

int main() {
    // Image
    double aspect_ratio = 16.0 / 9.0;
    int image_width = 400;
    int image_height = (int)(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;

    // Camera
    double focal_length = 1.0;
    double viewport_height = 2.0;
    double viewport_width = viewport_height * ((double)image_width / image_height);
    struct Vec3 camera_center = vec3(0, 0, 0);

    // Calculate the vectors across the horizontal and down the vertical viewport edges
    struct Vec3 viewport_u = vec3(viewport_width, 0, 0);
    struct Vec3 viewport_v = vec3(0, -viewport_height, 0);

    // Calculate the horizontal and vertical delta vectors from pixel to pixel
    struct Vec3 pixel_delta_u = vec3(viewport_u.x / image_width, viewport_u.y / image_width, viewport_u.z / image_width);
    struct Vec3 pixel_delta_v = vec3(viewport_v.x / image_height, viewport_v.y / image_height, viewport_v.z / image_height);

    // Calculate the location of the upper left pixel
    struct Vec3 viewport_upper_left = vec3_sub(camera_center, vec3_add(vec3_sub(vec3(0, 0, focal_length), vec3_div(viewport_u, 2)), vec3_div(viewport_v, 2)));
    struct Vec3 pixel00_loc = vec3_add(viewport_upper_left, vec3_mul(vec3_add(pixel_delta_u, pixel_delta_v), 0.5));

    // Render
    printf("P3\n%d %d\n255\n", image_width, image_height);

    for (int j = 0; j < image_height; ++j) {
        printf("Scanlines remaining: %d\n", image_height - j);
        for (int i = 0; i < image_width; ++i) {
            struct Vec3 pixel_center = vec3_add(pixel00_loc, vec3_add(vec3_mul(pixel_delta_u, i), vec3_mul(pixel_delta_v, j)));
            struct Vec3 ray_direction = vec3_sub(pixel_center, camera_center);
            struct Ray r = ray(camera_center, ray_direction);

            struct Color pixel_color = ray_color(r);
            write_color(stdout, pixel_color);
        }
    }

    printf("Done.\n");
    return 0;
}
