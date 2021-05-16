#include "Board.hpp"

using namespace std;

namespace pandemic{

    Board::Board(){
        
        read_city_file();
       
    }
 
    void Board::read_city_file(){
        ifstream file{"cities_map.txt"};

        string line;
        string city;
        string nighbor_city;
        string color;

        
        while(getline(file,line)){
            istringstream iss(line);

            iss>>city;
            
            cubes[city_str.at(city)]=0;
            research_station[city_str.at(city)]=false;

            iss>>color;
            
            cityes_color_map[city_str.at(city)]=color_str.at(color);
    
            while(iss >> nighbor_city){
                
                connections[city_str.at(city)].push_back(city_str.at(nighbor_city));

            }
        }

    }

    int& Board::operator[](City c) {  
           
        return cubes[c];
        
    }  
    

    bool Board::is_clean(){
        for (auto const& x : cubes){
            if(x.second!=0){
                return false;
            }

        }
        return true;   
    }

    void Board::remove_cures(){
       for (auto& x:cure){
           cure[x.first]=false;
       }   
    }

    void Board::remove_stations(){
        research_station.clear();
    }

    ostream& operator<<(std::ostream& out, Board b){
        out<<"level of disease"<<endl;
       for (auto const& x :b.cubes){
           out<<city_to_string(x.first)<<"["<<x.second<<"]"<<endl;

       }
        out<<"cure that has been found"<<endl;
        out<<"red"<<"="<<b.cure[Color::Red];
        out<<"blue"<<"="<<b.cure[Color::Blue]<<endl;
        out<<"yellow"<<"="<<b.cure[Color::Yellow]<<endl;
        out<<"black"<<"="<<b.cure[Color::Black]<<endl;

        out<<"resarch statin that has been build"<<endl;
        for (auto const& x : b.research_station ){
           out<<city_to_string(x.first)<<" , ";

        }
        out<<endl;
        return out;
    }

    bool Board::is_nighbor(City c1,City c2){
       return(find(connections[c1].begin(),connections[c1].end(), c2) !=connections[c1].end());
    
    }
    
    bool Board::is_research_station(City c){
       return research_station[c];  
    }

    // using insert if exsists doesnt override
    void Board::set_research(City c){
        research_station[c]=true;
    }
    
    Color Board::get_city_color(const City city){ 
         return this->cityes_color_map[city];
    }

    bool Board::is_cuerd(Color color){
        return cure[color];
    }
    void Board::set_cure(Color color){
        this->cure[color]=true;
    }
   
           

}    
    

