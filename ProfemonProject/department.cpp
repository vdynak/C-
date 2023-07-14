//
//  department.cpp
//  135
//
//  Created by Victoria Dynak on 5/16/23.
//

#include "department.hpp"
#include "trainer.hpp"
#include "profemon.hpp"

MLDepartment::MLDepartment(std::vector<Profemon> profemons){ //inheritance, initialization
    for(int i = 0; i < profemons.size(); i++){
        if(profemons[i].literalSpecialty(profemons[i].getSpecialty()) == "ML"){
            Trainer::addProfemon(profemons[i]);
        }
    }
}

bool MLDepartment::addProfemon(Profemon profemon){
    if(profemon.literalSpecialty(profemon.getSpecialty()) == "ML"){
        return true; //return Trainer::addProfemon(profemon)
    }
    return false;
}

SoftwareDepartment::SoftwareDepartment(std::vector<Profemon> profemons){
    for(int i = 0; i < profemons.size(); i++){
        if(profemons[i].literalSpecialty(profemons[i].getSpecialty()) == "SOFTWARE"){
            Trainer::addProfemon(profemons[i]);
        }
    }
}

bool SoftwareDepartment::addProfemon(Profemon profemon){
    if(profemon.literalSpecialty(profemon.getSpecialty()) == "SOFTWARE"){
        return true;
    }
    return false;
}

HardwareDepartment::HardwareDepartment(std::vector<Profemon> profemons){
    for(int i = 0; i < profemons.size(); i++){
        if(profemons[i].literalSpecialty(profemons[i].getSpecialty()) == "HARDWARE"){
            Trainer::addProfemon(profemons[i]);
        }
    }
}

bool HardwareDepartment::addProfemon(Profemon profemon){
    if(profemon.literalSpecialty(profemon.getSpecialty()) == "HARDWARE"){
        return true;
    }
    return false;
}
