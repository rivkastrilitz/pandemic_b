#include "Scientist.hpp"
#include "Player.hpp"

namespace pandemic{

    Scientist::Scientist(Board& b ,City c , int n):Player(b,c), num(n){
        
    }

   

    Scientist& Scientist::discover_cure(Color color){

         if(board.is_cuerd(color))
         {
             return *this;
         }
        if(board.is_research_station(get_city())){
            
              
                if(find_cardes(color)>=num){
                    erase_cardes(color,num);
                    board.set_cure(color); 

                }else{
                    throw("you dont have enough cardes in the disease color");
                }
              
        }else{
            throw("cant discover cure when not in city with reaserch station");
        }
        return *this;
    }
     

     
    string Scientist::role(){
        return "Scientist";
    } 

    

}
