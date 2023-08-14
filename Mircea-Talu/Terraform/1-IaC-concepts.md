# IaC (Infrastructure as Code) Concepts

### The Problem with Manual Configuration
* Downsides:
  + Easy to misconfigure
  + Hard to manage the expected state of configuration for compliance
  + Hard to trasnfer configuration knowledge to other team members

* Infrastructure as Code (IaC)
  + Write a configuration to **automate** _creating, updating or destroying_ cloud infrastructure
  + IaC is a **blueprint** of your infrastructure
  + IaC allows you to easily **share, version or inventory** your cloud infrastructure
  ![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/aefcfdd9-3da0-4a69-8538-427b1fe57b05)

<br>

# Popular IaC tools

### Declarative vs Imperative
* **Declarative**
  + What you see is what you get -> **Explicit**
  + More verbose, but zero chance of misconfiguration
  + Use scripting languages eg. JSON, YAML, XML

* **Imperative**
  + You say what you want, and the rest is filled in -> **Implicit**
  + Less verbose, you could end up with misconfiguration
  + Can do more than Declarative
  + Uses programming languages eg. Python, Ruby, JavaScript

<br>

* Terraform is declarative, but the Terraform Language features **imperative-like functionality**
* The best of both worlds
![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/44c0c8c5-3f08-4fed-9682-d0752be63b7f)

<br>

# Infrastructure Lifecycle
* A number of clearly defined and distinct work phases, used by DevOps Engineers to **plan, design, build, test, deliver, maintain and retire** cloud infrastructure
* Day 0, Day 1, Day 2
  + Day 0 - Plan and Design
  + Day 1 - Develop and Iterate
  + Day 2 - Go live and maintain
* How does IaC enhance the Infrastructure Lifecycle?
  + **Reliability** - IaC makes changes **idempotent**, consistent, repeatable and predictable
    - **Idempotent** : no matter how many times you run IaC, you will always end up with the same state that is expected
    - In IaC, idempotency means that you can run your script multiple times, but the outcome will be the same as running it just once
  + **Manageability**
    - Enable mutation via code
    - Revised, with minimal changes
  + **Sensibility**
    - Avoid financial and reputational losses to even loss of life when considering government and military dependencies on infrastructure

<br>

# Indempotent vs Non-Idempotent
![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/047d324a-5ab3-490b-b82d-34507b03a16d)

<br>

# Provisioning vs Deployment vs Orchestration
* Sometimes they have overlapping responsabilities

## Provisioning
* To prepare a server with systems, data and software, and make it ready for network operation.
* Using Configuration Management tools like Puppet, Ansible, Chef, Bash scripts, Powershell or Cloud-Init you can provision a server
* When you launch a cloud service and configure it you are **provisioning**

## Deployment
* The act of delivering a version of your application to run a provisioned server
* Deployment could be performed via AWS CodePipline, Harness, Jenkins, GitHub Actions, CircleCI

## Orchestration
* Orchestration is the act of coordinating multiple systems or services
* Orchestration is a common term when working with microsrevices, Containers and Kubernetes
* Orchestration could be Kubernetes, Salt, Fabric

<br>

# Configuration Drift
* **Configuration Drift** is when provisioned infrastructure has **an unexpected configuration change** due to:
  - team members manually adjusting configuration options
  - malicious actors
  - side affects from APIs, SDK or CLIs
* **Configuration Drift** going unnoticed could be loss or breach of cloud services and residing data or result in interruption of services or unexpected downtime.
* How to **detect** configuration drift?
* A compliance tool that can detect misconfiguration eg. AWS Config, Azure Policies, *GCP Security Health Analytics
* Built-in support for drift detection eg. AWS CloudFormation Drift Detection
* Storing the expected state eg. **Terraform state files**
* How to **correct** configuration drift?
* A compliance tool that can remediate (correct) misconfiguration e.g. AWS Config
* Terraform **refresh** and **plan** commands
* Manually correcting the configration (not recommended)
* Tearing down and setting up the infrastructure again
* How to **prevent** configuration drift?
* **Immutable infrastructure**, always create and destroy, never reuse, Blue, Green deployment strategy.
  - Servers are never modified after they are deployed
    + **Baking AMI images or containers** via AWS Image Builder or HashiCorp Packer, or a build server eg. GCP Cloud Run
* Using GitOps to version control our IaC, and peer review every single change to infrastructure via Pull Requests

<br>

# Mutable vs Immutable Infrastructure
![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/382811ce-6257-4769-8f53-68c4a6c9418b)

<br>

# What is GitOps?
* **GitOps** is when you take Infrastructure as Code (IaC) and you use a git repository to **introduce a formal process to review and accept changes to infrastructure code**, once that code is accepted, it automatically triggers a deploy
![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/17687f03-bb60-44c2-81e5-0f9ce5821ebd)

<br>

# Immutable Infrastructure Guarantee
* Terraform encourages your mind towards an Immutable Infrastructure architect so you get the following guarantee.
- **Cloud Resource Failure** - What if an EC2 instance fails a status check?
- **Application Failure** - What if your post installation script fails due to change in package?
- **Time to Deploy** - What if I need to deploy in a hurry?
* **Worst Case Scenario**
  - Accidental Deletion
  - Compromised by malicious actor
  - Need to Change Regions (region outage)
* **No Guarantee of 1-to-1**
  - Every time Cloud-Init runs post deploy there is no guarantee its one-to-one with your other VMs.
    ![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/ff73c4d3-d27a-41f3-ac03-b18c7878102f)
