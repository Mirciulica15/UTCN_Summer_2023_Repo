# UTCN Summer 2023 - Polytechnic Computer Science Course

Welcome to the UTCN Summer 2023 repository for the Polytechnic Computer Science Course. This repository is dedicated to exploring and understanding the CNCF's Cloud Native adoption via the trail map.

## Table of Contents

1. [Introduction](#introduction)
2. [Cloud Native Concepts](#cloud-native-concepts)
3. [CNCF Trail Map](#cncf-trail-map)
4. [Repository Structure](#repository-structure)
5. [Getting Started](#getting-started)
6. [Contributors](#contributors)
7. [License](#license)

## Introduction

The Cloud Native Computing Foundation (CNCF) provides a trail map to guide enterprises through the journey of adopting Cloud Native. This repository aims to delve deep into each phase of the trail map, providing detailed explanations, examples, and best practices.

## Cloud Native Concepts

Cloud Native technologies empower organizations to build and run scalable applications in modern, dynamic environments such as public, private, and hybrid clouds. Containers, service meshes, microservices, immutable infrastructure, and declarative APIs exemplify this approach.

## CNCF Trail Map

The CNCF trail map outlines the recommended path to cloud native adoption:

1. **Containerization**: Packaging the application and its dependencies in a container.
2. **CI/CD**: Continuous integration and continuous delivery ensure that code changes are automatically tested and deployed.
3. **Orchestration & Application Definition**: Using tools like Kubernetes to manage containerized applications.
4. ... [Further steps can be added based on the trail map]

## Repository Structure

- **C++ Code**: The repository primarily contains C++ code, which can be found [here](https://github.com/Mirciulica15/UTCN_Summer_2023_Repo/search?l=c%2B%2B).
- **C Code**: There's also a portion of C code present in the repository.

## Getting Started

1. **Clone the Repository**: `git clone https://github.com/Mirciulica15/UTCN_Summer_2023_Repo.git`
2. **Navigate to the Directory**: `cd UTCN_Summer_2023_Repo`
3. **Install Dependencies**: [Instructions for installing dependencies]
4. **Run the Application**: [Instructions for running the application]

## Contributors

- **Mirciulica15**: Repository owner and primary contributor.
- **Bogdan Dragos**: Contributed to various parts of the repository.

## License

This project is licensed under the [MIT License](LICENSE).

---

This is a draft README.md for your repository. You can further customize it based on your requirements and the specific details of your project.

---

I've accessed the provided GitLab repository. Here's a brief overview:

- **Repository Name**: Authentication App
- **Owner**: Mircea Talu
- **Description**: The repository contains an authentication app designed to be deployed in AWS EKS. It's a simple login form developed using the Flask framework, with basic password hashing. The primary goal is to deploy this application in AWS (Amazon Web Services) EKS (Elastic Kubernetes Services).

Given the information and your request, I'll draft a detailed README.md for your GitLab repository:

---

# Authentication App for AWS EKS Deployment

Welcome to the Authentication App repository. This project focuses on creating a simple login form using the Flask framework and deploying it on AWS EKS.

## Table of Contents

1. [Introduction](#introduction)
2. [Project Structure](#project-structure)
3. [Getting Started](#getting-started)
4. [Deployment](#deployment)
5. [Contributors](#contributors)

## Introduction

The Authentication App is a straightforward login form developed using the Flask framework. It employs basic hashing for password security. The primary objective of this project is to deploy this application on AWS EKS.

## Project Structure

- **chart**: Contains Helm charts for Kubernetes deployment.
- **code**: Houses the main application code, including the Flask application file (`app.py`), an HTML template (`login.html`), and a Dockerfile for containerization.
- **.gitlab-ci.yml**: Defines the CI/CD pipeline for GitLab, automating the process of building the Docker image and deploying it.

## Getting Started

1. **Clone the Repository**: `git clone https://gitlab.com/Mirciulica15/resources-utilization.git`
2. **Navigate to the Directory**: `cd resources-utilization`
3. **Build the Docker Image**: `docker build -t my-image .`
4. **Run the Application**: `docker run -p 8081:8081 my-image`

## Deployment

The deployment process involves several steps:

1. **Containerization**: The app is containerized using a Dockerfile. The application code is located in the `code/` directory.
2. **CI/CD Pipeline**: The `.gitlab-ci.yml` file automates the process of building the Docker image and deploying it. The build stage creates an image and uploads it to Docker Hub.
3. **Helm Deployment**: Helm is used to create templates and configurations for Kubernetes clusters. The Helm chart for this project can be found in the `chart` directory.

## Contributors

- **Mircea Talu**: Repository owner and primary contributor.

---

This is a draft README.md for your GitLab repository. You can further customize it based on your requirements and the specific details of your project.

---

I've accessed the provided GitLab repository. Here's a brief overview:

- **Repository Name**: Resource Utilization
- **Owner**: Mircea Talu
- **Description**: The repository contains a Resource Utilization Application designed to be deployed in AWS EKS.

Given the information and your request, I'll draft a detailed README.md for your GitLab repository:

---

# Resource Utilization Application for AWS EKS Deployment

Welcome to the Resource Utilization Application repository. This project focuses on monitoring and managing resource utilization, designed specifically for deployment on AWS EKS.

## Table of Contents

1. [Introduction](#introduction)
2. [Project Structure](#project-structure)
3. [Getting Started](#getting-started)
4. [Deployment](#deployment)
5. [Contributors](#contributors)

## Introduction

The Resource Utilization Application is designed to monitor and manage the utilization of resources in a cloud environment. The primary objective of this project is to deploy this application on AWS EKS, providing insights and tools for efficient resource management.

## Project Structure

- **chart**: Contains Helm charts for Kubernetes deployment.
- **code**: Houses the main application code.
- **.gitlab-ci.yml**: Defines the CI/CD pipeline for GitLab, automating the process of building the Docker image and deploying it.

## Getting Started

1. **Clone the Repository**: `git clone https://gitlab.com/Mirciulica15/resource-utilization.git`
2. **Navigate to the Directory**: `cd resource-utilization`
3. **Follow the Instructions in README**: The `README.md` file provides detailed steps for setting up, building, and deploying the application.

## Deployment

The deployment process involves several steps:

1. **Containerization**: The app can be containerized using a Dockerfile provided in the repository.
2. **CI/CD Pipeline**: The `.gitlab-ci.yml` file automates the process of building the Docker image and deploying it on AWS EKS.
3. **Helm Deployment**: Helm is used to create templates and configurations for Kubernetes clusters. The Helm chart for this project can be found in the `chart` directory.

## Contributors

- **Mircea Talu**: Repository owner and primary contributor.

---

This is a draft README.md for your GitLab repository. You can further customize it based on your requirements and the specific details of your project.

---

I've accessed the provided GitLab repository. Here's a brief overview:

- **Repository Name**: Terraform-Infrastructure
- **Owner**: Mircea Talu
- **Description**: The repository is focused on infrastructure setup using Terraform.

Given the information and your request, I'll draft a detailed README.md for your GitLab repository:

---

# Terraform-Infrastructure for AWS Deployment

Welcome to the Terraform-Infrastructure repository. This project is dedicated to setting up and managing infrastructure on AWS using Terraform.

## Table of Contents

1. [Introduction](#introduction)
2. [Project Structure](#project-structure)
3. [Getting Started](#getting-started)
4. [Deployment](#deployment)
5. [Contributors](#contributors)

## Introduction

Terraform is an open-source infrastructure as code software tool that provides a consistent CLI workflow to manage hundreds of cloud services. This repository focuses on leveraging Terraform to set up and manage infrastructure on AWS.

## Project Structure

- **.gitignore**: Contains a list of files and directories that are ignored by Git.
- **.gitlab-ci.yml**: Defines the CI/CD pipeline for GitLab.
- **k8s-control-plane.tf**: Terraform configuration for setting up the Kubernetes control plane.
- **k8s-worker-nodes.tf**: Terraform configuration for setting up Kubernetes worker nodes.
- **provider.tf**: Specifies the Terraform provider and its configuration.
- **variables.tf**: Contains variable definitions used in Terraform configurations.

## Getting Started

1. **Clone the Repository**: `git clone https://gitlab.com/Mirciulica15/terraform-infrastructure.git`
2. **Navigate to the Directory**: `cd terraform-infrastructure`
3. **Initialize Terraform**: `terraform init`
4. **Apply Terraform Configuration**: `terraform apply`

## Deployment

The deployment process involves several steps:

1. **Terraform Initialization**: This step initializes the working directory containing Terraform configuration files.
2. **Terraform Plan**: This step creates an execution plan, determining what actions are necessary to achieve the desired state specified in the configuration files.
3. **Terraform Apply**: This step applies the changes required to reach the desired state.

## Contributors

- **Mircea Talu**: Repository owner and primary contributor.

---

This is a draft README.md for your GitLab repository. You can further customize it based on your requirements and the specific details of your project.
