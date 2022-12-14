// Copyright (c) 2005-2014 Code Synthesis Tools CC
//
// This program was generated by CodeSynthesis XSD, an XML Schema to
// C++ data binding compiler.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
//
// In addition, as a special exception, Code Synthesis Tools CC gives
// permission to link this program with the Xerces-C++ library (or with
// modified versions of Xerces-C++ that use the same license as Xerces-C++),
// and distribute linked combinations including the two. You must obey
// the GNU General Public License version 2 in all respects for all of
// the code used other than Xerces-C++. If you modify this copy of the
// program, you may extend this exception to your version of the program,
// but you are not obligated to do so. If you do not wish to do so, delete
// this exception statement from your version.
//
// Furthermore, Code Synthesis Tools CC makes a special exception for
// the Free/Libre and Open Source Software (FLOSS) which is described
// in the accompanying FLOSSE file.
//

// Begin prologue.
//
//
// End prologue.

#include <xsd/cxx/pre.hxx>

#include "molsim-pskel.h"
namespace XMLReader {
// simulation_pskel
//

    void simulation_pskel::
    t_end_parser(xml_schema::double_pskel &p) {
        this->t_end_parser_ = &p;
    }

    void simulation_pskel::
    delta_t_parser(xml_schema::double_pskel &p) {
        this->delta_t_parser_ = &p;
    }

    void simulation_pskel::
    domain_x_parser(xml_schema::double_pskel &p) {
        this->domain_x_parser_ = &p;
    }

    void simulation_pskel::
    domain_y_parser(xml_schema::double_pskel &p) {
        this->domain_y_parser_ = &p;
    }

    void simulation_pskel::
    domain_z_parser(xml_schema::double_pskel &p) {
        this->domain_z_parser_ = &p;
    }

    void simulation_pskel::
    domain_cutOf_parser(xml_schema::double_pskel &p) {
        this->domain_cutOf_parser_ = &p;
    }

    void simulation_pskel::
    name_parser(xml_schema::string_pskel &p) {
        this->name_parser_ = &p;
    }

    void simulation_pskel::
    frequency_parser(xml_schema::int_pskel &p) {
        this->frequency_parser_ = &p;
    }

    void simulation_pskel::
    parsers(xml_schema::double_pskel &t_end,
            xml_schema::double_pskel &delta_t,
            xml_schema::double_pskel &domain_x,
            xml_schema::double_pskel &domain_y,
            xml_schema::double_pskel &domain_z,
            xml_schema::double_pskel &domain_cutOf,
            xml_schema::string_pskel &name,
            xml_schema::int_pskel &frequency) {
        this->t_end_parser_ = &t_end;
        this->delta_t_parser_ = &delta_t;
        this->domain_x_parser_ = &domain_x;
        this->domain_y_parser_ = &domain_y;
        this->domain_z_parser_ = &domain_z;
        this->domain_cutOf_parser_ = &domain_cutOf;
        this->name_parser_ = &name;
        this->frequency_parser_ = &frequency;
    }

    simulation_pskel::
    simulation_pskel()
            : t_end_parser_(0),
              delta_t_parser_(0),
              domain_x_parser_(0),
              domain_y_parser_(0),
              domain_z_parser_(0),
              domain_cutOf_parser_(0),
              name_parser_(0),
              frequency_parser_(0) {
    }

// temperature_pskel
//

    void temperature_pskel::
    temp_int_parser(xml_schema::double_pskel &p) {
        this->temp_int_parser_ = &p;
    }

    void temperature_pskel::
    n_thermostat_parser(xml_schema::int_pskel &p) {
        this->n_thermostat_parser_ = &p;
    }

    void temperature_pskel::
    temp_target_parser(xml_schema::double_pskel &p) {
        this->temp_target_parser_ = &p;
    }

    void temperature_pskel::
    temp_delta_parser(xml_schema::double_pskel &p) {
        this->temp_delta_parser_ = &p;
    }

