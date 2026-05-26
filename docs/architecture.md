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

## Overview
Define the functional and non-functional requirements for cache configuration to support flexible simulation setup, scalable cache architectures, deterministic simulation behavior, and future extensibility within CacheScope.
These requirements establish the foundation for:
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

### Functional Requirements (CFR)

| ID     | Requirement                                                                                       | Priority |
| :---   | :---                                                                                              | :---     |
| CFR-01 | This sytem shall allow users to configure cache size                                              | High     |
| CFR-02 | The system shall allow users to configur ecache associatiity                                      | High     |
| CFR-03 | The system shall allow users to configure cache block size                                        | High     |
| CFR-04 | The system shall allow users to configure replacement policies                                    |
| CFR-05 | The system shall validate invalid cache configurations before simulation execution                | High     |
| CFR-06 | The system shall support deterministic cache configuration processing                             | Medium   |
| CFR-07 | The system shall support extensivle cache configuration structures for future cache architectures |          |

### Low-Level Functional Requirements (CLFR)

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

### Derived Calculation
### Number of Sets
The number of cache sets shall be calculated using:
Sets = \frac{Cache Size}{(Block Size \x Associativity)}

### Cache Lines
The total number of cache lines shall be calculated using:
Lines = \frac{Cache size}{Block Size}

## Constraints

| ID     | Constraint                                                                                                                |
| :---   | :---                                                                                                                      |
| CON-01 | Only valid cache configurations may enter simulation execustion                                                           |
| CON-02 | Replacement policies must remain implementation-independent at the requirements stage                                     |
| CON-03 | Cache configuration structures must preserve separation between backend simulation logic and frontend visualization logic |
| CON-04 | Configuration requirements must remain compatible with future analytics and metrics subsystems                            |

### Use Cases

| Use Case ID | Use Case                     |
| UC-01       | Configure Cache              |
| UC-02       | Validate Cache Configuration |

### CFR -> CLFR -> Use Case Traceability

| CFR    | CLFR                      | Use Case              |
| :---:  | :---:                     | :---:                 |
| CFR-01 | CLFR-01, CLFR-02          | UC-01 Configure Cache |
| :---   | :---                      | :---                  |
| CFR-02 | CLFR-03, CLFR-04, CLFR-05 | UC-01 Configure Cache |

---

## 1. Core Functional Requirements (CFR)
- **CFR-1 (Cache Config):** The system must accept user-defined cache sizes, associativity, and block sizes.
- **CFR-2 (Address Mapping):** The system must accurately compute tags, indexes, and offsets.

## 2. Component Low-Level Functional Requirements (CLFR)
### 2.1 Cache Configuration (US-1.1.x)
- [ ] CLFR-1.1.1: Cache sizes must be powers of 2 (minimum 1KB, maximum 64KB).

## 3. Use Case Traceability Matrix

| Requirement ID | Component / Task ID | Target Use Case | Verification Status |
| :--- | :--- | :--- | :--- |
| CFR-1 | US-1.1.1 / US-1.1.2 | UC-01: Initialize Cache | ... Pending |
| CFR-2 | US-1.2.1 | UC-02: Map Memory Address| ... Pending |

---

## Requirements

