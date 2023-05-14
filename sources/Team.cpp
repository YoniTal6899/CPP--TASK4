#include "Team.hpp"
using namespace ariel;

const int BIG_DISTANCE= 1000000;
void Team::add(character* mem)
{
    if (this->members.size()<9){this->members.push_back(mem);}
}

int Team::stillAlive()
{
    int counter=0;
    for(character* mem : this->members){if(mem->isAlive()){counter+=1;}}
    return counter;
}

void Team::print()
{
    for(character* mem : this->members)
    {
        if(mem->getType()=="Cowboy")
        {
            Cowboy* cowboy = dynamic_cast<Cowboy*>(mem);
            cout << cowboy->print() <<endl;

        }

    }
    for(character* mem : this->members)
    {
        if(mem->getType()=="Ninja")
        {
            Ninja* ninja = dynamic_cast<Ninja*>(mem);
            cout <<ninja->print() << endl;
        }
    }
    
}

character* Team::assignLeader()
{
    double minDist=BIG_DISTANCE;
    double dist=0;
    character* newLeader=this->members.front();
    for(character* mem : this->members)
    {
        if(mem->isAlive())
        {
            dist=mem->getLocation().distance(this->teamLead->getLocation());
            if(dist<minDist)
            {
                minDist=dist;
                newLeader=mem;
            }
        }
    }
    return newLeader;
}

character* Team::findClosestEnemy(Team* other)
{
    double minDist=BIG_DISTANCE;
    double dist=0;
    character* closestEnemy=other->members.front();
    for(character* mem : other->members)
    {
        if(mem->isAlive())
        {
            dist=mem->getLocation().distance(this->teamLead->getLocation());
            if(dist<minDist)
            {
                minDist=dist;
                closestEnemy=mem;
            }
        }
    }
    return closestEnemy;

}
void Team::attack(Team* other)
{
    if(!this->teamLead->isAlive()){this->teamLead=assignLeader();}
    character* closest_enemy= this->findClosestEnemy(other);
    for(character* mem : this->members)
    {
        if(mem->isAlive())
        {
            if(mem->getType()=="Cowboy")
            {
                Cowboy* cowboy = dynamic_cast<Cowboy*>(mem);
                if(!closest_enemy->isAlive()){closest_enemy=findClosestEnemy(other);}
                cowboy->shoot(closest_enemy);            
            }
            if(mem->getType()=="Ninja")
            {
                Ninja* ninja = dynamic_cast<Ninja*>(mem);
                if(!closest_enemy->isAlive()){closest_enemy=findClosestEnemy(other);}
                ninja->slash(closest_enemy);            
            }
        }
    }
}