    void temperature_pskel::
    parsers(xml_schema::double_pskel &temp_int,
            xml_schema::int_pskel &n_thermostat,
            xml_schema::double_pskel &temp_target,
            xml_schema::double_pskel &temp_delta) {
        this->temp_int_parser_ = &temp_int;
        this->n_thermostat_parser_ = &n_thermostat;
        this->temp_target_parser_ = &temp_target;
        this->temp_delta_parser_ = &temp_delta;
    }

    temperature_pskel::
    temperature_pskel()
            : temp_int_parser_(0),
              n_thermostat_parser_(0),
              temp_target_parser_(0),
              temp_delta_parser_(0) {
    }

// cuboid_pskel
//

    void cuboid_pskel::
    x_parser(xml_schema::double_pskel &p) {
        this->x_parser_ = &p;
    }

    void cuboid_pskel::
    y_parser(xml_schema::double_pskel &p) {
        this->y_parser_ = &p;
    }

    void cuboid_pskel::
    z_parser(xml_schema::double_pskel &p) {
        this->z_parser_ = &p;
    }

    void cuboid_pskel::
    n_x_parser(xml_schema::int_pskel &p) {
        this->n_x_parser_ = &p;
    }

    void cuboid_pskel::
    n_y_parser(xml_schema::int_pskel &p) {
        this->n_y_parser_ = &p;
    }

    void cuboid_pskel::
    n_z_parser(xml_schema::int_pskel &p) {
        this->n_z_parser_ = &p;
    }

    void cuboid_pskel::
    h_parser(xml_schema::double_pskel &p) {
        this->h_parser_ = &p;
    }

    void cuboid_pskel::
    m_parser(xml_schema::double_pskel &p) {
        this->m_parser_ = &p;
    }

    void cuboid_pskel::
    v_x_parser(xml_schema::double_pskel &p) {
        this->v_x_parser_ = &p;
    }

    void cuboid_pskel::
    v_y_parser(xml_schema::double_pskel &p) {
        this->v_y_parser_ = &p;
    }

    void cuboid_pskel::
    v_z_parser(xml_schema::double_pskel &p) {
        this->v_z_parser_ = &p;
    }

    void cuboid_pskel::
    parsers(xml_schema::double_pskel &x,
            xml_schema::double_pskel &y,
            xml_schema::double_pskel &z,
            xml_schema::int_pskel &n_x,
            xml_schema::int_pskel &n_y,
            xml_schema::int_pskel &n_z,
            xml_schema::double_pskel &h,
            xml_schema::double_pskel &m,
            xml_schema::double_pskel &v_x,
            xml_schema::double_pskel &v_y,
            xml_schema::double_pskel &v_z) {
        this->x_parser_ = &x;
        this->y_parser_ = &y;
        this->z_parser_ = &z;
        this->n_x_parser_ = &n_x;
        this->n_y_parser_ = &n_y;
        this->n_z_parser_ = &n_z;
        this->h_parser_ = &h;
        this->m_parser_ = &m;
        this->v_x_parser_ = &v_x;
        this->v_y_parser_ = &v_y;
        this->v_z_parser_ = &v_z;
    }

    cuboid_pskel::
    cuboid_pskel()
            : x_parser_(0),
              y_parser_(0),
              z_parser_(0),
              n_x_parser_(0),
              n_y_parser_(0),
              n_z_parser_(0),
              h_parser_(0),
              m_parser_(0),
              v_x_parser_(0),
              v_y_parser_(0),
              v_z_parser_(0) {
    }

// cuboid_input_pskel
//

    void cuboid_input_pskel::
    path_parser(xml_schema::string_pskel &p) {
        this->path_parser_ = &p;
    }

    void cuboid_input_pskel::
    parsers(xml_schema::string_pskel &path) {
        this->path_parser_ = &path;
    }

    cuboid_input_pskel::
    cuboid_input_pskel()
            : path_parser_(0) {
    }

// spheres_input_pskel
//

    void spheres_input_pskel::
    path_parser(xml_schema::string_pskel &p) {
        this->path_parser_ = &p;
    }

