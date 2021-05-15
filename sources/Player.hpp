# pragma once 
# include <stdio.h>
#include "Color.hpp"
#include "City.hpp"
#include "Board.hpp"
#include <vector>
#include <iostream>
#include <map>
#include <array>
#include <bits/stdc++.h>
#define FIVE 5

using pandemic::Board;

namespace pandemic{
    class Player{
        public:
            Player(Board& b ,City city);

       
        virtual Player& drive(City c );
        virtual Player& fly_direct(City c);
        virtual Player& fly_charter(City c);
        virtual Player& fly_shuttle(City c);
        virtual Player& build();
        virtual Player& discover_cure(Color color);
        virtual Player& treat(City c);
        Player& take_card(City c);
        Player& remove_cards();
        
        // pure virtual
        virtual std::string role ()=0;

        // inline func
        City get_city(){
            return this->city;
        }
        void set_city(City c){
            this->city=c;
        }

        protected:
            Board& board;
            City city;
            std::unordered_set <City> cardes ;
            int find_cardes(Color color);
            void erase_cardes(Color color,int num_cardes);






    };
}

