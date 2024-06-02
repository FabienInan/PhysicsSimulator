//
//  NewtonLawsSimulator.cpp
//  GravitySimulator
//
//  Created by Fabien Inan on 2024-06-02.
//

#include "NewtonLawsSimulator.hpp"

void NewtonLawsSimulator::applySecondLawOfNewton(Body& b1, Body& b2, double dt) {
    // Reset accelerations
    b1.resetAcceleration();
    b2.resetAcceleration();
    
    // Apply gravitational forces
    applyGravitationalForces(b1, b2);
    
    //update velocity and position
    b1.updatePosition(dt);
    b1.updateVelocity(dt);
    
    b2.updatePosition(dt);
    b2.updateVelocity(dt);
    
}

//F = G * ( m1 * m2) * distance*distance
void NewtonLawsSimulator::applyGravitationalForces(Body& b1, Body& b2) {
    vector<double> direction = b2.getPosition() - b1.getPosition();
    double distance = norm_2(direction);
    if (distance == 0.0) return;
    double forceMagnitude = (GRAVITATIONAL_CONSTANT * b1.getMass() * b2.getMass()) / (distance * distance);
    vector<double> force = direction / distance * forceMagnitude;
    
    vector<double> newAccelerationB1 = b1.getAcceleration() + (force / b1.getMass());
    b1.setAcceleration(newAccelerationB1);
    vector<double> newAccelerationB2 = b2.getAcceleration() - (force / b2.getMass());
    b2.setAcceleration(newAccelerationB2);
}
