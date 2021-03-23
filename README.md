# VcPcap
**简单实现一个基于Libpcap 捕获HTTP流量 保存为Pcap包**

---

[![Build Status](https://travis-ci.com/VcSpace/VcPcap.svg?branch=master)](https://travis-ci.com/VcSpace/VcPcap) 

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
# Build
```
make
#查看帮助
./Vcpcap -h 
```

# License
![GitHub](https://img.shields.io/github/license/VcSpace/VcPcap?color=inactive)

