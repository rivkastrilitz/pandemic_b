#pragma once 
#include <stdio.h>
#include "Player.hpp"

namespace pandemic{
    class Researcher:public Player{

        public:
            Researcher(Board& b ,City c);
            Researcher& discover_cure(Color color);
            std::string role();
    };



}