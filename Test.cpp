#include "doctest.h"

#include <iostream>
#include <string>
using namespace std;

#include "sources/Character.hpp"
#include "sources/Team.hpp"
#include "sources/point.hpp"
using namespace ariel;

TEST_CASE("TESTS")
{
    Point p1(0.0,0.0);
    Point p2(4.0,0.0);
    Point p3(0.0,4.0);
    CHECK(p1.distance(p2)==p2.distance(p1));
    CHECK(p1.distance(p3)==p3.distance(p1));
    CHECK(p1.distance(p2)==p1.distance(p3));
    CHECK(p1.distance(p2)==4.0);

    Cowboy* c1= new Cowboy("Cowboy1",p1);
    CHECK(c1->getBullets()==6);
    CHECK(c1->getName()=="Cowboy1");
    CHECK(c1->hasboolets()==true);
    CHECK(c1->isAlive()==true);
    CHECK_NOTHROW(c1->reload());
    CHECK(c1->getBullets()==12);

    YoungNinja* yn1= new YoungNinja("YoungNinja1",p2);
    CHECK(yn1->getName()=="YoungNinja1");
    CHECK(yn1->distance(c1)==4.0);
    CHECK(yn1->getSpeed()==14);
    CHECK_NOTHROW(yn1->move(c1));

    TrainedNinja* tn1= new TrainedNinja("TraindNinja1",p3);
    CHECK(tn1->getName()=="TraindNinja1");
    CHECK(tn1->distance(c1)==4.0);
    CHECK(tn1->getSpeed()==12);
    CHECK_NOTHROW(tn1->move(c1));

    Point p4(4.0,4.0);
    OldNinja* on1= new OldNinja("OldNinja1",p4);
    CHECK(on1->getName()=="OldNinja1");
    CHECK(on1->getSpeed()==8);
    CHECK_NOTHROW(on1->move(c1));
    CHECK_NOTHROW(on1->move(tn1));
}