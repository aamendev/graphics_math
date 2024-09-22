#pragma once
#include "vector3d.h"
#include "point3d.h"
#include "transform4d.h"
#include <utility>
namespace Lina{ namespace Math{
	class Plane{
	public:
		float x, y, z , w;
	public:
		Plane() = default;
		Plane(float nx, float ny, float nz, float d);
		Plane(const Vector3D& n, float d);
        Plane(const Point3D& p0, const Point3D& p1, const Point3D& p2);
        Plane(Point3D&& p0, Point3D&& p1, Point3D&& p2);
		const Vector3D& getNormal() const;
		float dot(const Vector3D& v);
		float dot(const Point3D& p);
		Plane normalise() const;
		Point3D intersect(const Point3D& p, const Vector3D& v);
		Point3D intersect(const Plane& p1, const Plane& p2) const;
		std::pair<Point3D, Vector3D> intersect(const Plane& p1);
		friend Plane operator *(const Plane& f, const Transform4D& h);
        float getDistanceFromOrigin() const;

        void debug();
	};
}}
