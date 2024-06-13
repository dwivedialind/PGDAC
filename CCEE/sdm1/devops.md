## DevOps

- Dev Team -> Developers, Testers
- Ops Team

**_SDLC LifeCycle_**

- Planning
- Defining
- Designing
- Building
- Testing
- Deployment

### Entities involved

Developers --> Testers --> Operations Team

### Responsibilities

1. Developers

   - develop the application
   - package the application
   - Fix the Bugs
   - maintain the application

2. Testers

   - thorough testing
   - report bugs to developer

3. Operations Team
   - make all necessary resources ready(computer, memory, network, HR)
   - deploy the application
   - maintain multiple environments
     - creation
     - config
   - continuously monitor application uptime.
   - manage the resources

### Challenges

1. Developers and Testers

   - slow process
   - pressure to work on new feature and fixing older code
   - not flexible

2. Operations Team
   - Uptime (**maximize**)
   - configure huge infrastructure
   - diagnose and fix the issue

## Agile Development

**_followed in every sprint_**
![scrumProcess](https://i.imgur.com/4eROGM6.png)

### Scrum Process

1. Product owner with input from End-Users, Customers, Teams and Other Stakeholders create a **_Product Backlog_** which have all the features.
2. Team goes through **_Product Backlog_** in **_Sprint Planning Meeting_** and **_selects how much to do by sprint's end_** and create **_sprint backlog_**.
3. Sprint goes form **1-4 Weeks** with **_Daily Scrum Meetings and Artifacts Update_**, **_Scrum Master_** keep an eye over it, with **_Product Backlog Refinement_**.
4. There are **No Change is Duration or Goal**, after sprint **_Review_** held for sprint and **_Potentially Shippable Product Increment_**.
5. **_Retrospective_** : A time-boxed meeting that takes place after **_sprint review_** and before **_sprint planning_**, to examine how just-completed sprint went.

### Waterfall Vs Agile

- The Waterfall Process

-----Design------|----------Code----------|--Test--|---Deploy---

- Agile(while agile have Deploy at end but in Devops Deploy is after each sprint)

--Design--|--Code--|--Test--|--Deploy--|----|----|----|----|......

### Problems with Solutions

1. Managing and tracking changes in code is difficult **_SCM(Source Code Management/Version Control System) Tools_**
2. Incremental builds are difficult to manage, test and deploy **_Jenkins(CI/CD)_**
3. Manual testing and deployment of various components take time **_Selenium (Test Automation)_**
4. Ensuring consistency, adaptability and scalability across environments is very difficult task **_Puppet (Continuous Configuration)_**
5. Environmental Dependencies makes the project behave differently in different environments **_Docker_**

### What is DevOps?

**_Devops is not a goal but never ending process of continuous improvement_**

- promotes collaboration between Development and Operations Team

  - to deploy code to production faster in an automated and repeatable way.
  - Automating infrastructure (continuous config tools)
  - Automating workflow (CI/CD pipeline)
  - Continuously measuring application performance (monitoring)

- allow organizations

  - to deliver applications and services faster
  - serve customers better
  - compete strongly in market

### Why DevOps needed

- Without Devops
  - dev and ops team worked in complete isolation, with separate deadlines causing further delays.
  - testing and deploy happens after design-build, consuming more time than actual build cycles.
  - team member spend more time in testing, deploying and designing instead of building the project.
  - manual code deployment leads to human errors in production.

```bash
Devops not
    1. role, person or organization
    2. separate team
    3. not a product or tool
    4. just writing scripts or implementing tools

```

### Reasons to Use DevOps

1. Predictability: significant lower failure rate of new releases
2. Reproducibility: version everything so earlier version can be restored anytime
3. Maintainability: effortless process of recovery in the event of a new release crashing or disabling the current system
4. Time to market: reduced upto 50% through streamlined software delivery
5. Greater Quality: incorporation of infrastructure issues, improve quality of application development
6. Reduced Risk: incorporation of security aspects, helps in reduction of defects across the lifecycle.
7. Resiliency

### DevOps Lifecycle

plan -> code -> build -> test -> release -> deploy -> operate -> monitor

1. Plan
   - plan, track, visualize and summarize your project before start working on it.

```bash
General Tools:
    - Excel
    - Text Files
Cloud Tools:
    - cloud drive
    - google drive
    - one drive
    - dropbox
Planning/ Scrum tools
    - Jira
    - Orange Scrum
```

2. Code
   - write program using programming language

```bash
Editors:
    - Vim, Vscode, Atom, Sublime
IDEs:
    - VS, Android Studio, PyCharm, Eclipse, WebStorm
SDK:
    - .Net SDK
    - Android SDKs
    - ios SDK
    - JDK
package manager:
    - Node -> npm
    - Window -> NuGet
    - Python -> pip(Python Index Packages)
    - Ruby -> Gems/pod
    - ios -> cocoa pods
languages
    - compiled -> c, c++, Go, Swift
    - interpreted -> ruby, js
    - mixed -> java, python
SCM tool:
    - LVCS -> source safe
    - CVCS
    - DVCs -> git, bazaar, bitkeeper
```

3. Build
   - compile the code + add dependencies + create deployable packages

```bash
tools:
    - ant [deprecated]
    - maven
    - gradle [groovy]
deployable packages:
    - web -> bundle
    - android -> .apk, .aab
    - ios -> .ipa
    - windows -> .msi(microsoft software installer), .exe
    - linux -> .rpm, .deb
    - macos -> .dmg
```

4. Test
   - executing automated tests
   - feedback about the changes as quickly as possible

```bash
Unit Testing:
    - JavaScript -> Jest, Jasmin
    - Python -> PyUnit
    - C# -> NUnit
    - Java -> JUnit
UI Testing:
    - Selenium -> python, C++, c#, Java, JS
    - cypress
    - TestNG
Performance Testing
    - LoadRunner
    - JMeter
        - scalability testing
```

5. Release
   - CI/CD pipeline tools
   - integrate code into shared repository using which you can detect and locate errors quickly and easily

**_CI/CD Pipeline_**

**SCM - Build - Test - Environment Creation - Environment Configuration - Deployment**

```bash
CI tools
    - travis CI, Circle CI,
    - Github CI
CD tools
    - ArgoCD
CI/CD tools
    - Jenkins, Bamboo

```

6. Deploy
   - manage and maintain, development and deployment of software systems and server in any computational environment.

```bash
virtualized deployment:
    - Virtual Box
    - VMWare, parallels
    - Qemu, Bosch
cloud
    - AWS, Azure, GCP
    - RAckSpace, Digital Ocean
    - IBM cloud
containerized deployment
    - docker
    - podman
    - LMCTFY
    - containerd
container orchestration
    - docker swarm
    - k8s
    - mesos
    - marathon
```

7. Operate
   - updated system gets operated

```bash
Environment creation tools
    - local environment -> vagrant
    - cloud environment -> terraform, AWS, cloud formation
Environment configuration tools
    - puppet
    - chef
    - ansible
    - saltstack
```

8. Monitor
   - application is performing as expected and environment is stable
   - quickly determines when a service is unavailable and understand the underlying causes

```bash
tools
    - Nagios
    - Splunk
    - DataDog
    - NewRelik

```
