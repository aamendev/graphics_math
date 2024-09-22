#include <iostream>
#include "../all.h"
using namespace Lina::Math;
int main()
{
    Point3D p0(0, 0, 1.0);
    Point3D p1(5.0, 0.0, 1.0);
    Point3D p2(2.5, 2.5, 1.0);

    Point3D l1(2.5, 2.6, 3.0);
    Point3D l2(2.5,2.5, 0.0);
    Line2 l(l1, l2);
    Triangle t(p0, p1, p2);
    t.getPlane().debug();
    std::cout<< t.lineIntersects(l);
    t.debug();
}