    void spheres_input_pskel::
    parsers(xml_schema::string_pskel &path) {
        this->path_parser_ = &path;
    }

    spheres_input_pskel::
    spheres_input_pskel()
            : path_parser_(0) {
    }

// boundaries_pskel
//

    void boundaries_pskel::
    top_parser(xml_schema::string_pskel &p) {
        this->top_parser_ = &p;
    }

    void boundaries_pskel::
    bottom_parser(xml_schema::string_pskel &p) {
        this->bottom_parser_ = &p;
    }

    void boundaries_pskel::
    left_parser(xml_schema::string_pskel &p) {
        this->left_parser_ = &p;
    }

    void boundaries_pskel::
    right_parser(xml_schema::string_pskel &p) {
        this->right_parser_ = &p;
    }

    void boundaries_pskel::
    parsers(xml_schema::string_pskel &top,
            xml_schema::string_pskel &bottom,
            xml_schema::string_pskel &left,
            xml_schema::string_pskel &right) {
        this->top_parser_ = &top;
        this->bottom_parser_ = &bottom;
        this->left_parser_ = &left;
        this->right_parser_ = &right;
    }

    boundaries_pskel::
    boundaries_pskel()
            : top_parser_(0),
              bottom_parser_(0),
              left_parser_(0),
              right_parser_(0) {
    }

// molecular_pskel
//

    void molecular_pskel::
    cuboid_parser(cuboid_pskel &p) {
        this->cuboid_parser_ = &p;
    }

    void molecular_pskel::
    simulation_parser(simulation_pskel &p) {
        this->simulation_parser_ = &p;
    }

    void molecular_pskel::
    cuboid_input_parser(cuboid_input_pskel &p) {
        this->cuboid_input_parser_ = &p;
    }

    void molecular_pskel::
    spheres_input_parser(spheres_input_pskel &p) {
        this->spheres_input_parser_ = &p;
    }

    void molecular_pskel::
    boundaries_parser(boundaries_pskel &p) {
        this->boundaries_parser_ = &p;
    }

    void molecular_pskel::
    temperature_parser(temperature_pskel &p) {
        this->temperature_parser_ = &p;
    }

    void molecular_pskel::
    parsers(cuboid_pskel &cuboid,
            simulation_pskel &simulation,
            cuboid_input_pskel &cuboid_input,
            spheres_input_pskel &spheres_input,
            boundaries_pskel &boundaries,
            temperature_pskel &temperature) {
        this->cuboid_parser_ = &cuboid;
        this->simulation_parser_ = &simulation;
        this->cuboid_input_parser_ = &cuboid_input;
        this->spheres_input_parser_ = &spheres_input;
        this->boundaries_parser_ = &boundaries;
        this->temperature_parser_ = &temperature;
    }

    molecular_pskel::
    molecular_pskel()
            : cuboid_parser_(0),
              simulation_parser_(0),
              cuboid_input_parser_(0),
              spheres_input_parser_(0),
              boundaries_parser_(0),
              temperature_parser_(0) {
    }

// simulation_pskel
//

    void simulation_pskel::
    t_end(double) {
    }

    void simulation_pskel::
    delta_t(double) {
    }

    void simulation_pskel::
    domain_x(double) {
    }

    void simulation_pskel::
    domain_y(double) {
    }

    void simulation_pskel::
    domain_z(double) {
    }

    void simulation_pskel::
    domain_cutOf(double) {
    }

    void simulation_pskel::
    name(const ::std::string &) {
    }

    void simulation_pskel::
    frequency(int) {
    }

    void simulation_pskel::
    post_simulation() {
    }

