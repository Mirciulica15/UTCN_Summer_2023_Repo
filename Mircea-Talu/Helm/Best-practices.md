# [Helm best practices](https://codersociety.com/blog/articles/helm-best-practices)

<br>

### 1. Take Advantage of the [Helm Ecosystem](https://artifacthub.io/packages/search)

<br>

### 2. Use Subcharts to Manage Your Dependencies

<br>

### 3. Use Labels to Find Resources Easily

<br>

### 4. Document Your Charts

- Comments

- README

- NOTES.txt

<br>

### 5. Test Your Charts

- ```"helm.sh/hook": test-success```

<br>

### 6. Ensure Secrets are Secure

- encrypt secrets: ```helm secrets enc secrets.yaml```

<br>

### 7. Make Your Chart Reusable by Using Template Functions

- _default_, _required_

<br>

### 8. Update Your Deployments When ConfigMaps or Secrets Change

- ```checksum/config: {{ include (print $.Template.BasePath "/configmap.yaml") . | sha256sum }}```

<br>

### 9. Opt Out of Resource Deletion with Resource Policies

- ```"helm.sh/resource-policy": keep```

<br>

### 10. Useful Commands for Debugging Helm Charts

- ```helm lint```

- ```helm install --dry-run --debug```

- ```helm get manifest```

- ```helm get values```

<br>

### 11. Use the lookup Function to Avoid Secret Regeneration

<br>

### 12. Migrate to Helm 3 for Simpler and More Secure Kubernetes Applications

- removal of Tiller

- improved chart upgrade strategy

- ```helm3 plugin install https://github.com/helm/helm-2to3```

<br>

### 13. Keep Your Continuous Delivery Pipelines Idempotent

- always use ```helm upgrade --install```

- **--atomic** flag to rollback changes in the event of a failed operation during helm upgrade
