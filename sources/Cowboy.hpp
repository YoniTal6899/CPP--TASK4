#pragma once
#include "Character.hpp"
using namespace ariel;

class Cowboy : public Character
    {
        protected:
            int bulletsNum;
        
        public:
            Cowboy() : Character() , bulletsNum(0){}
            Cowboy(string name,Point loc) : Character(loc,110,name) , bulletsNum(6){}
            int getBullets() const {return this->bulletsNum;}
            void shoot(Character* enemy);
            bool hasboolets() const {return (this->getBullets()>0);}
            void reload();
            string print() {return "C "+Character::print();}
            string getType() const override {return "Cowboy";}
    };