    bool simulation_pskel::
    _start_element_impl(const xml_schema::ro_string &ns,
                        const xml_schema::ro_string &n,
                        const xml_schema::ro_string *t) {
        XSD_UNUSED (t);

        if (this->xml_schema::complex_content::_start_element_impl(ns, n, t))
            return true;

        if (n == "t_end" && ns.empty()) {
            this->xml_schema::complex_content::context_.top().parser_ = this->t_end_parser_;

            if (this->t_end_parser_)
                this->t_end_parser_->pre();

            return true;
        }

        if (n == "delta_t" && ns.empty()) {
            this->xml_schema::complex_content::context_.top().parser_ = this->delta_t_parser_;

            if (this->delta_t_parser_)
                this->delta_t_parser_->pre();

            return true;
        }

        if (n == "domain_x" && ns.empty()) {
            this->xml_schema::complex_content::context_.top().parser_ = this->domain_x_parser_;

            if (this->domain_x_parser_)
                this->domain_x_parser_->pre();

            return true;
        }

        if (n == "domain_y" && ns.empty()) {
            this->xml_schema::complex_content::context_.top().parser_ = this->domain_y_parser_;

            if (this->domain_y_parser_)
                this->domain_y_parser_->pre();

            return true;
        }

        if (n == "domain_z" && ns.empty()) {
            this->xml_schema::complex_content::context_.top().parser_ = this->domain_z_parser_;

            if (this->domain_z_parser_)
                this->domain_z_parser_->pre();

            return true;
        }

        if (n == "domain_cutOf" && ns.empty()) {
            this->xml_schema::complex_content::context_.top().parser_ = this->domain_cutOf_parser_;

            if (this->domain_cutOf_parser_)
                this->domain_cutOf_parser_->pre();

            return true;
        }

        if (n == "name" && ns.empty()) {
            this->xml_schema::complex_content::context_.top().parser_ = this->name_parser_;

            if (this->name_parser_)
                this->name_parser_->pre();

            return true;
        }

        if (n == "frequency" && ns.empty()) {
            this->xml_schema::complex_content::context_.top().parser_ = this->frequency_parser_;

            if (this->frequency_parser_)
                this->frequency_parser_->pre();

            return true;
        }

        return false;
    }

    bool simulation_pskel::
    _end_element_impl(const xml_schema::ro_string &ns,
                      const xml_schema::ro_string &n) {
        if (this->xml_schema::complex_content::_end_element_impl(ns, n))
            return true;

        if (n == "t_end" && ns.empty()) {
            if (this->t_end_parser_)
                this->t_end(this->t_end_parser_->post_double());

            return true;
        }

        if (n == "delta_t" && ns.empty()) {
            if (this->delta_t_parser_)
                this->delta_t(this->delta_t_parser_->post_double());

            return true;
        }

        if (n == "domain_x" && ns.empty()) {
            if (this->domain_x_parser_)
                this->domain_x(this->domain_x_parser_->post_double());

            return true;
        }

        if (n == "domain_y" && ns.empty()) {
            if (this->domain_y_parser_)
                this->domain_y(this->domain_y_parser_->post_double());

            return true;
        }

        if (n == "domain_z" && ns.empty()) {
            if (this->domain_z_parser_)
                this->domain_z(this->domain_z_parser_->post_double());

            return true;
        }

        if (n == "domain_cutOf" && ns.empty()) {
            if (this->domain_cutOf_parser_)
                this->domain_cutOf(this->domain_cutOf_parser_->post_double());

            return true;
        }

        if (n == "name" && ns.empty()) {
            if (this->name_parser_)
                this->name(this->name_parser_->post_string());

            return true;
        }

        if (n == "frequency" && ns.empty()) {
            if (this->frequency_parser_)
                this->frequency(this->frequency_parser_->post_int());

            return true;
        }

        return false;
    }

// temperature_pskel
//

    void temperature_pskel::
    temp_int(double) {
    }

    void temperature_pskel::
    n_thermostat(int) {
    }

    void temperature_pskel::
    temp_target(double) {
    }

    void temperature_pskel::
    temp_delta(double) {
    }

    void temperature_pskel::
    post_temperature() {
    }

