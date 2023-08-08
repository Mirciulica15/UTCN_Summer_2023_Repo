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
* **kubelet** is responsible for managing the **container runtime**
* **kube proxy** is respoible for the **network connectivity** of the **pods** -> IP table
* ![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/19c6e532-699e-44c5-86b9-998e3883c305)

