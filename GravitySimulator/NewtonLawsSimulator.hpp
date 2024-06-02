//
//  NewtonLawsSimulator.hpp
//  GravitySimulator
//
//  Created by Fabien Inan on 2024-06-02.
//

#ifndef NewtonLawsSimulator_hpp
#define NewtonLawsSimulator_hpp

#include <stdio.h>
#include <boost/numeric/ublas/vector.hpp>
#include "Body.hpp"
#include "constants.hpp"

using namespace boost::numeric::ublas;

class NewtonLawsSimulator {
    
public:
    void applySecondLawOfNewton(Body& b1, Body& b2, double dt);
    void applyGravitationalForces(Body& b1, Body& b2);
    
};

#endif /* NewtonLawsSimulator_hpp */
