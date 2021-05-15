#include "Dispatcher.hpp"

namespace pandemic{
   
    Dispatcher::Dispatcher(Board& b ,City c):Player(b,c){ }
    
    Dispatcher& Dispatcher::fly_direct(City c){
        if(get_city()==c){
            throw ("cannot flay from city to itself");
        }
        if(board.is_research_station(get_city())){
            set_city(c);

        }else{
            Player::fly_direct(c);
        }
        return *this;
    }

    string Dispatcher::role(){
        return "Dispatcher";
    }


}