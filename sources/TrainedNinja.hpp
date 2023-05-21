#pragma once
#include "Character.hpp"
using namespace ariel;

class TrainedNinja : public Ninja
{        
    public:
        TrainedNinja () : Ninja(){}
        TrainedNinja (string name, Point loc) : Ninja(loc,120,name,12){}
};