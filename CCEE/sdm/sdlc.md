# Introduction

1. Software:

   - Program: Executable code, that serves some computational purpose.

   - Software is collection of executable code, associated libraries(dependencies(runtime libraries, resources, frameworks)) and documentations.
   - packages -> software
     1. Website: .bundle, .war
     2. windows: .msi, .exe
     3. linux: .deb, .rpm
     4. macos: .dmg
     5. android: .apk, .aab
     6. ios: .ipa

> software made for specific requirement called software product.

2. What is Software Engineering?

   - developing a software product using software engineering principles and methods
   - developing software that is reliable and work efficiently on real machines.

3. Software Types:

   - system software : os, device drivers
   - application software: photoshop, office
   - engineering/scientific software: autocad, catia, matalb
   - embedded software: RTOS
   - AI Software: chatgpt, Bard, Gemini
   - Legacy Software: Windows 3.0
   - Web/Mobile Software

4. Why SE is important?

   - to build complex system in timely manner
   - ensure high quality of software (**testing**)
   - imposes discipline to work (**6 stages**)
   - minimizes software cost and decreases time.

5. Characteristics of good software:

   - How to judge a software product?
     - features(what it offers)
     - quality(how well)
   - Operational
   - Transitional
   - Maintenance

6. Operational: tells us how well software work in operations.

   can be measured on:

   1. Budget: software developed within budget
   2. Usability: should be usable by the end user
   3. Efficiency: efficient use of storage space, computation power and memory.
   4. Correctness: provide all features without bug/issue.
   5. Functionality: meet all user requirements
   6. Dependability: contain all dependencies in its package.
   7. Security: keep all data safe from external threat.
   8. Safety: software not harmful to environment.

#### Security

- Confidentiality: confidential data must by encrypted.
- Integrity: a valid user must get information uploaded earlier.

**_A -> Authentication: validating user -> 2FA -> 1. What user knows (password) 2. what user has (otp, keys)_**

**_A -> Authorization: check if authenticated user has enough permissions [JWT]_**

**_A -> Availability: making app available for valid user [Horizontal_Scaling]_**

7. Transitional: important when software is moved from one platform to another.

   can be measured on:

   1. Portability: software can perform same operations on different environments and platforms.
   2. Interoperability: ability of software to use the information transparently.
   3. Reusability: doing slight modification on software, can be used fo different purpose.
   4. Adaptability: ability to adapt to new changes in the environment.

![software_stages](https://i.imgur.com/M4o4PtI.png)

8. Maintenance: capability of software to maintain itself in ever-changing environment.

   can be measured on:

   1. Maintainability: easy to maintain by user.
   2. Flexibility: software should be flexible to any changes made to it.
   3. Extensibility: no problem with software on increasing number of functions performed by it.
   4. Testability: easy to test
   5. Modularity: divided in separate independent parts, and can be modified and tested separately.
   6. Scalability: easy to scale.

## Software Development Life Cycle

**_SRS (Software Requirement Specifications)_**

1. Planning(Planning and Requirement Analysis)
   **Requirement Gathering and Analysis**

   - most important and fundamental stage
   - performed by senior members of team with inputs from Customer, sales department, market surveys and domain experts.
   - information used to plan the basic project approach and to conduct product feasibility study in the economical, operational and technical areas.
   - planning for quality assurance requirements and identification of risks associated with the project.
   - outcome of technical feasibility study is to define the various technical approaches that can be followed to implement the project successfully with minimum risks.

2. Defining
   **_Defining Requirements_**

   - after requirement gathering the next step is to clearly define and document the product requirements and get them approved from the customer or the market analysts.
   - This is done through a **_SRS_** document
     which consists of all the product requirements to be designed and developed during the project life cycle.

> SRS document needed by Developers and Testers.

3. Designing
   **_DDS (Design Document Specification)_**

   - SRS is the reference for product architects to come out with the best architecture for the product to be developed.
   - Based on product requirements in SRS, usually more than one design approach for the product architecture is proposed and documented in a DDS-Design Document Specification.
   - DDS is reviewed by stakeholders (client, vc, customer) and based on various parameters, the best design approach is selected for the product.
   - A design approach clearly defines all the architectural modules of the product along with its communication and data flow representations with the external and third party modules(if any).
   - internal design of all the modules of the proposed architecture should be clearly defined with the minutest of the details in DDS.

4. Building
   **_Building or Developing the Product_**

   - actual development starts
   - programming code is generated as per DDS + SRS during this stage.
   - if design is detailed and organized, code can be generated without much hassle.
   - developers should follow coding guidelines.
   - programming language is chosen with respect to the type of software being developed.

5. Testing the Product
   **_TDD (Test Driven Development)_**
   **_This stage is usually a subset of all the stages as in the modern SDLC models_**

   - testing only stage, product defects are reported, tracked, fixed and retested until the product reaches the quality standards defined in the SRS.

6. Deployment
   - once tested, released formally in the appropriate market.
   - sometimes product deployment happens in stages as per business strategy of that organization.
   - **UAT (User Acceptance Testing)**: release product in limited segment and tested in the real business environment.
   - based on feedback, release as it is or with suggested enhancements in the targeting market segment.
   - after release, its maintenance is done for the existing customer base.

## SDLC/Software Development Process Models

There are various **SDLC** models defined and designed which are followed during the software development process.

- Waterfall Model
- Iterative Model
- Spiral Model
- V-Model
- Big Bang Model
- Agile Model

### Waterfall Model

- **_Requirement specification_** : planning + defining
  - **_System Design_** : designing
    - **_Design Implementation_** : coding
      - **_Verification & Testing_** : testing
        - **_System Deployment_** : deployment
          - **_Software Maintenance_**

1. Pros
   - simple and easy to use
   - easy to manage
   - each stage has specific deliverables and a review process
   - phase are processed and completed one at a time.
   - work well for small projects with clearly defined requirements, stages.
   - well understood milestones
   - easy to arrange tasks
   - process and results are well documented.

> Integration is done as a "big-bang". at the very end, which doesn't allow identifying any technological or business bottleneck or challenges early.
