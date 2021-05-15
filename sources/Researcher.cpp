#include "Researcher.hpp"

namespace pandemic{

     Researcher::Researcher(Board& b ,City c):Player(b,c){
         
        
    }

    Researcher& Researcher::discover_cure(Color color){
     
        if(board.is_cuerd(color)){
            return *this;
        }
            
            if(find_cardes(color)>=FIVE){
                erase_cardes(color,FIVE);
                board.set_cure(color); 

            }else{
                throw("you dont have enough cardes in the disease color");
            }   
       
        return *this;
        
    }

    string Researcher::role(){
        return "Researcher";
    }
}