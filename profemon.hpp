/*
 Victoria Dynak
 CSCI135
 Genady Maryash
 profemon.hpp
 */

#ifndef profemon_hpp
#define profemon_hpp
#include <iostream>
#include <vector>
#include "skill.hpp"
using namespace std;

enum Specialty{ML = 0, SOFTWARE = 1, HARDWARE = 2};

class Profemon{
public:
    Profemon();
    Profemon(std::string name, double max_health, Specialty specialty);
    std::string getName();
    //included helper function for printProfemon(bool print_skills)
    std::string literalSpecialty(Specialty s);
    Specialty getSpecialty();
    Skill getSkill(int slot); //helper function for Project 3B
    int getLevel();
    double getMaxHealth();
    int getCurrExp();
    int getReqExp();
    void setName(std::string name);
    void levelUp(int exp);
    bool learnSkill(int slot, Skill skill);
    void printProfemon(bool print_skills);
private:
    string profemonname;
    int profemonlevel;
    int requiredexperience;
    int experience;
    double profemonhealth;
    Specialty profemonspecialty;
    Skill learned[3];
};

#endif /* profemon_hpp */
