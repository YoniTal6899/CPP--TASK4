#include "point.hpp"
using namespace ariel;


double Point::distance(Point other)
{
    double x_diff = other.get_x() - this->x_loc;
    double y_diff = other.get_y() - this->y_loc;
    double dist = sqrt((x_diff * x_diff) + (y_diff * y_diff));
    return dist;
}

Point Point::moveTowards(Point src, Point dst, double dist)
{
    double pointsDistance=src.distance(dst);
    if(pointsDistance<=dist){return dst;}
    double ratio = dist / pointsDistance;
    double newX = (src.get_x()*(1 - ratio)) + (ratio * dst.get_x());
    double newY = (src.get_y()*(1 - ratio)) + (ratio * dst.get_y());
    return Point(newX,newY);
}

string Point::print()
{
    string str= "( "+to_string(this->get_x())+" , " +to_string(this->get_y())+" )";
    return str;
}