#include "Character.hpp"
using namespace ariel;

double Character::distance(Character* other)
{
    double dist= this->getLocation().distance(other->getLocation());
    return dist;
}

void Character::hit(int damage)
{
    if(damage<0){__throw_invalid_argument("Damage can't be negative!");}
    this->lifePoints-=damage;
    if(this->lifePoints<=0)
    {
        this->lifePoints=0;        
    }
}

string Character::print()
{
    if(this->isAlive())
    {
        string str= this->getName()+" , "+to_string(this->lifePoints)+" , "+this->getLocation().print();
        return str;
    }
    string str= "( "+this->getName()+" ) , "+this->getLocation().print();
    return str;
}

void Ninja::move(Character* enemy)
{
    this->location = this->location.moveTowards(this->getLocation(),enemy->getLocation(),this->speed);
}

void Ninja::slash(Character* enemy)
{
    if(enemy==this){__throw_runtime_error("Self harm...?");}
    if(!enemy->isAlive()){__throw_runtime_error("Enemy is dead!");}
    if(!this->isAlive()){__throw_runtime_error("Character is dead!");}
    if(this->isAlive() && (this->distance(enemy)<1))
    {
        enemy->hit(40);
    }
}