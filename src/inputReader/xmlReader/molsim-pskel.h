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

#ifndef MOLSIM_PSKEL_H
#define MOLSIM_PSKEL_H

#ifndef XSD_CXX11
#define XSD_CXX11
#endif

// Begin prologue.
//
//
// End prologue.

#include <xsd/cxx/config.hxx>

#if (XSD_INT_VERSION != 4000000L)
#error XSD runtime version mismatch
#endif

#include <xsd/cxx/pre.hxx>

// Forward declarations
//

#ifndef XSD_USE_CHAR
#define XSD_USE_CHAR
#endif

#ifndef XSD_CXX_PARSER_USE_CHAR
#define XSD_CXX_PARSER_USE_CHAR
#endif

#include <xsd/cxx/xml/char-utf8.hxx>
#include <xsd/cxx/xml/error-handler.hxx>
#include <xsd/cxx/parser/exceptions.hxx>
#include <xsd/cxx/parser/elements.hxx>
#include <xsd/cxx/parser/xml-schema.hxx>
#include <xsd/cxx/parser/non-validating/parser.hxx>
#include <xsd/cxx/parser/non-validating/xml-schema-pskel.hxx>
#include <xsd/cxx/parser/non-validating/xml-schema-pimpl.hxx>
#include <xsd/cxx/parser/xerces/elements.hxx>
namespace XMLReader {
    class simulation_pskel;

    class cuboid_pskel;

    class cuboid_input_pskel;

    class molecular_pskel;

    namespace xml_schema {
        // Built-in XML Schema types mapping.
        //
        typedef ::xsd::cxx::parser::string_sequence<char> string_sequence;
        typedef ::xsd::cxx::parser::qname<char> qname;
        typedef ::xsd::cxx::parser::buffer buffer;
        typedef ::xsd::cxx::parser::time_zone time_zone;
        typedef ::xsd::cxx::parser::gday gday;
        typedef ::xsd::cxx::parser::gmonth gmonth;
        typedef ::xsd::cxx::parser::gyear gyear;
        typedef ::xsd::cxx::parser::gmonth_day gmonth_day;
        typedef ::xsd::cxx::parser::gyear_month gyear_month;
        typedef ::xsd::cxx::parser::date date;
        typedef ::xsd::cxx::parser::time time;
        typedef ::xsd::cxx::parser::date_time date_time;
        typedef ::xsd::cxx::parser::duration duration;

        // Base parser skeletons.
        //
        typedef ::xsd::cxx::parser::parser_base<char> parser_base;
        typedef ::xsd::cxx::parser::non_validating::empty_content<char> empty_content;
        typedef ::xsd::cxx::parser::non_validating::simple_content<char> simple_content;
        typedef ::xsd::cxx::parser::non_validating::complex_content<char> complex_content;
        typedef ::xsd::cxx::parser::non_validating::list_base<char> list_base;

        // Parser skeletons and implementations for the XML Schema
        // built-in types.
        //
        typedef ::xsd::cxx::parser::non_validating::any_type_pskel<char> any_type_pskel;
        typedef ::xsd::cxx::parser::non_validating::any_type_pimpl<char> any_type_pimpl;

        typedef ::xsd::cxx::parser::non_validating::any_simple_type_pskel<char> any_simple_type_pskel;
        typedef ::xsd::cxx::parser::non_validating::any_simple_type_pimpl<char> any_simple_type_pimpl;

        typedef ::xsd::cxx::parser::non_validating::byte_pskel<char> byte_pskel;
        typedef ::xsd::cxx::parser::non_validating::byte_pimpl<char> byte_pimpl;

        typedef ::xsd::cxx::parser::non_validating::unsigned_byte_pskel<char> unsigned_byte_pskel;
        typedef ::xsd::cxx::parser::non_validating::unsigned_byte_pimpl<char> unsigned_byte_pimpl;

        typedef ::xsd::cxx::parser::non_validating::short_pskel<char> short_pskel;
        typedef ::xsd::cxx::parser::non_validating::short_pimpl<char> short_pimpl;

