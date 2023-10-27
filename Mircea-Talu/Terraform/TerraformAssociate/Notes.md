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

```
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






















