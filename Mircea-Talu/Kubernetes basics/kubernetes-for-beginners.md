# Kubernetes for Beginners

# Pods

```
apiVersion: v1
kind: Pod
metadata:
  name: nginx
spec:
  containers:
  - name: nginx
    image: nginx:1.14.2
    ports:
    - containerPort: 80
```

### Restaurant order analogy
- apiVersion = menu
- kind = client
- metadata, name = name of client
- spec = details of client and order