        typedef ::xsd::cxx::parser::non_validating::unsigned_short_pskel<char> unsigned_short_pskel;
        typedef ::xsd::cxx::parser::non_validating::unsigned_short_pimpl<char> unsigned_short_pimpl;

        typedef ::xsd::cxx::parser::non_validating::int_pskel<char> int_pskel;
        typedef ::xsd::cxx::parser::non_validating::int_pimpl<char> int_pimpl;

        typedef ::xsd::cxx::parser::non_validating::unsigned_int_pskel<char> unsigned_int_pskel;
        typedef ::xsd::cxx::parser::non_validating::unsigned_int_pimpl<char> unsigned_int_pimpl;

        typedef ::xsd::cxx::parser::non_validating::long_pskel<char> long_pskel;
        typedef ::xsd::cxx::parser::non_validating::long_pimpl<char> long_pimpl;

        typedef ::xsd::cxx::parser::non_validating::unsigned_long_pskel<char> unsigned_long_pskel;
        typedef ::xsd::cxx::parser::non_validating::unsigned_long_pimpl<char> unsigned_long_pimpl;

        typedef ::xsd::cxx::parser::non_validating::integer_pskel<char> integer_pskel;
        typedef ::xsd::cxx::parser::non_validating::integer_pimpl<char> integer_pimpl;

        typedef ::xsd::cxx::parser::non_validating::non_positive_integer_pskel<char> non_positive_integer_pskel;
        typedef ::xsd::cxx::parser::non_validating::non_positive_integer_pimpl<char> non_positive_integer_pimpl;

        typedef ::xsd::cxx::parser::non_validating::non_negative_integer_pskel<char> non_negative_integer_pskel;
        typedef ::xsd::cxx::parser::non_validating::non_negative_integer_pimpl<char> non_negative_integer_pimpl;

        typedef ::xsd::cxx::parser::non_validating::positive_integer_pskel<char> positive_integer_pskel;
        typedef ::xsd::cxx::parser::non_validating::positive_integer_pimpl<char> positive_integer_pimpl;

        typedef ::xsd::cxx::parser::non_validating::negative_integer_pskel<char> negative_integer_pskel;
        typedef ::xsd::cxx::parser::non_validating::negative_integer_pimpl<char> negative_integer_pimpl;

        typedef ::xsd::cxx::parser::non_validating::boolean_pskel<char> boolean_pskel;
        typedef ::xsd::cxx::parser::non_validating::boolean_pimpl<char> boolean_pimpl;

        typedef ::xsd::cxx::parser::non_validating::float_pskel<char> float_pskel;
        typedef ::xsd::cxx::parser::non_validating::float_pimpl<char> float_pimpl;

        typedef ::xsd::cxx::parser::non_validating::double_pskel<char> double_pskel;
        typedef ::xsd::cxx::parser::non_validating::double_pimpl<char> double_pimpl;

        typedef ::xsd::cxx::parser::non_validating::decimal_pskel<char> decimal_pskel;
        typedef ::xsd::cxx::parser::non_validating::decimal_pimpl<char> decimal_pimpl;

        typedef ::xsd::cxx::parser::non_validating::string_pskel<char> string_pskel;
        typedef ::xsd::cxx::parser::non_validating::string_pimpl<char> string_pimpl;

        typedef ::xsd::cxx::parser::non_validating::normalized_string_pskel<char> normalized_string_pskel;
        typedef ::xsd::cxx::parser::non_validating::normalized_string_pimpl<char> normalized_string_pimpl;

        typedef ::xsd::cxx::parser::non_validating::token_pskel<char> token_pskel;
        typedef ::xsd::cxx::parser::non_validating::token_pimpl<char> token_pimpl;

        typedef ::xsd::cxx::parser::non_validating::name_pskel<char> name_pskel;
        typedef ::xsd::cxx::parser::non_validating::name_pimpl<char> name_pimpl;

        typedef ::xsd::cxx::parser::non_validating::nmtoken_pskel<char> nmtoken_pskel;
        typedef ::xsd::cxx::parser::non_validating::nmtoken_pimpl<char> nmtoken_pimpl;

        typedef ::xsd::cxx::parser::non_validating::nmtokens_pskel<char> nmtokens_pskel;
        typedef ::xsd::cxx::parser::non_validating::nmtokens_pimpl<char> nmtokens_pimpl;

