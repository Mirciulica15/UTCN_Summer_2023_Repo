# Terraform Associate Exam Preparation

## Types of IaC Tools

- Configuration Management (Ansible, Puppet, SaltStack)
- Server Templating (Docker, Packer, Vagrant)
- Provisioning Tools (Terraform, CloudFormation)

### Configuration Management

- designed to install and manage software
- version controlled
- idempotent

### Server Templating Tools

- virtual machine or docker images
- pre installed software or dependencies
- immutable infrastructure

### Provisioning Tools

- immutable infrastructure resources
- servers, databases, network components etc
- multiple providers

## Why Terraform

- installed as a single binary
- ability to deploy resources on multiple platforms
- **providers** enable Terraform to provision infrastructure
- uses HCL language, simple declarative language (easy to version control)
- Terraform can **import** other resources created by another entity and bring them into its administration

## Getting started

- .tf extension
- HCL format
- a resource is an **object managed by Terraform**

### HCL basics

```hcl
<block> <parameters> {
  key1 = value1
  key2 = value2
}

resource "local_file" "pet" {
  filename = "/root.pets.txt"
  content = "We love pets!"
}
```

**resource -> Block Name
local_file --> Resource Type
local --> Provider
file --> Resource
pet --> Resource Name
filename, content --> Arguments**

- 4 steps:
  - write tf file
  - terraform init
  - terraform plan
  - terraform apply

