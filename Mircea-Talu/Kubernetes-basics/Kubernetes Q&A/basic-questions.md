# Basic Questions

<br>

1. **What do you understand by Kubernetes?**
   - Kubernetes is an open-source container management (orchestration) tool. It's container management responsibilities include container deployment, scaling & descaling of containers & container load balancing.

<br>

2. **How is Kubernetes related to Docker?**
   - Docker is responsible for managing the lifecycle of containers and these containers are manually linked and orchestrated with Kubernetes.

<br>

3. **What's the difference between deploying applications on host and containers?**
   - ![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/5315f4eb-003f-4363-8453-594176f19dc5)

<br>

4. **What do you understand by Container Orchestration?**
   - Container Orchestration can be thought of as an automated management with immense coordination with all the containers present in the cluster.

<br>

5. **Why do we need Container Orchestration?**
   - In order to deploy multiservice applications
   - ![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/4a3adc38-bc4e-46b9-a891-2bcd8fd0064d)

<br>

6. **How is Kubernetes different from Docker Swarm?**
   - Kubernetes is more suitable when we have 100-1000s of containers in production
   - Kubernetes has auto scaling
   - Kubernetes has a bigger and more complex framework which, among other things, makes scaling up slower
   - Kubernetes has a GUI, Docker Swarm doesn't
   - Kubernetes needs manual intervention for load balancing, Docker Swarm has auto load balancing
   - Kubernetes has built-in tools for logging and monitoring
   - Kubernetes can share storage volumes only with the other containers inside the same pod

<br>

7. **What are the features of Kubernetes?**
   - Automated Scheduling : K8s provides advanced scheduler to launch container on cluster nodes
   - Self Healing Capabilities : Rescheduling, replacing and restarting the containers which have died
   - Automated rollouts and rollback : Updating the pods one by one, in case of failure, rolling back to previous versions (tries to go from **current state** to **desired state**)
   - Horizontal Scaling and Load Balancing : K8s scales the application based on the requirements and traffic, K8s balances the load on the nodes

<br>

8. **How does Kubernetes simplify Containerized Deployment?**
   - K8s uses yaml files to specify configurations (deployments, pods, services, etc).

<br>

9. **What do you know abount Cluster in Kubernetes?**
    - ![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/3263b9c9-1a50-41b4-8124-8989878ad1ca)

<br>

10. **What is Google Container (Kubernetes) Engine (GKE)?**
    - A Google Container Engine, also known as GKE, is an open source container management system which is based on Kubernetes. This is mainly a container orchestration and management system for Docker containers and cluster.
    - Basically Kubernetes, but it's an environment managed by Google (cluster setups, maintenance, scaling, updates, monitoring, security patches, etc).

<br>

11. **What is Heapster?**
    - Heapster is an open-source project that provides monitoring and performance management for containerized applications in Kubernetes clusters.

<br>

12. **What is Minikube?**
    - Minikube is a tool that runs a single node Kubernetes cluster, simplifying learning

<br>

13. **What is Kubectl?**
    - Kubectl is the command line interface available to run the commands against Kubernetes cluster.

<br>

14. **What is Kubelet?**
    - Kubelet is a process specific to every pod that handles the Container Runtime (usually Docker) for every container inside the pod

<br>

15. **What do you understand by node in Kubernetes?**
    - A node (main worker machine, aka minions) is the place where pods run, each node represents a host machine
