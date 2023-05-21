#include "Team.hpp"
using namespace ariel;

const int BIG_DISTANCE= 1000000;
void Team::add(Character* mem)
{
    if(mem->isPlaying()){__throw_runtime_error("Player is already playing!");}
    if (this->members.size()<10){
        this->members.push_back(mem);
        mem->added();
    }
    else{__throw_runtime_error("Team is full!");}
}

int Team::stillAlive()
{
    int counter=0;
    for(Character* mem : this->members)
    {
        if(mem->isAlive()){counter+=1;}
    }
    return counter;
}

void Team::print()
{
    for(Character* mem : this->members)
    {
        if(mem->getType()=="Cowboy")
        {
            Cowboy* cowboy = dynamic_cast<Cowboy*>(mem);
            cout << cowboy->print() <<endl;

        }

    }
    for(Character* mem : this->members)
    {
        if(mem->getType()=="Ninja")
        {
            Ninja* ninja = dynamic_cast<Ninja*>(mem);
            cout <<ninja->print() << endl;
        }
    }
    
}

Character* Team::assignLeader()
{
    double minDist=BIG_DISTANCE;
    double dist=0;
    Character* newLeader=this->members.front();
    for(Character* mem : this->members)
    {
        if(mem->isAlive())
        {
            dist=mem->distance(this->teamLead);
            if(dist<=minDist)
            {
                minDist=dist;
                newLeader=mem;
            }
        }
    }
    return newLeader;
}

Character* Team::findClosestEnemy(Team* other)
{
    double minDist=BIG_DISTANCE;
    double dist=0;
    Character* closestEnemy=other->members.front();
    for(Character* mem : other->members)
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
    if(other==nullptr){__throw_invalid_argument("Enemy team doesn't exsits!");}
    if(other->stillAlive()==0){__throw_runtime_error("Attacking dead team");}
    Character* closest_enemy= this->findClosestEnemy(other);
    this->attackCowboys(other,closest_enemy);
    if(other->stillAlive())
    {
        if(!closest_enemy-> isAlive()){closest_enemy= this->findClosestEnemy(other);}
        this->attackNinjas(other,closest_enemy);
    }
    
}
    

void Team::attackCowboys(Team* other, Character* closest_enemy)
{
    if(!this->teamLead->isAlive()){this->teamLead=assignLeader();}

    for(Character* mem : this->members)
    {
        if(mem->isAlive() && other->stillAlive())
        {
            if(mem->getType()=="Cowboy")
            {
                Cowboy* cowboy = dynamic_cast<Cowboy*>(mem);
                if(!closest_enemy->isAlive()){closest_enemy=this->findClosestEnemy(other);}
                if(cowboy->hasboolets())
                {
                    cowboy->shoot(closest_enemy);
                } 
                else{cowboy->reload();}                                           
            }
        }
    }
}

void Team::attackNinjas(Team* other,Character* closest_enemy)
{
    if(!this->teamLead->isAlive()){this->teamLead=assignLeader();}
    for(Character* mem : this->members)
    {
        if(mem->isAlive() && other->stillAlive())
        {
            if(mem->getType()=="Ninja")
            {
                Ninja* ninja = dynamic_cast<Ninja*>(mem);
                if(!closest_enemy->isAlive()){closest_enemy=this->findClosestEnemy(other);}
                if(ninja->distance(closest_enemy)<1){ninja->slash(closest_enemy);}
                else{ninja->move(closest_enemy);}
                }                            
            }
        }
    }







