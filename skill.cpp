/*
 Victoria Dynak
 CSCI135
 Genady Mayash
 skill.cpp
 */

#include <iostream>
#include <vector>
#include "skill.hpp"
using namespace std;

Skill::Skill(){
    skillname = "Undefined";
    skilldescription = "Undefined";
    limit = -1;
    specialty = -1;
}

Skill::Skill(std::string name, std::string description, int specialty, int uses){
    skillname = name;
    skilldescription = description;
    limit = uses;
    this -> specialty = specialty;
}

string Skill::getName(){
    return skillname;
}

string Skill::getDescription(){
    return skilldescription;
}

int Skill::getTotalUses(){
    return limit;
}

int Skill::getSpecialty(){
    return specialty;
}

void Skill::setName(std::string name){
    skillname = name;
}

void Skill::setDescription(std::string description){
    skilldescription = description;
}

void Skill::setTotalUses(int uses){
    limit = uses;
}

bool Skill::setSpecialty(int specialty){
    if(specialty == 0 || specialty == 1 || specialty == 2){
        this -> specialty = specialty;
    }
    else{
        return false;
    }
    return true;
}

