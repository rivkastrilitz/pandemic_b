#include "Virologist.hpp"

namespace pandemic{

    Virologist::Virologist(Board& b ,City c):Player(b,c){}

    
    Virologist& Virologist::treat(City c){
       
        if(cardes.find(c)!=cardes.end()){
            if(board[c]==0){
                throw ("infection level in this city is 0");
            }
            
            if(board.is_cuerd(board.get_city_color(c))){
                board[c]=0;
            }
            else{
            board[c]-=1;
            }
        
        }else{
            Player::treat(c);
        }
        return *this;


    }

    string Virologist::role(){
        return "Virologist";
    } 
}