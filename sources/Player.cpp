
#include "Player.hpp"

using namespace std;
using pandemic::Board;


namespace pandemic{

    

    Player::Player(Board& b ,City c):board(b),city(c){}


    // drive to c if c is neighbor of current city 
    Player& Player::drive(City c ){
      if(get_city()!=c && board.is_nighbor(get_city(),c)){
        set_city(c);
      }else{
          throw invalid_argument("cant drive to non connected city");
      }
        return *this;
    }

    Player& Player::fly_direct(City c){
        if(cardes.find(c)!=cardes.end() && get_city()!=c){
            cardes.erase(c);
            set_city(c);
        }else{
            throw("you dont have the needed card for fly_direct");
        }
        return *this;
    }

    Player& Player::fly_charter(City c){
        if(cardes.find(get_city())!=cardes.end() && get_city()!=c){
            cardes.erase(get_city());
            set_city(c);
        }else{
            throw("you dont have the needed card for fly_charter");
        }
        return *this;
    }

    Player& Player::fly_shuttle(City c){
       if(board.is_research_station(get_city()) && get_city()!=c){
           if(board.is_research_station(c)){
               set_city(c);
            }else{
                throw("cant fly_shuttle to a city with no research station");
            }
        }else{
            throw("cant fly_shuttle if you not in city with research station right now");
        }
        return *this;
    }

    Player& Player::build(){
        if(!board.is_research_station(get_city())){
            if( cardes.find( get_city() )!=cardes.end()){
                board.set_research(get_city());
                cardes.erase(get_city());
            }else{
                 throw("you dont have the needed card for build"); 
            }

        }
        return *this;
    }

    int Player::find_cardes(Color color){
        int count_cardes=0;
        for (const auto& card: cardes){
            Color curr_color=board.get_city_color(card);
            if(curr_color==color){
            count_cardes++;
            }
        }
        return count_cardes;   
    }

    void Player::erase_cardes(Color color,int num_cardes){
        int erased=0;
        
        for(auto card=cardes.begin();card!=cardes.end();){
            if(board.get_city_color(*card)==color){
                cardes.erase(card++);
                erased++;
                if(erased==num_cardes){
                    return;
                }
            }else{
                ++card;
            }
        }

    }
    

    Player& Player::discover_cure(Color color){

       if(board.is_cuerd(color))
       {
           return *this;
       }
        if(board.is_research_station(get_city())){
                if(find_cardes(color)>=FIVE){
                    erase_cardes(color,FIVE);
                    board.set_cure(color); 

                }else{
                    throw("you dont have enough cardes in the disease color");
                }
               
        }else{
            throw("cant discover cure when not in city with reaserch station");
        }
        return *this;
    }
    

    Player& Player::treat(City c){
       
        if(c==get_city()){
            if(board[c]==0){
                throw ("infection level in this city is 0");
            }
            
                if(board.is_cuerd(board.get_city_color(c))){
                    board[c]=0;
                }
                else{
                board[c]=board[c]-1;}
           
        }else{
            throw("you cant use treat outside the wanted city");
        }
        return *this;
    }
    
    Player& Player::take_card(City c){
        this->cardes.insert(c);
        return *this;
    }

    Player& Player::remove_cards(){
        this->cardes.clear();
        return *this;

     } 
}