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

## Main Success Scenario.
```txt
@startuml
<style>
sequenceDiagram {
  participant {
    Padding 10
  }
  box {
    Padding 10
  }
}
</style>

skinparam maxMessageSize 100

actor User
participant "CacheConfigurationView" as View <<boundary>>
participant "ConfigurationController" as Controller <<control>>
participant "Cache" as Cache 
participant "AddressMapper" as Mapper
participant "Metrics" as Metrics
participant "VisualizationController" as Viz

User -> View : configureCache()
activate View

View -> Controller : submitConfiguration()
activate Controller

Controller -> Cache : validate()
activate Cache
Cache --> Controller : configurationValid
deactivate Cache

Controller -> Cache : applyConfiguration()
activate Cache

Cache -> Mapper : map()
activate Mapper
Mapper --> Cache : mapped
deactivate Mapper

Cache -> Metrics : track()
activate Metrics
Metrics --> Cache : tracked
deactivate Metrics

Cache -> Viz : updateVisualization()
activate Viz
Viz --> Cache : updated
deactivate Viz

Cache --> Controller : configurationApplied
deactivate Cache

Controller --> View : configurationSuccess
deactivate Controller

View -> View : displayReady()
activate View
deactivate View

@enduml

```

<div align='center'>
  <img src="../images/us3.2-sd1-MainSuccessScenario.png" height='400' alt="US-3.2 Main Success Scenario">
  <p><b>Fig. 1:</b> Main Success Scenario </p>
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
```txt
User
 |
 | inputAddress()
 v
AddressInputView
 |
 | submitAddress()
 v
AddressProcessingController
 |
 | translate()
 v
AddressMapper
 |
 | extractTag()
 |
 | extractIndex()
 |
 | extractOffset()
 |
 v
AddressProcessingController
 |
 | translationResult
 v
AddressInputView
```

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
```txt
AddressProcessingController
 |
 | translatedAddress
 v
CacheResolutionController
 |
 | search(index)
 v
Cache
 |
 | getSet(index)
 v
CacheSet
 |
 | findMatchingTag(tag)
 v
CacheLine
 |
 | tagMatch=true
 v
CacheSet
 |
 v
CacheResolutionController
 |
 | recordHit()
 +----> Metrics
 |
 | updateMetadata()
 +----> ReplacementPolicy
 |
 v
result=HIT
```

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
```txt
CacheResolutionController
 |
 | search(index)
 v
CacheSet
 |
 | noMatchingTag
 |
 | findEmptyLine()
 v
CacheLine
 |
 | allocate(tag)
 |
 v
CacheResolutionController
 |
 | recordMiss()
 +----> Metrics
 |
 v
result=MISS
```

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
```txt
CacheResolutionController
 |
 | search(index)
 v
CacheSet
 |
 | noEmptyLine
 |
 v
ReplacementPolicy
 |
 | selectVictim()
 |
 v
CacheLine
 |
 | replace()
 |
 v
CacheResolutionController
 |
 | updateMetadata()
 |
 +----> Metrics
 |
 v
result=MISS_EVICTION
```

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
```txt
User
 |
 | requestVisualization()
 v
VisualizationController
 |
 | getTranslationData()
 v
AddressMapper
 |
 | translationResult
 v
VisualizationController
 |
 | render()
 v
CacheVisualizationView
 |
 | displayAddressBits()
 |
 | displayTag()
 |
 | displayIndex()
 |
 | displayOffset()
```

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
