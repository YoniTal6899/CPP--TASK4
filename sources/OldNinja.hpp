#pragma once
#include "Character.hpp"
using namespace ariel;

class OldNinja   : public Ninja
{        
    public:
        OldNinja () : Ninja(){}
        OldNinja (string name, Point loc) : Ninja(loc,150,name,8){}
};