# The _terraform init_ command
* From the main.tf file:
  - initializes the backend
  - initializes provider plugins
  - creates a lock file to record the provider selections it made
  - you may now begin working with terraform

# The _terraform fmt_ command
* Formats the code.

# The _terraform validate_ command
* Validates the configuration (checks if it is valid).

<br>

# The _terraform plan_ command
* Terraform uses the selected providers to generate the execution plan.
* Resource actions are indicated with the **+** symbol.

# The _terraform apply_ command
* Performs the _terraform plan_ command and then executed the plan if the user elects to.
* This can be done with specific plans.

# Important Note
* If you didn't use the -out option to save the plan after running _terraform plan_, Terraform can't guarantee to take exactly these actions if you run "terraform apply" now.

<br>

# Updating a configuration
* Changing the configuration and running the _terraform apply_ command does not create a new instance => **idempotent**.
* Instead, it changes the current configuration => **update in-place**
* This does not mean that there is no stoppage in the service!

<br>

# Input Variables
* We create variables with:
  ```
  variable "instance_type" {
    type = string
  }
  ```
* We can create a **tfvars** file, like _terraform.tfvars_ where we store the variables
  ```
  instance_type = "t2.micro"
  ```
* _NOTE: t2.micro is free on AWS_

# The terraform.tfstate file
* This file describes the current state of the configuration
* There is also a .backup for it

<br>

# Local Variables
  ```
  locals {
    project_name = "Mircea"
  }
  ```
* Local variables are usually hard-coded
* Referencing them:
  ```
  ${local.project_name}
  ```

<br>

# Outputs

* Similar to locals
  ```
  output "instance_ip_addr" {
    value = aws_instance.app_server.public_ip
  }
  ```
* Then, we have to at least run **terraform refresh** to make the state from the **tfstate** file match the remote configuration
* Then, we should be able to see the outputs

# The _terraform output_ command
* Shows the outputs
* **terraform output <optional-output>** shows the value of the output labeled as optional-output

<br>

# Divide Files
* Terraform takes all the **.tf** files and puts them together, so we can divide the code into files as we see fit
* Normally, we have **main.tf, variables.tf, outputs.tf, providers.tf** and, of course, the other .tf files, like **aws.tf** for example

<br>

# Terraform Destroy
* **terraform apply -destroy** destroys our infrastructure

<br>

# Terraform Cloud
* _terraform workspace list_ shows the workspaces (the only one is default)
* We can login into our Terraform Cloud account using a key
* We also need to set Terraform variables (instance_type in our example) and Environment variables (AWS_ACCESS_KEY_ID, etc)
* Once uploaded to the Terraform Cloud, we can destroy the configuration locally and recreate it using the Cloud

<br>

# Cleanup
* We can delete the Workspace from Terraform Cloud, from Settings -> Destruction and Deletion
