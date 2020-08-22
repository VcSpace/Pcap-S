#include "VcPcap.h"

#include <iostream>

void PcapUsage()
{
    std::cout << "VcPcap Usage " << std::endl;
    std::cout << "- d: device_name \n- f: savefile_name \n- h: help \n- v: versin \n- l: device_list" << std::endl;
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

    char * buf = NULL;
    buf = pcap_lookupdev(errbuf);
    std::cout << " \nUp devces:\n" << buf << std::endl; 
}

void packet_handler(u_char *user, const struct pcap_pkthdr *pkt_header, const u_char *pkt_data)
{
    pcap_dump(user, pkt_header, pkt_data);// 输出数据到文件
}

/*
 * d:f:p::hv
 */
static struct option Vcopts[] = {

    {"device", required_argument, NULL, 'd'},
    {"savefile", optional_argument, NULL, 'f'},
    {"help", no_argument, NULL, 'h'},
    {"version", no_argument, NULL, 'v'},
    {"Device list", no_argument, NULL, 'l'},
    {0, 0, 0, 0}
};


int main(int argc, char **argv)
{
    std::string device;
    std::string savefile;
    int opt;

    /*
     * -d device
     * -f save filename
     * -p pthread
     * -h helpusage
     * -v version
     */
    int optionIndex = 0;

    while((opt = getopt_long(argc, argv, "d:f:hvl", Vcopts, &optionIndex)) != -1)
    {
        switch(opt)
        {
            case 'd':
                device = optarg;
                break;
            case 'f':
                savefile = optarg;
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

    //start dev, savefile
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    handle = pcap_open_live(device.c_str(), BUFSIZ, 1, 200, errbuf);
    if(handle == NULL)
    {
        std::cout << "Couldn't open device: " << device << std::endl;
        //std::cout << "Errbuf: " << errbuf << std::endl;
        exit(0);
    }

    *errbuf = NULL;
    bpf_u_int32 localnet, netmask;
    int ne = pcap_lookupnet(device.c_str(), &localnet, &netmask, errbuf);
    if(ne != 0)
    {
        std::cout << "lookupnet errbuf: " << errbuf << std::endl;
        exit(1);
    }
    //std::cout << "localnet : " << localnet << std::endl;
    //std::cout << "netmask : " << netmask << std::endl;

    std::cout << "Start Device: " << device << std::endl;

    //struct and set network
    struct bpf_program filter;
    int net = pcap_compile(handle, &filter, NULL, 1, netmask);
    if(net != 0)
    {
        std::cout << "Net error: " << pcap_geterr(handle) << std::endl;
    }

    /*
     * char filter_app[] = "port 80";
     * pcap_setfilter(handle, &filter);
     */
    pcap_dumper_t * out_pcap;
    savefile = "/root/git/VcSpace/VcPcap/pcapsave/" + savefile + ".pcap";
    std::cout << savefile << std::endl;

    /*
     * outfile
     */
    out_pcap = pcap_dump_open(handle, savefile.c_str());

    int loop = pcap_loop(handle, 60, packet_handler, (u_char *) out_pcap);
    if(loop == -1)
    {
        std::cout << "loop error " << std::endl;
        exit(-1);
    }

    //flush
    //pcap_dump_flush(out_pcap);

    //End close device
    pcap_close(handle);
    pcap_dump_close(out_pcap);

    return 0;
}
