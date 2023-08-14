# Ex.No. 1 <center>Networking Commands</center>

## Procedure

Check if `tcpdump` is installed on your system

```bash
$ which tcpdump
```

OUTPUT:

```
/usr/bin/tcpdump
```

*Indicates that tcpdump was installed on my linux*

----

If `tcpdump` is not installed, run

```bash
$ sudo apt install -y tcpdump
```

---

To get supervisor privilege

```bash
$ su
```

or 

```bash
$ sudo su
```

*($ is changed to # and the commands can be executed in supervisor)*

---

**Capturing packets with tcpdump**

Use the command `tcpdump -D` to see which interfaces are available for capture.

```
# tcpdump -D
```

OUTPUT:

```
1.eth0 [Up, Running, Connected]
2.any (Pseudo-device that captures on all interfaces) [Up, Running]
3.lo [Up, Running, Loopback]
4.bluetooth-monitor (Bluetooth Linux Monitor) [Wireless]
5.nflog (Linux netfilter log (NFLOG) interface) [none]
6.nfqueue (Linux netfilter queue (NFQUEUE) interface) [none]
7.dbus-system (D-Bus system bus) [none]
8.dbus-session (D-Bus session bus) [none]
```

Sample Execution:

![Execution](https://i.postimg.cc/T1WkbR3S/Screenshot-2023-08-14-13-38-59.png)

---

**Capture all packets in any interface by running this command:**

```
# tcpdump -i any
```

Command info: 

    -i  - Interface
    any - Capture packets from any interface

OUTPUT:
```
tcpdump: data link type LINUX_SLL2
tcpdump: verbose output suppressed, use -v[v]... for full protocol decode
listening on any, link-type LINUX_SLL2 (Linux cooked v2), snapshot length 262144 bytes
08:12:02.310255 eth0  In  IP 172.17.0.1 > c38a1eced6f1: ICMP echo request, id 61864, seq 1, length 64
08:12:02.310267 eth0  Out IP c38a1eced6f1 > 172.17.0.1: ICMP echo reply, id 61864, seq 1, length 64
08:12:02.378068 eth0  Out IP c38a1eced6f1.40973 > 192.168.43.1.domain: 59388+ PTR? 1.0.17.172.in-addr.arpa. (41)
.
.
.
^C
8 packets captured
8 packets received by filter
0 packets dropped by kernel

```

*Note: The output may vary on your execution.*

![Execution](https://i.postimg.cc/bNQv0WdS/Screenshot-2023-08-14-13-46-58.png)

---

**Filter packets based on the source or destination IP Address**

Based on source

```
# tcpdump -i any -c5 -nn src 172.17.0.2
```

Command info:

    -i any  -> Captures packets from all interfaces.
    -c5     -> Captures only 5 packets.
    -nn     -> Disables hostname and port name resolution.
    src     -> This is a filter that specifies the source IP address.

OUTPUT:

```
tcpdump: data link type LINUX_SLL2
tcpdump: verbose output suppressed, use -v[v]... for full protocol decode
listening on any, link-type LINUX_SLL2 (Linux cooked v2), snapshot length 262144 bytes
08:22:56.416519 eth0  Out IP 172.17.0.2 > 172.17.0.1: ICMP echo reply, id 49667, seq 1, length 64
08:22:57.441997 eth0  Out IP 172.17.0.2 > 172.17.0.1: ICMP echo reply, id 49667, seq 2, length 64
08:22:58.465987 eth0  Out IP 172.17.0.2 > 172.17.0.1: ICMP echo reply, id 49667, seq 3, length 64
08:22:59.489870 eth0  Out IP 172.17.0.2 > 172.17.0.1: ICMP echo reply, id 49667, seq 4, length 64
08:23:00.513975 eth0  Out IP 172.17.0.2 > 172.17.0.1: ICMP echo reply, id 49667, seq 5, length 64
5 packets captured
5 packets received by filter
0 packets dropped by kernel
```

*Note: Ensure that the source IP address mentioned (`172.17.0.2`) matches the actual source you intend to monitor. You can confirm your source IP address by running the `ifconfig` command.*

Based on destination

```
# tcpdump -i any -c5 -nn dst 172.17.0.1
```

OUTPUT:

```
tcpdump: data link type LINUX_SLL2
tcpdump: verbose output suppressed, use -v[v]... for full protocol decode
listening on any, link-type LINUX_SLL2 (Linux cooked v2), snapshot length 262144 bytes
08:32:09.381865 eth0  Out IP 172.17.0.2 > 172.17.0.1: ICMP echo reply, id 49667, seq 541, length 64
08:32:10.401867 eth0  Out IP 172.17.0.2 > 172.17.0.1: ICMP echo reply, id 49667, seq 542, length 64
08:32:12.074885 eth0  Out IP 172.17.0.2 > 172.17.0.1: ICMP echo reply, id 21424, seq 1, length 64
08:32:13.093976 eth0  Out IP 172.17.0.2 > 172.17.0.1: ICMP echo reply, id 21424, seq 2, length 64
08:32:14.113974 eth0  Out IP 172.17.0.2 > 172.17.0.1: ICMP echo reply, id 21424, seq 3, length 64
5 packets captured
5 packets received by filter
0 packets dropped by kernel
```

*Note: Ensure that the destination IP address mentioned (`172.17.0.1`) matches the actual destination you intend to monitor.*

---

**To filter packets based on protocol, specifying the protocol in the command line. For example, capture ICMP packets only by using this command:**

```
# tcpdump -i any -c5 icmp
```

OUTPUT:

```
tcpdump: data link type LINUX_SLL2
tcpdump: verbose output suppressed, use -v[v]... for full protocol decode
listening on any, link-type LINUX_SLL2 (Linux cooked v2), snapshot length 262144 bytes
08:35:46.938069 eth0  In  IP 172.17.0.1 > c38a1eced6f1: ICMP echo request, id 24173, seq 0, length 8
08:35:46.938087 eth0  Out IP c38a1eced6f1 > 172.17.0.1: ICMP echo reply, id 24173, seq 0, length 8
08:35:47.938214 eth0  In  IP 172.17.0.1 > c38a1eced6f1: ICMP echo request, id 24173, seq 256, length 8
08:35:47.938234 eth0  Out IP c38a1eced6f1 > 172.17.0.1: ICMP echo reply, id 24173, seq 256, length 8
08:35:48.938378 eth0  In  IP 172.17.0.1 > c38a1eced6f1: ICMP echo request, id 24173, seq 512, length 8
5 packets captured
6 packets received by filter
0 packets dropped by kernel
```

*Note: Output may vary based on ICMP packets received by your device.*

---

**a). windump (for Windows)**

WinDump is the Windows version of tcpdump, the command line network analyzer for UNIX. WinDump is fully compatible with tcpdump and can be used to watch, diagnose and save to disk network traffic according to various complex rules.

**INSTALLATION PROCEDURE:**

    1. Download and install Windump (http://www.winpcap.org/windump/)

    2. You will need to place your network card into promiscuous mode – for this, install WinPcap. Download and install WinPcap. (http://www.winpcap.org/install/default.htm)

**Testing Procedure:**

1. Open a Command Prompt with Administrator Rights.
2. Change the directory to your download directory. `cd c:\Program Files\`
3. Run windump to collect packets. `c:\Program Files\windump`
4. Run windump to locate your network adapter. `c:\Program Files\windump –D`
5. Windump will list your adapter with a number. You may have several adapters listed. You select the interface to start running windump. (as shown in step 5 using interface number 1).
6. Run windump to collect packets and write out to a file. `c:\Program Files\windump -i 1 -q -w C:\perflogs\diagTraces -n -C 30 -W 10 -U -s 0`

This will create a directory c:\perflogs\ and a file called diagTrace0.

The switches mean this:

-i is the number of NIC selected in the previous step

-q is quiet mode

-w <name> is the prefix of the files to create

-n the logging will not resolve host names, all data will be in IP address format

-C the size in Millions of Bytes the logs files so grow to before moving to the next file

-W the number of circular log files to retain in addition to the current log file, specify in <path> where the files are to be stored

-U as each packet is saved, it will be written to the output file

-s decreases the amount of packet buffering, set this to zero

---

**2. netstat (For LINUX and Windows)**

netstat (network statistics) is a command line tool for monitoring network connections both incoming and outgoing as well as viewing routing tables, interface statistics etc.

```
$ netstat
```

OUTPUT:
```
Active Internet connections (w/o servers)
Proto Recv-Q Send-Q Local Address           Foreign Address         State      
tcp        0      0 djoe:46106              91.108.23.100:https     ESTABLISHED
tcp        0      0 djoe:46096              91.108.23.100:https     ESTABLISHED
tcp        0      0 djoe:50324              55.65.117.34.bc.g:https ESTABLISHED
tcp        0      0 djoe:58018              lb-140-82-114-26-:https ESTABLISHED
tcp        0      0 djoe:46122              91.108.23.100:https     ESTABLISHED
tcp        0      0 djoe:54764              91.108.56.188:https     ESTABLISHED
tcp        0      0 djoe:39214              91.108.23.100:https     ESTABLISHED
...
Active UNIX domain sockets (w/o servers)
Proto RefCnt Flags       Type       State         I-Node   Path

unix  3      [ ]         STREAM     CONNECTED     23441    
unix  3      [ ]         STREAM     CONNECTED     28107    /run/user/1000/bus
unix  3      [ ]         STREAM     CONNECTED     26790    
unix  3      [ ]         STREAM     CONNECTED     28869    /run/user/1000/at-spi/bus_0
unix  3      [ ]         STREAM     CONNECTED     30739    /run/dbus/system_bus_socket
unix  3      [ ]         STREAM     CONNECTED     131983   
unix  3      [ ]         STREAM     CONNECTED     22329    
unix  3      [ ]         STREAM     CONNECTED     138798   /run/user/1000/at-spi/bus_0
unix  3      [ ]         STREAM     CONNECTED     115356   
...
```

*Note: Output may vary*

---

**3. ifconfig (For LINUX)**

It displays the details of a network interface card like IP address, MAC Address, and the status of a network interface card.

```
ifconfig
```

OUTPUT:

```
eth0: flags=4163<UP,BROADCAST,RUNNING,MULTICAST>  mtu 1500
        inet 172.17.0.2  netmask 255.255.0.0  broadcast 172.17.255.255
        ether 02:42:ac:11:00:02  txqueuelen 0  (Ethernet)
        RX packets 942  bytes 581770 (581.7 KB)
        RX errors 0  dropped 0  overruns 0  frame 0
        TX packets 888  bytes 75991 (75.9 KB)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0

lo: flags=73<UP,LOOPBACK,RUNNING>  mtu 65536
        inet 127.0.0.1  netmask 255.0.0.0
        loop  txqueuelen 1000  (Local Loopback)
        RX packets 0  bytes 0 (0.0 B)
        RX errors 0  dropped 0  overruns 0  frame 0
        TX packets 0  bytes 0 (0.0 B)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0
```

*Note: Output may vary*

---

**a). ipconfig (For Windows)**

![Execution](https://i.postimg.cc/0y38FX9P/Screenshot-2023-08-14-14-21-56.png)

---

**4. nslookup (For LINUX and Windows)**

nslookup (stands for “Name Server Lookup”) is a useful command for getting information from DNS server. It is a network administration tool for querying the Domain Name System (DNS) to obtain domain name or IP address mapping or any other specific DNS record.

1. `nslookup annauniv.edu`
2. `nslookup 172.217.26.206`
3. `nslookup -type=any annauniv.edu`



```
$ nslookup annauniv.edu
```

OUTPUT:

```
Server:         192.168.43.1
Address:        192.168.43.1#53

Non-authoritative answer:
Name:   annauniv.edu
Address: 14.139.161.7
```

---

**5. traceroute ( For LINUX)**

The traceroute command is used in Linux to map the journey that a packet of information undertakes from its source to its destination.

```
$ traceroute
```

OUTPUT:

```
Usage:
  traceroute [ -46dFITnreAUDV ] [ -f first_ttl ] [ -g gate,... ] [ -i device ] [ -m max_ttl ] [ -N squeries ] [ -p port ] [ -t tos ] [ -l flow_label ] [ -w MAX,HERE,NEAR ] [ -q nqueries ] [ -s src_addr ] [ -z sendwait ] [ --fwmark=num ] host [ packetlen ]
...
```

```
$ traceroute annauniv.edu
```

OUTPUT:

```
traceroute to annauniv.edu (14.139.161.7), 30 hops max, 60 byte packets
 1  _gateway (192.168.43.1)  1.907 ms  1.916 ms  2.538 ms
 2  117.96.121.33 (117.96.121.33)  61.752 ms  71.042 ms  71.263 ms
 3  dsl-tn-dynamic-021.223.22.125.airtelbroadband.in (125.22.223.21)  74.057 ms dsl-tn-dynamic-053.223.22.125.airtelbroadband.in (125.22.223.53)  69.425 ms  69.643 ms
 4  116.119.94.36 (116.119.94.36)  71.267 ms 182.79.198.216 (182.79.198.216)  69.659 ms 182.79.142.234 (182.79.142.234)  71.246 ms
 5  49.44.220.188 (49.44.220.188)  87.423 ms  87.163 ms  87.401 ms
 6  * * *
 7  115.247.85.130 (115.247.85.130)  44.260 ms  53.485 ms  53.215 ms
...
```

```
traceroute 172.16.20.139
```

OUTPUT:

```
traceroute to 172.16.20.139 (172.16.20.139), 30 hops max, 60 byte packets
 1  _gateway (192.168.43.1)  3.126 ms  3.139 ms  3.229 ms
 2  117.96.121.33 (117.96.121.33)  60.528 ms  60.510 ms  63.581 ms
 3  dsl-tn-dynamic-021.223.22.125.airtelbroadband.in (125.22.223.21)  63.563 ms dsl-tn-dynamic-053.223.22.125.airtelbroadband.in (125.22.223.53)  60.462 ms  60.193 ms
 4  116.119.68.223 (116.119.68.223)  92.171 ms 116.119.57.158 (116.119.57.158)  102.614 ms 116.119.81.151 (116.119.81.151)  92.499 ms
 5  * * *
...
```

---

**a). tracert (For Windows)**

1. `tracert /?`
2. `tracert drsacoe.com`
3. `tracert 172.16.20.139`

---

**6. ping command**

a). ping 127.0.0.1

```
$ ping 127.0.0.1
```

OUTPUT:
```
PING 127.0.0.1 (127.0.0.1) 56(84) bytes of data.
64 bytes from 127.0.0.1: icmp_seq=1 ttl=64 time=0.030 ms
64 bytes from 127.0.0.1: icmp_seq=2 ttl=64 time=0.048 ms
64 bytes from 127.0.0.1: icmp_seq=3 ttl=64 time=0.027 ms
...
```

b).ping localhost

```
$ ping localhost
```

OUTPUT:

```
PING localhost(localhost (::1)) 56 data bytes
64 bytes from localhost (::1): icmp_seq=1 ttl=64 time=0.028 ms
64 bytes from localhost (::1): icmp_seq=2 ttl=64 time=0.024 ms
64 bytes from localhost (::1): icmp_seq=3 ttl=64 time=0.028 ms
...
```

c). ping \<IPv4 address>

```
$ ping 166.62.28.89
```

OUTPUT:

```
PING 166.62.28.89 (166.62.28.89) 56(84) bytes of data.
64 bytes from 166.62.28.89: icmp_seq=1 ttl=54 time=185 ms
64 bytes from 166.62.28.89: icmp_seq=2 ttl=54 time=87.9 ms
64 bytes from 166.62.28.89: icmp_seq=3 ttl=54 time=231 ms
...
```

d).ping \<hostname>

```
$ ping google.com
```

OUTPUT:

```
PING google.com(bom07s33-in-x0e.1e100.net (2404:6800:4009:826::200e)) 56 data bytes
64 bytes from bom07s33-in-x0e.1e100.net (2404:6800:4009:826::200e): icmp_seq=1 ttl=118 time=89.6 ms
64 bytes from bom07s33-in-x0e.1e100.net (2404:6800:4009:826::200e): icmp_seq=2 ttl=118 time=99.9 ms
64 bytes from bom07s33-in-x0e.1e100.net (2404:6800:4009:826::200e): icmp_seq=3 ttl=118 time=68.3 ms
...
```

e). ping < default gateway address>

```
$ ping 192.168.43.1
```

OUTPUT:

```
PING 192.168.43.1 (192.168.43.1) 56(84) bytes of data.
64 bytes from 192.168.43.1: icmp_seq=1 ttl=64 time=34.4 ms
64 bytes from 192.168.43.1: icmp_seq=2 ttl=64 time=34.5 ms
64 bytes from 192.168.43.1: icmp_seq=3 ttl=64 time=3.19 ms
...
```

f). Ping an Internet Host by IPv4 Address

```
$ ping 8.8.8.8
```

OUTPUT:

```
PING 8.8.8.8 (8.8.8.8) 56(84) bytes of data.
64 bytes from 8.8.8.8: icmp_seq=1 ttl=59 time=424 ms
64 bytes from 8.8.8.8: icmp_seq=2 ttl=59 time=68.6 ms
64 bytes from 8.8.8.8: icmp_seq=3 ttl=59 time=69.8 ms
...
```

g). Ping an Internet Host by Name

```
$ ping google.com
```

OUTPUT:

```
PING google.com(bom07s33-in-x0e.1e100.net (2404:6800:4009:826::200e)) 56 data bytes
64 bytes from bom07s33-in-x0e.1e100.net (2404:6800:4009:826::200e): icmp_seq=1 ttl=118 time=89.6 ms
64 bytes from bom07s33-in-x0e.1e100.net (2404:6800:4009:826::200e): icmp_seq=2 ttl=118 time=99.9 ms
64 bytes from bom07s33-in-x0e.1e100.net (2404:6800:4009:826::200e): icmp_seq=3 ttl=118 time=68.3 ms
...
```

h). Ping an Internet Host by IPv6 Address

```
$ ping6 2404:6800:4007:818::200e
```

OUTPUT:
```
PING 2404:6800:4007:818::200e(2404:6800:4007:818::200e) 56 data bytes
64 bytes from 2404:6800:4007:818::200e: icmp_seq=1 ttl=59 time=80.5 ms
64 bytes from 2404:6800:4007:818::200e: icmp_seq=2 ttl=59 time=97.2 ms
64 bytes from 2404:6800:4007:818::200e: icmp_seq=3 ttl=59 time=168 ms
...
```

i). Ping an Internet Host by IPv6 Name

```
$ ping6 google.com
```

OUTPUT:
```
PING google.com(maa05s17-in-x0e.1e100.net (2404:6800:4007:818::200e)) 56 data bytes
64 bytes from maa05s17-in-x0e.1e100.net (2404:6800:4007:818::200e): icmp_seq=1 ttl=59 time=89.5 ms
64 bytes from maa05s17-in-x0e.1e100.net (2404:6800:4007:818::200e): icmp_seq=2 ttl=59 time=99.3 ms
64 bytes from maa05s17-in-x0e.1e100.net (2404:6800:4007:818::200e): icmp_seq=3 ttl=59 time=62.7 ms
...
```