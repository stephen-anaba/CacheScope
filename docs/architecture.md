# Core Use Case (UC)

| ID     | Use Case               |
| :---   | :---                   |
| CUC-1  | Configure Cache        |
| CUC-2  | Submit Memory Address  |
| CUC-3  | Update Cache State     |
| CUC-4  | Input Address          |
| CUC-5  | Translate Address      |
| CUC-6  | Visualize Address Bits |
| CUC-7  | Search Cache Set       |
| CUC-8  | Detect Cache Hit       |
| CUC-9  | Detect Cache Miss      |
| CUC-10 | Execute LRU Eviction   |
| CUC-11 | Execute FIFO Eviction  |
| CUC-12 | Replace Cache Line     |
| CUC-13 | Render Cache State     |
| CUC-14 | Highlight Cache Events |
| CUC-15 | Animate Evictions      |
| CUC-16 | Calculate Hit Rate     |
| CUC-17 | Calculate Miss Rate    |
| CUC-18 | Display Live Metrics   |
| :---   | :---                   |

--- 

# US 1.1: Define Cache Configuration Requirments

## Requirements

### Overview
Define the functional and non-functional requirements for cache configuration to support flexible simulation setup, scalable cache architectures, deterministic simulation behavior, and future extensibility within CacheScope.

### These requirements establish the foundation for:
* cache simulation logic
* configuration validation
* address decomposition
* replacement-policy execution
* visualization synchronization
* future multi-level cache support

## User Story
As a computer architecture student, I want to configure cache parameters, so that I can simulate and analyze different cache architectures and runtime behaviors.

## Scope
### This user story covers:
* cache configuration input requirements
* cache validation rules
* replacement-policy configuration
* associativity modeling
* cache-size constraints
* traceability mappings

### This user story does not yet cover:
* runtime cache simulation
* address translation execution
* visualization rendering
* multi-level cache orchestration

## Functional Requirements (CFR)

| ID     | Requirement                                                                                       | Priority |
| :---   | :---                                                                                              | :---     |
| CFR-01 | This sytem shall allow users to configure cache size                                              | High     |
| CFR-02 | The system shall allow users to configur ecache associatiity                                      | High     |
| CFR-03 | The system shall allow users to configure cache block size                                        | High     |
| CFR-04 | The system shall allow users to configure replacement policies                                    |
| CFR-05 | The system shall validate invalid cache configurations before simulation execution                | High     |
| CFR-06 | The system shall support deterministic cache configuration processing                             | Medium   |
| CFR-07 | The system shall support extensivle cache configuration structures for future cache architectures |          |

## Low-Level Functional Requirements (CLFR)

| ID      | Requirement                                                                          | Parent CFR |
| :---    | :---                                                                                 | :---       |
| CLFR-01 | Cache size shall support KB and MB input formats                                     | CFR-01     |
| CLFR-02 | Cache size shall be stored internally in bytes                                       | CFR-01     |
| CLFR-03 | Associativity shall support direct-mapped mode                                       | CFR-02     |
| CLFR-04 | Associativity shall support direct-mapped mode                                       | CFR-02     |
| CLFR-05 | Associativity shall support fully associative mode                                   | CFR-02     |
| CLFR-06 | Block size shall be configurable in bytes                                            | CFR-03     |
| CLFR-07 | Block size shall support power-of-two validation                                     | CFR-03     |
| CLFR-08 | Replacement policies shall include LRU                                               | CFR-04     |
| CLFR-09 | replacement policies                                                                 | CFR-04     |
| CLFR-10 | Cache size must be divisible by block size                                           | CFR-05     |
| CLFR-11 | Number of cache sets must evaluate to an integer value                               | CFR-05     |
| CLFR-12 | Associativity must be a positivie power of two                                       | CFR-05     |
| CLFR-13 | Configuration validation shall occur before simulation execution                     | CFR-06     |
| CLFR-14 | Configuration structures shall remain extensible for future multi-lvel cache support | CFR-07     |

## Non-Functional Requirements (CNFR)

| ID      | Requirement                                                                                                                    |
| :---    | :---                                                                                                                           |
| CNFR-01 | Cache configuration validation shall complete within 100ms under standard input conditions                                     |
| CNFR-02 | Cache configuration structures shall support future extensibility without requiring major susystem redesign                    |
| CNFR-03 | Cache configuration interfaces shall remian understandable for computer architecture students and beginner systems programmers |
| CNFR-04 | Configuration processing shall remain deterministic across repeated simulations with identical inputs                          |
| CNFR-05 | Cache configuration logic shall remain modular and independent from visualization rendering logic                              |

## Configuration Parameters

| Parameter          | Description                    | Example Values      |
| :---               | :---                           | :---                |
| Cache Size         | Total cache storage capacity   | 16KB, 32KB, 64KB    |
| Block Size         | Number of bytes per cache line | 16B, 32B, 64B       |
| Associativity      | Number of cache lines per set  | 1-way, 2-way, 4-way |
| Replacement Policy | Cache-line eviction strategy   | LRU, FIFO           |
| Address Width      | Memory-address size            | 32-bit, 64-bit      |

## Validation Rules

