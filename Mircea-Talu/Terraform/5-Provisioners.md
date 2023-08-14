# Terraform Provisioners

* **Terraform Provisioners** install software, edit files, and provision machines created with Terraform
* Terraform allows you to work with 2 different provisioners:
  - **Cloud-init**
    + industry standard for cross-platform cloud instance initializations
    + when you launch a VM on a Cloud Service Provider(CSP), you'll provide a YAML or Bash script
    ![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/0a78cad7-6629-445e-a70e-ed5d39bc9ad7)

  - **Packer**
    + automated image-builder service
    + you provide a configuration file to create and provision the machine image and the image is then delivered to a repository for use
    
* Provisioners should only be used as a **last resort**. For most common situations there are better alternatives.
* The main reason is that provisioners will do something that won't be reflected in the Terraform state. And the better alternative for that one is to use cloud-provider features like Cloud-init scripts.
![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/bf8ad7f5-98bc-4fe5-b791-8b91e708b4ad)

* Terraform used to directly support third-party Provisioning tools in the Terraform language.
* However, this was deprecated because Terraform considered using Provisioners to be poor practice suggesting better alternatives.

<br>

# Local-Exec

```
provisioner "local-exec" {
  command = "echo ${self.private_ip} >> private_ips.txt"
}
```
* Works locally, on the machine running the configuration

<br>

# Local-Exec example

![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/99e623fe-31a0-43f9-bfa2-16cc5286a85a)

<br>

# Remote-Exec

![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/d886548a-633b-494a-ae84-9dc2370c9f43)

<br>

# File

* **file provisioner** is used to copy files or directories from our local machine to the newly created resource
![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/39a21eab-e270-4955-aa6b-5492f8b1189f)

<br>

# Connection

* A **connection block** tells a **provisioner** or **resource** how to establish a connection
![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/60993704-877d-420f-a746-78f93177673a)

<br>

# Null Resources

* **null_resource** is a placeholder for resources that have no specific association to a provider resource
![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/9e9e8db8-19cd-4238-be99-8a23434b981d)

<br>

# Terraform Data
* Similar to **null_resources** but does not require the configuration of a provider
