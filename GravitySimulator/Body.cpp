//
//  Body.cpp
//  GravitySimulator
//
//  Created by Fabien Inan on 2024-06-02.
//

#include "Body.hpp"

using namespace boost::numeric::ublas;

Body::Body(double mass, const vector<double>& position, const vector<double>& velocity)
    : mass(mass), position(position), velocity(velocity), acceleration(3) {
    resetAcceleration();
}

double Body::getMass() const{
    return mass;
}

vector<double> Body::getPosition() const{
    return position;
}
    
vector<double> Body::getVelocity() const{
    return velocity;
}
    
vector<double> Body::getAcceleration() const{
    return acceleration;
}

void Body::setMass(double mass_val) {
    mass = mass_val;
}

void Body::setPosition(vector<double>& position_val) {
    position = position_val;
}

void Body::setVelocity(vector<double>& velocity_val) {
    velocity = velocity_val;
}

void Body::setAcceleration(vector<double>& acceleration_val) {
    acceleration = acceleration_val;
}

void Body::resetAcceleration() {
    acceleration(0) = 0.0;
    acceleration(1) = 0.0;
    acceleration(2) = 0.0;
}

void Body::updatePosition(double dt) {
    position += velocity * dt + acceleration * 0.5 * dt * dt;
}
    
void Body::updateVelocity(double dt) {
    velocity += acceleration * dt;
}
