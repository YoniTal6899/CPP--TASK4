#pragma once
#include <iostream>
#include <cmath>
using namespace std;

namespace ariel
{
    class Point
    {
        private:
            double x_loc;
            double y_loc;
   
        public:
            Point() : x_loc(0), y_loc(0)
            {}
            Point(double xpos, double ypos) : x_loc(xpos), y_loc(ypos)
            {}
            double get_x() const{return this->x_loc;}
            double get_y() const{return this->y_loc;}
            double distance(Point other);
            static Point moveTowards(Point src, Point dst, double distance);
            string print();
        
    };
}