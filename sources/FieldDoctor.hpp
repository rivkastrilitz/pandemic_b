#pragma once 
#include <stdio.h>
#include "Player.hpp"

namespace pandemic{
    class FieldDoctor:public Player{
        public:
            FieldDoctor(Board& b,City c);
            FieldDoctor& treat(City c);
            std::string role();

    };



}