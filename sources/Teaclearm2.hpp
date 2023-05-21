#include "Team.hpp"
using namespace std;
namespace ariel
{
    class SmartTeam : public Team
    {
        private:

        public:
        SmartTeam() : Team(){}
        SmartTeam(Character* leader) : Team(leader){}
        void attack(Team* other) override;  // Override the attack() function
        Character* getCowboyTarget(Team* other);
        Character* findClosestEnemy(Team* other) override;
        Character* getNinjaTarget(Team* other);
        int GetNinjaDamage(Character* target);
        Character* getClosestCowboy(Team* other);
        int GetNinjasNum();
    };
}
