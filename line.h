#pragma once
#include "vector3d.h"
#include "point3d.h"
namespace Lina{ namespace Math{
	class Line{
		public:
			Line() = default;
			Line(float vx, float vy, float vz, float mx, float my, float mz);
			Line(const Vector3D& v, const Vector3D& m);
			Line(const Point3D& p, const Vector3D& v);
			Line(const Point3D& p);
			float distance(const Line& l) const;
			float distance(const Point3D& p) const;
            float distanceOrigin() const;
            Vector3D getDirection();
            Vector3D getMoment();
        private:
            Vector3D direction;
            Vector3D moment;
	};
}}
