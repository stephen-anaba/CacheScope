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


# Architecture & Requirements Specification

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
#  US 1.1: Define cache Configuration Requirements

## Part 1: The Configuration Parameter Table


| Parameter ID | Attribute Name | Data Type | Default Value | Constraints |
| :--- | :--- | :--- | :--- | :--- |
| **CFG-01** | `cache_size` | Integer | 32 KB | Must be a power of 2 ( 1 KB ≤ X ≤ 64 MB ) |
| **CFG-02** | `block_size` | Integer | 64 Bytes | Must be a power of 2 ( 4 Bytes ≤ X ≤ 1 KB ) |
| **CFG-03** | `associativity` | Integer | 4 (4-way) | Must be a power of 2 (1 ≤ X ≤ 64) or 0 for Fully Associative |
| **CFG-04** | `replacement_policy` | String/Enum | "LRU" | Options: LRU, FIFO, LFU, Random |


## Part 2: Functional Requirements
```text
1. Power-of-Two Enforcement: The system must validate that cache_size, block_size, and associativity conform to  mathematical validation before initializing simulation structures.

2. Dependent Dimension Validation: The system must verify that total cache_size is greater than or equal to the selected block_size.

3. Total Block Calculation: The system must dynamically compute the total number of blocks using the formula: 
```
$$ \text{Total Blocks} = \frac{\text{Cache Size}}{\text{Block Size}} $$

| Parameter ID | Attribute Name       | Data Type   | Default Value | Constraints                                                  |
| :---         | :---                 | :---        | :---          | :---                                                         |
| **CFG-01**   | `cache_size`         | Integer     | 32 KB         | Must be a power of 2 ( 1 KB ≤ X ≤ 64 MB )                    |
| **CFG-02**   | `block_size`         | Integer     | 64 Bytes      | Must be a power of 2 ( 4 Bytes ≤ X ≤ 1 KB )                  |
| **CFG-03**   | `associativity`      | Integer     | 4 (4-way)     | Must be a power of 2 (1 ≤ X ≤ 64) or 0 for Fully Associative |
| **CFG-04**   | `replacement_policy` | String/Enum | "LRU"         | Options: LRU, FIFO, LFU, Random                              |


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
