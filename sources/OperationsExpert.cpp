
#include "OperationsExpert.hpp"
namespace pandemic{


    OperationsExpert::OperationsExpert(Board& b ,City c):Player(b,c){
    
    }

    OperationsExpert& OperationsExpert::build(){
        if(! board.is_research_station(get_city())){
            board.set_research(get_city());
        }
        return *this;
    }

    string OperationsExpert::role(){
        return "OperationsExpert";
    }

} 