/*
 Victoria Dynak
 CSCI135
 Genady Maryash
 main.cpp
 */

#include "profemon.hpp"
#include "skill.hpp"
#include "trainer.hpp"
#include <vector>
using namespace std;
int main(){
    // maryash skills
    Skill oop("OOP", "a programming paradigm based on the concept of objects, which can contain data and code", SOFTWARE, 30);
    Skill dynamic_array("Vector", "a c++ dynamic array library", SOFTWARE, 30);
    Skill pointer("Pointer", "a pointer stores a memory address", SOFTWARE, 10);
    // ligorio
    Skill sorting("Sorting", "algorithms to sort things in order", SOFTWARE, 30);
    Skill polymorphism("Polymorphism", "the same entity (function or object) behaves differently in different scenarios", SOFTWARE, 20);
    Skill searching("Searching", "algorithms to efficiently search items in data structures", SOFTWARE, 30);
    // shostak skills
    Skill report("Report", "report a student for cheating", SOFTWARE, 30);
    Skill tree("Tree", "an abstract data type that represents a hierarchical tree structure with a set of connected nodes", SOFTWARE, 25);
    Skill hashtable("HashTable", "an abstract data type that maps keys to values", SOFTWARE, 30);
    // shankar skills
    Skill nickname("Nickname", "assign a nickname to the students", HARDWARE, 20);
    Skill mips("MIPS", "an assembly level programming language", HARDWARE, 10);
    Skill multiplexer("Multiplexer", "a device that selects between several analog or digital input signals and forwards the selected input to a single output line", HARDWARE, 30);
    // schweitzer skills
    Skill flashbag("Flashbag", "creates and throws rgb backpack to blind enemies", HARDWARE, 5);
    Skill induction("Induction", "a method of mathematical proof typically used to establish a given statement for all possible cases", HARDWARE, 15);
    Skill recurrence("Recurrence", "n equation that defines a sequence based on a rule that gives the next term as a function of the previous term(s)", HARDWARE, 15);
    // zamfirescu
    Skill flipflop("Flip-Flop", "circuits that can store state(on/off) information", HARDWARE, 20);
    Skill number_system("Number System", "a technique to represent numbers", HARDWARE, 20);
    Skill kmap("Karnaugh Map", "a table that simplify the expressions to Boolean functions", HARDWARE, 5);
    // raja skills
    Skill supervised("Supervised Learning", "a ML training method that uses labeled datasets and algorithms classify data or predict outcomes accurately", ML, 25);
    Skill unsupervised("Unsupervised Learning", "a ML training method that can discover hidden patterns or data groupings without the need for human intervention", ML, 30);
    Skill reinforcement("Reinforcement Learning", "a ML training method based on rewarding desired behaviors and/or punishing undesired ones", ML, 15);
    // levitan skills
    Skill ngrams("Ngrams", "a contiguous sequence of n items from a given sample of text or speech", ML, 10);
    Skill tokenizing("Tokenizing", "breaks the raw text into words, sentences called tokens", ML, 30);
    Skill lemmatizing("Lemmatizing", "the process of grouping together different inflected forms of the same word", ML, 20);
    // epstein skill
    Skill perceptron("Perceptron", "a ML algorithm that can decide whether an input belongs to some specific class", ML, 20);
    Skill neuralnetwork("Neural Network", "a series of perceptrons that have an input, output, and hidden layer", ML, 30);
    Skill autoencoder("Autoencoder", "a ML technique that involves the use of a generator which generates fake information and a discriminator which can discern whether the information is fake or not", ML, 30);

    Profemon maryash("Maryash", 13500, SOFTWARE);
    cout << maryash.learnSkill(0, oop) << endl;                 // prints 1
    /*
        Maryash [SOFTWARE] | lvl 0 | exp 0/50 | hp 13500
            OOP [30] : a programming paradigm based on the concept of objects, which can contain data and code
    */
    maryash.printProfemon(true);

    Profemon ligorio("Ligorio", 23500, SOFTWARE);
    cout << ligorio.learnSkill(2, perceptron) << endl;          // prints 0

    Profemon shostak("Shostak", 33500, SOFTWARE);
    shostak.levelUp(200);
    cout << shostak.getLevel() << endl;                         // prints 3

    Profemon shankar("Shankar", 26000, HARDWARE);
    Profemon schweitzer("Schweitzer", 15000, HARDWARE);
    Profemon zamfirescu("Zamfirescu", 16000, HARDWARE);
    Profemon raja("Raja", 35000, ML);
    Profemon levitan("Levitan", 49362, ML);
    Profemon epstein("Epstein", 49377, ML);

    // . . . test your functions here
    epstein.printProfemon(true);
    epstein.levelUp(250);
    cout<<"Level: "<<epstein.getLevel()<<endl;
    cout<<"Status: "<<epstein.learnSkill(0, neuralnetwork)<<endl;
    cout<<"Status: "<<epstein.learnSkill(1, ngrams)<<endl;
    epstein.printProfemon(true);

    vector<Profemon> wprof = {maryash, raja};
    Trainer dynak(wprof);
    dynak.addProfemon(epstein);
    dynak.addProfemon(shostak);
    dynak.addProfemon(levitan);
    dynak.addProfemon(shankar);
    //dynak.removeProfemon("Raja");
    dynak.setTeamMember(1, "Shankar");
    dynak.printTeam();
    cout<<endl<<endl;
    dynak.printProfedex();
    
//    vector<Profemon> wp = {maryash, levitan, ligorio, shankar, epstein};
//    Trainer dynak(wp);
//    dynak.removeProfemon("Maryash");
//    dynak.addProfemon(shostak);
//    dynak.setTeamMember(0, "Shostak");
//    dynak.printTeam();
//    bool ans = dynak.contains("Raja");
//    if(ans == 1){
//        cout<<"True";
//    }
//    else{
//        cout<<"False";
//    }
//    dynak.chooseProfemon(2);
//
//    cout<<endl<<"break:"<<endl;
//    dynak.printProfedex();
//    cout<<endl<<endl;
//    dynak.removeProfemon("Shostak");
//    dynak.addProfemon(maryash);
//    dynak.setTeamMember(0, "Maryash");
//    dynak.setTeamMember(0, "Epstein");
//
//    dynak.printTeam();
//    cout<<endl<<endl;
//    dynak.printProfedex();

    return 0;
}
