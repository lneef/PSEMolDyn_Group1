//
// Created by lukas on 01.12.22.
//

#include <iostream>
#include "cuboid_pimpl.h"
#include "inputReader/CuboidGenerator.h"

namespace XMLReader {

    void cuboid_pimpl::x(double x_arg) {
        pos.push(x_arg);
    }

    void cuboid_pimpl::y(double y_arg) {
        pos.push(y_arg);
    }

    void cuboid_pimpl::z(double z_arg) {
        pos.push(z_arg);
    }

    void cuboid_pimpl::n_x(int n_xarg) {
        num.push(n_xarg);
    }

    void cuboid_pimpl::n_y(int n_yarg) {
        num.push(n_yarg);
    }

    void cuboid_pimpl::n_z(int n_zarg) {
        num.push(n_zarg);
    }

    void cuboid_pimpl::h(double dist) {
        width = dist;
    }

    void cuboid_pimpl::m(double m_arg) {
        mass = m_arg;
    }

    void cuboid_pimpl::v_x(double v_arg) {
        vel.push(v_arg);
    }

    void cuboid_pimpl::v_y(double v_arg) {
        vel.push(v_arg);
    }

    void cuboid_pimpl::v_z(double v_arg) {
        vel.push(v_arg);
    }

    void cuboid_pimpl::post_cuboid() {
        std::array<double, 3> x{};
        std::array<double, 3> v{};
        std::array<int, 3> n{};
        for (size_t i = 0; i < 3; ++i) {
            x[i] = pos.front();
            v[i] = vel.front();
            n[i] = num.front();
            std::cout << "no" << n[0] << pos.size() << std::endl;
            pos.pop();
            vel.pop();
            num.pop();
        };

        CuboidGenerator<LinkedCellContainer> cub{};
        cub.generateCuboid(cells, x, n, width, mass, v);
        std::cout << cells->size();
    }

    void cuboid_pimpl::init(std::shared_ptr<LinkedCellContainer> &lc) {
        cells = lc;
    }


}