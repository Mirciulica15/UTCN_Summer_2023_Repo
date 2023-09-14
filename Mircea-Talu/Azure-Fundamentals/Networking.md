# Networking

[WATCH THIS!!!](https://www.youtube.com/watch?v=15amNny_kKI)

VPN - virtual private network

Create tunnel for secure connection between private networks over untrusted network (usually the internet)

_Interesting_ traffic

### IPSEC phases

Phase 1 - Diffie Hellman algorithm => Phase 1 key

Phase 2 - Create Phase 2 key

### Types of VPNs

1. Policy-based

  - Uses the prefix to route interesting traffic

  - Simple

2. Route-based

   - Uses different _rules_ to route
  
   - You can create multiple **Phase 2 keys** over the tunnel
  
![image](https://github.com/Mirciulica15/UTCN_Summer_2023_Repo/assets/36898665/5ad8c744-474f-4a2e-b001-f261e414208a)

<br>

### BGP

[WATCH THIS!!!](https://www.youtube.com/watch?v=6XW5cRa3ZKM)

Border Gateway Protocol

Made of lots of self-managing networks, called **autonomous systems**.

AS - **Autonomous System**

ASN - Autonomous System Number -> managed by IANA

AS Path - **Shortest path**

AS Path Prepending - Artificially making the path longer to make it less appealing

![image](https://github.com/Mirciulica15/UTCN_Summer_2023_Repo/assets/36898665/f6c57dad-560f-4b48-bbe6-f6ddb6aaea6b)

<br>

### ACL

[WATCH THIS!!!](https://www.youtube.com/watch?v=0gGhuYOh-54&list=PLIFyRwBY_4bRkAk_BkWL3ea6lRvOn8AKs)

Access Control Lists

Used to **identify traffic**

ACLs applied to **interfaces** are sometimes called **packet filters**

Only 1 Packet Filter ACL can be applied:

- per interface

- per direction

- per IP protocol

Types:

1. **Standard** (Matches only on source IP)

2. **Extended** (Matches on source IP, destination IP, source port, destination port, protocol) => granular control
