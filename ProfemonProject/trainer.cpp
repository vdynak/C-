//
//  trainer.cpp
//  135
//
//  Created by Victoria Dynak on 5/14/23.
// contains, remove, setteammember, / chooseProfemon, getCurrent

#include <iostream>
#include <vector>
#include <cfloat>
#include <string>
#include "trainer.hpp"
#include "profemon.hpp"
#include "skill.hpp"
using namespace std;

Trainer::Trainer(){
    selectProfemon = nullptr;
    Profemon team[] = {Profemon(), Profemon(), Profemon()};
    this->profedex;
}

Trainer::Trainer(std::vector<Profemon> profemons){
    int i = 0;
    for(Profemon& profemon: profemons){
        if(i < 3){
            team[i] = profemon;
            i++;
        }
        else{
            profedex.push_back(profemon);
        }
    }
    //last step
    selectProfemon = &team[0];
}

/*
 for(int i = 0; i < profemons.size(); i++){
     if(i < 3){
         team[i] = profemons[i];
         profedex.push_back(profemons[i]);
     }
     else{
         profedex.push_back(profemons[i]);
     }
 }
 */
bool Trainer::contains(std::string name){
    for(int i = 0; i < 3; i++){
        if(team[i].getName() == name){
            return true;
        }
    }
    for (Profemon& profemon : profedex) {
        if (profemon.getName() == name) {
            return true;
        }
    }
    return false;
}

/*
 
 for(Profemon& profemon: team){
     if(profemon.getName() == name){
         return true;
     }
 }
 for(Profemon& profemon: profedex){ //reference to each object in profedex
     if(profemon.getName() == name){
         return true;
     }
 }
 return false;
memory allocation problems:
 for(int i = 0; i < 3; i++){
     if(team[i].getName() == name){
         return true;
     }
 }
 for(int i = 0; profedex.size(); i++){
     if(profedex[i].getName() == name){
         return true;
     }
 }
 return false;
 */

bool Trainer::addProfemon(Profemon profemon){
    //1. check if the profemon is found in either array or vector, yes --> false
    if(contains(profemon.getName())){ //boolean
        return false; //ends program
    }
    //check for team space
    for(int i = 0; i < 3; i++){
        if(team[i].getName() == "Undefined"){
            team[i] = profemon;
            return true;
        }
    }
//    if(team[2].getName() != " "){
//        if(profedex.size() < FLT_MAX){
    profedex.push_back(profemon);
    return true;
        //}
//    }
//    return false;
}
/*
    @param      :   a profémon that is to be added
    @return     :   boolean indicating successful add operation
    @post       :   Add the given parameter profémon to the team
                    or the profedex. Only add the profemon to
                    profédex if the current team is full. If the
                    profémon is being added to the team, add it
                    to the smallest index possible. The profémon
                    can't be added if another profémon with the
                    same name already exists in the team or
                    the profédex
*/

bool Trainer::removeProfemon(std::string name){
    for(int i = 0; i < 3; i++){
        if(team[i].getName() == name){
            team[i] = Profemon(); //"Undefined"
            return true;
        } //works correctly
    }
    for(int i = 0; i < profedex.size(); i++){
        if(profedex[i].getName() == name){
            profedex.erase(profedex.begin() + i);
            return true;
        }
    }
    return false;
}

/*
 for (int i = 0; i < 3; i++) {
         if (team[i].getName() == name) {
             team[i] = Profemon(); //default constructor
             return true;
         }
     }

     // Check the profedex vector
     for (auto removal = profedex.begin(); removal != profedex.end(); removal++) {
         if (removal->getName() == name) {
             profedex.erase(removal);
             return true;
         }
     }
     return false; //not there
 
 would not work in this context
 for(Profemon& profemon: profedex){
     if(profemon.getName() == name){
         profedex.erase(profemon);
         return true;
     }
 }
 return false;

 for(int i = 0; i < profedex.size(); i++){
     if(profedex[i].getName() == name){
         profedex[i] = Profemon(); //this part needs work
         return true;
     }
 }
 return false;
*/

void Trainer::setTeamMember(int slot, std::string name){
    
    for(int i = 0; i < profedex.size(); i++){
        if(profedex[i].getName() == name){
            if(team[slot].getName() != "Undefined"){
                Profemon temporary = team[slot]; //potential error?
                team[slot] = profedex[i];
                profedex[i] = temporary;
            }
            else{
                team[slot] = profedex[i];
                profedex.erase(profedex.begin() + i);
            }
        }
    }
}

    
    
