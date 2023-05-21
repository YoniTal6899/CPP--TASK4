#pragma once
#include "Character.hpp"
using namespace ariel;

class YoungNinja  : public Ninja
    {        
        public:
            YoungNinja() : Ninja(){}
            YoungNinja(string name, Point loc) : Ninja(loc,100,name,14){}
    };