# Ex.No. 5a - Write the use of the following network configuration commands in respective environment - Unix / Windows

**i) tcpdump**

**ii) netstat**

**iii) ifconfig / ipconfig**

**iv) nslookup**

**v) traceroute**

## i) TCPDUMP

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

![Execution](https://imgur.com/t2mpNDX.png)

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

![Execution](https://imgur.com/mLZEJZG.png)

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

## ii) NETSTAT

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

## iii) IFCONFIG / IPCONFIG

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

**ipconfig (For Windows)**

![Execution](https://i.postimg.cc/0y38FX9P/Screenshot-2023-08-14-14-21-56.png)

---

## iv) NSLOOKUP

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

## v) TRACEROUTE

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
