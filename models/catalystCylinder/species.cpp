#include<species.H>

namespace mflo_species
{
    amrex::Vector<std::string> specnames(NUM_SPECIES);
    AMREX_GPU_DEVICE_MANAGED amrex::Real advect_flags[NUM_SPECIES]={one};
    AMREX_GPU_DEVICE_MANAGED amrex::Real molwts[NUM_SPECIES]={one};

    void init()
    {
        specnames[AIR_ID]="air";
        specnames[A_ID]="specA";
        specnames[B_ID]="specB";
        specnames[S_ID]="sites";
        
        //kg/mol
        molwts[AIR_ID]  =0.0289;
        molwts[A_ID]=0.044;
        molwts[B_ID]=0.028;
        molwts[S_ID]=0.001;

        advect_flags[S_ID]=0;
    }    
    void close()
    {
        specnames.clear();
    }
    int find_id(std::string specname)
    {
        int loc=-1;
        auto it=std::find(specnames.begin(),specnames.end(),specname);
        if(it != specnames.end())
        {
            loc=it-specnames.begin();
        }
        return(loc);
    }
}
