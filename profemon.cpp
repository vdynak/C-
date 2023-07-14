/*
 Victoria Dynak
 CSCI135
 Genady Maryash
 profemon.cpp
 */

#include <iostream>
#include <vector>
#include "profemon.hpp"
#include "skill.hpp"
using namespace std;

Profemon::Profemon(){
    profemonname = "Undefined";
}

Profemon::Profemon(std::string name, double max_health, Specialty specialty){
    profemonname = name;
    profemonhealth = max_health;
    profemonspecialty = specialty;
    requiredexperience = 50;
    experience = 0;
    profemonlevel = 0;
}

string Profemon::getName(){
    return profemonname;
}

Specialty Profemon::getSpecialty(){
    return profemonspecialty;
}

int Profemon::getLevel(){
    return profemonlevel;
}

double Profemon::getMaxHealth(){
    return profemonhealth;
}

void Profemon::setName(std::string name){
    profemonname = name;
}

void Profemon::levelUp(int exp){
    experience = experience + exp;
    while(experience >= requiredexperience){ //continues for as many levels as needed
        experience = experience - requiredexperience;
        profemonlevel ++;
        if(getSpecialty() == ML){
            requiredexperience += 10;
        }
        else if(getSpecialty() == SOFTWARE){
            requiredexperience += 15;
        }
        else if(getSpecialty() == HARDWARE){
            requiredexperience += 20;
        }
    }
}

////Attempt with recursion
//void Profemon::levelUp(int exp){
//    experience = experience + exp;
//    if(experience >= requiredexperience){
//        experience = experience - requiredexperience;
//        profemonlevel ++;
//        if(getSpecialty() == ML){
//            requiredexperience += 10;
//        }
//        else if(getSpecialty() == SOFTWARE){
//            requiredexperience += 15;
//        }
//        else if(getSpecialty() == HARDWARE){
//            requiredexperience += 20;
//        }
//    }
//    levelUp(experience - exp); //check this part
//}

bool Profemon::learnSkill(int slot, Skill skill){
    if(slot == 0 || slot == 1 || slot == 2){
        if(skill.getSpecialty() == getSpecialty()){
            learned[slot] = skill;
            return true;
        }
    }
    return false;
}

//implementing helper function for void Profemon::printProfemon(bool print_skills)
string Profemon::literalSpecialty(Specialty s){
    switch(s){
        case ML:
            return "ML";
        case SOFTWARE:
            return "SOFTWARE";
        case HARDWARE:
            return "HARDWARE";
        default:
            return "Undefined";
    }
}

void Profemon::printProfemon(bool print_skills){
    cout<<profemonname<<" ["<<literalSpecialty(profemonspecialty)<<"] | lvl "<<profemonlevel<<" | exp "<<experience<<"/"<<requiredexperience<< " | hp "<<profemonhealth<<endl;
    if(print_skills == true){
        for(int i = 0; i < 3; i++){
            if(learned[i].getName() != "Undefined"){
                cout<<"    "<<learned[i].getName()<< " ["<<learned[i].getTotalUses()<< "] : "<<learned[i].getDescription()<<endl;
            }
        }
    }
}

int Profemon::getCurrExp(){
    return experience;
}

int Profemon::getReqExp(){
    return requiredexperience;
}

Skill Profemon::getSkill(int slot){
    if(slot >= 0 && slot <3){
        return learned[slot];
    }
    else{
        return Skill();
    }
}
