# GitHub Actions

[Link to Video](https://www.youtube.com/watch?v=R8_veQiYBjI&ab_channel=TechWorldwithNana)

### What is GitHub Actions?
* Platform to automate developer workflows
* CI/CD is just one of the many workflows you can automate

### What are those workflows?
* **github** is a platform for a lot of open-source projects
* publically available to use and contribute to the projects
* there are a lot of **organizational tasks**
* we want to **automate as much as possible**
* that's why GitHub Actions was created

### Every time something happens to the repository, automatic ACTIONS are executed in response
* these "things" are called GitHub Events
  1. Listen to event
  2. Trigger specific workflow
- use **same tool** instead of third-party intergration
- setup of the pipeline is **easy**
- tool for **developers**

<br>

# Why is the setup easier?
* intergration with other technologies is important
* easy integration with many different tools

<br>

# Where does the code run?
* GitHub Action Runner
* managed by GitHub (but you can also host your own)
* **each job** in a workflow runs in a **fresh** virtual environment
* jobs run in **parallel** by default
