# Important concepts

<br>

## - "Legacy solutions" and "vendor solutions"

* these are terms used in the context of technology and software to describe different types of products or systems

### Legacy Solutions
* Legacy solutions refer to older, often outdated, technology or software systems that have been in use for a significant amount of time
* these systems might have been effective in their time, but they may lack modern features, security enhancements, and compatibility with newer technologies
* legacy solutions can become challenging to maintain and integrate with newer systems due to their age and potential lack of support
* organizations might consider migrating away from legacy solutions to more modern alternatives to improve efficiency, security, and performance

### Vendor Solutions
* Vendor solutions are software or technology products provided by third-party vendors or companies
* these solutions are typically developed, maintained, and supported by the vendor, and they are intended to address specific business needs or challenges
* Vendor solutions can range from software applications and platforms to hardware devices
* organizations often opt for vendor solutions when they require specialized expertise, do not want to build a solution in-house, or want to benefit from the vendor's ongoing support and updates

#### In essence, "legacy solutions" refer to older, potentially outdated systems that may need replacement or modernization, while "vendor solutions" refer to software or technology products provided by external vendors to address specific business needs.
#### The decision to migrate from legacy solutions to vendor solutions can be driven by factors such as the need for modern features, improved performance, security enhancements, and ongoing support.

<br>

## - Monolith

#### In software development, a "monolith" refers to a type of application architecture where the entire application is built as a single, unified unit.
#### In a monolithic architecture, all components, modules, and functionality of the application are tightly integrated and run within a single codebase, process, and deployment unit.

#### Key characteristics of monolithic architecture include:

1. **Single Codebase**
   * the entire application, including its various components and features, is written as a single codebase
   * this codebase can be organized into different modules or sections, but they are all part of the same application

2. **Tight Integration**
   * all components and modules of the application are tightly coupled and interact directly with each other
   * this can lead to easier communication and sharing of data within the application

3. **Shared Database**
   * in many monolithic applications, there is often a single shared database that stores data used by different parts of the application

4. **Single Deployment Unit**
   * the entire application is deployed as a single unit
   * updates or changes to any part of the application require redeploying the entire monolith

5. **Scalability Challenges**
    * scaling a monolithic application can be challenging
    * if one component requires more resources, the entire application may need to be scaled up, which can be inefficient

6. **Complexity**
    * as the application grows, the codebase can become large and complex, making it harder to maintain, understand, and extend

7. **Dependency Challenges**
    * changes to one part of the application can have unintended consequences on other parts, making it challenging to make isolated updates

8. **Technology Stack**
    * the entire application typically uses a single technology stack and programming language

#### While monolithic architectures have been common in the past and can be relatively straightforward to develop initially, they can become problematic as applications grow and evolve.
#### For larger and more complex applications, maintaining and updating a monolith can become difficult, and the lack of modularity can hinder development teams' ability to work independently on different parts of the application.

#### To address these challenges, many organizations have adopted more modular and distributed architectures, such as microservices, where different parts of the application are developed and deployed independently. Microservices architectures offer benefits like improved scalability, easier maintenance, and the ability to adopt different technologies for different components. However, transitioning from a monolithic architecture to a microservices architecture can be a significant undertaking and requires careful planning.
