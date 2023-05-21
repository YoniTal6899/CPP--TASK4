#pragma once
#include <iostream>
#include <cmath>
#include "point.hpp"
using namespace std;

namespace ariel
{
    const int NEW_STACK=6;
    class Character
    {
        protected:
            bool playing;
            Point location;    
            int lifePoints;
            string name;

        public:
            Character() : location(Point(0,0)), lifePoints(0), name("Default"), playing(false)
            {}
            Character(Point loc, int lifeP, string NAME) : location(loc), lifePoints(lifeP), name(NAME), playing(false)
            {}
            string getName() const {return this->name;}
            void added(){this->playing=true;}
            bool isPlaying() const {return this->playing;}
            Point getLocation() const {return this->location;}
            bool isAlive() const {return this->lifePoints>0;}
            double distance(Character* other);
            void hit(int damage);
            int GetHP() const {return this->lifePoints;}
            string print();
            virtual string getType() const {return "Character";}
        
    };

    class Ninja : public Character
    {
        protected:
            int speed;
        
        public:
            Ninja() : Character() , speed(0){}
            Ninja(Point loc, int HP, string name, int speed) : Character(loc,HP,name) , speed(speed){}
            int getSpeed()const{return this->speed;}
            void move(Character* enemy);
            void slash(Character* enemy);
            string print() {return "N "+Character::print();}
            string getType() const override {return "Ninja";}
    };   
}