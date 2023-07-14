//
//  department.hpp
//  135
//
//  Created by Victoria Dynak on 5/16/23.
//

#ifndef DEPARTMENT
#define DEPARTMENT

#include "trainer.hpp"
#include "profemon.hpp"

class MLDepartment: public Trainer{
    public:
        MLDepartment(std::vector<Profemon> profemons);
        bool addProfemon(Profemon profemon);
};

class SoftwareDepartment: public Trainer{
    public:
        SoftwareDepartment(std::vector<Profemon> profemons);
        bool addProfemon(Profemon profemon);
};

class HardwareDepartment: public Trainer{
    public:
        HardwareDepartment(std::vector<Profemon> profemons);
        bool addProfemon(Profemon profemon);
};

#endif