    bool temperature_pskel::
    _start_element_impl(const xml_schema::ro_string &ns,
                        const xml_schema::ro_string &n,
                        const xml_schema::ro_string *t) {
        XSD_UNUSED (t);

        if (this->xml_schema::complex_content::_start_element_impl(ns, n, t))
            return true;

        if (n == "temp_int" && ns.empty()) {
            this->xml_schema::complex_content::context_.top().parser_ = this->temp_int_parser_;

            if (this->temp_int_parser_)
                this->temp_int_parser_->pre();

            return true;
        }

        if (n == "n_thermostat" && ns.empty()) {
            this->xml_schema::complex_content::context_.top().parser_ = this->n_thermostat_parser_;

            if (this->n_thermostat_parser_)
                this->n_thermostat_parser_->pre();

            return true;
        }

        if (n == "temp_target" && ns.empty()) {
            this->xml_schema::complex_content::context_.top().parser_ = this->temp_target_parser_;

            if (this->temp_target_parser_)
                this->temp_target_parser_->pre();

            return true;
        }

        if (n == "temp_delta" && ns.empty()) {
            this->xml_schema::complex_content::context_.top().parser_ = this->temp_delta_parser_;

            if (this->temp_delta_parser_)
                this->temp_delta_parser_->pre();

            return true;
        }

        return false;
    }

    bool temperature_pskel::
    _end_element_impl(const xml_schema::ro_string &ns,
                      const xml_schema::ro_string &n) {
        if (this->xml_schema::complex_content::_end_element_impl(ns, n))
            return true;

        if (n == "temp_int" && ns.empty()) {
            if (this->temp_int_parser_)
                this->temp_int(this->temp_int_parser_->post_double());

            return true;
        }

        if (n == "n_thermostat" && ns.empty()) {
            if (this->n_thermostat_parser_)
                this->n_thermostat(this->n_thermostat_parser_->post_int());

            return true;
        }

        if (n == "temp_target" && ns.empty()) {
            if (this->temp_target_parser_)
                this->temp_target(this->temp_target_parser_->post_double());

            return true;
        }

        if (n == "temp_delta" && ns.empty()) {
            if (this->temp_delta_parser_)
                this->temp_delta(this->temp_delta_parser_->post_double());

            return true;
        }

        return false;
    }

// cuboid_pskel
//

    void cuboid_pskel::
    x(double) {
    }

    void cuboid_pskel::
    y(double) {
    }

    void cuboid_pskel::
    z(double) {
    }

    void cuboid_pskel::
    n_x(int) {
    }

    void cuboid_pskel::
    n_y(int) {
    }

    void cuboid_pskel::
    n_z(int) {
    }

    void cuboid_pskel::
    h(double) {
    }

    void cuboid_pskel::
    m(double) {
    }

    void cuboid_pskel::
    v_x(double) {
    }

    void cuboid_pskel::
    v_y(double) {
    }

    void cuboid_pskel::
    v_z(double) {
    }

    void cuboid_pskel::
    post_cuboid() {
    }

