#ifndef VC_PCAP_H_
#define VC_PCAP_H_

#include <pcap.h>
#include <unistd.h>
#include <getopt.h>
#include <string>
#include <cstdlib>

namespace Vc
{
    char * dev;
    std::string device;
    std::string savefile;
}

#endif //VC_PCAP_H_
