#pragma once
#include "../molsim-pskel.h"
#include "container/LinkedCellContainer.h"
namespace XMLReader {
    class from_checkpoint_pimpl : public from_checkpoint_pskel {
    private:
        std::shared_ptr<LinkedCellContainer> cells;
        std::string filename;
    public:
        void init(std::shared_ptr<LinkedCellContainer> &cells_arg);

        void path(const ::std::string &) override;

        void post_from_checkpoint() override;

    };
}