    bool cuboid_pskel::
    _start_element_impl(const xml_schema::ro_string &ns,
                        const xml_schema::ro_string &n,
                        const xml_schema::ro_string *t) {
        XSD_UNUSED (t);

        if (this->xml_schema::complex_content::_start_element_impl(ns, n, t))
            return true;

        if (n == "x" && ns.empty()) {
            this->xml_schema::complex_content::context_.top().parser_ = this->x_parser_;

            if (this->x_parser_)
                this->x_parser_->pre();

            return true;
        }

        if (n == "y" && ns.empty()) {
            this->xml_schema::complex_content::context_.top().parser_ = this->y_parser_;

            if (this->y_parser_)
                this->y_parser_->pre();

            return true;
        }

        if (n == "z" && ns.empty()) {
            this->xml_schema::complex_content::context_.top().parser_ = this->z_parser_;

            if (this->z_parser_)
                this->z_parser_->pre();

            return true;
        }

        if (n == "n_x" && ns.empty()) {
            this->xml_schema::complex_content::context_.top().parser_ = this->n_x_parser_;

            if (this->n_x_parser_)
                this->n_x_parser_->pre();

            return true;
        }

        if (n == "n_y" && ns.empty()) {
            this->xml_schema::complex_content::context_.top().parser_ = this->n_y_parser_;

            if (this->n_y_parser_)
                this->n_y_parser_->pre();

            return true;
        }

        if (n == "n_z" && ns.empty()) {
            this->xml_schema::complex_content::context_.top().parser_ = this->n_z_parser_;

            if (this->n_z_parser_)
                this->n_z_parser_->pre();

            return true;
        }

        if (n == "h" && ns.empty()) {
            this->xml_schema::complex_content::context_.top().parser_ = this->h_parser_;

            if (this->h_parser_)
                this->h_parser_->pre();

            return true;
        }

        if (n == "m" && ns.empty()) {
            this->xml_schema::complex_content::context_.top().parser_ = this->m_parser_;

            if (this->m_parser_)
                this->m_parser_->pre();

            return true;
        }

        if (n == "v_x" && ns.empty()) {
            this->xml_schema::complex_content::context_.top().parser_ = this->v_x_parser_;

            if (this->v_x_parser_)
                this->v_x_parser_->pre();

            return true;
        }

        if (n == "v_y" && ns.empty()) {
            this->xml_schema::complex_content::context_.top().parser_ = this->v_y_parser_;

            if (this->v_y_parser_)
                this->v_y_parser_->pre();

            return true;
        }

        if (n == "v_z" && ns.empty()) {
            this->xml_schema::complex_content::context_.top().parser_ = this->v_z_parser_;

            if (this->v_z_parser_)
                this->v_z_parser_->pre();

            return true;
        }

        return false;
    }

    bool cuboid_pskel::
    _end_element_impl(const xml_schema::ro_string &ns,
                      const xml_schema::ro_string &n) {
        if (this->xml_schema::complex_content::_end_element_impl(ns, n))
            return true;

        if (n == "x" && ns.empty()) {
            if (this->x_parser_)
                this->x(this->x_parser_->post_double());

            return true;
        }

        if (n == "y" && ns.empty()) {
            if (this->y_parser_)
                this->y(this->y_parser_->post_double());

            return true;
        }

        if (n == "z" && ns.empty()) {
            if (this->z_parser_)
                this->z(this->z_parser_->post_double());

            return true;
        }

        if (n == "n_x" && ns.empty()) {
            if (this->n_x_parser_)
                this->n_x(this->n_x_parser_->post_int());

            return true;
        }

        if (n == "n_y" && ns.empty()) {
            if (this->n_y_parser_)
                this->n_y(this->n_y_parser_->post_int());

            return true;
        }

        if (n == "n_z" && ns.empty()) {
            if (this->n_z_parser_)
                this->n_z(this->n_z_parser_->post_int());

            return true;
        }

        if (n == "h" && ns.empty()) {
            if (this->h_parser_)
                this->h(this->h_parser_->post_double());

            return true;
        }

        if (n == "m" && ns.empty()) {
            if (this->m_parser_)
                this->m(this->m_parser_->post_double());

            return true;
        }

        if (n == "v_x" && ns.empty()) {
            if (this->v_x_parser_)
                this->v_x(this->v_x_parser_->post_double());

            return true;
        }

        if (n == "v_y" && ns.empty()) {
            if (this->v_y_parser_)
                this->v_y(this->v_y_parser_->post_double());

            return true;
        }

        if (n == "v_z" && ns.empty()) {
            if (this->v_z_parser_)
                this->v_z(this->v_z_parser_->post_double());

            return true;
        }

        return false;
    }

// cuboid_input_pskel
//

    void cuboid_input_pskel::
    path(const ::std::string &) {
    }

    void cuboid_input_pskel::
    post_cuboid_input() {
    }

