#include "Medic.hpp"

namespace pandemic{

     Medic::Medic(Board& b ,City c):Player(b,c){
        
    }

     Medic& Medic::treat(City c){
        if(c==get_city()){
            if(board[c]==0){
                throw ("infection level in this city is 0");
            }
            board[c]=0;
        }else{
             throw("you cant use treat outside the wanted city");
        }
        return *this;
    }



    Medic& Medic::drive(City c ){
       Player::drive(c);
        auto_treat(c);
        return *this;

    }

    Medic& Medic::fly_direct(City c){
        Player::fly_direct(c);
        auto_treat(c);
        return *this;
    }

    Medic& Medic::fly_charter(City c){
       Player::fly_charter(c);
        auto_treat(c);
        return *this;
    }

    Medic& Medic::fly_shuttle(City c){
        Player::fly_shuttle(c);
        auto_treat(c);
        return *this;

    }

    void Medic::auto_treat(City city){
       if(board.is_cuerd(board.get_city_color(city))){
            board[city]=0;
        } 
    }

    Medic& Medic::discover_cure(Color color){
        Player::discover_cure(color);
        if(board.is_cuerd(board.get_city_color(get_city()))){
            board[get_city()]=0;
        } 
        
        return *this;
    }

     string Medic::role(){
        return "Medic";
    }
}