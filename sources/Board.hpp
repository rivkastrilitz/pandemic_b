#pragma once
#include <stdio.h>
#include <unordered_map>
#include <vector>
#include <string>
#include <array>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include "Color.hpp"
#include "City.hpp"

namespace pandemic{
    class Board{

        public:
            Board();
            void read_city_file();
            bool is_clean();
            int& operator[](City c);
            friend std::ostream& operator << (std::ostream& out ,const Board b);
            void remove_cures();
            void remove_stations();

            bool is_nighbor(City c1,City c2);
            bool is_research_station(City c);
            void set_research(City c);
            Color get_city_color(const City city);
            bool is_cuerd(Color color);
            void set_cure(Color color);
            
           
        

        private:
            std::unordered_map<City,int>cubes;
            std::unordered_map<City,std::vector<City>> connections;
            std::unordered_map<City,Color>cityes_color_map;
            
            // defult is false
            unordered_map<City,bool>research_station;
           
            unordered_map<Color,bool>cure={ { Color::Blue,false}, { Color::Black ,false}, {Color::Red ,false}, {Color::Yellow,false }    };


        

    };
}

