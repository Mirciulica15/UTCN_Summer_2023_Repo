# Azure Pipelines

### Agents

1. Microsoft-hosted agents

   - cost-effective
  
   - isolation
  
   - scalable

2. Self-hosted

   - more control on infrastructure
  
   - essential if you have on-premise resources (ex: you need to deploy on-premise)
  
<br>

### Jobs

1. Agent pool jobs

   - most common

2. Container jobs

   - run in a container on an agent part of an agent pool

3. Deployment group jobs

   - run on systems in a deployment group

4. Agentless jobs

   - run directly on Azure DevOps
  
   - they don't require an agent for execution (Server Jobs)

<br>

### Pools

- organize agents into agent pools

- organization-scoped

<br>

### Communication

![image](https://github.com/Mirciulica15/UTCN_Summer_2023_Repo/assets/36898665/f3e8f355-e96a-454d-8d55-1da50917487a)

- HTTPS

- OAuth token

![image](https://github.com/Mirciulica15/UTCN_Summer_2023_Repo/assets/36898665/ec061b6f-41ae-4503-ad06-886e7f7ec9c1)

Solutions:

1. Self-hosted agents

2. Azure VPN Gateway

3. ExpressRoute

<br>

### Create agent

- you need a PAT (Personal Access Token)