        typedef ::xsd::cxx::parser::non_validating::ncname_pskel<char> ncname_pskel;
        typedef ::xsd::cxx::parser::non_validating::ncname_pimpl<char> ncname_pimpl;

        typedef ::xsd::cxx::parser::non_validating::language_pskel<char> language_pskel;
        typedef ::xsd::cxx::parser::non_validating::language_pimpl<char> language_pimpl;

        typedef ::xsd::cxx::parser::non_validating::id_pskel<char> id_pskel;
        typedef ::xsd::cxx::parser::non_validating::id_pimpl<char> id_pimpl;

        typedef ::xsd::cxx::parser::non_validating::idref_pskel<char> idref_pskel;
        typedef ::xsd::cxx::parser::non_validating::idref_pimpl<char> idref_pimpl;

        typedef ::xsd::cxx::parser::non_validating::idrefs_pskel<char> idrefs_pskel;
        typedef ::xsd::cxx::parser::non_validating::idrefs_pimpl<char> idrefs_pimpl;

        typedef ::xsd::cxx::parser::non_validating::uri_pskel<char> uri_pskel;
        typedef ::xsd::cxx::parser::non_validating::uri_pimpl<char> uri_pimpl;

        typedef ::xsd::cxx::parser::non_validating::qname_pskel<char> qname_pskel;
        typedef ::xsd::cxx::parser::non_validating::qname_pimpl<char> qname_pimpl;

        typedef ::xsd::cxx::parser::non_validating::base64_binary_pskel<char> base64_binary_pskel;
        typedef ::xsd::cxx::parser::non_validating::base64_binary_pimpl<char> base64_binary_pimpl;

        typedef ::xsd::cxx::parser::non_validating::hex_binary_pskel<char> hex_binary_pskel;
        typedef ::xsd::cxx::parser::non_validating::hex_binary_pimpl<char> hex_binary_pimpl;

        typedef ::xsd::cxx::parser::non_validating::date_pskel<char> date_pskel;
        typedef ::xsd::cxx::parser::non_validating::date_pimpl<char> date_pimpl;

        typedef ::xsd::cxx::parser::non_validating::date_time_pskel<char> date_time_pskel;
        typedef ::xsd::cxx::parser::non_validating::date_time_pimpl<char> date_time_pimpl;

        typedef ::xsd::cxx::parser::non_validating::duration_pskel<char> duration_pskel;
        typedef ::xsd::cxx::parser::non_validating::duration_pimpl<char> duration_pimpl;

        typedef ::xsd::cxx::parser::non_validating::gday_pskel<char> gday_pskel;
        typedef ::xsd::cxx::parser::non_validating::gday_pimpl<char> gday_pimpl;

        typedef ::xsd::cxx::parser::non_validating::gmonth_pskel<char> gmonth_pskel;
        typedef ::xsd::cxx::parser::non_validating::gmonth_pimpl<char> gmonth_pimpl;

        typedef ::xsd::cxx::parser::non_validating::gmonth_day_pskel<char> gmonth_day_pskel;
        typedef ::xsd::cxx::parser::non_validating::gmonth_day_pimpl<char> gmonth_day_pimpl;

        typedef ::xsd::cxx::parser::non_validating::gyear_pskel<char> gyear_pskel;
        typedef ::xsd::cxx::parser::non_validating::gyear_pimpl<char> gyear_pimpl;

        typedef ::xsd::cxx::parser::non_validating::gyear_month_pskel<char> gyear_month_pskel;
        typedef ::xsd::cxx::parser::non_validating::gyear_month_pimpl<char> gyear_month_pimpl;

        typedef ::xsd::cxx::parser::non_validating::time_pskel<char> time_pskel;
        typedef ::xsd::cxx::parser::non_validating::time_pimpl<char> time_pimpl;

        // Exceptions. See libxsd/xsd/cxx/parser/exceptions.hxx for details.
        //
        typedef ::xsd::cxx::parser::exception<char> exception;

