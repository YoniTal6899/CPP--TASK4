#include "Teaclearm2.hpp"
using namespace ariel;
using namespace std;
#include <limits>

Character* SmartTeam::getCowboyTarget(Team* other)
{
    int TotalDamage=0;
    Character* target=nullptr;
    for(Character* mem : this->members){if(mem->getType()=="Cowboy"){TotalDamage+=10;}}
    for(Character* mem: other->getMembers())
    {
        if(mem->isAlive() && mem->GetHP()<=TotalDamage)
        {
            target=mem;
            TotalDamage=mem->GetHP();
        }
    }
    return target;
}

int SmartTeam::GetNinjaDamage(Character* target)
{
    int HP=target->GetHP();
    for(Character* mem : this->getMembers())
    {        
        if(mem->getType()=="Ninja" && mem->isAlive())
        {
            if(mem->distance(target)<1){HP-=40;}
        }
    }
    if(HP<0){return 0;}
    return HP;
}

Character* SmartTeam::getNinjaTarget(Team* other)
{
    Character* target=nullptr;
    int minHP=numeric_limits<int>::max();
    for(Character* mem : other->getMembers())
    {
        if(mem->getType()=="Ninja" && mem->isAlive())
        {
            int NinjaDamage=GetNinjaDamage(mem);
            if(NinjaDamage==0){return mem;}
        }
    }
    for(Character* mem : other->getMembers())
    {
        if(mem->getType()=="Cowboy" && mem->isAlive())
        {
            int NinjaDamage=GetNinjaDamage(mem);
            if(NinjaDamage<mem->GetHP() && NinjaDamage<minHP)
            {
                minHP=NinjaDamage;
                target=mem;
            }
        }
    }
    return target;

}

int SmartTeam::GetNinjasNum()
{
    int counter=0;
    for(Character* mem: this->members){if(mem->getType()=="Ninja"){counter+=1;}}
    return counter;
}

Character* SmartTeam::getClosestCowboy(Team* other)
{
    Character* target= other->getLeader();
    int minSteps=numeric_limits<int>::max();
    for(Character* mem : other->getMembers())
    {
        if(mem->getType()=="Cowwboy")
        {
            for(Character* ninja : this->members)
            {
                if(ninja->getType()=="Ninja")
                {
                    Ninja* nin= dynamic_cast<Ninja*>(ninja);
                    int steps=mem->distance(nin)/nin->getSpeed();
                    if(steps<minSteps)
                    {
                        minSteps=steps;
                        target=mem;
                    }
                }
            }
        }
    }
    return target;

}

Character* SmartTeam::findClosestEnemy(Team* other)
{
    Character* target=this->getCowboyTarget(other);
    if(target){return target;}
    target=this->getNinjaTarget(other);
    if(target){return target;}
    return this->getClosestCowboy(other);
}

void SmartTeam::attack(Team* other)
{
    if(other==nullptr){__throw_invalid_argument("Enemy team doesn't exsits!");}
    if(other->stillAlive()==0){__throw_runtime_error("Attacking dead team");}
    Character* CowboyTarget=this->getCowboyTarget(other);
    Character* NinjaTarget=this->getNinjaTarget(other);
    if(!NinjaTarget){NinjaTarget=this->getCowboyTarget(other);}
    if(CowboyTarget)
    {
        Team::attack(other);
        return;
    }
    if(NinjaTarget)
    {
        Team::attackNinjas(other,NinjaTarget);
        Team::attackCowboys(other,NinjaTarget);
    }

}