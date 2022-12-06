
#include "XmlReader.h"
#include "MolSimLogger.h"

namespace XMLReader {
    XmlReader::XmlReader(std::string &s) {
        filename = s;
    }

    void XmlReader::read(std::shared_ptr<Simulation> &sim, std::shared_ptr<LinkedCellContainer> &lc) {
        XMLReader::molecular_pimpl parser{};
        xml_schema::document doc_p(parser, "molecular");
        sim_p.parsers(double_p, double_p, double_p, double_p, double_p, double_p, string_p, int_p);
        cub_in_p.parsers(string_p);
        cub_p.parsers(double_p, double_p, double_p, int_p, int_p, int_p, double_p, double_p, double_p, double_p,
                      double_p);
        sph_in_p.parsers(string_p);
        bou_in_p.parsers(string_p, string_p, string_p, string_p);

        sim_p.init(lc, sim);
        cub_p.init(lc);
        cub_in_p.init(lc);
        sph_in_p.init(lc);
        bou_in_p.init(lc);
        parser.parsers(cub_p, sim_p, cub_in_p, sph_in_p, bou_in_p);
        parser.pre();
        parser.init(sim, lc);
        try {
            MolSimLogger::logInfo("Parsing xml file:{}", filename);
            doc_p.parse(filename, xml_schema::flags::dont_validate);
        } catch (xml_schema::exception &e) {
            MolSimLogger::logError("{}", e.what());
            exit(-1);
        }
        parser.post_molecular();
    }

    void XmlReader::read(std::shared_ptr<Simulation> &sim) {
        std::shared_ptr<LinkedCellContainer> cell = std::make_shared<LinkedCellContainer>();
        read(sim, cell);
        sim->setParticle(cell);
    }

}
