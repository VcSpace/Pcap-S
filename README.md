# VcPcap
**VcPcap based libpcap: Capture traffic and save as pcap file and analyze pcap files**

---
![OSX](https://img.shields.io/badge/TestOS-Ubuntu16--64%20%7C%20Ubuntu18--64%20%7C%20Ubuntu20--64-inactive)
![GCC](https://img.shields.io/badge/GCC-5.5%20%7C%207.3%20%7C%209.3%20%7C%20-inactive)

[![Build Status](https://travis-ci.com/VcSpace/VcPcap.svg?branch=master)](https://travis-ci.com/VcSpace/VcPcap) 
![GitHub issues](https://img.shields.io/github/issues/VcSpace/VcPcap?color=brightgreen)
![GitHub last commit (branch)](https://img.shields.io/github/last-commit/VcSpace/VcPcap/master)

# Support Network
1. TCP
2. UDP
3. DNS
4. ICMP
5. IPV4/IPV6
6. GTP
7. HTTP
8. ...and more


# Install libpcap
```
ubuntu18, ubuntu20: 
apt-get -y install flex
apt-get -y install byacc
apt-get -y install libpcap-dev

centos7:
yum -y install flex 
yum -y install  byacc 
yum -y install bison

wget https://www.tcpdump.org/release/libpcap-1.9.1.tar.gz
tar -xvf libpcap-1.9.1.tar.gz
cd libpcap-1.9.1
./configure && make &&make install
```
# Build VcPcap
```
git clone https://github.com/VcSpace/VcPcap.git
cd VcPcap
make -j4
./Vcpcap -h
```

# Useage
[VcPcap Usage](https://VcSpace.github.io/post/VcPcap)

# License
![GitHub](https://img.shields.io/github/license/VcSpace/VcPcap?color=inactive)