        // Parsing diagnostics.
        //
        typedef ::xsd::cxx::parser::severity severity;
        typedef ::xsd::cxx::parser::error<char> error;
        typedef ::xsd::cxx::parser::diagnostics<char> diagnostics;
        typedef ::xsd::cxx::parser::parsing<char> parsing;

        // Error handler. See libxsd/xsd/cxx/xml/error-handler.hxx for details.
        //
        typedef ::xsd::cxx::xml::error_handler<char> error_handler;

        // Read-only string.
        //
        typedef ::xsd::cxx::ro_string<char> ro_string;

        // Parsing flags. See libxsd/xsd/cxx/parser/xerces/elements.hxx
        // for details.
        //
        typedef ::xsd::cxx::parser::xerces::flags flags;

        // Parsing properties. See libxsd/xsd/cxx/parser/xerces/elements.hxx
        // for details.
        //
        typedef ::xsd::cxx::parser::xerces::properties<char> properties;

        // Document type. See libxsd/xsd/cxx/parser/xerces/elements.hxx
        // for details.
        //
        typedef ::xsd::cxx::parser::xerces::document<char> document;
    }


    class simulation_pskel : public xml_schema::complex_content {
    public:
        // Parser callbacks. Override them in your implementation.
        //
        // virtual void
        // pre ();

        virtual void
        t_end(double);

        virtual void
        delta_t(double);

        virtual void
        domain_x(double);

        virtual void
        domain_y(double);

        virtual void
        domain_z(double);

        virtual void
        domain_cutOf(double);

        virtual void
        name(const ::std::string &);

        virtual void
        frequency(int);

        virtual void
        post_simulation();

        // Parser construction API.
        //
        void
        t_end_parser(xml_schema::double_pskel &);

        void
        delta_t_parser(xml_schema::double_pskel &);

        void
        domain_x_parser(xml_schema::double_pskel &);

        void
        domain_y_parser(xml_schema::double_pskel &);

        void
        domain_z_parser(xml_schema::double_pskel &);

        void
        domain_cutOf_parser(xml_schema::double_pskel &);

        void
        name_parser(xml_schema::string_pskel &);

        void
        frequency_parser(xml_schema::int_pskel &);

        void
        parsers(xml_schema::double_pskel & /* t_end */,
                xml_schema::double_pskel & /* delta_t */,
                xml_schema::double_pskel & /* domain_x */,
                xml_schema::double_pskel & /* domain_y */,
                xml_schema::double_pskel & /* domain_z */,
                xml_schema::double_pskel & /* domain_cutOf */,
                xml_schema::string_pskel & /* name */,
                xml_schema::int_pskel & /* frequency */);

        // Constructor.
        //
        simulation_pskel();

        // Implementation.
        //
    protected:
        virtual bool
        _start_element_impl(const xml_schema::ro_string &,
                            const xml_schema::ro_string &,
                            const xml_schema::ro_string *);

        virtual bool
        _end_element_impl(const xml_schema::ro_string &,
                          const xml_schema::ro_string &);

    protected:
        xml_schema::double_pskel *t_end_parser_;
        xml_schema::double_pskel *delta_t_parser_;
        xml_schema::double_pskel *domain_x_parser_;
        xml_schema::double_pskel *domain_y_parser_;
        xml_schema::double_pskel *domain_z_parser_;
        xml_schema::double_pskel *domain_cutOf_parser_;
        xml_schema::string_pskel *name_parser_;
        xml_schema::int_pskel *frequency_parser_;
    };

    class cuboid_pskel : public xml_schema::complex_content {
    public:
        // Parser callbacks. Override them in your implementation.
        //
        // virtual void
        // pre ();

        virtual void
        x(double);

        virtual void
        y(double);

        virtual void
        z(double);

        virtual void
        n_x(int);

        virtual void
        n_y(int);

        virtual void
        n_z(int);

        virtual void
        h(double);

        virtual void
        m(double);

        virtual void
        v_x(double);

        virtual void
        v_y(double);

        virtual void
        v_z(double);

        virtual void
        post_cuboid();

        // Parser construction API.
        //
        void
        x_parser(xml_schema::double_pskel &);

        void
        y_parser(xml_schema::double_pskel &);

        void
        z_parser(xml_schema::double_pskel &);

