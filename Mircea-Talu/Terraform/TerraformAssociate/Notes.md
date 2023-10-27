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