| ID                      | Core Functional Requirements                                      | ID       | Low Level Core Requirements                                             |
| :---                    | :---                                                              | :---     | :---                                                                    |
|                         | **Cache Simulation**                                              |          |                                                                         |
| CFR-1                   | The system shall simulate cache memory access                     | CLFR-1.1 | The system shall process sequential memory access requests              |
|                         |                                                                   | CLFR-1.2 | The system shall update cache state after each access                   |
|                         |                                                                   | CLFR-1.3 | The system shall maintain deterministic simulation execution            |
| **Cache Configuration** |                                                                   |          |                                                                         |
| CFR-2                   | The system shall support configurable cache parameters            | CLFR-2.1 | The system shall support configurable cache sizes                       |
|                         |                                                                   | CLFR-2.2 | The system shall support configurable block sizes                       |
|                         |                                                                   | CLFR-2.3 | The system shall support configurable associativity levels              |
| **Address Trans.**      |                                                                   |          |                                                                         |
| CFR-3                   | The system shall determine cache hits and cache misses            | CLFR-3.1 | The system shall accept hexadecimal memory addresses                    |
|                         |                                                                   | CLFR-3.2 | The system shall decompose addresses into tag, index, and offset fields |
|                         |                                                                   | CLFR-3.3 | The system shall visualize binary address decomposition                 |
| **Hit/Miss Res.**       |                                                                   |          |                                                                         |
| CFR-4                   | The system shall apply cache replacement policies during eviction | CLFR-4.1 | The system shall search cache sets for matching tags                    |
|                         |                                                                   | CLFR-4.2 | The system shall classify accesses as hits or misses                    |
|                         |                                                                   | CLFR-4.3 | The system shall update cache metadata after each access                |
| **Repl. Policies**      |                                                                   |          |                                                                         |
| CFR-5                   | The system shall handle cache replacement mechanics               | CLFR-5.1 | The system shall support Least Recently Used (LRU) eviction             |
|                         |                                                                   | CLFR-5.2 | The system shall support First-In First-Out (FIFO) eviction             |
|                         |                                                                   | CLFR-5.3 | The system shall replace cache lines during misses when sets are full   |
| **Visualization**       |                                                                   |          |                                                                         |
| CFR-6                   | The system shall visually render cache state changes              | CLFR-6.1 | The system shall render cache-line states visually                      |
|                         |                                                                   | CLFR-6.2 | The system shall highlight cache hits and misses                        |
|                         |                                                                   | CLFR-6.3 | The system shall animate cache evictions                                |
| **Cache Analytics**     |                                                                   |          |                                                                         |
| CFR-7                   | The system shall display cache analytics in real time             | CLFR-7.1 | The system shall calculate cache hit rates                              |
|                         |                                                                   | CLFR-7.2 | The system shall calculate cache miss rates                             |
|                         |                                                                   | CLFR-7.3 | The system shall display real-time simulation metrics                   |

---

# 1. Cache Configuration Requirements
```
text
Key:
• CFR = Cache Functional Requrements
• CLFR = Cache Low-Level Functional Requirement
• UC = Use Case
```

## User Story Statement
### US 1.1: Define cache Configuration Requirements
### User Story Statement
```
text
As a user, I want to configure cache parameters, to that I can simulate and analyze different chace behaviors.
```
### Overview
```
text
This user story defines the configurable properties of the cache simulation engine, including cache size, associativity, block size, replacement policies, and write strategies.
```
### Functional Requirements Table

| ID    | Requirement                            | Priority |
| :---  | :---                                   | :---     |
| FR-01 | User can configure cache size          | High     |
| FR-02 | User can configure block size          | High     |
| FR-03 | User can configure associativity       | High     |
| FR-04 | User can select replacement policy     | Medium   |
| FR-05 | User can select write policy           | Medium   |
| FR-06 | System validates invalid configuration | High     |


## Configuration Parameters Table

| Parameter          | Description           | Example Values |
| :---               | :---                  | :---           |
| Cache Size         | Total cache capacity  | `32KB, 64KB`   |
| Block Size         | Bytes per cache line  | `16B, 64B`     |
| Associativity      | Number of ways        | `1-way, 4-way` |
| Replacement Policy | Eviction strategy     | LRU, FIFO      |
| Write Policy       | Memory write behavior | Write-back     |

## Validation Rules

| Rule ID | Validation Rule                            |
| :---    | :---                                       |
| VF-01   | Cache size must be divisible by block size |
| VR-02   | Associativity must be a power of 2         |
| VR-03   | Number of sets must be an integer          |

## Acceptance Criteria
- User can successfully configure all required cache parameters
- Invalid cache configurations are rejected
- System displays configuration summary before simulation

---

# CacheScope File Structure
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
