#include "FieldDoctor.hpp"

namespace pandemic{

    FieldDoctor::FieldDoctor(Board& b ,City c):Player(b,c){
        
        
    }
    FieldDoctor& FieldDoctor::treat(City c){
       
        if( c==get_city()|| board.is_nighbor(c,get_city()) ){
            if(!(board[c]==0)){
                if(board.is_cuerd(board.get_city_color(c))){
                    board[c]=0;
                }
                else
                {
                board[c]-=1;}
            }else{
                throw ("infection level in this city is 0");
            }
        }else{
            throw("cant use treat in unconnected city");
        }
        return *this;
    }

    string FieldDoctor::role(){
        return "FieldDoctor";
    }
    
}