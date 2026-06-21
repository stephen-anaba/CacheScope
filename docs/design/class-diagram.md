# US-3.3 : Create Design Class Diagram
## Overview
Create Design Class Diagrams (DCDs) to model the internal structure of CacheScope, define responsibilities, establish relationships, and prepare implementation boundaries before development.

This artifact translates:
* requirements
* use cases
* SSDs
* sequence diagrams
* GRASP analysis
into an implementation-oriented design.

## User Story
As a software designer,
I want to define classes and relationships,
so that CacheScope implementation remains maintainable, extensible, and aligned with requirements.

## Objectives
Create:
* Boundary classes
* Control classes
* Entity classes
* Relationships
* Responsibilities
* Multiplicities
* Dependency rules

## Scope
#### Included:
* class definitions
* attributes
* methods
* inheritance
* composition
* aggregation
* dependencies

#### Excluded:
* UI styling
* runtime metrics implementation
* deployment concerns

## System Layers

Presentation
    ↓
Application
    ↓
Domain
    ↓
Infrastructure

## Boundary Classes
### CacheConfigurationView
Responsibilities
* Collect configuration input
* Submit configuration requests

Methods:
+ configureCache()
+ displayValidation()
+ displayReady()

### AddressInputView
Methods:
+ submitAddress()
+ displayError()

### CacheVisualizationView
Methods:
+ renderGrid()
+ renderAddress()
+ renderSimulation()

### MetricsPanelView
Methods:
+ displayHitRate()
+ displayMissRate()

## Control Classes

### ConfigurationController
Responsibilities:
* Coordinate configuration workflow

Methods:
+ validate()
+ apply()

### AddressProcessingController
Methods:
+ processAddress()
+ translate()

#### HashSet
Responsibilities:
- Store unique values
- Perform Robin Hood insertion
- Perform membership queries
- Manage tombstones
- Manage resizing

Attributes:
- size_
- used_
- tombstones_
- table_

Methods:
- Add()
- Contains()
- Remove()
- Clear()
- Rehash()
- Hash()
- Fingerprint()
- ProbeIndex()

### Entry
Attributes:
- key
- fingerprint
- probe_count
- state

Methods:
- none

### New Enumeration
#### State
- EMPTY
- OCCUPIED
- DELETED


### CacheResolutionController
Methods:
+ lookup()
+ classify()
+ update()


### VisualizationController
Methods:
+ render()
+ refresh()

## Entity Classes

### Cache
Attributes:
- cacheSize
- associativity
- blockSize
- sets
- policy

Methods:
- lookup()
- allocate()
- evict()


### CacheSet
Attributes:
- index
- lines[]

Methods:
- find()
- replace()

### CacheLine
Attributes:
- tag
- valid
- data
- metadata

Methods:
- match()
- update()

### AddressMapper
Attributes:
- tagBits
- indexBits
- offsetBits

Methods:
- translate()
- extract()

### ReplacementPolicy
Methods:
- selectVictim()
- updateMetadata()

### LRUPolicy
Methods:
- selectVictim()

### FIFOPolicy
Methods:
- selectVictim()

### Metrics
Attributes:
- hits
- misses
- rate

Methods:
- calculate()

## Relationships

ConfigurationController → Cache

AddressProcessingController → AddressMapper

CacheResolutionController → Cache

VisualizationController → CacheVisualizationView

Cache ◆── CacheSet

CacheSet ◆── CacheLine

HashSet ◆── Entry

Entry → State

Cache ◇── ReplacementPolicy

ReplacementPolicy △── LRUPolicy

ReplacementPolicy △── FIFOPolicy

Metrics
→ Cache

## Legend:
◆ Composition
◇ Aggregation
△ Inheritance
→ Association


## Multiplicity
Cache 1 ---- * CacheSet

CacheSet 1 ---- * CacheLine

Cache 1 ---- 1 ReplacementPolicy

Controller 1 ---- 1 Domain Object


## GRASP Mapping

| **Principle***       | ***Class***             | ***Reason*** |
| :---                 | :---                    | :---         |
| Controller           | ConfigurationController |              |
| Information Expert   | Cache                   |              |
| Low Coupling         | AddressMapper           |              |
| High Cohesion        | CacheSet                |              |
| Polymorphism         | ReplacementPolicy       |              |
| Protected Variations | LRUPolicy/FIFOPolicy    |              |


| Principle            | Class                   | Reason                                                                                                            |
| :---                 | :---                    | :---                                                                                                              |
| Controller           | ConfigurationController | Acts as the first non-user interface object to receive and coordinate system events for updating system settings. |
| Information Expert   | Cache                   | Holds all data, sets, and policies required to delegate lookups, updates, and evictions.                          |
| Creator              | HashSet                 | Owns probe counts, fingerprints, tombstones, insertion strategy                                                   |
| Low Coupling         | AddressMapper           | Isolates memory address translations so physical layout changes do not break core execution logic.                |
| Low Coupling         | HashSet                 | Doesn't know about UI, Cache Visualization, Metrics, Controllers                                                  |
| High Cohesion        | CacheSet                | Focuses entirely on managing a single bucket of cache lines and executing local replacements.                     |
| High Cohesion        | HashSet                 | Only handles hashing, probing, insertion, removal                                                                 |
| Polymorphism         | ReplacementPolicy       | Defines a common interface to allow different eviction behaviors to be interchanged seamlessly.                   |
| Protected Variations | LRUPolicy/FIFOPolicy    | Implements stable policy interfaces to shield the cache system from changes in specific algorithmic rules.        |
| Protected Variations | HashSet                 | Protects variation: Hash(), Fingerprint(), ProbeIndex()                                                           |


## Traceability

| Source | Target                      |
| :---   | :---                        |
| SSD-1  | ConfigurationController     |
| SSD-2  | AddressProcessingController |
| SSD-3  | VisualizationController     |
| UC-2.7 | CacheResolutionController   |

## Acceptance Criteria
* Boundary classes defined
* Control classes defined
* Entity classes defined
* Relationships documented
* Multiplicity documented
* GRASP alignment documented
* Traceability maintained

## Technical Notes
Save as:

docs/design/class-diagram.md

This is the direct input for:
* Sequence Diagrams
* Operation Contracts
* GRASP Analysis
* implementation of frontend/src/components
* implementation of services/
* future testing strategy