    bool cuboid_input_pskel::
    _start_element_impl(const xml_schema::ro_string &ns,
                        const xml_schema::ro_string &n,
                        const xml_schema::ro_string *t) {
        XSD_UNUSED (t);

        if (this->xml_schema::complex_content::_start_element_impl(ns, n, t))
            return true;

        if (n == "path" && ns.empty()) {
            this->xml_schema::complex_content::context_.top().parser_ = this->path_parser_;

            if (this->path_parser_)
                this->path_parser_->pre();

            return true;
        }

        return false;
    }

    bool cuboid_input_pskel::
    _end_element_impl(const xml_schema::ro_string &ns,
                      const xml_schema::ro_string &n) {
        if (this->xml_schema::complex_content::_end_element_impl(ns, n))
            return true;

        if (n == "path" && ns.empty()) {
            if (this->path_parser_)
                this->path(this->path_parser_->post_string());

            return true;
        }

        return false;
    }

// spheres_input_pskel
//

    void spheres_input_pskel::
    path(const ::std::string &) {
    }

    void spheres_input_pskel::
    post_spheres_input() {
    }

    bool spheres_input_pskel::
    _start_element_impl(const xml_schema::ro_string &ns,
                        const xml_schema::ro_string &n,
                        const xml_schema::ro_string *t) {
        XSD_UNUSED (t);

        if (this->xml_schema::complex_content::_start_element_impl(ns, n, t))
            return true;

        if (n == "path" && ns.empty()) {
            this->xml_schema::complex_content::context_.top().parser_ = this->path_parser_;

            if (this->path_parser_)
                this->path_parser_->pre();

            return true;
        }

        return false;
    }

    bool spheres_input_pskel::
    _end_element_impl(const xml_schema::ro_string &ns,
                      const xml_schema::ro_string &n) {
        if (this->xml_schema::complex_content::_end_element_impl(ns, n))
            return true;

        if (n == "path" && ns.empty()) {
            if (this->path_parser_)
                this->path(this->path_parser_->post_string());

            return true;
        }

        return false;
    }

// boundaries_pskel
//

    void boundaries_pskel::
    top(const ::std::string &) {
    }

    void boundaries_pskel::
    bottom(const ::std::string &) {
    }

    void boundaries_pskel::
    left(const ::std::string &) {
    }

    void boundaries_pskel::
    right(const ::std::string &) {
    }

    void boundaries_pskel::
    post_boundaries() {
    }

    bool boundaries_pskel::
    _start_element_impl(const xml_schema::ro_string &ns,
                        const xml_schema::ro_string &n,
                        const xml_schema::ro_string *t) {
        XSD_UNUSED (t);

        if (this->xml_schema::complex_content::_start_element_impl(ns, n, t))
            return true;

        if (n == "top" && ns.empty()) {
            this->xml_schema::complex_content::context_.top().parser_ = this->top_parser_;

            if (this->top_parser_)
                this->top_parser_->pre();

            return true;
        }

        if (n == "bottom" && ns.empty()) {
            this->xml_schema::complex_content::context_.top().parser_ = this->bottom_parser_;

            if (this->bottom_parser_)
                this->bottom_parser_->pre();

            return true;
        }

        if (n == "left" && ns.empty()) {
            this->xml_schema::complex_content::context_.top().parser_ = this->left_parser_;

            if (this->left_parser_)
                this->left_parser_->pre();

            return true;
        }

        if (n == "right" && ns.empty()) {
            this->xml_schema::complex_content::context_.top().parser_ = this->right_parser_;

            if (this->right_parser_)
                this->right_parser_->pre();

            return true;
        }

        return false;
    }

    bool boundaries_pskel::
    _end_element_impl(const xml_schema::ro_string &ns,
                      const xml_schema::ro_string &n) {
        if (this->xml_schema::complex_content::_end_element_impl(ns, n))
            return true;

        if (n == "top" && ns.empty()) {
            if (this->top_parser_)
                this->top(this->top_parser_->post_string());

            return true;
        }

        if (n == "bottom" && ns.empty()) {
            if (this->bottom_parser_)
                this->bottom(this->bottom_parser_->post_string());

            return true;
        }

        if (n == "left" && ns.empty()) {
            if (this->left_parser_)
                this->left(this->left_parser_->post_string());

            return true;
        }

        if (n == "right" && ns.empty()) {
            if (this->right_parser_)
                this->right(this->right_parser_->post_string());

            return true;
        }

        return false;
    }

// molecular_pskel
//