- read the documentation of each provider and resource from [Terraform Registry](https://registry.terraform.io/)

## Terraform Providers

- types:
  - official
  - partner
  - community

- you can have **multiple** providers in the same configuration

## Configuration Directory

- main.tf : main configuration file containing resource definitions
- variables.tf : contains variable declarations
- outputs.tf : contains outputs form resources
- provider.tf : contains provider definition

## Variables

- string
- number
- bool
- any
- list
- set
- map
- object
- tuple

```hcl
variable "length" {
  default = 2
  type = number
  description = "Length of name"
}

variable "prefix" {
  default = ["Mr", "Mrs", "Sir"]
  type = list

var.prefix[0], var.prefix[1], var.prefix[2]

variable file-content {
  type = map
  default = {
    "statement1" = "We love pets!"
    "statement2" = "We love animals!"
  }
}

var.file-content["statement2"]

variable "fruit" {
  default = ["apple", "orange", "grape"]
  type = set(string)

// sets cannot have duplicate elements

variable "bella" {
  type = object({
    name = string
    color = string
    age = number
    food = list(string)
    favorite_pet = bool
  })

  default = {
    name = "bella"
    color = "brown"
    age = 7
    food = ["fish", "chicken"]
    favorite_pet = true
  }
}

variable "kitty" {
  type = tuple([string, number, bool])
  default = ["bella", 7, true]
```

- if we don't write default values, we will be prompted to do so when we apply
- we can use the -var argument to provide arguments: **terraform apply -var "filename=/root/pets.txt"**
- better, we can use the syntax: **TF_VAR_filename** and then simply do **terraform apply** (TF_VAR prefix)
- another option is to create a **terraform.tfvars** (or terraform.tfvars.json, \*.auto.tfvars, \*.auto.tfvars.json) file where we can easily specifies the values (**filename = "/root/pets.txt"**)
- if you use a different name for the tfvars, you have to pass it at apply time like this: **terraform apply -var-file variables.tfvars**

If you use multiple ways to define a variable, terraform uses **variable definition precedence**!

-var or -var-file > *.auto.tfvars (alphabetical order) > terraform.tfvars > environment variables !!! (in terms of **strength**)

## Resource Dependencies

- implicit dependency : use **attribute** of another resource via reference expressions (terraform figures order on its own)
- explicit dependency : use **depends_on**

## Output variables

```hcl
output "<variable_name>" {
  value = "<variable_value">
  <arguments>
}

output pet-name {
  value = random_pet.my-pet.id
  description = "Record the value of the pet ID"
}
```

- when running terraform apply, we can see an **Outputs:** block
- **terraform output** shows outputs
- they get saved in the **state file** also

## Terraform state (.tfstate)

- JSON file
- single state of **truth** for Terraform
- when we run plan or apply, Terraform **refreshes** the .tfstate file with the actual state
- **then**, it reconciles it with the desired configuration
- resources can be created in **parallel** as long as they do not have any **dependency** (implicit or explicit) between them
- if we are 100% **confident** that the actual infrastructure has not changed outside of terraform, we can run **terraform plan/apply --refresh=false**
- this could **save time** with large infrastructure, but could be **dangerous**
- make state **accesible** to all team members (remote state **backends**)

## Terraform Commands

- **terraform validate** - check configuration (does **not** check the values for the resources, just the **arguments**)
- **terraform fmt** - format the code
- **terraform show** - print current state of the infrastructure
- **terraform providers** - show all providers
- **terraform output** - print outputs
- **terraform refresh** - reconcile state with actual infrastructure (in case it is changed outside of Terraform)
- **terraform graph** - create a dependency graph for the resources
- install graphviz --> **terraform graph | dot -Tsvg graph.svg**

## Mutable vs Immutable Infrastructure

- **configuration drift** leaves infrastructure in complex state
- **immutable** = does not change
- create new, then delete old

## Lifecycle Rules

- **lifecycle** block
- example:

```hcl
lifecycle {
  create_before_destroy = true
}
```

```hcl
lifecycle {
  prevent_destroy = true
}
```

```hcl
lifecycle {
  ignore_changes = [
    tags
  ]
}
```

- be **careful** with create_before_destroy, if nothing changes, terraform might create the resource (idempotent) and then delete it (no more resource)

## Data Sources

- read resource attributes from resources provisioned outside of Terraform

## Meta Arguments

- **count**: create multiple resources

```hcl
resource "local_file" "pet" {
  filename = var.filename[count.index]
  count = length(var.filename)
}
```

- **for_each**: only works with a **map** or a **set**
- use list, or **toset()**
- resources identified by unique **string**, not by **id** (count)

## Version Constraints

- specifies constraints for providers in code

```hcl
terraform {
  required_providers {
    local = {
      source  = "hashicorp/local"
      version = "1.4.0"
    }
  }
}
```

- can use **!=**, **>**, **<**, **~>**, etc.

## AWS & IAM

- create users, put them in groups
- assign policies
- IAM is independent of region (Global)

2 types of access methods:

- access to **management console**
- **programatic access** (access keys)

## AWS CLI

- **aws configure**: configure credential access
- **aws \<command\> \<subcommand\> \[options and parameters\]**

## Heredoc

```hcl
policy = <<EOF
  {
    "Version": "2012-10-17",
    "Statement": [
      {
        "Effect": "Allow",
        "Action": "*",
        "Resource": "*"
      }
    ]
  }
  EOF
```

## AWS S3

- 2 access methods:
  - bucket policy
  - access control lists (ACLs)

## AWS DynamoDB

- NoSQL
- one primary key
- great for large data
- scalable

## Remote State

- **don't** store the state in a **version control system**
- the .tfstate holds **sensitive** information
- should not allow **concurrent** operations -> **state lock**
- GitHub doesn't support state lock
- you should hold it in a **remote state backend** (AWS S3, Terraform Cloud, etc.) -> they allow state locking + security

**backend** block

```hcl
backend "s3" {
  bucket = "bucket-name"
  key    = "dir/terraform.tfstate"
  region = "us-west-1"
  (dynamodb_table = "state-locking")
}
```

- you must run **terraform init** again after changing backend

## terraform state \<subcommand\> \[options\] \[args\]

- terraform state list -> shows resources (just the names, easy to read)
- terraform state show RESOURCE -> show specific resource
- terraform state mv -> change attribute (name)
- terraform state pull -> pull state and print
- terraform state rm ADDRESS -> remove resources from state file (when you no longer want to manage them)
- the resources are not actually **destroyed**, they are just moved from Terraform's **management**

## Amazon EC2

- Amazon Machine Image (AMI)
- Instance types: General Purpose, Compute Optimized, Memory Optimized
- General Purpose: T2 (nano, micro, small, medium, large, xlarge, 2xlarge), T3, M5
- EBS (Elastic Block Storage)
- **user_data** section: you can write a script (to install nginx for example) -> only works at **first run** (creation, not modification of resource)
- create SSH key to connect to VM
- **aws_key_pair**: authentication, SSH key pair
- **aws_security_group**: configure access to resource

## Remote Exec

- run tasks (eg. a script) using a **provisioner "remote-exec" block**

## Local Exec

- run tasks locally, on the machine which runs Terraform
- by default, provisioners are run after the resources are created
- **destroy** time provisioner, run before destruction of resource
- **on_failure = continue**, allows terraform apply to not fail if provisioner fails

## Considerations with Provisioners

- use rarely
- they increase complexity
- use **native** provisioners for resources (like **user_data**)
- keep post provisioning to a minimum

## Terraform Taint

- if an apply operations fails on a resource, then that resource is **tainted**
- tainted resources are **replaced** (recreated) at the next apply operation
- we can use this interesting functionality
- if an external change is made on a resource (the nginx version is changed on a VM), and terraform cannot know that, we can **taint** the resource for reacreation
- **terraform taint \<resouce_name\>**
- **terraform untaint \<resource_name\>** (untaint)

## Debugging

- **TF_LOG** environment variable
- example: **export TF_LOG=TRACE**
- we can set it to: INFO, WARNING, ERROR, DEBUG, TRACE
- **TF_LOG_PATH** environment variable specifies the place where the logs are to be saved (optional)
- **unset TF_LOG_PATH** (remove)
- **TRACE** provides the most details

## Terraform Import

- import resources to be managed by Terraform
- **terraform import \<resource_type\>.\<resource_name\> \<attribute\>**
- you have to write an empty resource block, and then use terraform import to populate it

## Terraform Modules

- **root** module: module where the terraform commands are executed
- **module** block

```hcl
module "dev-webserver" {
  source = "../aws-instance"
}
```

- in this case, aws-instance is called **child** root
- you can use modules from registries
- these can be validated (by HashiCorp), or not (community modules)
- **terraform get**: to get modules, before plan and apply
- you must rerun **terraform init** if the path to modules changed

## More Terraform Function

- **terraform console**: allows us to experience and test with functions and interpolations
- **file()**
- **length()**
- **toset()**

### Numeric Functions
- **max()**
- **min()**
- **max(var.num...)** (... expansion)
- **ceil(10.1)** -> 11
- **floor(10.9)** -> 10

### String Functions

- **split(",", "ami-xyz,AMI-ABC,ami-efg")**
- **lower()**
- **upper()**
- **title()**
- **substr(var.ami, 8, 7)**: from position 8, 7 characters
- **join(",", "var.ami")**: opposite of split()

### Collection Functions

- **length()**
- **index(var.ami, "AMI-ABC")**: 1
- **element(var.ami, 2)**: ami-efg
- **contains(var.ami, "AMI-ABC)**: true

### Map Functions

- **keys()**: convert map to list
- **lookup(var.ami, "ca-central-1")**

## Conditional Expressions

### Numeric Operators

- +, -, *, /, ==, !=, >, <, >=, <=

### Logical Operators

- &&, ||, !

## Conditional Expressions

- condition ? true_value : false_value

## Terraform Workspaces

- workspaces allow you to use the same configuration to replicate infrastructure
- **terraform workspace new \<workspace_name\>**
- **terraform workspace list**
- **terraform workspace select \<workspace_name\>** (move between workspaces)
- Terraform creates a **terraform.tfstate.d** directory, instead of terraform.tfstate
- in this directory, we can find each workspace as a directory and a **terraform.tfstate** inside for each of them
- you must run **terraform apply** for each workspace (use **select** to move between them)
