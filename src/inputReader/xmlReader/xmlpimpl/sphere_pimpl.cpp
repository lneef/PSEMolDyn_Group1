//
// Created by dominik on 14.12.22.
//

#include "sphere_pimpl.h"
#include "inputReader/CuboidGenerator.h"

namespace XMLReader {
    void sphere_pimpl::init(std::shared_ptr<LinkedCellContainer> &lc, std::shared_ptr<Simulation> &simulation) {
        cells = lc;
        sim = simulation;
    }

    void sphere_pimpl::x(double x_arg) {
        centre.push(x_arg);
    }

    void sphere_pimpl::y(double y_arg) {
        centre.push(y_arg);
    }

    void sphere_pimpl::z(double z_arg) {
        centre.push(z_arg);
    }

    void sphere_pimpl::r(int r) {
        radius = r;
    }

    void sphere_pimpl::h(double h) {
        width = h;
    }

    void sphere_pimpl::m(double m) {
        mass = m;
    }

    void sphere_pimpl::v_x(double v_arg) {
        vel.push(v_arg);
    }

    void sphere_pimpl::v_y(double v_arg) {
        vel.push(v_arg);
    }

    void sphere_pimpl::v_z(double v_arg) {
        vel.push(v_arg);
    }

    void sphere_pimpl::brownianMotion(bool bm) {
        browMot = bm;
    }

    /*bool sphere_pimpl::checkZeroVelocity(std::array<double, 3> v){
        bool check = true;
        for(auto &i : v){
            if(i != 0){
                check = false;
            }
        }
        return check;
    }*/

    void sphere_pimpl::post_sphere() {
        std::array<double, 3> c{};
        std::array<double, 3> v{};
        for (size_t i = 0; i < 3; ++i) {
            c[i] = centre.front();
            v[i] = vel.front();

            centre.pop();
            vel.pop();
        }
        CuboidGenerator<LinkedCellContainer> cub{};
        if (!browMot) {
            cub.generateSphereNoBrownian(cells, c, v, radius, mass, width);
        } else {
            double meanVelocity;
            if (sim->getThermostat() != NULL) {
                meanVelocity = sqrt(sim->getThermostat()->getTemp() / mass);
            } else {
                meanVelocity = 0.1;
            }
            cub.generateSphereBrownian(cells, c, v, radius, mass, width, meanVelocity, sigma_s, epsilon_s, type_s);
        }

        browMot = true;
        type_s = 1;
        sigma_s = 1;
        epsilon_s = 5;
    }

    void sphere_pimpl::type(int type_arg) {
        type_s = type_arg;
    }

    void sphere_pimpl::sigma(double sigma_arg) {
        sigma_s = sigma_arg;
    }

    void sphere_pimpl::epsilon(double epsilon_arg) {
        epsilon_s = epsilon_arg;
    }
}