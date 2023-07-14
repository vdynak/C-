//
//  trainer.hpp
//  135
//
//  Created by Victoria Dynak on 5/14/23.
//

#ifndef trainer_hpp
#define trainer_hpp

#include <iostream>
#include <vector>
#include <string>
#include "profemon.hpp"
//using namespace std;

class Trainer{
public:
    Trainer();
    Trainer(std::vector<Profemon> profemons);
    bool contains(std::string name);
    bool addProfemon(Profemon profemon);
    bool removeProfemon(std::string name);
    void setTeamMember(int slot, std::string name);
    bool chooseProfemon(int slot);
    Profemon getCurrent();
    void printProfedex();
    void printTeam();
private:
    std::vector<Profemon> profedex;
    Profemon team[3];
    Profemon *selectProfemon;
};

#endif /* trainer_hpp */
