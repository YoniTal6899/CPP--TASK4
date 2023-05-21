#pragma once
#include <iostream>
#include <list>
#include "Character.hpp"
#include "Cowboy.hpp"
#include "YoungNinja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
using namespace std;

namespace ariel
{
    class Team
    {
        protected:
            list<Character*> members;   
            Character* teamLead;
        public:
            Team(Character* leader) : teamLead(leader){this->add(leader);}
            Team() : teamLead(new Character()){}
            void add(Character* mem);
            int stillAlive();
            virtual void print();
            virtual void attack(Team* other);
            Character* assignLeader();
            virtual Character* findClosestEnemy(Team* other);     
            Character* getLeader(){return this->teamLead;}
            list<Character*> getMembers() const {return this->members;}
            void attackCowboys(Team* other, Character* closest_enemy);
            void attackNinjas(Team* other, Character* closest_enemy);     
    };
}