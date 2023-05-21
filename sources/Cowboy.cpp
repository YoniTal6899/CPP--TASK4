#include "Cowboy.hpp"
using namespace ariel;

void Cowboy::reload()
{
    if(!this->isAlive()){__throw_runtime_error("Dead cowboy can't reload");}
    this->bulletsNum=NEW_STACK;
}
void Cowboy::shoot(Character* enemy)
{
    if(enemy==this){__throw_runtime_error("Self harm...?");}
    if(!enemy->isAlive()){__throw_runtime_error("Enemy is dead!");}
    if(!this->isAlive()){__throw_runtime_error("Character is dead!");}
    if(this->isAlive())
    {
        if(this->hasboolets())
        {
            enemy->hit(10);
            this->bulletsNum-=1;
        }        
    }
}
