# VcPcap
**VcPcap base libpcap: Capture traffic and save as pcap file and analyze pcap files**

![build] ![pass] ![Binger]

# Suupport Network
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
# Make VcPcap
```
git clone https://github.com/VcSpace/VcPcap.git
cd VcPcap
make -j4
./Vcpcap -h
```

# Useage
[VcPcap Usage](https://VcSpace.github.io/post/VcPcap)

# License
![Lic]  **LGPL-2.1 License**
