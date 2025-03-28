#ifndef TJ2GBE_SUBDOMAIN_HPP
#define TJ2GBE_SUBDOMAIN_HPP

#include <string>


class Subdomain{
    private:
        double fmax [5]; // subdomain max
        double afrange [5]; // subdomain range
        int    ndiv [5]; // number of cells in each dimension of the subdomain
        int totaln; // total number of cells
        unsigned int numGB; // number of grain boundaries
        int ksym;
    public:
        unsigned int * num; // number of GB in cells
        unsigned int * cumnum;
        unsigned int * ids; // GB IDs in cells
        int * qs; 

        void initialize(const double* fmax_, const int* n_,
                unsigned int numGB, int numSym);
        ~Subdomain();
        unsigned int neuler_to_cell(const double* af);
        bool in_subdomain(const double* af);
        void count_each_cell(const unsigned int* idxcell,const int* Qs);
        void write_cellInfo(std::string outDir);
};

#endif
