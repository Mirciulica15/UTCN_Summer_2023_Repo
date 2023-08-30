# Objects in Kubernetes

_Kubernetes objects_ are persistent entities in the Kubernetes system.
Kubernetes uses these entities to represent the **state** of your cluster.

Specifically, they can describe:
* What containerized applications are running (on which nodes)
* The resources available to those applications
* The policies around how those applications behave, such as restart policies, upgrades, and fault-tolerance

A Kubernetes object is a "record of intent" - once you create the object, the Kubernetes system will constantly work to ensure that object exists.

To work with K8s objects (create, modify and delete), you need to use the **Kubernetes API**.

<br>

### Object _spec_ and _status_

Almost every K8s object include 2 nested object fields that govern the object's configuration: the object **spec** and the object **status**.

You have to set the **spec** when creating the object, providing a description of the characteristics you want the resource to have: its _desired state_.

The **status** describes the _current state_ of the object, supplied and updated by the K8s system and its compoenents.

<br>

### Describing a Kubernetes object

* The API request must include the information as JSON in the request body.
* **Most often, you provide the information to _kubectl_ in a .yaml file.**
* **kubectl apply object.yaml**
 
<br>

### Required fields
* **apiVersion** - Which version of the Kubernetes API you're using to create this object
* **kind** - What kind of object you want to create
* **metadata** - Data that helps to uniquely identify the object, including a **name** string, **UID**, and optional **namespace**
* **spec** - What state you desire for the object

