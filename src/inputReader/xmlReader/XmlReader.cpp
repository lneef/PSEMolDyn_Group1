//
// Created by lukas on 01.12.22.
//

#include "XmlReader.h"

XmlReader::XmlReader(std::string &s) {
    filename = s;
}

void XmlReader::read(std::shared_ptr<Simulation> &sim, std::shared_ptr<LinkedCellContainer> &lc) {
    molecular_pimpl parser{};
    xml_schema::document doc_p(parser, "molecular");
    sim_p.parsers(double_p, double_p, double_p, double_p ,double_p, double_p,string_p, int_p);
    cub_in_p.parsers(string_p);
    cub_p.parsers(double_p, double_p, double_p, int_p, int_p, int_p, double_p, double_p, double_p, double_p, double_p);
    sim_p.init(lc, sim);
    cub_p.init(lc);
    parser.parsers(cub_p, sim_p, cub_in_p);
    parser.pre();
    parser.init(sim, lc);
    try {
        doc_p.parse(filename, xml_schema::flags::dont_validate);
    } catch (xml_schema::exception &e) {
        e.what();
        return;
    }
    parser.post_molecular();
}


