# Terraform Lifecycle

![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/dd0f0841-96fd-46c8-a23d-f08689bae170)

<br>

# Change Automation

* What is **Change Management**?
  - A standard approach to apply change, and resolving conflicts brough about by change
  - In the context of Infrastructure as Code (IaC), Change Management is the procedure that will be followed when resources are modified and applied via configuration script.
* What is **Change Automation**?
  - A way of **automatically** creating a consisitent, systematic, and predictale way of managing change requests via controls and policies

* Terraform uses Change Automation in the form of **Execution Plans** and **Resource graphs** to apply and review complex **ChangeSets**
* What is a **ChangeSet**?
  - A collection of commits that represent changes made to a versioning repository
  - IaC uses ChangeSets so you can see what was changed by who over time.
* Change Automation allows you to know exactly what Terraform will change and in what order, avoiding many possible human errors.

<br>

# Execution Plans

* An **Execution Plan** is a **manual review** of what will be **added, changed or destroyed** before you apply changes eg. terraform apply
![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/0ad9a4dd-a85a-4d53-8541-2a8256a457b8)

<br>

# Visualizing Execution Plans
* You can **visualize an execution plan** as a graph using the **terraform graph** command Terraform will output a GraphViz file (you'll need GraphViz installed to view the file)
* **GraphViz** is an open-source tool for drwaing graphs speified in DOT language scripts having the file name extension "gv"
![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/805b8ca2-c26d-45bc-8854-69110b768817)

<br>

# Resource Graph
* Terraform build a **dependency graph** from the Terraform configurations, and walks this graph to generate plans, refresh state, and more.
* When you use **terraform graph**, this is a visual representation of the dependency graph
* **What is a dependency graph?**
* In mathematics, it's a directed graph representing dependencies of several objects towards each other
![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/4d7e328b-c034-4ffa-a043-3d09ea121201)

<br>

# Use Cases

* **IaC for Exotic Providers**
  - Terraform supports a variety of providers outside of GCP, AWS, Azure and sometimes is the only provider.
  - Terraform is open-source and extendable so any API could be used to create IaC tooling for any kind of cloud platform or technology eg. Heroku, Spotify Playlists.

* **Multi-Tier Applications**
  - Terraform by default makes it easy to divide large and complex applications into isolate configuration scripts (module).
  - It has a complexity advantage over cloud-native IaC tools for its flexibility while retaining simplicity over Imperative tools.

* **Disposable Environments**
  - Easily stand up an environment for a software demo or a temporary development environment.

* **Resource Schedulers**
  - Terraform is not just defined to infrastructure of cloud resource but can be used to dynamically schedule Docker containers, Haddop, Spark and other software tools.
  - You can provision your own scheduling grid.

* **Multi-Cloud Deployment**
  - Terraform is cloud-agnostic and allows a single configuration to be used to manage multiple providers, and to even handle cross-cloud dependencies.

<br>

# Terraform Core and Terraform Plugins

* Terraform is logically split into 2 main parts:
  1. **Terraform Core**
     - uses remote procedure calls (RPC) to communicate with Terraform Plugins
  2. **Terraform Plugins**
     - expose an implementation for a specific service, or provisioner
* Terraform Core is a statically-compiled **binary written in the Go programming language**.
![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/177b3bb3-ec76-4ff3-bd4d-1e47c4a791f2)

<br>

# Terraform Up and Running
![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/dd92b7d3-afec-4b01-93e5-120857f345d4)

<br>

# Terraform Best Practices
![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/1ede8010-4da8-43ef-aac2-0cdc497bce89)

[Best Practices](www.terraform-best-practices.com)