| ID    | Rule                                                   |
| :---  | :---                                                   |
| VR-01 | Cache size must be divisible by block size             |
| VR-02 | Associativity must be greater than zero                |
| VR-03 | Associativity must be a power of two                   |
| VR-04 | Block size must be a power of two                      |
| VR-05 | Number of cache sets must evaluate to an integer value |
| VR-06 | Cache size must be alrger than block size              |

## Derived Calculation
### Number of Sets
The number of cache sets shall be calculated using:

$$ \text{Sets} = \frac{\text{Cache Size}}{\text{Block Size \x Associativity}} $$

## Cache Lines
The total number of cache lines shall be calculated using:
$$ \text{Lines} = \frac{\text{Cache Size}}{\text{Block Size}} $$

## Constraints

| ID     | Constraint                                                                                                                |
| :---   | :---                                                                                                                      |
| CON-01 | Only valid cache configurations may enter simulation execustion                                                           |
| CON-02 | Replacement policies must remain implementation-independent at the requirements stage                                     |
| CON-03 | Cache configuration structures must preserve separation between backend simulation logic and frontend visualization logic |
| CON-04 | Configuration requirements must remain compatible with future analytics and metrics subsystems                            |

## Use Cases

| Use Case ID | Use Case                     |
| UC-01       | Configure Cache              |
| UC-02       | Validate Cache Configuration |

## CFR -> CLFR -> Use Case Traceability

| CFR    | CLFR                      | Use Case                           |
| :---   | :---                      | :---                               |
| CFR-01 | CLFR-01, CLFR-02          | UC-01 Configure Cache              |
| CFR-02 | CLFR-03, CLFR-04, CLFR-05 | UC-01 Configure Cache              |
| CFR-03 | CLFR-06, CLFR-07          | UC-01 Configure Cache              |
| CFR-04 | CLFR-08, CLFR-09          | UC-01 Configure Cache              |
| CFR-05 | CLFR-10, CLFR-11, CLFR-12 | UC-02 Validate Cache Configuration |
| CFR-06 | CLFR-13                   | UC-02 Validate Cache Configuration |
| CFR-07 | CLFR-14                   | UC-01 Configure Cache              |

## Acceptance Criteria
* Functional requirements for cache configuration are documented.
* Non-functional requirements for cache configuration are documented.
* Cache size, associativity, block size, and replacement-policy requirements are defined.
* Validation rules for invalid cache configurations are specified.
* Derived cache calculations are documented.
* CFR -> CLFR -> Use Case traceability mappings are established.
* Requirements align with future UML, SSD, GRASP, and domain-model artifacts.
* Requirements support future extensibility for additional cache architectures.

## Technical Notes
* Maintain CFR -> CLFR -> Use Case traceability consistency.
* Preserve separation between simulation and visualization responsibilities.
* Use requirement identifiers consistently across all architecture artifacts.
* Align requirements with future Cache, CacheSet, AddressMapper, and Metrics subsystems.
* Future replacement policies should integrate through Strategy Pattern abstractions

## Deliverables
* Updated architecture documentation
* Cache configuration requirement definitions
* Validation-rule documentation
* Cache configuration traceability mappings
* Foundational inputs for future UML and GRASP artifacts

---



---

# File Structure
```text
cache-scope/
│
|———— frontend/
│   │
│   |——— public/
│   │
│   |——— src/
│   │   │
│   │   ├── components/
│   │   │   ├── cache-grid.ts
│   │   │   ├── control-panel.ts
│   │   │   ├── metrics-panel.ts
│   │   │   ├── trace-viewer.ts
│   │   │   ├── memory-map.ts
│   │   │   └── simulation-log.ts
│   │   │
│   │   ├── services/
│   │   │   └── api.ts
│   │   │
│   │   ├── styles/
│   │   │   └── global.css
│   │   │
│   │   ├── types/
│   │   │   └── simulation.ts
│   │   │
│   │   ├── utils/
│   │   │   └── formatter.ts
│   │   │
│   │   ├── main.ts
│   │   └── vite-env.d.ts
│   │
│   ├── package.json
│   ├── tsconfig.json
│   ├── vite.config.ts
│   └── README.md
│
├── backend/
│   │
│   ├── src/
│   │   │
│   │   ├── api/
│   │   │   └── routes.cpp
│   │   │
│   │   ├── cache/
│   │   │   ├── cache.cpp
│   │   │   ├── cache.h
│   │   │   ├── cache_block.h
│   │   │   ├── cache_set.h
│   │   │   └── replacement_policy.h
│   │   │
│   │   ├── hash/
│   │   │   ├── hash_set.cpp
│   │   │   └── hash_set.h
│   │   │
│   │   ├── simulation/
│   │   │   ├── simulator.cpp
│   │   │   ├── simulator.h
│   │   │   └── metrics.h
│   │   │
│   │   ├── utils/
│   │   │   └── parser.h
│   │   │
│   │   └── main.cpp
│   │
│   ├── tests/
│   │
│   ├── build/
│   │
│   ├── CMakeLists.txt
│   └── README.md
│
├── docs/
│   ├── architecture.md
│   ├── api-spec.md
│   └── screenshots/
│
├── .gitignore
├── README.md
└── LICENSE
```
