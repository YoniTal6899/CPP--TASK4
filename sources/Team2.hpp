#pragma once
#include "Team.hpp"
using namespace std;

namespace ariel
{
    class Team2 : public Team
    {
        public:
        Team2() : Team(){}
        Team2(Character* leader) : Team(leader){}
        void print() override;  // Override the print() function
        void attack(Team* other) override;  // Override the attack() function
    };
}
