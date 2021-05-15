
#pragma once 
#include <stdio.h>
#include "Player.hpp"

namespace pandemic{
    class Medic:public Player{

        public:
            Medic(Board& b ,City c);
            Medic& treat(City c);
            Medic& drive(City c );
            Medic& fly_direct(City c);
            Medic& fly_charter(City c);
            Medic& fly_shuttle(City c);
            Medic& discover_cure(Color color);
            void auto_treat(City city);
            std::string role();
    };



}