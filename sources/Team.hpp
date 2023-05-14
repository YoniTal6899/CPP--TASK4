#pragma once
#include <iostream>
#include <list>
#include "Character.hpp"
using namespace std;

namespace ariel
{
    class Team
    {
        private:
            list<character*> members;   
            character* teamLead;
        public:
            Team(character* leader) : teamLead(leader){this->add(leader);}
            Team() : teamLead(new character()){}
            void add(character* mem);
            int stillAlive();
            void print();
            void attack(Team* other);
            character* assignLeader();
            character* findClosestEnemy(Team* other);          
    };

    class team2 : public Team
    {};

    class SmartTeam : public Team
    {};
}