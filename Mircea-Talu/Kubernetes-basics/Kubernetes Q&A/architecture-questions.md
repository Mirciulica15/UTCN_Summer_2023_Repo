# Architecture Questions

<br>

1. **What are the different components of Kubernetes architecture?**
   - Main Node (Master) : handles the Control plane
   - Worker Nodes : they have pods, pods have containers
   - API Server : the "gate" we use to make requests to the cluster (validates and configures data for the API objects such as the pods, services etc
   - Scheduler : is responsible for distribution and management off workloads
   - Controller Manager :
     + daemon that embeds controllers. It basically does namespace creation and garbage collection
     + ![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/778e5aeb-9bbb-4169-8e3d-120a44e2a2f9)
   - etcd : distributed key:value database, designed to provide a reliable and highly available way to store and manage config data, metadata, and all esential information for distributed systems and applications
   - Kubelet : specific to every node, handles the Container Runtime
   - Kube proxy : specific to every node, handles networking (performs simple TCP/UDP packet forwarding across backend network service)

