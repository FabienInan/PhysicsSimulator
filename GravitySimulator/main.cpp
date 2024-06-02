#include <iostream>
#include <boost/numeric/odeint.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <array>

#include "Body.hpp"
#include "NewtonLawsSimulator.hpp"

int main() {
    using namespace boost::numeric::ublas;

    // Initialize positions and velocities
    vector<double> earth_position(3), earth_velocity(3);
    earth_position(0) = 0.0; earth_position(1) = 0.0; earth_position(2) = 0.0;
    earth_velocity(0) = 0.0; earth_velocity(1) = 0.0; earth_velocity(2) = 0.0;

    vector<double> satellite_position(3), satellite_velocity(3);
    satellite_position(0) = 0.0; satellite_position(1) = 6.371e6; satellite_position(2) = 0.0;
    satellite_velocity(0) = 7800.0; satellite_velocity(1) = 0.0; satellite_velocity(2) = 0.0;

    // Create bodies
    Body earth(5.972e24, earth_position, earth_velocity);
    Body satellite(1000, satellite_position, satellite_velocity);

    // Create simulation
    NewtonLawsSimulator simulator;

    double dt = 1; // Time step in seconds
    for (int i = 0; i < 10; ++i) {
        simulator.applySecondLawOfNewton(earth, satellite, dt);
        std::cout << "Earth Position: " << earth.getPosition() << std::endl;
        std::cout << "Satellite Position: " << satellite.getPosition() << std::endl;
    }
    return 0;
}
