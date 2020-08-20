#include "VcPcap.h"

#include <iostream>

void PcapUsage()
{
    std::cout << "    VcPcap Usage " << std::endl;
    std::cout << "  -d: device \n  -f: savefile \n  -h: help \n  -v: versin \n  -l: list" << std::endl;
}

void PcapVersion()
{
    std::cout << "VcPcap Version: 20.8.1 " << std::endl;
}

void VcDevice_List()
{
    pcap_if_t *it;
    char errbuf[PCAP_ERRBUF_SIZE];
    int m_dev = pcap_findalldevs(&it, errbuf);

    if(m_dev == 0)
    {
        std::cout << "Device List: \n";
        while(it)
        {
            std::cout << it->name << std::endl;
            it = it->next;
        }
    }
}

/*
 * d:f:p::hv
 */
static struct option Vcopts[] = {

    {"device", required_argument, NULL, 'd'},
    {"savefile", optional_argument, NULL, 'f'},
    {"pthread", required_argument, NULL, 'p'},
    {"help", no_argument, NULL, 'h'},
    {"version", no_argument, NULL, 'v'},
    {"Device list", no_argument, NULL, 'l'},
    {0, 0, 0, 0}
};


int main(int argc, char **argv)
{
    //char * dev = argv[2];
    int opt;

    /*
     * -d device
     * -f save filename
     * -p pthread
     * -h helpusage
     * -v version
     */
    int optionIndex = 0;

    while((opt = getopt_long(argc, argv, "d:f:p::hvl", Vcopts, &optionIndex)) != -1)
    {
        switch(opt)
        {
            
            case 'd':
                Vc::device = optarg;
                break;
            case 'f':
                Vc::savefile = optarg;
                std::cout << "filename = " << Vc::savefile << "\n";
                break;
            case 'p':
                break;
            case 'h':
                PcapUsage();
                exit(1);
            case 'v':
                PcapVersion();
                exit(1);
            case 'l':
                VcDevice_List();
                exit(1);
            default:
                PcapUsage();
                exit(1);
        }
    }

    return 0;
}
