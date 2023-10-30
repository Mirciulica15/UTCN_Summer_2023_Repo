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
