#pragma once
#include <iostream>
#include <cmath>
#include "point.hpp"
using namespace std;

namespace ariel
{
    const int NEW_STACK=6;
    class character
    {
        protected:
            Point location;    
            int lifePoints;
            string name;

        public:
            character() : location(Point(0,0)), lifePoints(0), name("Default")
            {}
            character(Point loc, int lifeP, string NAME) : location(loc), lifePoints(lifeP), name(NAME)
            {}
            string getName() const {return this->name;}
            Point getLocation() const {return this->location;}
            bool isAlive() const {return this->lifePoints>0;}
            double distance(character* other);
            void hit(int damage);
            string print();
            virtual string getType() const {return "Character";}
        
    };

    class Cowboy : public character
    {
        protected:
            int bulletsNum;
        
        public:
            Cowboy() : character() , bulletsNum(0){}
            Cowboy(string name,Point loc) : character(loc,110,name) , bulletsNum(6){}
            int getBullets() const {return this->bulletsNum;}
            void shoot(character* enemy);
            bool hasboolets() const {return (this->getBullets()>0);}
            void reload(){this->bulletsNum+=NEW_STACK;}
            string print() {return "C "+character::print();}
            string getType() const override {return "Cowboy";}
    };

    class Ninja : public character
    {
        protected:
            int speed;
        
        public:
            Ninja() : character() , speed(0){}
            Ninja(Point loc, int HP, string name, int speed) : character(loc,HP,name) , speed(speed){}
            int getSpeed()const{return this->speed;}
            void move(character* enemy);
            void slash(character* enemy);
            string print() {return "N "+character::print();}
            string getType() const override {return "Ninja";}
    };

    class YoungNinja  : public Ninja
    {        
        public:
            YoungNinja() : Ninja(){}
            YoungNinja(string name, Point loc) : Ninja(loc,100,name,14){}
    };

    class TrainedNinja : public Ninja
    {        
        public:
            TrainedNinja () : Ninja(){}
            TrainedNinja (string name, Point loc) : Ninja(loc,120,name,12){}
    };

    class OldNinja   : public Ninja
    {        
        public:
            OldNinja () : Ninja(){}
            OldNinja (string name, Point loc) : Ninja(loc,150,name,8){}
    };
}