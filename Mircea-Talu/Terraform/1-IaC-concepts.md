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
  + ![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/aefcfdd9-3da0-4a69-8538-427b1fe57b05)

<br>

# Popular IaC tools

### Declarative vs Imperative
* **Declarative**
  + What you see is what you get -> **Explicit**
  + More verbose, but zero chance of misconfiguration
  + Use scripting languages eg. JSON, YAML, XML

* **Imperative**
  + You say what you want, and the rest is filled in -> **Implicit**
  + Less verbose, you could endup with misconfiguration
  + Can do more than Declarative
  + Uses programming languages eg. Python, Ruby, JavaScript

<br>

* Terraform is declarative, but the Terraform Language features **imperative-like functionality**
* The best of both worlds
* ![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/44c0c8c5-3f08-4fed-9682-d0752be63b7f)

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













 




