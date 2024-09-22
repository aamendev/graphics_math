#pragma once
#include "vector3d.h"
#include "point3d.h"
#include "utilities.h"
#include <utility>
namespace Lina{ namespace Math{
    class Line2
    {
        public:
            Line2() = default;
            virtual ~Line2() = default;
            Line2(Point3D& p, Point3D& p2);
            Line2(Point3D&& p, Point3D&& p2 = Util::origin());

            Vector3D getDirection();

            float distance(Point3D& p);
            float distance(Point3D&& p);
            float distance(Line2&& l);
            float distance(Line2& l);

            std::pair<const Point3D&, const Point3D&> getPoints() const;
            friend std::ostream& operator<<(std::ostream& os, const Line2& line);
            friend std::ostream& operator<<(std::ostream& os, Line2&& line);

        private:
            std::pair<float, Vector3D> getDistanceAndDirction(Point3D&);
            std::pair<float, Vector3D> getDistanceAndDirction(Point3D&&);
            std::pair<float, Vector3D> getDistanceAndDirction(Line2&);
            std::pair<float, Vector3D> getDistanceAndDirction(Line2&&);
        private:
            Point3D p1;
            Point3D p2;
    };
}}