The precise format of the object **spec** is different for every Kubernetes object, and contains nested fields specific to that object.
The [Kubernetes API Reference](https://kubernetes.io/docs/reference/kubernetes-api/) can help you find the spec format for all the objects you can create using K8s.

<br>

### Server side field validation

* **kubectl --validate**
  - **Strict** - Strict field validation, errors on validation failure
  - **Warn** - Field validation is performed, but errors are exposed as warnings rather than failing the request
  - **Ignore** - No server side field validation is performed

<br>

<br>

# Kubernetes Object Management

The **kubectl** command-line tool supports several different ways to create and manage Kubernetes objects.

**Warning**: A kuberentes object should be managed using only one technique. Mixing and matching techniques for the same object results in undefined behavior.

![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/f9f6de06-f8dc-48e9-adca-b0c2ed3c3a7a)

<br>

### Imperative commands

When using imperative commands, a user operates directly on live objects in a cluster.
The user provides operations to the **kubectl** command as arguments or flags.

<br>

**Trade-offs**

Advantages compared to object configuration:
  - Commands are expressed as a single action word
  - Commands require only a single step to make changes to the cluster

Disadvantages compared to object configuration:
  - Commands do not integrate with change review processes
  - Commands do not provide an audit trail associated with changes
  - Commands do not provide a source of records except for what is live
  - Commands do not provide a template for creating new objects

<br>

### Imperative object configuration
In imperative object configuration, the **kubectl** command specifies the operation (create, replace, etc.), optional flags and at least one file name.
The file specified must contain a full definition of the object in YAML or JSON format.

**Warning**:
- The imperative **replace** command replaces the existing spec with the newly provided one, dropping all changes to the object missing from the configuration file.
- This approach should not be used with resource types whose specs are updated independently of the confuguration file.
- Services of type **LoadBalancer**, for example, have their **externalIPs** field updated independently from the configuration by the cluster.

<br>

**Trade-offs**

Advantages compared to imperative commands:
- Object configuration can be stored in a source control system such as Git.
- Object configuration can integrate with processes such as reviewing changes before push and audit trails.
- Object configuration provides a template for creating new objects.

Disadvantages compared to impreative commands:
- Object configuration requires basic understanding of the object schema.
- Object configuration requires the additional step of writing a YAML file.

Advantages compared to declarative object configuration:
- Imperative object configuration behaviour is simpler and easier to understand
- As of K8s version 1.5, imperative object configuration is more mature.

Disadvantages compared to declarative object configuration:
- Imperative object configuration works best on files, not directories.
- Updates to live objects must be reflected in configuration fies, or they will be lost during the next replacement.

<br>

### Declarative object configuration

When using declarative object confugration, a user operates on object configuration files stored locally, however the user does not define the operations to be taken on the files.
Create, update, and delete operations are automatically detected per-object by **kubectl**.
This enables working on directories, where different opeations might be needed for different objects.

**Note**:
  - Declarative object configuration retains changes made by other writers, even if the changes are not merged back to the object configuration file.
  - This is possible by using the **patch** API operation to write only observed differences, instead of the **replace** API operation to replace the entire object configuration.

<br>

**Trade-offs**

Advantages compared to imperative object configuration:
- Changes made directly to live objects are retained, even if they are not merged back into the configuration files.
- Declarative object configuration has better support for operating on directories and automatically detecting operation types (create, patch, delete) per-object.

Disadvantages compared to imperative object configuration:
- Declarative object configuration is harder to debug and understand results when they are unexpected.
- Partial updates using diffs create complex merge and patch operations.

<br>

<br>

# Object Names and IDs

Each object in your cluster has a Name that is unique for that type of resource.
Every Kubernetes object also has a UID that is unique across your whole cluster.
For example, you can only have one Pod named myapp-1234 within the same namespace, but you can have one Pod and one Deployment that are each named myapp-1234.

<br>

### Names

A client-provided string that refers to an object in a resource URL, such as /api/v1/pods/some-name.

**Names must be unique across all API versions of the same resource.**
**API resources are distinguished by their API group, resource type, namespace (for namespaced resources), and name. In other words, API version is irrelevant in this context.**

**Note**: In cases when objects represent a physical entity, like a Node representing a physical host, when the host is re-created under the same name without deleting and re-creating the Node, Kubernetes treats the new host as the old one, which may lead to inconsistencies.

<br>

### UIDs

A Kubernetes systems-generated string to **uniquely identify objects**.

**Every object created over the whole lifetime** of a Kubernetes cluster has a distinct UID. It is intended to distinguish between **historical occurrences of similar entities**.

Kubernetes UIDs are universally unique identifiers (also known as UUIDs). UUIDs are standardized as ISO/IEC 9834-8 and as ITU-T X.667.

<br>

<br>

# Labels and Selectors

<br>

### Labels

* Labels are **key/value pairs** that are attached to objects such as Pods.
* Labels are intended to be used to **specify identifying attributes** of objects that are meaningful and relevant to users, but **do not directly imply semantics to the core system**.
* Labels can be used to **organize** and to **select** subsets of objects.
* Labels can be attached to objects at **creation time** and subsequently **added and modified at any time**.
* Each object can have a set of key/value labels defined. Each Key must be **unique for a given object**.

```
"metadata": {
  "labels": {
    "key1" : "value1",
    "key2" : "value2"
  }
}
```

<br>

### Label selectors

* Unlike names and UIDs, **labels do not provide uniqueness**. In general, we expect many objects to carry the **same label(s)**.
* Via a label selector, the client/user can **identify** a set of objects. The label selector is the **core grouping primitive** in Kubernetes.
* The API currently supports two types of selectors: **equality-based** and **set-based**.
* A label selector can be made of multiple requirements which are **comma-separated**.

_Equality-based_ requirement
Three kinds of operators are admitted: **=, ==, !=**.
The first 2 represent _equality_ and are synonyms, while te latter represents _inequality_.

```
environment = production
tier != frontend
```

<br>

_Set-based_ requirement
Allows filtering keys according to a **set of values**.
Three kinds of operators are supported: **in, notin, exists** (only the key identifier)

```
environment in (production, qa)
tier notin (frontend, backend)
partition
!partition
```

<br>

### API. LIST and WATCH filtering

LIST and WATCH operations may specify label selectors to filter the sets of objects returned using a query parameter. Both requirements are permitted (presented here as they would appear in a URL query string):

- equality-based requirements: ?
  ```labelSelector=environment%3Dproduction,tier%3Dfrontend```
- set-based requirements: ?
  ```labelSelector=environment+in+%28production%2Cqa%29%2Ctier+in+%28frontend%29```

```kubectl get pods -l environment=production,tier=frontend```

<br>

<br>

# Namespaces

* **kubectl get namespace**
* In Kubernetes, namespaces provides a mechanism for **isolating groups of resources** within a single cluster.
* **Names of resources need to be unique within a namespace, but not across namespaces.**
* Namespace-based scoping is applicable only for namespaced objects (e.g. Deployments, Services, etc) and not for cluster-wide objects (e.g. StorageClass, Nodes, PersistentVolumes, etc).

<br>

### When to Use Multiple Namespaces?

Namespaces are intended for use in environments with many users spread across multiple teams, or projects.
For clusters with a few to tens of users, you should not need to create or think about namespaces at all.

**Note**: For a production cluster, consider not using the _default_ namespace. Instead, make other namespaces and use those.

<br>

### Initial namespaces 

Kubernetes starts with 4 initial namespaces:

* **default**
Kubernetes includes this namespace so that you can start using your new cluster without first creating a namespace.

* **kube-node-lease**
This namespace holds Lease objects associated with each node. Node leases allow the kubelet to send heartbeats so that the control plane can detect node failure.

* **kube-public**
This namespace is readable by all clients (including those not authenticated). This namespace is mostly reserved for cluster usage, in case that some resources should be visible and readable publicly throughout the whole cluster. The public aspect of this namespace is only a convention, not a requirement.

* **kube-system**
The namespace for objects created by the Kubernetes system.

<br>

<br>

### Namespaces and DNS

* **When you create a Service, it creates a corresponding DNS entry.**
* This entry is of the form **<service-name>.<namespace-name>.svc.cluster.local**, which means that if a container only uses **<service-name>**, it will resolve to the service which is local to a namespace.
* This is useful for using the same configuration across multiple namespaces such as Development, Staging and Production. If you want to reach across namespaces, you need to use the **fully qualified domain name (FQDN)**.

<br>

<br>

# Annotations

You can use Kubernetes annotations to attach arbitrary non-identifying metadata to objects. Clients such as tools and libraries can retrieve this metadata.

```
"metadata": {
  "annotations": {
    "key1" : "value1",
    "key2" : "value2"
  }
}
```

<br>

<br>

# Field Selectors

Field selectors let you select Kubernetes objects based on the value of one or more resource fields.

Example:
```kubectl get pods --field-selector status.phase=Running```

Field selectors vs label selectors:
- Field selectors are used to filter and select resources based on specific fields in their metadata.
- These fields include properties like resource name, creation timestamp, namespace, and more.
- Field selectors are useful for selecting resources based on **attributes that are inherent to the resource, such as its name or creation time**.
- They are less flexible than label selectors but can be handy when you need to find resources with specific characteristics.

<br>

<br>

# Finalizers

Finalizers are namespaced keys that tell Kubernetes to wait until specific conditions are met before it fully deletes resources marked for deletion. Finalizers alert controllers to clean up resources the deleted object owned.

* When you tell Kubernetes to delete an object that has finalizers specified for it, the Kubernetes API marks the object for deletion by populating **.metadata.deletionTimestamp**, and returns a **202 status code (HTTP "Accepted")**.
* The target object remains in a **terminating state** while the control plane, or other components, take the actions defined by the **finalizers**.
* After these actions are complete, the controller removes the relevant finalizers from the target object.
* When the **metadata.finalizers** field is empty, Kubernetes considers the deletion complete and deletes the object.

A common example of a finalizer is **kubernetes.io/pv-protection**, which prevents accidental deletion of **PersistentVolume** objects.
When a PersistentVolume object is in use by a Pod, Kubernetes adds the **pv-protection finalizer**.
If you try to delete the PersistentVolume, it enters a **Terminating** status, but the controller can't delete it because the finalizer exists.
**When the Pod stops using the PersistentVolume, Kubernetes clears the pv-protection finalizer, and the controller deletes the volume.**

<br>

<br>

# Owners and Dependents

In Kubernetes, some objects are owners of other objects. For example, a ReplicaSet is the owner of a set of Pods. These owned objects are dependents of their owner.

Example: Kubernetes uses **finalizers** to make sure we don't delete a Persistent Volume (owner) used by a Pod (dependent).

<br>

<br>

# Recommended Labels

You can visualize and manage Kubernetes objects with more tools than kubectl and the dashboard. A common set of labels allows tools to work interoperably, describing objects in a common manner that all tools can understand.

In addition to supporting tooling, the recommended labels describe applications in a way that can be queried.
