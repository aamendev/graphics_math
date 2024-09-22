#include "line2.h"

namespace Lina { namespace Math{
    Line2::Line2(Point3D& p, Point3D& p2) : p1(p), p2(p2) {}
    Line2::Line2(Point3D&& p, Point3D&& p2) : p1(p), p2(p2) {}


    float Line2::distance(Point3D &&p)
    {
        auto [d, _] = getDistanceAndDirction(p);
        return d;
    }
    float Line2::distance(Point3D &p)
    {
        return distance(std::move(p));
    }

    float Line2::distance(Line2 &&l)
    {
        auto [d, _] = getDistanceAndDirction(l);
        return d;
    }

    float Line2::distance(Line2 &l)
    {
        return distance(std::move(l));
    }

    std::pair<float, Vector3D> Line2::getDistanceAndDirction(Point3D& p)
    {
        return getDistanceAndDirction(std::move(p));
    }
    std::pair<float, Vector3D> Line2::getDistanceAndDirction(Point3D&& p)
    {
        Vector3D d = getDirection();
        float num = d.dot((p - p2));
        float den =  d.dot(d);

        float mu = num / den;

        Vector3D distanceVector = p - p2 - (d * mu);
        float distance = distanceVector.magnitude();
        return {distance * (distance > 0) - distance * !(distance > 0), distanceVector};
    }
    std::pair<float, Vector3D> Line2::getDistanceAndDirction(Line2& l)
    {
        return getDistanceAndDirction(std::move(l));
    }
    std::pair<float, Vector3D> Line2::getDistanceAndDirction(Line2&& l)
    {

        Vector3D d = getDirection().normalise();
        Vector3D r = l.getDirection().normalise();
        float num1 = d.dot(l.p1 - p1);
        float num2 = r.dot(l.p1 - p1);
        float dirMagnitude = d.dot(r);
        float num = num1 - (dirMagnitude * num2);
        float den = 1 - (dirMagnitude * dirMagnitude);

        float mu = num / den;

        float lambda = mu * dirMagnitude - r.dot(l.p1 - p1);
        Vector3D distanceVector = l.p1 + (r * lambda) - (p1 + d * mu);
        float distance = distanceVector.magnitude();

        return {distance * (distance > 0) - distance * !(distance > 0), distanceVector};
    }

    //getters
    std::pair<const Point3D&, const Point3D&> Line2::getPoints() const
    {
        return {p1, p2};
    }

    //log
    std::ostream& operator<<(std::ostream& os, Line2&& line)
    {
        os << "{" << line.p1 << ", " << line.p2 << "}";
        return os;
    }
    std::ostream& operator<<(std::ostream& os, const Line2& line)
    {
        os << "{" << line.p1 << ", " << line.p2 << "}";
        return os;
    }

    Vector3D Line2::getDirection()
    {
        return {p2.x - p1.x, p2.y - p1.y, p2.z - p1.z};
    }
}}
