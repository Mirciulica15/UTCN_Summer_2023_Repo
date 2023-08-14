# HashiCorp
* **HashiCorp** is a company specializing in managed **open-source tools** used t support the **development and deployment of large-scale service-oriented software installations**.
* What is **HashiCorp Cloud Platform (HCP)**?
  - HCP is a unified platform to access HashiCorp various products
  - HCP services are **cloud agnostic**
    + support for the main cloud service providers (CSPs) eg. AWS, GCP and Azure
  - highly suited for **multi-cloud workloads**

## HashiCorp Products
* **Boundary** - secure remote access to systems based on trusted identity
* **Consul** - service discovery platform; provides a full-featured service mesh for secure service segmentation across any cloud or runtime environment, and distributed key-value storage for application configuration
* **Nomad** - scheduling and deployment of tasks across worker nodes in a cluster
* **Packer** - tool for bulding virtual-machine images for later deployment
* **Terraform** - infrastructure as code software which enables provisioning and adapting virtual infrastructure across all major cloud provider
  - **Terraform Cloud** - a place to store and manage IaC in the cloud or with teams
* **Vagrant** - building and maintenance of reproductible software development environments via virtualization technology
* **Vault** - secrets management, identity-based access, encrypting application data and auditing of secrets for applications, system and users
* **Waypoint** - modern workflow to build, deploy, and release across platforms

<br>

# What is Terraform?
* **Terraform** is an **open-source** and **cloud-agnostic** Infrastucture as Code (IaC) tool.
* Terraform uses **declarative** configuration files.
* The configuration files are written in **HashiCorp Configuration Language (HCL)** (also known as **Terraform Language**).
* Notable features of Terraform:
  - Installable modules
  - Plan and predict changes
  - Dependency graphing
  - State management
  - Provision infrastructure in familiar languages (via AWS CDK)
* Terraform Registry with 1000+ providers
![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/1ac88ff7-fe6c-43a5-af4c-7c7417937105)

<br>

# What is Terraform Cloud?
* Terraform Cloud is a Software as Service (SaaS) offering for:
  - Remote state storage
  - Version Control integrations
  - Flexible workflows
  - Collaborate on Infrastructure changes in a single **unified web portal** (www.terraform.io/cloud)
* Terraform Cloud has a **generous free-tier** that allows for team collaboration for the first 5 users of your organization.
* The underlying software for Terraform Cloud and Terraform Enterprise is known as the "Terraform Platform".
