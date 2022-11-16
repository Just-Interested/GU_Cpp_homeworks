#include <iostream>
#include <vector>
#include "stdlib.h"
#include <unistd.h>
#include <getopt.h>
#include "PcapLiveDeviceList.h"
#include "PcapFileDevice.h"
#include "SystemUtils.h"


#define EXIT_WITH_ERROR(reason) do { \
	printUsage(); \
	std::cout << std::endl << "ERROR: " << reason << std::endl << std::endl; \
	exit(1); \
	} while(0)


static struct option app_options[] =
{
	{"interface",  required_argument, 0, 'i'},
    {"list",  no_argument, 0, 'l'},
    {"help",  no_argument, 0, 'h'},
	{0, 0, 0, 0}
};

void printUsage()
{
    std::cout << std::endl
		<< "Usage:" << std::endl
		<< "------" << std::endl
		<< pcpp::AppName::get() << " -i interface_ip" << std::endl
		<< std::endl
		<< "Options:" << std::endl
		<< std::endl
		<< "    -i interface_ip   : The IPv4 address of interface to use" << std::endl
        << "    -l                : List interfaces" << std::endl
        << "    -h                : Show this help" << std::endl
		<< std::endl;
}

int listInterfaces()
{
    const std::vector<pcpp::PcapLiveDevice*>& dev_list = pcpp::PcapLiveDeviceList::getInstance().getPcapLiveDevicesList();
    if (dev_list.empty())
    {
        std::cout << "Cannot list interfaces" << std::endl;
        return 1;
    }
    else
    {
        for (auto dev : dev_list)
        {
            std::cout << "Name: " << dev->getName() << " IP: " << dev->getIPv4Address().toString() << std::endl;
        }
    }
    return 0;
}

void capturePackets(pcpp::PcapLiveDevice* dev)
{
    if (!dev->open())
	{
		EXIT_WITH_ERROR("Cannot open interface");
	}

    std::cout << "Device name: " << dev->getName() << std::endl;

    pcpp::RawPacketVector packet_vec;

    dev->startCapture(packet_vec);

    int n_sec = 10;
    std::cout << "Capturing ";
    while (n_sec > 0)
    {
        sleep(1);
        std::cout << ".";
        n_sec--;
    }

    dev->stopCapture();
    std::cout << " Done." << std::endl;

    pcpp::PcapFileWriterDevice pcap_writer("output.pcap", pcpp::LINKTYPE_ETHERNET);

    if (!pcap_writer.open())
    {
        std::cout << ("Cannot open output.pcap for writing") << std::endl;
        exit(1);
    }

    for (auto pkt : packet_vec)
    {
        pcap_writer.writePacket(*pkt);
    }

    pcap_writer.close();
}

int main(int argc, char** argv) {
    
    pcpp::AppName::init(argc, argv);

    std::string iface = "";

    int optionIndex = 0;
	int opt = 0;

    while((opt = getopt_long(argc, argv, "i:lh", app_options, &optionIndex)) != -1)
	{
		switch (opt)
		{
			case 0:
				break;
			case 'i':
				iface = optarg;
				break;
            case 'h':
                printUsage();
				exit(0);
                break;
            case 'l':
                listInterfaces();
                exit(0);
				break;
			default:
				printUsage();
				exit(-1);
		}
	}

    if(iface == "")
	{
		EXIT_WITH_ERROR("Please specify interface IP");
	}

    pcpp::IPv4Address ifaceAddr(iface);

    pcpp::PcapLiveDevice* pIfaceDevice = pcpp::PcapLiveDeviceList::getInstance().getPcapLiveDeviceByIp(ifaceAddr);

    if (pIfaceDevice == NULL)
	{
		EXIT_WITH_ERROR("Cannot find interface");
	}

    capturePackets(pIfaceDevice);

    return 0;
}
