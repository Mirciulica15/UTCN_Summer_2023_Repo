# [Network Namespaces](https://www.youtube.com/watch?v=j_UUnlVC2Ss&t=342s&ab_channel=KodeKloud)

* they are used by containers like Docker to implement network isolation
* containers are separated from the underlying host using namespaces
* namespaces are the **rooms** inside of the house (host) => **privacy**
* you can establish **connectivity** between rooms
* the container only sees the processes run by it
* the host sees everything
* the host has its own interfaces that connects to the local area network (routing and ARP table)
* we want to **seal** everything from the container
* we create a network namespace for the container so it doesn't have any info outside
* inside the namespace, the container can have its own virtual interfaces, routinf and ARP tables

## Create a new network
* **ip netns add red** creates a network namespace called **red**
* **ip netns** lists all the network namespaces
* **ip link** lists the interfaces on the host
* **ip netns exec red ip link** executed **ip link** inside the **red** namespace
* same for the ARP table:
* **ip -n red link** does the same thing
* **arp** on the host has a list of entries
* **ip netns exec red arp** => no entries
* same for routing table (...)
* **ip netns add blue** creates another network namespace called **blue**
* right now, there is no conectivity between these 2 namespaces
* we use a **virtual internet pair** (**virtual cable** or **pipe**)
* **ip link add veth-red type veth peer name veth-blue**
* next, attach each interface to the appropiate namespaces:
* **ip link set veth-red netns red**
* **ip link set veth-blue netns vlue**
* assign IP addresses to these namespaces:
* **ip -n red addr 192.168.15.1 dev veth-red**
* **ip -n blue addr add 192.168.15.2 dev veth-blue**
* **ip -n red link set veth-red up**
* **ip -n blue link set veth-blue up**
* **ip netns exec red ping 192.168.15.2** => SUCCESS
* **ip netns exec red arp** => SUCCESS
* ![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/04de5894-022c-430a-b9fc-ca061c3c7733)

## What do we do when we have more namespaces? How do we enable them to communicate?
* we create a virtual network
* we need a virtual switch within our host
* we use the **Linux Bridge** option
* **ip link add v-net-0 type bridge** - an interface (the master switch)
* **ip link set dev v-net-0 up** - bring it up
* now we need to connect the namespaces to this switch
* we delete the previous link we had between red and blue
* ![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/32dae83c-a6ca-4a49-aa07-084616e44443)
* **ip link add veth-red type veth peer name veth-red-br** - connects to the **br** (bridge) network
* **ip link add veth-blue type veth peer name veth-blue-br** - connects to the **br** (bridge) network
* **ip link set veth-red netns red**
* **ip link set veth-blue netns blue**
* **ip link set veth-red-br master v-net-0** - specifies the master as the v-net-0
* **ip link set veth-blue-br master v-net-0** - specifies the master as the v-net-0
* **ip -n red addr add 192.168.15.1 dev veth-red**
* **ip -n red addr add 192.168.15.1 dev veth-red**
* turn up the devices:
* **ip -n red link set veth-red up**
* **ip -n blue link set veth-blue up**
* if we want to achieve connectivity between the host and the namespaces:
* assign an IP address to v-net-0
* **ip addr add 192.168.15.5/24 dev v-net-0**
* we have to create a Gateway to the outside world
* our **localhost** is the **Gateway**
* **ip netns exec blue ip route add 192.168.1.0/24 via 192.168.15.5** - route all traffic to 192.168.1 network through the gateway at 192.168.15.5
* we have to enable **NAT** on our host:
* **iptables -t nat -A POSTROUTING -s 192.168.15.0/24 -j MASQUERADE**
* **ip netns exec blue ip route add default via 192.168.15.5**
* ![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/1e0081bd-0dae-4db4-a4aa-77778c700317)
