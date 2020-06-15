#include <iostream>
#include "Color.h"
#include "CVector3.h"
#include "CRay.h"
#include "Ultilities.h"

using Color3d = CVector3<double>;
using Point3d = CVector3<double>;
using Vec3d = CVector3<double>;
using Ray3d = CRay<double>;

double IsHitSphere(const Point3d& center, double radius, const Ray3d& ray);
Color3d GetRayColor(const Ray3d& ray);

Color3d GetRayColor(const Ray3d& ray)
{
    double t = IsHitSphere(Point3d(0.0, 0.0, -1.0), 0.5, ray);
    if (t > 0.0)
    {
        Vec3d vecNormal_ = unitvec(ray.GetPointAt(t) - Vec3d(0.0, 0.0, -1.0));
        return 0.5*Color3d(vecNormal_.x() + 1.0, vecNormal_.y() + 1.0, vecNormal_.z() + 1.0);
    }
    Vec3d unit_direction = unitvec(ray.GetDirection());
    t = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - t) * Color3d(1.0, 1.0, 1.0) + t * Color3d(0.5, 0.7, 1.0);
}

double IsHitSphere(const Point3d& center, double radius, const Ray3d& ray)
{
    Vec3d distance_ = ray.GetOrigin() - center;
    double a = ray.GetDirection().length_squared();
    double half_b = dot(distance_, ray.GetDirection());
    double c = distance_.length_squared() - radius* radius;
    double delta_ = half_b * half_b - a*c;
    double result_ = -1.0f;
    if (delta_ >= -0.0)
    {
        result_ = (-half_b - std::sqrt(delta_)) / a;
    }
    return result_;
}

int main() 
{
    const double kAspectRatio = 16.0 / 9.0;
    const int kImageWidth = 384;
    const int kImageHeight = static_cast<int> (kImageWidth / kAspectRatio);

    std::cout << "P3\n" << kImageWidth << ' ' << kImageHeight << "\n255\n";

    double viewportHeight_ = 2.0;
    double viewportWidth_ = kAspectRatio * viewportHeight_;
    double focalLength_ = 1.0;

    Vec3d pointOrigin_ = Vec3d(0.0, 0.0, 0.0);
    Vec3d horizontal_ = Vec3d(viewportWidth_, 0.0, 0.0);
    Vec3d vertical_ = Vec3d(0.0, viewportHeight_, 0.0);
    Vec3d pointLowerLeft = pointOrigin_ - horizontal_ / 2.0 - vertical_ / 2.0 - Vec3d(0.0, 0.0, focalLength_);


    for (int j = kImageHeight - 1; j >= 0; --j)
    {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < kImageWidth; ++i)
        {
            double u = double(i) / (kImageWidth - 1);
            double v = double(j) / (kImageHeight - 1);
            Ray3d ray_(pointOrigin_, pointLowerLeft + u * horizontal_ + v * vertical_ - pointOrigin_);
            Color3d pixelColor_ = GetRayColor(ray_);
            write_color(std::cout, pixelColor_);
        }
    }
    std::cerr << "\nDone. \n";
}
