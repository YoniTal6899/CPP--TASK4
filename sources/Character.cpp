#include "Character.hpp"
using namespace ariel;

double character::distance(character* other)
{
    double dist= this->getLocation().distance(other->getLocation());
    return dist;
}

void character::hit(int damage)
{
    this->lifePoints-=damage;
    if(this->lifePoints<=0)
    {
        this->lifePoints=0;
    }
}

string character::print()
{
    if(this->isAlive())
    {
        string str= this->getName()+" , "+to_string(this->lifePoints)+" , "+this->getLocation().print();
        return str;
    }
    string str= "( "+this->getName()+" ) , "+this->getLocation().print();
    return str;
}

void Cowboy::shoot(character* enemy)
{
    if(this->isAlive() && this->hasboolets())
    {
        enemy->hit(10);
        this->bulletsNum-=1;
    }
    else{this->reload();}
}

void Ninja::move(character* enemy)
{
    this->location = this->location.moveTowards(this->getLocation(),enemy->getLocation(),this->speed);
}

void Ninja::slash(character* enemy)
{
    if(this->isAlive() && (this->distance(enemy)<1))
    {
        enemy->hit(40);
    }
    else{this->move(enemy);}
}