    void molecular_pskel::
    cuboid() {
    }

    void molecular_pskel::
    simulation() {
    }

    void molecular_pskel::
    cuboid_input() {
    }

    void molecular_pskel::
    spheres_input() {
    }

    void molecular_pskel::
    boundaries() {
    }

    void molecular_pskel::
    temperature() {
    }

    void molecular_pskel::
    post_molecular() {
    }

    bool molecular_pskel::
    _start_element_impl(const xml_schema::ro_string &ns,
                        const xml_schema::ro_string &n,
                        const xml_schema::ro_string *t) {
        XSD_UNUSED (t);

        if (this->xml_schema::complex_content::_start_element_impl(ns, n, t))
            return true;

        if (n == "cuboid" && ns.empty()) {
            this->xml_schema::complex_content::context_.top().parser_ = this->cuboid_parser_;

            if (this->cuboid_parser_)
                this->cuboid_parser_->pre();

            return true;
        }

        if (n == "simulation" && ns.empty()) {
            this->xml_schema::complex_content::context_.top().parser_ = this->simulation_parser_;

            if (this->simulation_parser_)
                this->simulation_parser_->pre();

            return true;
        }

        if (n == "cuboid_input" && ns.empty()) {
            this->xml_schema::complex_content::context_.top().parser_ = this->cuboid_input_parser_;

            if (this->cuboid_input_parser_)
                this->cuboid_input_parser_->pre();

            return true;
        }

        if (n == "spheres_input" && ns.empty()) {
            this->xml_schema::complex_content::context_.top().parser_ = this->spheres_input_parser_;

            if (this->spheres_input_parser_)
                this->spheres_input_parser_->pre();

            return true;
        }

        if (n == "boundaries" && ns.empty()) {
            this->xml_schema::complex_content::context_.top().parser_ = this->boundaries_parser_;

            if (this->boundaries_parser_)
                this->boundaries_parser_->pre();

            return true;
        }

        if (n == "temperature" && ns.empty()) {
            this->xml_schema::complex_content::context_.top().parser_ = this->temperature_parser_;

            if (this->temperature_parser_)
                this->temperature_parser_->pre();

            return true;
        }

        return false;
    }

    bool molecular_pskel::
    _end_element_impl(const xml_schema::ro_string &ns,
                      const xml_schema::ro_string &n) {
        if (this->xml_schema::complex_content::_end_element_impl(ns, n))
            return true;

        if (n == "cuboid" && ns.empty()) {
            if (this->cuboid_parser_) {
                this->cuboid_parser_->post_cuboid();
                this->cuboid();
            }

            return true;
        }

        if (n == "simulation" && ns.empty()) {
            if (this->simulation_parser_) {
                this->simulation_parser_->post_simulation();
                this->simulation();
            }

            return true;
        }

        if (n == "cuboid_input" && ns.empty()) {
            if (this->cuboid_input_parser_) {
                this->cuboid_input_parser_->post_cuboid_input();
                this->cuboid_input();
            }

            return true;
        }

        if (n == "spheres_input" && ns.empty()) {
            if (this->spheres_input_parser_) {
                this->spheres_input_parser_->post_spheres_input();
                this->spheres_input();
            }

            return true;
        }

        if (n == "boundaries" && ns.empty()) {
            if (this->boundaries_parser_) {
                this->boundaries_parser_->post_boundaries();
                this->boundaries();
            }

            return true;
        }

        if (n == "temperature" && ns.empty()) {
            if (this->temperature_parser_) {
                this->temperature_parser_->post_temperature();
                this->temperature();
            }

            return true;
        }

        return false;
    }

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

}