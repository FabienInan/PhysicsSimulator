//
//  Body.hpp
//  GravitySimulator
//
//  Created by Fabien Inan on 2024-06-02.
//

#ifndef Body_hpp
#define Body_hpp

#include <stdio.h>
#include <boost/numeric/ublas/vector.hpp>

using namespace boost::numeric::ublas;

class Body {
private:
    double mass;
    vector<double> position;
    vector<double> velocity;
    vector<double> acceleration;
    
public:
    
    Body(double mass, const vector<double>& position, const vector<double>& velocity);
    
    double getMass() const;
    vector<double> getPosition() const;
    vector<double> getVelocity() const;
    vector<double> getAcceleration() const;
    
    void setMass(double mass);
    void setPosition(vector<double>& position_val);
    void setVelocity(vector<double>& velocity_val);
    void setAcceleration(vector<double>& acceleration_val);
    
    void resetAcceleration();
    void updatePosition(double dt);
    void updateVelocity(double dt);
    
};
#endif /* Body_hpp */
