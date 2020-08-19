#include "VcPcap.h"

#include <iostream>

void VcPcapUsage()
{
    std::cout << "Help & version 20.8" std::endl;
}

int main(int argc, char **argv)
{
    char * dev = argv[2];
    int opt;

    /*
     * -d device
     * -f save filename
     * -p pthread
     * -h helpusage
     * -v version
     */
    if(argc < 2)
    {
        return VcPcapusage();
    }

    std::cout << "cin your device" << std::endl;
    /*
     * https://www.jianshu.com/p/76a4171a6d41
     */
    while((opt = getopt_long(argc, argv, "d:f:p::hv", VcPcapOption, &optionIndex)) != -1)
    {
        switch(opt)
        {
            case 0:
                break;
            case 'd':
                break;
            case 'f':
                break;
            case 'p':
                break;
            case 'v':
                return VcPcapUsage();
            default:
                return VcPcapUsage();
        }
    }

    return 0;
}
