# GitHub Actions

- secrets: ${{ secrets.secret_name }}

- variables: ${{ vars.variable_name }} (there are also environment variables)

- input parameters: ${{ github.event.inputs.input_name }}

- trigger workflow manually -> add input parameters

- define environment variables for job:

  ```
  env:
      AZURE_CLIENT_ID: ${{ secrets.AZURE_CLIENT_ID }}
      AZURE_CLIENT_SECRET: ${{ secrets.AZURE_CLIENT_SECRET }}
      AZURE_TENANT_ID: ${{ secrets.AZURE_TENANT_ID }}
      AZURE_SUBSCRIPTION_ID: ${{ secrets.AZURE_SUBSCRIPTION_ID }}
      RESOURCE_GROUP_NAME: ${{ vars.RESOURCE_GROUP_NAME }}
      VM_NAME: ${{ vars.VM_NAME }}
  ```

- jobs have steps

  ```
  steps:
      - name: Checkout code
        uses: actions/checkout@v2

      - name: Install Azure PowerShell Module
        run: Install-Module -Name Az -Force -AllowClobber -Scope CurrentUser
        shell: pwsh

      - name: Import Azure PowerShell Module
        run: Import-Module Az
        shell: pwsh

      - name: Run PowerShell script
        run: ./vm-scaling.ps1 -newVmSize ${{ github.event.inputs.newVmSize }}
        shell: pwsh
  ```

- you need to specify what the job runs on

  ```
  jobs:
    scale:
      runs-on: ubuntu-latest
  ```

- metadata and input variables

  ```
  name: Scale Virtual Machine

  on:
    push:
      branches: [ "main" ]
    pull_request:
      branches: [ "main" ]

    workflow_dispatch:
      inputs:
        newVmSize:
          description: 'New VM Size'
          required: true
  ```
