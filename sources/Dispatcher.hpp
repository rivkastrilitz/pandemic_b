#pragma once 
#include <stdio.h>
#include "Player.hpp"

namespace pandemic{
    class Dispatcher:public Player{
        public:
           Dispatcher(Board& b,City c); 
           Dispatcher& fly_direct(City c);
           std::string role();

    
    };



}