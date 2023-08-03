# What is Observability?

## Observability is how well you can understand the internals of a system by examining its meaningful outputs

### Why do we need observability?

1. **Complexity**
  * Modern systems are very complex
  * You want to identify **unknown unknowns**

2. **Chaos**
  * Small changes can snowball

3. **Unwelt** (german for **relativity**)
  * Different people and systems observe events differently

4. **Continuous improvement**
  * You can't improve what you can't measure
  * Similar to **Chaos**, a very small improvement now is going to compound in large benefits over time

5. **Unlocks advanced capabilities**
  * **Chaos engineering**
  * **A/B testing**
  * **Feature flagging**
  * **Reactive applications**

### Dimensions of measurements
1. Logging
  * answers the question **"What happened?"**
  * it answers this about separate events

2. Metrics
  * answers the question **"What is the context?"**
  * measures continunous data

3. Distributed tracing
  * answers the question **"Why?"**
  * it records the cause of events

### Example:
* **Logging** took 140 ms (is this good? is it bad?)
* We can't know simply from the logs
* The **metrics** records the logs over time (140ms is 99% slower than the average => there is a problem)
* But why is there a problem?
* This is where **tracing** comes in
* Tracing looks into the **call stack** and identifies **where** the problem is (the database in our example)
* This is how all the 3 components work **together** to tell us what is wrong in the system

### Logging
#### What kind of logs can we collect?
1. **Application logs**
2. **Payload logs** (raw request & response logs, we must be careful not to expose sensitive information)
3. **Garbage collection logs** (in Java)
4. **Access logs** (logs from the http servers)
5. **Others**

### Metrics
* With metrics we can aggregate the logs into __*time series data*__ (data that can change over time) -> this can identify **TRENDS**
* Metrics can also help **visualize data**
* It can be used for **learning** -> if something goes well outside the normal range, an alert can be set up for a human to get involved
* **Metrics add context**

### Distributed tracing
* The tracing is distributed because it can happen between **different application**
* We want to **track down events that are connected**
* We are looking for a **causal relationship**, not just a correlation
* We do this with **Context Propagation**
* When a service gets called, it is assigned a **TRACE ID**
* The **TRACE ID** will follow every related call
* We also have something called a **SPAN ID**
* The **SPAN ID** identifies the basic unit of work

## Unconventional Observability
* **Health checks** - we want to know whether the system is healthy and if not, why?
* **Info contributors** - provides information like a version, a port, environment variables, etc
* **Alarms**
* **Service discoverability** - how many instances of our service do we have running? and additional info about them

## "You know you're doing it right when you know you have a problem before the customer knows you have a problem."

## "You don't know what you don't know. Use Observability so when you figure out what you don't know, that answer is at your fingertips."

![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/c91c458d-53ff-4cac-8449-ed2f1ec13cb1)

[Video Link](https://www.youtube.com/watch?v=SqOtNXwZzDQ)
