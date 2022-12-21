#pragma once


#include "../molsim-pskel.h"
#include "container/LinkedCellContainer.h"
namespace XMLReader {
    class from_checkpoint_pimpl : public from_checkpoint_pskel {
    private:

        /**
         * @brief shared pointer to LinkedCellContainer where Particles are stored
         */
        std::shared_ptr<LinkedCellContainer> cells;

        /**
         * @brief file name of file containing checkpoint
         */
        std::string filename;
    public:
        /**
         * @brief function to initialize the checkpoint parser
         * @param cells_arg reference to shared pointer pointing to a LinkedCellContainer
         */
        void init(std::shared_ptr<LinkedCellContainer> &cells_arg);

        /**
         * @brief function to process the path to a file containing the checkpoint
         */
        void path(const ::std::string &) override;

        /**
         * @brief function to generate particles from the checkpoint
         */
        void post_from_checkpoint() override;

    };
}


