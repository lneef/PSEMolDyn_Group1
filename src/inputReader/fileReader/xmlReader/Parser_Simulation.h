//
// Created by dominik on 24.11.22.
//
namespace xmlParser{
    class Parser_Simulation{
    private:
        double t_end;
        double delta_t;

    public:
        Parser_Simulation(const double &t_end,const double &delta_t);
        const double &gett_end() const;
        const double &getdelta_t() const;
    };
}
