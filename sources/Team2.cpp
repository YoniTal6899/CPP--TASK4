#include "Team2.hpp"
using namespace ariel;

void Team2::print()
{
    for (Character* mem : this->members)
    {
        if(mem->getType()=="Cowboy")
        {
            Cowboy* cowboy = dynamic_cast<Cowboy*>(mem);
            cout << cowboy->print() <<endl;

        }
        if(mem->getType()=="Ninja")
        {
            Ninja* ninja = dynamic_cast<Ninja*>(mem);
            cout <<ninja->print() << endl;
        }
    }
}

void Team2::attack(Team* other)
{
    if(other==nullptr){__throw_invalid_argument("Enemy team doesn't exsits!");}
    if(!this->teamLead->isAlive()){this->teamLead=assignLeader();}
    Character* closest_enemy= this->findClosestEnemy(other);
    for(Character* mem : this->members)
    {
        Character* closest_enemy= this->findClosestEnemy(other);
        if(mem->isAlive() && closest_enemy->isAlive())
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
            if(mem->getType()=="Ninja")
            {
                Ninja* ninja = dynamic_cast<Ninja*>(mem);
                if(!closest_enemy->isAlive()){closest_enemy=this->findClosestEnemy(other);}
                if(ninja->distance(closest_enemy)<=1){ninja->slash(closest_enemy);}
                else{ninja->move(closest_enemy);}            
            }
        }
    }    
}