        void
        n_x_parser(xml_schema::int_pskel &);

        void
        n_y_parser(xml_schema::int_pskel &);

        void
        n_z_parser(xml_schema::int_pskel &);

        void
        h_parser(xml_schema::double_pskel &);

        void
        m_parser(xml_schema::double_pskel &);

        void
        v_x_parser(xml_schema::double_pskel &);

        void
        v_y_parser(xml_schema::double_pskel &);

        void
        v_z_parser(xml_schema::double_pskel &);

        void
        parsers(xml_schema::double_pskel & /* x */,
                xml_schema::double_pskel & /* y */,
                xml_schema::double_pskel & /* z */,
                xml_schema::int_pskel & /* n_x */,
                xml_schema::int_pskel & /* n_y */,
                xml_schema::int_pskel & /* n_z */,
                xml_schema::double_pskel & /* h */,
                xml_schema::double_pskel & /* m */,
                xml_schema::double_pskel & /* v_x */,
                xml_schema::double_pskel & /* v_y */,
                xml_schema::double_pskel & /* v_z */);

        // Constructor.
        //
        cuboid_pskel();

        // Implementation.
        //
    protected:
        virtual bool
        _start_element_impl(const xml_schema::ro_string &,
                            const xml_schema::ro_string &,
                            const xml_schema::ro_string *);

        virtual bool
        _end_element_impl(const xml_schema::ro_string &,
                          const xml_schema::ro_string &);

    protected:
        xml_schema::double_pskel *x_parser_;
        xml_schema::double_pskel *y_parser_;
        xml_schema::double_pskel *z_parser_;
        xml_schema::int_pskel *n_x_parser_;
        xml_schema::int_pskel *n_y_parser_;
        xml_schema::int_pskel *n_z_parser_;
        xml_schema::double_pskel *h_parser_;
        xml_schema::double_pskel *m_parser_;
        xml_schema::double_pskel *v_x_parser_;
        xml_schema::double_pskel *v_y_parser_;
        xml_schema::double_pskel *v_z_parser_;
    };

    class cuboid_input_pskel : public xml_schema::complex_content {
    public:
        // Parser callbacks. Override them in your implementation.
        //
        // virtual void
        // pre ();

        virtual void
        path(const ::std::string &);

        virtual void
        post_cuboid_input();

        // Parser construction API.
        //
        void
        path_parser(xml_schema::string_pskel &);

        void
        parsers(xml_schema::string_pskel & /* path */);

        // Constructor.
        //
        cuboid_input_pskel();

        // Implementation.
        //
    protected:
        virtual bool
        _start_element_impl(const xml_schema::ro_string &,
                            const xml_schema::ro_string &,
                            const xml_schema::ro_string *);

        virtual bool
        _end_element_impl(const xml_schema::ro_string &,
                          const xml_schema::ro_string &);

    protected:
        xml_schema::string_pskel *path_parser_;
    };

    class molecular_pskel : public xml_schema::complex_content {
    public:
        // Parser callbacks. Override them in your implementation.
        //
        // virtual void
        // pre ();

        virtual void
        cuboid();

        virtual void
        simulation();

        virtual void
        cuboid_input();

        virtual void
        post_molecular();

        // Parser construction API.
        //
        void
        cuboid_parser(cuboid_pskel &);

        void
        simulation_parser(simulation_pskel &);

        void
        cuboid_input_parser(cuboid_input_pskel &);

        void
        parsers(cuboid_pskel & /* cuboid */,
                simulation_pskel & /* simulation */,
                cuboid_input_pskel & /* cuboid_input */);

        // Constructor.
        //
        molecular_pskel();

        // Implementation.
        //
    protected:
        virtual bool
        _start_element_impl(const xml_schema::ro_string &,
                            const xml_schema::ro_string &,
                            const xml_schema::ro_string *);

        virtual bool
        _end_element_impl(const xml_schema::ro_string &,
                          const xml_schema::ro_string &);

    protected:
        cuboid_pskel *cuboid_parser_;
        simulation_pskel *simulation_parser_;
        cuboid_input_pskel *cuboid_input_parser_;
    };
}
#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // MOLSIM_PSKEL_H
