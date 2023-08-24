# What is Kubernetes?

* Monolithic -> Microservices
* Kubernetes is a **container orchestration system**
* YAML syntax - declarative format
* Main Node and Worker Nodes
* The Worker Nodes run Pods
* PODS are abastractions of CONTAINERS
* Pods are assigned IP addresses

<br>

# Main node
* provide IP for pod
* provide load-balancing
* has 4 functionalities
  1. **API server** - allows to communicate with the cluster thorugh CLI
  2. **Controller Manager** - keeps track of the state within the cluster
  3. **Scheduler** - ensures where a pod has to be placed
  4. **etcd** - keeps track of the state of the cluster (provides changes in state, i.e. when a pod goes down)
* **kubectl** interface -> make calls to the API server
* **API server** is reponsible for **interaction** between the cluster and the **outside world**
* is also responsible for **authetication**
* **API Server** interacts with the etcd
* **etcd** is a **key:value** store (database)
* each request from the **API Server** to the **etcd** has specific values attached to it (IDs)
* based on that, etcd can **order** the requests
* **kube scheduler** - knows the resources available in each node
* the available nodes are called **feasible**
* you can manage the scheduler yourself
* **kube controller manager** - knows the overall cluster state
* **compares** the desired state to the current state of the cluster and decides upon the action

<br>

![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/19c6e532-699e-44c5-86b9-998e3883c305)

<br>

# Worker nodes
* **kubelet** is responsible for managing the **container runtime**
* **container runtime** is the software responsible for running the container, typically **Docker**
* **kube proxy** is respoible for the **network connectivity** of the **pods** -> IP table
* usually we want to have only **1** container per pod, but we can have more
* we can have **multiple** pods inside a node
* pods are not **consistent**, they are often taken down or they fail
* we should be able to **spin them up**
* each time a pod is spinned up, it gets another IP address => problem
* that's why we usually have a service wrapped around our pod, that determines a fixed IP address
* that way, the pod can fail and restart and so on, but the IP stays fixed
* pods also have persistent storage volume
* **POD STATES**:
  1. **Running** - all containers are up and running
  2. **Uknown**
  3. **Failed** - all the containers are terminated, at least one failed
  4. **Succeded** - all processes were executed and finished
  5. **Pending** - the pod has benn created, but one or more containers isn't running yet

<br>

![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/797a19ed-0722-4fbf-99da-4b9d21206ad9)

<br>

# Services

* each pod has its own IP address
* each time they get terminated and restarted, they change that IP
* **ClusterIP** defined in the yaml to setup the pods
* the Service interfaces with the **Ingress** Controller (our interface with the outside world)

# Setup a local Kubernetes Cluster


