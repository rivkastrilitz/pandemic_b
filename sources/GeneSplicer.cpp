#include "GeneSplicer.hpp"


namespace pandemic{

    GeneSplicer::GeneSplicer(Board& b ,City c):Player(b,c){}

    GeneSplicer& GeneSplicer::discover_cure(Color color){
        if(board.is_cuerd(color)){
            return *this;
        }
          
        if(!board.is_research_station(get_city())){
            throw("cant discover cure when not in city with reaserch station");
        } 
        int erased=0;
        if(cardes.size()>=FIVE){
            for(auto it=cardes.begin();it!=cardes.end();){
                cardes.erase(it++);
                erased++;
                if(erased==FIVE){
                    break;
                }
            }
            board.set_cure(color); 

        }else{
            throw("you dont have enough cardes in the disease color");
        }
                  
        return *this;
    }

    string GeneSplicer::role(){
        return "GeneSplicer";
    }

}