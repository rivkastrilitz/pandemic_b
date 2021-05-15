#pragma once 
#include <stdio.h>
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"

namespace pandemic{
    class OperationsExpert:public Player{
        public:
            OperationsExpert(Board& b ,City c);
            OperationsExpert& build();
            std::string role();

       
            

    };

}