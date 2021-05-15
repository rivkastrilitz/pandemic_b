#pragma once 
#include <stdio.h>
#include "Player.hpp"

namespace pandemic{
    class Virologist:public Player{

        public:
            Virologist(Board& b ,City c);
            Virologist& treat(City c);
            std::string role();
    };



}