/*
 Victoria Dynak
 CSCI135
 Genady Maryash
 skill.hpp
 */

#ifndef skill_hpp
#define skill_hpp
#include <iostream>
#include <vector>
using namespace std;

class Skill{
public:
    Skill();
    Skill(std::string name, std::string description, int specialty, int uses);
    std::string getName();
    std::string getDescription();
    int getTotalUses();
    int getSpecialty();
    void setName(std::string name);
    void setDescription(std::string description);
    void setTotalUses(int uses);
    bool setSpecialty(int specialty);
private:
    string skillname;
    string skilldescription;
    int limit;
    int specialty;
};

#endif /* skill_hpp */
