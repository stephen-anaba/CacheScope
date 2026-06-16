# US-3.2 — Create Sequence Diagrams
## Overview
Create Sequence Diagrams to model internal object collaboration within CacheScope. These diagrams refine the SSDs by identifying participating objects, message flows, control responsibilities, and interactions between controllers, entities, and supporting services.

#### The purpose is to:
* allocate responsibilities
* validate object interactions
* support GRASP analysis
* guide implementation
* verify class relationships
* prepare operation contracts

## User Story
As a software designer,
I want to model internal object interactions,
so that CacheScope implementation follows clear responsibility assignments and low-coupling design principles.

## Scope
#### Included:
* controller interactions
* entity interactions
* replacement-policy interactions
* cache-resolution workflows
* address-translation workflows
* visualization update workflows

#### Excluded:
* UI styling
* deployment logic
* testing workflows
* infrastructure concerns

## SD-1 — Configure Cache
#### Related Use Cases
* UC-2.1 Configure Cache
* UC-2.2 Validate Cache Configuration
* UC-2.3 Apply Cache Configuration

#### Participating Objects
```txt
User
CacheConfigurationView
ConfigurationController
Cache
AddressMapper
VisualizationController
Metrics
```

## Main Success Scenario

<div align='center'>
  <img src="../images/us3.2-sd1-MainSuccessScenario.png" height='400' alt="US-3.2 Main Success Scenario">
  <p><b>Fig. 1:</b> SD-1 Main Success Scenario </p>
</div>

## Responsibility Assignment

| Object                  | Responsibility             |
| :---                    | :---                       |
| CacheConfigurationView  | Capture user input         |
| ConfigurationController | Coordinate workflow        |
| Cache                   | Validate architecture      |
| AddressMapper           | Recalculate bit allocation |
| Metrics                 | Reset analytics            |
| VisualizationController | Refresh displays           |

## SD-2 — Process Memory Address
#### Related Use Cases
* UC-2.4 Input Memory Address
* UC-2.5 Translate Address

#### Participating Objects
```txt
User
AddressInputView
AddressProcessingController
AddressMapper
```

## Main Success Scenario

<div align='center'>
  <img src="../images/us3.2-sd2-MainSuccesScenario.png" height='400' alt="US-3.2 Main Success Scenario">
  <p><b>Fig. 2:</b> SD-2 Main Success Scenario </p>
</div>

## Responsibility Assignment

| Object                      | Responsibility        |
| :---                        | :---                  |
| AddressInputView            | Capture address       |
| AddressProcessingController | Coordinate processing |
| AddressMapper               | Perform decomposition |

## SD-3 — Cache Hit Resolution
#### Related Use Cases
* UC-2.7 Search Cache Set
* UC-2.8 Detect Cache Hit
* UC-2.10 Update Cache State

#### Participating Objects
```txt
AddressProcessingController
CacheResolutionController
Cache
CacheSet
CacheLine
ReplacementPolicy
Metrics
```

## Main Success Scenario

<div align='center'>
  <img src="../images/us3.2-sd3-MainSuccessScenario.png" height='400' alt="US-3.2 SD">
  <p><b>Fig. 3:</b> SD-3 Main Success Scenario </p>
</div>

## GRASP Notes
* CacheResolutionController = Controller
* CacheSet = Information Expert
* ReplacementPolicy = Polymorphism

## SD-4 — Cache Miss Resolution (Empty Line)
#### Related Use Cases
* UC-2.9 Detect Cache Miss
* UC-2.10 Update Cache State

#### Participating Objects
```txt
CacheResolutionController
Cache
CacheSet
CacheLine
Metrics
```

## Main Success Scenario

<div align='center'>
  <img src="../images/us3.2-sd4-MainSuccessScenario.png" height='400' alt="US-3.2 SD4">
  <p><b>Fig. 4:</b> SD-4 Main Success Scenario </p>
</div>

## SD-5 — Cache Miss Resolution (Eviction Required)
#### Related Use Cases
* UC-2.9 Detect Cache Miss
* UC-2.10 Update Cache State

#### Participating Objects
```txt
CacheResolutionController
Cache
CacheSet
ReplacementPolicy
CacheLine
Metrics
```

## Main Success Scenario

<div align='center'>
  <img src="../images/us3.2-sd5-MainSuccessScenario.png" height='400' alt="US-3.2 SD5">
  <p><b>Fig. 5:</b> SD-5 Main Success Scenario </p>
</div>

## GRASP Notes

| Principle            | Object                    |
| :---                 | :---                      |
| Controller           | CacheResolutionController |
| Information Expert   | CacheSet                  |
| Polymorphism         | ReplacementPolicy         |
| Protected Variations | LRUPolicy/FIFOPolicy      |

## SD-6 — Visualization Update
#### Related Use Cases
* UC-2.6 Visualize Address Bits

#### Participating Objects
```txt
User
VisualizationController
AddressMapper
CacheVisualizationView
```

## Main Success Scenario

<div align='center'>
  <img src="../images/us3.2-sd6-MainSuccessScenario.png" height='400' alt="US-3.2 SD6">
  <p><b>Fig. 6:</b> SD-6 Main Success Scenario </p>
</div>

## Sequence Diagram → Class Mapping

#### Sequence Diagram	Main Classes

| SD-1 | ConfigurationController, Cache             |
| :--- | :---                                       |
| SD-2 | AddressProcessingController, AddressMapper |
| SD-3 | CacheResolutionController, CacheSet        |
| SD-4 | CacheResolutionController, CacheLine       |
| SD-5 | ReplacementPolicy, CacheLine               |
| SD-6 | VisualizationController, AddressMapper     |

## Traceability

| Sequence Diagram | Source Use Cases       |
| :---             | :---                   |
| SD-1             | UC-2.1, UC-2.2, UC-2.3 |
| SD-2             | UC-2.4, UC-2.5         |
| SD-3             | UC-2.7, UC-2.8         |
| SD-4             | UC-2.9, UC-2.10        |
| SD-5             | UC-2.9, UC-2.10        |
| SD-6             | UC-2.6                 |

## Acceptance Criteria
* Sequence diagrams created for all major workflows.
* Participating objects identified.
* Message flow documented.
* Controller responsibilities assigned.
* Entity responsibilities assigned.
* GRASP alignment documented.
* Traceability to use cases established.
* Diagrams support implementation planning.

## Technical Notes
Store in:
```txt
docs/design/sequence-diagrams.md
```
