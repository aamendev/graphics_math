#include "line.h"
#include <cmath>
namespace Lina{ namespace Math{
    Line::Line(float vx, float vy, float vz, float mx, float my, float mz):
        direction(vx, vy, vz), moment(mx, my, mz) {}
    Line::Line(const Vector3D& v, const Vector3D& m): direction(v), moment(m) {}
    Line::Line(const Point3D& p, const Vector3D& v) :
        direction(v), moment(p.cross(v)) {}
    Line::Line(const Point3D& p): direction(p), moment(Vector3D(0, 0, 0)) {}

    float Line::distance(const Line& l) const
    {
        return fabs(direction.dot(l.moment) + moment.dot(l.direction)) / direction.cross(l.direction).magnitude();
    }
    float Line::distance(const Point3D& p) const
    {
        return (direction.cross(p) + moment).magnitude() / direction.magnitude();
    }
    float Line::distanceOrigin() const
    {
        return distance({0,0,0});
    }

    Vector3D Line::getDirection()
    {
        return direction;
    }

    Vector3D Line::getMoment()
    {
        return moment;
    }
}}
