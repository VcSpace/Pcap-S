#include "VcPcap.h"

#include <iostream>
namespace Vc
{
    void PcapUsage()
    {
        std::cout << "VcPcap Usage " << std::endl;
        std::cout << "- d: device_name \n- f: savefile_name \n- h: help \n- v: versin \n- l: device_list" << std::endl;
    }

    void PcapVersion()
    {
        std::cout << "VcPcap Version: 20.8.2 " << std::endl;
    }
}