//    int position;
//    //verify slots, this is a vector, notation -->functionality
//    for(Profemon& chosenone: profedex){
//        if(chosenone.getName() == name){
//            if(team[slot].getName() != "Undefined"){
//                Profemon temporary = team[slot]; //potential error?
//                team[slot] = chosenone;
//                chosenone = temporary; //these are copies, i need the actual value
//
//
//            }
//            else{
//                team[slot] = chosenone;
//
//            }
//      }
//   }
//}
   
/*
 verify slots, this is a vector, notation -->functionality
 for(Profemon& chosenone: profedex){
     if(chosenone.getName() == name){
         if(team[slot].getName() != "Undefined"){
             Profemon temporary = team[slot]; potential error?
             team[slot] = chosenone;
             chosenone = temporary; these are copies, i need the actual value
         }
         else{
             team[slot] = chosenone;
         }
            //explanation for this part of the code below
            profedex.erase(std::remove_if(profedex.begin(), profedex.end(), [&](Profemon& del){
                        return del.getName() == name;
                    }
                ),
                profedex.end()
            );
     }
 }
}
 */
    
    
    //remove_if() = three arguments, the range over which it will work on, plus the Profemon object del which allows for a boolean to be returned of whether it should be removed (true) or not (false). This condition is satisifed by the conditional del.getName() == name?. All the elements that meet the condition are moved to the end of the vector, to which erase then removes them.

/*
 alternative:
 if(slot >= 0 && slot < 3){
     for(auto chosenone = profedex.begin(); chosenone != profedex.end(); chosenone++){
         if(chosenone->getName() == name){
             if(team[slot].getName() != ""){
                 Profemon notchosen = team[slot];
                 team[slot] = *chosenone;
                 *chosenone = notchosen;
             }
             else{
                 team[slot] = *chosenone;
             }
             break;
 for(Profemon& chosenone: profedex){
     if(chosenone.getName() == name){
         if(team[slot].getName() != " "){
             Profemon temporary = team[slot]; //potential error?
             team[slot] = chosenone;
             chosenone = temporary; //these are copies, i need the actual value
         }
         else{
             team[slot] = chosenone;
         }
     }
 }
}
 */
/*
    @param      :   integer representing a slot in the team (0,1 or 2)
    @param      :   name of the profémon that is to be added to the team
    @post       :   assuming that a profémon with the given 'name' exists
                    in the profédex and given 'slot' is valid (0,1,2), add
                    the profémon to the team at the given slot. If the slot
                    already contains a profémon, swap the profémon with the
                    profémon that is being added to the team. If the 'slot'
                    doesn't contain a profémon, move the profémon from the
                    profédex to the slot

For example :

    Let's suppose the current team array is: ["Enxhi", "Undefined", "Kimberly"]
    And profédex is: ["Sadab", "Yoomin", "Zilola", "Brandon"]

    If we call 'setTeamMember(1,"Yoomin")', the team and profédex becomes:
    Team: ["Enxhi", "Yoomin", "Kimberly"]
    Profédex: ["Sadab", "Zilola", "Brandon"]
    The profémon is moved to the team's empty slot (Undefined means empty)

    However, if we call 'setTeamMember(0,"Zilola")':
    Team: ["Zilola", "Undefined", "Kimberly"]
    Profédex: ["Sadab", "Yoomin", "Enxhi", "Brandon"]
    The profémon is swapped with the profémon in slot 0
*/

bool Trainer::chooseProfemon(int slot){
    if(slot < 0 || slot > 3){ //slot != 0 || slot != 1 || slot != 2
        return false;
    }
    if(team[slot].getName() != "Undefined"){ //undefined?
        selectProfemon = &(team[slot]);
        return true;
    }
    return false;
}

Profemon Trainer::getCurrent(){
        return *selectProfemon;
}

void Trainer::printProfedex(){
    for(int i = 0; i < profedex.size(); i++){
        profedex[i].printProfemon(false);
        cout<<endl;
    }
}

void Trainer::printTeam(){
    for(int i = 0; i <= 2; i++){
        if(team[i].getName() != "Undefined"){ //undefined?
            team[i].printProfemon(true);
            cout<<endl;
        }
    }
}

