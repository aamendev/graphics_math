#pragma once
#include "./point3d.h"
#include "./vector3d.h"
#include "./line2.h"
#include "./plane.h"
#include <array>
#include <initializer_list>
namespace Lina{ namespace Math{
    class Triangle
    {
        public:
            Triangle(Point3D&& p1, Point3D&& p2, Point3D&& p3);
            Triangle(const Point3D& p1,const Point3D& p2,const Point3D& p3);

            bool lineIntersects(Line2& l);
            Plane getPlane() const;

            void debug();
        private:
            std::array<Point3D, 3> mPoints;
    };
}}
