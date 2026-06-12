# Core Use Case (UC)

| **ID** | **Use Case**           |
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

--- 

# US 1.1: Define Cache Configuration Requirements

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

| **ID**     | **Requirement**                                                                                       | **Priority** |
| :---   | :---                                                                                              | :---     |
| CFR-01 | The sytem shall allow users to configure cache size                                              | High     |
| CFR-02 | The system shall allow users to configure cache associatiity                                      | High     |
| CFR-03 | The system shall allow users to configure cache block size                                        | High     |
| CFR-04 | The system shall allow users to configure replacement policies                                    |
| CFR-05 | The system shall validate invalid cache configurations before simulation execution                | High     |
| CFR-06 | The system shall support deterministic cache configuration processing                             | Medium   |
| CFR-07 | The system shall support extensive cache configuration structures for future cache architectures |          |

## Low-Level Functional Requirements (CLFR)

| **ID**      | **Requirement**                                                                          | **Parent CFR** |
| :---    | :---                                                                                 | :---       |
| CLFR-01 | Cache size shall support KB and MB input formats                                     | CFR-01     |
| CLFR-02 | Cache size shall be stored internally in bytes                                       | CFR-01     |
| CLFR-03 | Associativity shall support direct-mapped mode                                       | CFR-02     |
| CLFR-04 | Associativity shall support set-associative mode                                       | CFR-02     |
| CLFR-05 | Associativity shall support fully associative mode                                   | CFR-02     |
| CLFR-06 | Block size shall be configurable in bytes                                            | CFR-03     |
| CLFR-07 | Block size shall support power-of-two validation                                     | CFR-03     |
| CLFR-08 | Replacement policies shall include LRU                                               | CFR-04     |
| CLFR-09 | Replacement policies shall incllude FIFO                                                                | CFR-04     |
| CLFR-10 | Cache size must be divisible by block size                                           | CFR-05     |
| CLFR-11 | Number of cache sets must evaluate to an integer value                               | CFR-05     |
| CLFR-12 | Associativity must be a positivie power of two                                       | CFR-05     |
| CLFR-13 | Configuration validation shall occur before simulation execution                     | CFR-06     |
| CLFR-14 | Configuration structures shall remain extensible for future multi-lvel cache support | CFR-07     |

## Non-Functional Requirements (CNFR)

| **ID**      | **Requirement**                                                                                                                    |
| :---    | :---                                                                                                                           |
| CNFR-01 | Cache configuration validation shall complete within 100ms under standard input conditions                                     |
| CNFR-02 | Cache configuration structures shall support future extensibility without requiring major system redesign                    |
| CNFR-03 | Cache configuration interfaces shall remian understandable for computer architecture students and beginner systems programmers |
| CNFR-04 | Configuration processing shall remain deterministic across repeated simulations with identical inputs                          |
| CNFR-05 | Cache configuration logic shall remain modular and independent from visualization rendering logic                              |

## Configuration Parameters

| **Parameter**          | **Description**                    | **Example Values**      |
| :---               | :---                           | :---                |
| Cache Size         | Total cache storage capacity   | 16KB, 32KB, 64KB    |
| Block Size         | Number of bytes per cache line | 16B, 32B, 64B       |
| Associativity      | Number of cache lines per set  | 1-way, 2-way, 4-way |
| Replacement Policy | Cache-line eviction strategy   | LRU, FIFO           |
| Address Width      | Memory-address size            | 32-bit, 64-bit      |

## Validation Rules

| **ID**    | **Rule**                                                   |
| :---  | :---                                                   |
| VR-01 | Cache size must be divisible by block size             |
| VR-02 | Associativity must be greater than zero                |
| VR-03 | Associativity must be a power of two                   |
| VR-04 | Block size must be a power of two                      |
| VR-05 | Number of cache sets must evaluate to an integer value |
| VR-06 | Cache size must be larger than block size              |

## Derived Calculation
### Number of Sets
The number of cache sets shall be calculated using:

$$ \text{Sets} = \frac{\text{Cache Size}}{\text{Block Size x Associativity}} $$

## Cache Lines
The total number of cache lines shall be calculated using:
$$ \text{Lines} = \frac{\text{Cache Size}}{\text{Block Size}} $$

## Constraints

| **ID**     | **Constraint**                                                                                                                |
| :---   | :---                                                                                                                      |
| CON-01 | Only valid cache configurations may enter simulation execusion                                                           |
| CON-02 | Replacement policies must remain implementation-independent at the requirements stage                                     |
| CON-03 | Cache configuration structures must preserve separation between backend simulation logic and frontend visualization logic |
| CON-04 | Configuration requirements must remain compatible with future analytics and metrics sub-systems                            |

## Use Cases

| **Use Case ID** | **Use Case**                     |
| :---        | :---                         |
| UC-01       | Configure Cache              |
| UC-02       | Validate Cache Configuration |

## CFR -> CLFR -> Use Case Traceability

| **CFR**    | **CLFR**                      | **Use Case**                           |
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
# US 1.2: Define Memory Address Mapping Requirements

## Requirements

### Overview
Define the functional and non-functional requirements for memory-address parsing, decomposition, validation, and visualization to support accurate cache mapping simulation and deterministic address interpretation within CacheScope.

### These requirements establish the foundation for:
* address parsing logic
* tag/index/offset decomposition
* binary address visualization
* cache-set mapping
* address validation
* future address-analysis tooling

## User Story
As a computer architecture student, I want to input and visualize memory addresses, so that I can understand how addresses map into cache structures and influence cache behavior.

## Scope
### This user story covers:
* hexadecimal memory-address input
* binary address conversion
* tag/index/offset decomposition
* address validation
* address-width compatibility
* address visualization requirements
* traceability mappings

### This user story does not yet cover:
* cache-hit/miss execution
* runtime cache replacement
* visualization rendering implementation
* advanced memory hierarchy modeling

## Functional Requirements (CFR)

| **ID**     | **Requirement**                                                                                          |
| :---   | :---                                                                                                 |
| CFR-01 | The system shall allow users to input hexadecimal memory address                                     |
| CFR-02 | The system shall convert hexadecimal adresses into binary representation                             |
| CFR-03 | The system shall decompose memory addresses into tag, index, and offset components                   |
| CFR-04 | The system shall visually represent address decomposition resuts                                     |
| CFR-05 | The system shall validate invalid memory-address inputs before simulation execution                  |
| CFR-06 | The system shall support configurable address widths                                                 |
| CFR-07 | The system shall supprt deterministic address decomposition behavior                                 |
| CFR-08 | The system shall support extensible address-processing structures for future architectural expansion |


## Low-Level Functional Requirements (CLFR)

| **ID**      | **Requirement**                                                                                             |
| :---    | :---                                                                                                    |
| CLFR-01 | Address input shall supprt hexadecimal notation using standard prefixes and formats                     |
| CLFR-02 | Address input shall reject unsupported into binary representation before decomposition                  |
| CLFR-03 | Hexdecimal addresses shall be converted into binary representation before decomposition                 |
| CLFR-04 | Binary conversion shall preserve address-width consistency                                              |
| CLFR-05 | Address decomposition shall calculate tag bits using cache configuration parameters                     |
| CLFR-06 | Address decomposition shall calculate index bits using cache configuration parameters                   |
| CLFR-07 | Address decomposition shall calculate offset bits using cache configuration parameters                  |
| CLFR-08 | Binary visualization shall visually distinguish tag, index, and offset regions                          |
| CLFR-09 | Address visualization shall remain synchronized with cache configuration changes                        |
| CLFR-10 | Invalid address inputs shall prevent siulation execution                                                |
| CLFR-11 | Invalid address inputs shall generate descriptive validation feedback                                   |
| CLFR-12 | The system shall support both 32-bit and 64-bit address widths                                          |
| CLFR-13 | Address decomposition shall remain deterministic for repeated identical inputs                          |
| CLFR-14 | Address-processing structures shall support future extensibility for advanced address-analysis features |


## Non-Functional Requirements (CNFR)

| **ID**      | **Requirement**                                                                                                           |
| :---    | :---                                                                                                                  |
| CNFR-01 | Address decomposition calculations shall complete within 100ms under standard simulation conditions                   |
| CNFR-02 | Address-processing logic shall remain modular and independent from visualization rendering logic                      |
| CNFR-03 | Address visualization shall remain understandable for computer architecture students and beginner systems programmers |
| CNFR-04 | Address-processing behavior shall remain deterministic across repeated simulations with identical inputs              |
| CNFR-05 | Address-processing structures shall support future extnsibility without major subsystem redesign                      |

## Address Components

| Component | Description                                                               |
| :---      | :---                                                                      |
| Tag       | Identifies whether a cache line corresponds to the requested memory block |
| Index     | Identifies the target cache set                                           |
| Offset    | Identifies the byte position within a cache block                         |

## Address Processing Workflow
1. User submits hexadecimal memory address.
2. System validates address format.
3. System converts hexadecimal address into binary.
4. System determines tag/index/offset bit widths.
5. System decomposes binary address.
6. System updates visualization structures.
7. System forwards processed address to cache-resolution subsystem

## Derived Calculations
### Offset Bits
$$ \text{Offset Bits} = \text{log2(Block Size)} $$

### Number of Sets
$$ \text{Sets} = \frac{\text{Cache Size}}{\text{Block Size x Associativity}} $$

## Validation Rules

| **ID**    | **Rule**                                                                                 |
| :---  | :---                                                                                 |
| VR-02 | Address input must contain only valid hexadecimal characters                         |
| VR-02 | Address width must match configured architecture contraints                          |
| VR-03 | Address decomposition calculations must produce non-negative tag/index/offset values |
| VR-04 | Binary decomposition calculations must produce non-negative tag/index/offset values  |
| VR-05 | Invalid addresses must prevent simulation execution                                  |

## Constraints

| **ID**     | **Constraint**                                                                             |
| :---   | :---                                                                                   |
| CON-01 | Address decomposition logic must remain independent from visualization rendering logic |
| CON-02 | Address-processing workflows must reamin compatible with future cache architectures    |
| CON-03 | Address-processing behavior must remain deterministic                                  |
| CON-04 | Address calculations must remain synchronized with cache configuration parameters      |

## Use Cases

| **Use Case ID** | **Use Case**               |
| :---        | :---                   |
| UC-03       | Input Memory Address   |
| UC-04       | Translate Address      |
| UC-05       | Visualize Address Bits |
| UC-06       | Validate Address Input |

## CFR → CLFR → Use Case Traceability

| **CFR**    | **CLFR**                      | **Use Case**                     |
| :---   | :---                      | :---                         |
| CFR-01 | CLFR-01, CLFR-02          | UC-02 Input Memory Address   |
| CFR-02 | CLFR-03, CLFR-04          | UC-04 Translate Address      |
| CFR-03 | CLFR-05, CLFR-06, CLFR-07 | UC-04 Translate Address      |
| CFR-04 | CLFR-08, CLFR-09          | UC-05 Visualize Addres Bits  |
| CFR-05 | CLFR-10, CFR-11           | UC-06 Validate Address Input |
| CFR-06 | CLFR-12                   | UC-04 Translate Address      |
| CFR-07 | CLFR-13                   | UC-04 Translate Address      |
 CFR-08 | CLFR-14 | UC-05 Visualize Address Bits |

## Acceptance Criteria
* Functional requirements for address processing are documented.
* Non-functional requirements for address processing are documented.
* Hexadecimal input requirements are defined.
* Tag/index/offset decomposition requirements are documented.
* Binary visualization requirements are specified.
* Validation rules for invalid addresses are documented.
* Derived address calculations are documented.
* CFR → CLFR → Use Case traceability mappings are established.
* Requirements align with future UML, SSD, GRASP, and domain-model artifacts.
* Requirements support future extensibility for advanced memory-analysis features.

## Technical Notes
* Align requirements with future AddressMapper subsystem design.
* Preserve separation between simulation and visualization responsibilities.
* Use requirement identifiers consistently across all architecture artifacts.
* Ensure address-processing workflows remain deterministic.
* Maintain compatibility with future cache-analytics and visualization subsystems.

## Deliverables
* Updated architecture documentation
* Address-processing requirement definitions
* Address-validation documentation
* Address decomposition calculations
* CFR → CLFR → Use Case traceability mappings
* Foundational inputs for future UML and GRASP artifacts

---

# US-1.3 -- Define Cache Resolution

## Requirements

### Overflows
Define the functional and non-functional requirements for cache lookup, cache-hit detection, cache-miss classification, cache-state transitions, and deterministic cache-resolution behavior within CacheScope.

### These requirements establish the foundation for:
* cache-set lookup
* cache-hit detection
* cache-miss classification
* cache-state updates
* runtime simulation behavior
* replacement-policy integration

## User Story
As a computer architecture student, I want the system to accurately determine cache hits and misses, so that I can understand how memory accesses interact with cache architectures and replacement policies.

## Scope
### This user story covers:
* cache-set lookup requirements
* hit/miss detection requirements
* cache-state update requirements
* deterministic simulation execution
* replacement-policy integration points
* traceability mappings

### This user story does not yet cover:
* visualization rendering
* animation systems
* advanced multi-level cache orchestration
* distributed simulation execution

## Functional Requirements (CFR)

| **ID**      | **Requirement**                                                                                      | **Parent CFR** |
| :---    | :---                                                                                             | :---       |
| CLFR-01 | Cache lookup shall identify the target cache set using decomposed index bits.                    | CFR-01     |
| CLFR-02 | Cache lookup shall search all cache lines within the target set.                                 | CFR-01     |
| CLFR-03 | Cache-hit detection shall compare requested tags against stored cache-line tags.                 | CFR-02     |
| CLFR-04 | Cache-hit execution shall update replacement metadata when required.	CFR-02                   |
| CLFR-05 | Cache-miss detection shall occur when no valid matching tag exists.                              | CFR-03     |
| CLFR-06 | Cache misses shall support compulsory miss classification.	CFR-04                               |
| CLFR-07 | Cache misses shall support conflict miss classification.                                         | CFR-04     |
| CLFR-08 | Cache misses shall support capacity miss classification.                                         | CFR-04     |
| CLFR-09 | Cache-state updates shall support cache-line insertion after misses.                             | CFR-05     |
| CLFR-10 | Cache-state updates shall support valid-bit updates.                                             | CFR-05     |
| CLFR-11 | Replacement policies shall determine eviction targets during full-set insertion workflows.       | CFR-06     |
| CLFR-12 | Cache-resolution execution shall remain deterministic for repeated identical simulations.        | CFR-07     |
| CLFR-13 | Cache-resolution structures shall support future extensibility for advanced cache architectures. | CFR-08     |

## Low-Level Functional Requirements (CLFR)

| **ID**      | **Requirement**                                                                                     | **Parent CFR** |
| :---    | :---                                                                                            | :---       |
| CLFR-01 | Cache lookup shall identify the target cache set using decomposed index bits                    | CFR-01     |
| CLFR-02 | Cache lookup shall search all cache lines within the target set                                 | CFR-01     |
| CLFR-03 | Cache-hit detection shall compare requested tags against stored cache-line tags                 | CFR-02     |
| CLFR-04 | Cache-hit execution shall update replacement metadata when required                             | CFR-02     |
| CLFR-05 | Cache-miss detection shall occur when no valid matching tag exists                              | CFR-03     |
| CLFR-06 | Cache misses shall support compulsory miss classification                                       |
| CLFR-07 | Cache misses shall support conflict miss classification                                         | CFR-04     |
| CLFR-08 | Cache misses shall support capacity miss classification                                         | CFR-04     |
| CLFR-09 | Cache-state updates shall support cache-line insertion after misses                             | CFR-05     |
| CLFR-10 | Cahe-state updates shall support valid-bit updates                                              | CFR-05     |
| CLFR-11 | Replacement policies shall determine eviction targets during full-set insertion workflows       |
| CLFR-12 | Cache-resolution execution shall remain deterministic for repeated identical simulations        | CFR-07     |
| CLFR-13 | Cache-resolution structures shall support future extensibility for advanced cache architectures |

## Non-Functional Requirements (CNFR)

| **ID**      | **Requirement**                                                                                                                 |
| :---    | :---                                                                                                                        |
| CNFR-01 | Cache-resolution execution shall complete within 100ms under standard simulation conditions.                                |
| CNFR-02 | Cache-resolution logic shall remain modular and independent from visualization rendering logic.                             |
| CNFR-03 | Cache-resolution behavior shall remain deterministic across repeated simulations with identical inputs.                     |
| CNFR-04 | Cache-resolution workflows shall remain understandable for computer architecture students and beginner systems programmers. |
| CNFR-05 | Cache-resolution structures shall support future extensibility without major subsystem redesign.                            |

## Cache Resolution Workflow
1. Address decomposition subsystem forwards processed address.
2. System identifies target cache set.
3. System searches cache lines within target set.
4. System compares tags.
5. System determines hit or miss result.
6. System updates replacement metadata.
7. System updates cache state.
8. System forwards execution results to visualization and analytics subsystems.

## Validation Rules

| **ID**    | **Rule**                                                                              |
| :---  | :---                                                                              |
| VR-01 | Cache lookup operations must use decomposed index values.                         |
| VR-02 | Cache-hit detection must compare valid cache-line tags only.                      |
| VR-03 | Cache-state updates must preserve deterministic execution order.                  |
| VR-04 | Replacement-policy execution must occur only during full-set insertion workflows. |
| VR-05 | Cache misses must trigger cache-state update workflows.                           |

## Constraints

| ID     | Constraint                                                                                       |
| :---   | :---                                                                                             |
| CON-01 | Cache-resolution logic must remain independent from visualization rendering logic.               |
| CON-02 | Cache-resolution workflows must remain compatible with future replacement policies.              |
| CON-03 | Cache-resolution execution must remain deterministic.                                            |
| CON-04 | Cache-resolution workflows must remain synchronized with analytics and visualization subsystems. |

## Use Cases

| Use Case ID                        | Use Case           |
| :---                               | :---               |
| UC-07                              | Search Cache Set   |
| UC-08                              | Detect Cache Hit   |
| UC-09                              | Detect Cache Miss  |
| UC-10                              | Update Cache State |

## CFR → CLFR → Use Case Traceability

| CFR    | CLFR                      | Use Case                 |
| :---   | :---                      | :---                     |
| CFR-01 | CLFR-01, CLFR-02          | UC-07 Search Cache Set   |
| CFR-02 | CLFR-03, CLFR-04          | UC-08 Detect Cache Hit   |
| CFR-03 | CLFR-05                   | UC-09 Detect Cache Miss  |
| CFR-04 | CLFR-06, CLFR-07, CLFR-08 | UC-09 Detect Cache Miss  |
| CFR-05 | CLFR-09, CLFR-10          | UC-10 Update Cache State |
| CFR-06 | CLFR-11                   | UC-10 Update Cache State |
| CFR-07 | CLFR-12                   | UC-07 Search Cache Set   |
| CFR-08 | CLFR-13                   | UC-10 Update Cache State |

## Acceptance Criteria
* Functional requirements for cache resolution are documented.
* Non-functional requirements for cache resolution are documented.
* Cache-hit and cache-miss detection requirements are defined.
* Cache-state update requirements are documented.
* Miss-classification requirements are specified.
* Validation rules for cache-resolution workflows are documented.
* CFR → CLFR → Use Case traceability mappings are established.
* Requirements align with future UML, SSD, GRASP, and domain-model artifacts.
* Requirements support future extensibility for advanced cache architectures.

## Technical Notes
* Align requirements with future Cache and CacheSet subsystem design.
* Preserve separation between simulation and visualization responsibilities.
* Use requirement identifiers consistently across all architecture artifacts.
* Ensure cache-resolution workflows remain deterministic.
* Maintain compatibility with future analytics and visualization subsystems.

## Deliverables
* Updated architecture documentation
* Cache-resolution requirement definitions
* Cache-state transition documentation
* Miss-classification documentation
* CFR → CLFR → Use Case traceability mappings
* Foundational inputs for future UML and GRASP artifacts

---

# US-1.4 — Define Replacement Policy Requirements
### Overview
Define the functional and non-functional requirements for cache replacement policies, eviction workflows, replacement metadata management, and extensible replacement-policy execution within CacheScope.

### These requirements establish the foundation for:
* LRU policy execution
* FIFO policy execution
* eviction management
* replacement metadata tracking
* replacement-policy abstraction
* future policy extensibility

## User Story
As a computer architecture student, I want the simulator to model realistic replacement policies, so that I can analyze how eviction strategies influence cache behavior and performance.

## Scope
### This user story covers:
* replacement-policy requirements
* eviction workflows
* replacement metadata requirements
* policy abstraction requirements
* deterministic replacement execution
* traceability mappings

### This user story does not yet cover:
* visualization animation systems
* predictive replacement algorithms
* hardware-level optimization modeling
* distributed cache architectures

## Functional Requirements (CFR)

| ID                                       | Requirement                                                                 | Priority |
| :---                                     | :---                                                                        | :---     |
| CFR-01                                   | The system shall support LRU replacement-policy execution.                  | High     |
| CFR-02                                   | The system shall support FIFO replacement-policy execution.                 | High     |
| CFR-03                                   | The system shall support cache-line eviction workflows.                     | High     |
| CFR-04                                   | The system shall maintain replacement metadata during simulation execution. | High     |
| CFR-05                                   | The system shall support replacement-policy abstraction and extensibility.  | Medium   |
| CFR-06                                   | The system shall support deterministic replacement-policy execution.        | Medium   |
| CFR-07                                   | The system shall support future replacement-policy expansion.               | Medium   |

##  Low-Level Functional Requirements (CLFR)

| ID      | Requirement                                                                                     | Parent CFR |
| :---    | :---                                                                                            | :---       |
| CLFR-01 | LRU execution shall evict the least recently used cache line within a set.                      | CFR-01     |
| CLFR-02 | LRU execution shall update usage metadata after cache hits and insertions.                      | CFR-01     |
| CLFR-03 | FIFO execution shall evict the oldest inserted cache line within a set.                         | CFR-02     |
| CLFR-04 | FIFO execution shall preserve insertion-order metadata.                                         | CFR-02     |
| CLFR-05 | Eviction workflows shall execute when inserting into fully occupied cache sets.                 | CFR-03     |
| CLFR-06 | Eviction workflows shall identify and remove target cache lines before insertion.               | CFR-03     |
| CLFR-07 | Replacement metadata shall remain synchronized with cache-state transitions.                    | CFR-04     |
| CLFR-08 | Replacement-policy execution shall remain implementation-independent at the requirements stage. | CFR-05     |
| CLFR-09 | Replacement-policy structures shall support Strategy Pattern integration.                       | CFR-05     |
| CLFR-10 | Replacement-policy execution shall remain deterministic across repeated simulations.            | CFR-06     |
| CLFR-11 | Replacement-policy structures shall support future extensibility for additional policies.       | CFR-07     |

## Non-Functional Requirements (CNFR)

| ID      | Requirement                                                                                                                   |
| :---    | :---                                                                                                                          |
| CNFR-01 | Replacement-policy execution shall complete within 100ms under standard simulation conditions.                                |
| CNFR-02 | Replacement-policy logic shall remain modular and independent from visualization rendering logic.                             |
| CNFR-03 | Replacement-policy execution shall remain deterministic across repeated simulations with identical inputs.                    |
| CNFR-04 | Replacement-policy workflows shall remain understandable for computer architecture students and beginner systems programmers. |
| CNFR-05 | Replacement-policy structures shall support future extensibility without major subsystem redesign.                            |

## Replacement Workflow
1. Cache-resolution subsystem detects cache miss.
2. System identifies target cache set.
3. System determines whether free cache lines exist.
4. System invokes replacement-policy execution if set is full.
5. System selects eviction target.
6. System removes target cache line.
7. System inserts new cache line.
8. System updates replacement metadata.

## Validation Rules

| ID    | Rule                                                                        |
| :---  | :---                                                                        |
| VR-01 | Replacement policies must execute only during full-set insertion workflows. |
| VR-02 | Replacement metadata must remain synchronized with cache-state transitions. |
| VR-03 | Eviction workflows must preserve deterministic execution order.             |
| VR-04 | Replacement-policy execution must identify exactly one eviction target.     |
| VR-05 | Newly inserted cache lines must update replacement metadata.                |

## Constraints

| ID     | Constraint                                                                                       |
| :---   | :---                                                                                             |
| CON-01 | Replacement-policy logic must remain independent from visualization rendering logic.             |
| CON-02 | Replacement-policy execution must remain deterministic.                                          |
| CON-03 | Replacement-policy structures must remain compatible with future cache architectures.            |
| CON-04 | Replacement-policy workflows must remain compatible with analytics and visualization subsystems. |

## Use Cases

| Use Case ID                        | Use Case                    |
| :---                               | :---                        |
| UC-11                              | Execute LRU Policy          |
| UC-12                              | Execute FIFO Policy         |
| UC-13                              | Evict Cache Line            |
| UC-14                              | Update Replacement Metadata |

## CFR → CLFR → Use Case Traceability

| CFR    | CLFR             | Use Case                          |
| :---   | :---             | :---                              |
| CFR-01 | CLFR-01, CLFR-02 | UC-11 Execute LRU Policy          |
| CFR-02 | CLFR-03, CLFR-04 | UC-12 Execute FIFO Policy         |
| CFR-03 | CLFR-05, CLFR-06 | UC-13 Evict Cache Line            |
| CFR-04 | CLFR-07          | UC-14 Update Replacement Metadata |
| CFR-05 | CLFR-08, CLFR-09 | UC-11 Execute LRU Policy          |
| CFR-06 | CLFR-10          | UC-13 Evict Cache Line            |
| CFR-07 | CLFR-11          | UC-14 Update Replacement Metadata |

## Acceptance Criteria
* Functional requirements for replacement policies are documented.
* Non-functional requirements for replacement policies are documented.
* LRU and FIFO policy requirements are defined.
* Eviction workflow requirements are documented.
* Replacement metadata requirements are specified.
* Validation rules for replacement-policy execution are documented.
* CFR → CLFR → Use Case traceability mappings are established.
* Requirements align with future UML, SSD, GRASP, and domain-model artifacts.
* Requirements support future extensibility for advanced replacement policies.

## Technical Notes
* Align requirements with future replacement-policy subsystem design.
* Preserve separation between simulation and visualization responsibilities.
* Use requirement identifiers consistently across all architecture artifacts.
* Ensure replacement-policy workflows remain deterministic.
* Integrate future policies using Strategy Pattern abstractions.

## Deliverables
* Updated architecture documentation
* Replacement-policy requirement definitions
* Eviction workflow documentation
* Replacement metadata documentation
* CFR → CLFR → Use Case traceability mappings
* Foundational inputs for future UML and GRASP artifacts


# US-1.5 — Define Visualization Requirements
### Overview
Define the functional and non-functional requirements for cache visualization, runtime simulation feedback, cache-state rendering, and educational visualization workflows within CacheScope.

### These requirements establish the foundation for:
* cache-grid visualization
* hit/miss highlighting
* eviction visualization
* runtime simulation feedback
* simulation logging
* educational interaction workflows

## User Story
As a computer architecture student, I want to visually observe cache behavior during simulation execution, so that I can better understand memory mapping, cache hits/misses, and replacement-policy behavior.

## Scope
### This user story covers:
* cache-grid visualization requirements
* hit/miss highlighting requirements
* eviction visualization requirements
* simulation-log requirements
* visualization synchronization requirements
* educational feedback workflows
* traceability mappings

### This user story does not yet cover:
* advanced animation engines
* 3D visualization systems
* collaborative visualization tooling
* distributed rendering systems

## Functional Requirements (CFR)

| ID                                       | Requirement                                                                                  | Priority |
| :---                                     | :---                                                                                         | :---     |
| CFR-01                                   | The system shall visually represent cache structures during simulation execution.            | High     |
| CFR-02                                   | The system shall visually distinguish cache hits and cache misses.                           | High     |
| CFR-03                                   | The system shall visually represent cache-line eviction workflows.                           | Medium   |
| CFR-04                                   | The system shall provide runtime simulation logs and execution feedback.                     | Medium   |
| CFR-05                                   | The system shall synchronize visualization updates with simulation execution.                | High     |
| CFR-06                                   | The system shall support educational visualization workflows for beginner systems learners.  | Medium   |
| CFR-07                                   | The system shall support extensible visualization structures for future simulation features. | Medium   |

## Low-Level Functional Requirements (CLFR)

| ID                                 | Requirement                                                                                   | Parent CFR |
| :---                               | :---                                                                                          | :---       |
| CLFR-01                            | Cache visualization shall display cache sets and cache lines.                                 | CFR-01     |
| CLFR-02                            | Cache visualization shall display valid cache-line metadata.                                  | CFR-01     |
| CLFR-03                            | Cache-hit execution shall visually highlight successful lookups.                              | CFR-02     |
| CLFR-04                            | Cache-miss execution shall visually highlight failed lookups.                                 | CFR-02     |
| CLFR-05                            | Eviction workflows shall visually identify removed cache lines.                               | CFR-03     |
| CLFR-06                            | Eviction workflows shall visually identify inserted cache lines.                              | CFR-03     |
| CLFR-07                            | Runtime logs shall record simulation events and execution results.                            | CFR-04     |
| CLFR-08                            | Visualization updates shall remain synchronized with simulation-state transitions.            | CFR-05     |
| CLFR-09                            | Visualization workflows shall support step-by-step simulation analysis.                       | CFR-06     |
| CLFR-10                            | Visualization structures shall support future extensibility for advanced educational tooling. | CFR-07     |

## Non-Functional Requirements (CNFR)

| ID      | Requirement                                                                                                              |
| :---    | :---                                                                                                                     |
| CNFR-01 | Visualization updates shall complete within 100ms under standard simulation conditions.                                  |
| CNFR-02 | Visualization logic shall remain modular and independent from backend simulation logic.                                  |
| CNFR-03 | Visualization workflows shall remain understandable for computer architecture students and beginner systems programmers. |
| CNFR-04 | Visualization updates shall remain synchronized with deterministic simulation execution.                                 |
| CNFR-05 | Visualization structures shall support future extensibility without major subsystem redesign.                            |

### Visualization Workflow
1. Simulation subsystem executes cache operation.
2. Cache-resolution subsystem generates execution results.
3. Visualization subsystem receives simulation-state updates.
4. Visualization subsystem updates cache-grid representation.
5. Visualization subsystem highlights hit/miss outcomes.
6. Visualization subsystem updates runtime logs.
7. Visualization subsystem synchronizes execution feedback.

## Validation Rules

| ID    | Rule                                                                              |
| :---  | :---                                                                              |
| VR-01 | Visualization updates must remain synchronized with simulation-state transitions. |
| VR-02 | Cache-hit and cache-miss states must remain visually distinguishable.             |
| VR-03 | Runtime logs must preserve deterministic event order.                             |
| VR-04 | Visualization updates must reflect current cache state accurately.                |
| VR-05 | Visualization rendering failures must not interrupt simulation execution.         |

## Constraints

| ID     | Constraint                                                                               |
| :---   | :---                                                                                     |
| CON-01 | Visualization logic must remain independent from backend simulation logic.               |
| CON-02 | Visualization workflows must remain compatible with future cache architectures.          |
| CON-03 | Visualization updates must remain synchronized with analytics and simulation subsystems. |
| CON-04 | Visualization workflows must prioritize educational clarity over rendering complexity.   |

## Use Cases

| Use Case ID | Use Case               |
| :---        | :---                   |
| UC-15       | Visualize Cache State  |
| UC-16       | Highlight Cache Hit    |
| UC-17       | Highlight Cache Miss   |
| UC-18       | Display Simulation Log |

## CFR → CLFR → Use Case Traceability

| CFR    | CLFR             | Use Case                     |
| :---   | :---             | :---                         |
| CFR-01 | CLFR-01, CLFR-02 | UC-15 Visualize Cache State  |
| CFR-02 | CLFR-03, CLFR-04 | UC-16 Highlight Cache Hit    |
| CFR-03 | CLFR-05, CLFR-06 | UC-17 Highlight Cache Miss   |
| CFR-04 | CLFR-07          | UC-18 Display Simulation Log |
| CFR-05 | CLFR-08          | UC-15 Visualize Cache State  |
| CFR-06 | CLFR-09          | UC-18 Display Simulation Log |
| CFR-07 | CLFR-10          | UC-15 Visualize Cache State  |

## Acceptance Criteria
* Functional requirements for visualization workflows are documented.
* Non-functional requirements for visualization workflows are documented.
* Cache-grid visualization requirements are defined.
* Hit/miss highlighting requirements are documented.
* Eviction visualization requirements are specified.
* Runtime simulation-log requirements are documented.
* Validation rules for visualization synchronization are defined.
* CFR → CLFR → Use Case traceability mappings are established.
* Requirements align with future UML, SSD, GRASP, and domain-model artifacts.
* Requirements support future extensibility for advanced educational tooling.

## Technical Notes
* Align requirements with future visualization subsystem design.
* Preserve separation between visualization and backend simulation responsibilities.
* Use requirement identifiers consistently across all architecture artifacts.
* Ensure visualization workflows remain synchronized with deterministic simulation execution.
* Maintain compatibility with analytics and metrics subsystems.

## Deliverables
* Updated architecture documentation
* Visualization requirement definitions
* Runtime feedback workflow documentation
* Visualization synchronization documentation
* CFR → CLFR → Use Case traceability mappings
* Foundational inputs for future UML and GRASP artifacts

# US 1.6: Metrics & Analytics Requirements
## Overview
Define the functional and non-functional requirements for runtime metrics collection, cache-efficiency analytics, live performance monitoring, and simulation-analysis workflows within CacheScope.

### These requirements establish the foundation for:
* hit-rate analytics
* miss-rate analytics
* live runtime metrics
* simulation performance monitoring
* educational analytics visualization
* future performance-analysis tooling

## User Story
As a computer architecture student, I want to monitor runtime cache metrics during simulation execution, so that I can analyze cache efficiency and understand the performance impact of cache configurations and replacement policies

## Scope
This user story covers:
* hit-rate calculation requirements
* miss-rate calculation requirements
* live-metrics display requirements
* metrics-update synchronization
* runtime analytics requirements
* traceability mappings

### This story doesnot yet cover;
* distributed telemetry systems
* persistent analystics storage
* clooud-based monitoring infrastructure
* predicitive analytics engines

## Functional Requirements (CFR)

| ID     | Requirement                                                                             |
| :---   | :---                                                                                    |
| CFR-01 | the system shall calculate cache hit rates during simulation execution                  |
| CFR-02 | The system shall calculate cache miss rates during simulation execution                 |
| CFR-03 | The system shall provide live runtime metrics during simulation execustion              |
| CFR-04 | The system shall synchronize analytics updates with simulation execution                |
| CFR-05 | The system shall support educational performance-analysis workflows                     |
| CFR-06 | The systemshall suppport extensible analytics structures for future simulation features |

## Low-Level Functional Requirements (CLFR)

| ID      | Requirement                                                                                | Parent CFR |
| :---    | :---                                                                                       | :---       |
| CLFR-01 | Hit-rate calculations shall track total cache hits and total memory accesses.              | CFR-01     |
| CLFR-02 | Hit-rate calculations shall update after each simulation operation.                        | CFR-01     |
| CLFR-03 | Miss-rate calculations shall track total cache misses and total memory accesses.           | CFR-02     |
| CLFR-04 | Miss-rate calculations shall update after each simulation operation.                       | CFR-02     |
| CLFR-05 | Live metrics shall display current hit rates during simulation execution.                  | CFR-03     |
| CLFR-06 | Live metrics shall display current miss rates during simulation execution.                 | CFR-03     |
| CLFR-07 | Metrics updates shall remain synchronized with deterministic simulation-state transitions. | CFR-04     |
| CLFR-08 | Analytics workflows shall support step-by-step performance analysis.                       | CFR-05     |
| CLFR-09 | Analytics structures shall support future extensibility for advanced metrics tooling.      |

## Non-Functional Requirements (CNFR)

| ID      | Requirement                                                                                                        |
| :---    | :---                                                                                                               |
| CNFR-01 | Metrics updates shall complete within 100ms under standard simulation conditions.                                  |
| CNFR-02 | Analytics logic shall remain modular and independent from visualization rendering logic.                           |
| CNFR-03 | Metrics calculations shall remain deterministic across repeated simulations with identical inputs.                 |
| CNFR-04 | Runtime analytics shall remain understandable for computer architecture students and beginner systems programmers. |
| CNFR-05 | Analytics structures shall support future extensibility without major subsystem redesign.                          |

## Metrics Workflow
1. Simulation subsystem executes cache operation.
2. Cache-resolution subsystem generates hit/miss result.
3. Analytics subsystem updates runtime counters.
4. System recalculates hit and miss rates.
5. Visualization subsystem receives updated metrics.
6. Metrics display synchronizes runtime analytics feedback.

## Derived Calculations
### Hit Rate
$$ \text{Hit Rate} = \frac{\text{Total Cache Hits}}{\text{Total memory Access}} $$

### Cache Lines
$$ \text{Miss Rate} = \frac{\text{Total Cache Misses}}{\text{Total Memory Access}} $$

## Validation Rules

| ID    | Rule                                                                        |
| :---  | :---                                                                        |
| VR-01 | Hit-rate calculations must use total cache hits and total accesses.         |
| VR-02 | Miss-rate calculations must use total cache misses and total accesses.      |
| VR-03 | Metrics updates must remain synchronized with simulation-state transitions. |
| VR-04 | Metrics calculations must preserve deterministic execution order.           |
| VR-05 | Analytics update failures must not interrupt simulation execution           |

## Constraints

| ID     | Constraint                                                                                 |
| :---   | :---                                                                                       |
| CON-01 | Analytics logic must remain independent from visualization rendering logic.                |
| CON-02 | Analytics workflows must remain compatible with future cache architectures.                |
| CON-03 | Metrics calculations must remain deterministic.                                            |
| CON-04 | Analytics workflows must remain synchronized with visualization and simulation subsystems. |

## Use Cases

| Use Case ID | Use Case                  |
| :---        | :---                      |
| UC-19       | Calculate Hit Rate        |
| UC-20       | Calculate Miss Rate       |
| UC-21       | Display Runtime Metrics   |
| UC-22       | Analyze Cache Performance |

## CFR → CLFR → Use Case Traceability

| CFR    | CLFR             | Use Case                        |
| :---   | :---             | :---                            |
| CFR-01 | CLFR-01, CLFR-02 | UC-19 Calculate Hit Rate        |
| CFR-02 | CLFR-03, CLFR-04 | UC-20 Calculate Miss Rate       |
| CFR-03 | CLFR-05, CLFR-06 | UC-21 Display Runtime Metrics   |
| CFR-04 | CLFR-07          | UC-21 Display Runtime Metrics   |
| CFR-05 | CLFR-08          | UC-22 Analyze Cache Performance |
| CFR-06 | CLFR-09          | UC-22 Analyze Cache Performance |

## Technical Notes
* Align requirements with future Metrics subsystem design.
* Preserve separation between analytics and visualization responsibilities.
* Use requirement identifiers consistently across all architecture artifacts.
* Ensure analytics workflows remain synchronized with deterministic simulation execution.
* Maintain compatibility with visualization and simulation subsystems.

## Technical Notes
* Align requirements with future Metrics subsystem design.
* Preserve separation between analytics and visualization responsibilities.
* Use requirement identifiers consistently across all architecture artifacts.
* Ensure analytics workflows remain synchronized with deterministic simulation execution.
* Maintain compatibility with visualization and simulation subsystems.
---

US-2.1 — Create Cache Configuration Use Cases
Overview
Model cache-configuration behavior through formal use cases to support architecture-first system development, deterministic simulation setup workflows, and scalable cache-system orchestration within CacheScope.

These use cases establish the behavioral foundation for:
* cache-configuration workflows
* configuration validation
* simulation initialization
* subsystem synchronization
* future SSD development
* sequence-diagram modeling
* controller responsibility assignment
* GRASP analysis

User Story
As a computer architecture student, I want to configure cache simulation parameters before execution, so that I can experiment with different cache architectures and analyze their runtime behavior.

Scope
This user story covers:
* cache-configuration workflows
* configuration validation behavior
* actor/system interaction modeling
* configuration synchronization
* alternate execution flows
* failure scenarios
* preconditions and postconditions
* subsystem coordination

This user story does not yet cover:
* cache visualization rendering
* runtime metrics analytics
* distributed simulation systems
* advanced multi-level cache orchestration
* predictive configuration optimization

Actors
Actor	Description
User	Configures simulation parameters before runtime execution.
Configuration Controller	Coordinates cache-configuration workflows.
Cache Subsystem	Stores and applies validated cache parameters.
AddressMapper Subsystem	Recalculates address decomposition values after configuration changes.
Visualization Subsystem	Synchronizes configuration-dependent visualization updates.

Business Rules
ID	Rule
BR-01	Cache size must remain compatible with associativity and block size.
BR-02	Block size must be a power of two.
BR-03	Associativity must remain greater than zero.
BR-04	Replacement-policy selection must map to a supported strategy implementation.
BR-05	Configuration changes must synchronize dependent subsystems before simulation execution.

Use Cases
Use Case ID	Use Case
UC-2.1	Configure Cache
UC-2.2	Validate Cache Configuration
UC-2.3	Apply Cache Configuration

———

# UC-2.1 — Configure Cache
### Goal
Allow users to define simulation cache parameters before runtime execution.

### Primary Actor
User

### Supporting Actors
* Configuration Controller
* Cache Subsystem

### Trigger
User selects the cache-configuration interface.

### Preconditions
* CacheScope application is initialized.
* Simulation execution has not started.
* Configuration subsystem is available.

### Postconditions
#### Success:
* Valid configuration values are stored.
* Dependent subsystems synchronize configuration changes.

#### Failure
* Invalid configuration values are rejected.
* Existing valid configuration remains unchanged.

### Main Success Scenario
1. User opens cache-configuration interface.
2. System displays configurable cache parameters.
3. User enters cache size.
4. User enters associativity value.
5. User enters block size.
6. User selects replacement policy.
7. User submits configuration.
8. System validates configuration values.
9. System synchronizes dependent subsystems.
10. System stores updated configuration.
11. System confirms successful configuration.

### Alternate Flows
#### AF-01 — Partial Configuration Update
1. User modifies only one parameter.
2. System validates modified parameter.
3. System preserves unchanged configuration values.
4. System synchronizes affected subsystems only.

### Failure Flows
#### FF-01 — Invalid Cache Size
1. User enters unsupported cache size.
2. System rejects configuration.
3. System highlights invalid field.
4. System displays validation feedback.

#### FF-02 — Invalid Associativity
1. User enters invalid associativity value.
2. System rejects configuration
3. System highlights invalid field.
4. System displays validation feedback.
 
#### FF-03 — Invalid Block Size
1. User enters unsupported block size.
2. System rejects configuration.
3. System highlights invalid field.
5. System displays validation feedback.
 
####  FF-04 — Conflicting Parameters
1. User enters parameters where block size exceeds cache size.
2. System rejects configuration.
3. System displays error message explaining conflict.
4. System blocks simulation execution.
 
#### FF-05 — Empty Parameter Fields
1. User attempts simulation execution with blank configuration fields.
2. System prevents simulation start.
3. System highlights missing inputs.
4. System prompts user to complete setup.

---

# UC-2.2 — Validate Cache Configuration
## Overview
Validate cache configuration parameters before simulation execution to ensure configuration consistency, deterministic behavior, subsystem compatibility, and accurate cache modeling within CacheScope.

### This use case establishes the validation workflow for:
- cache size
- associativity
- block size
- replacement policies
- parameter compatibility
- subsystem synchronization readiness

### Goal
Ensure all cache configuration parameters are valid, compatible, and safe for simulation execution before the configuration is applied to the system.

### Primary Actor
Configuration Controller

### Supporting Actors
#### Actor	
Responsibility
#### User	
Provides cache configuration values.
#### Cache Subsystem	
Receives validated cache parameters.
#### AddressMapper Subsystem	
Uses configuration values for address decomposition calculations.
#### Visualization Subsystem	
Synchronizes configuration-dependent rendering behavior.

### Trigger
User submits cache configuration values through the configuration interface.

### Preconditions
1. CacheScope application is initialized.
2.  Configuration workflow is active.
3.  User has entered configuration values.
4.  Simulation execution has not started.

### Postconditions
#### Success
1. Configuration validity status is generated.
2. Valid configuration parameters are forwarded for application.
3. Dependent subsystems are cleared for synchronization.

### Failure
1. Invalid configuration is rejected.
2. Existing stable configuration remains unchanged.
3. Validation feedback is generated.

### Main Success Scenario
1. User submits cache configuration parameters.
2. System receives configuration request.
3. System validates cache size.
4. System validates associativity value.
5. System validates block size.
6. System validates replacement-policy selection.
7. System validates parameter compatibility.
8. System validates cache architecture constraints.
9. System confirms configuration validity.
10. System forwards validated configuration for application.
11. System generates successful validation feedback.

### Alternate Flows
#### AF-01 — Revalidation After Partial Update
1. User modifies only one configuration parameter.
2. System detects partial configuration update.
3. System validates only affected dependencies.
4. System preserves previously validated values.
5. System confirms successful revalidation.

#### AF-02 — Cached Validation State
1. System detects previously validated configuration.
2. System reuses cached validation results.
3. System skips redundant validation calculations.
4. System forwards cached validation status.

### Failure Flows
#### FF-01 — Invalid Cache Size
1. System detects unsupported cache size.
2. System rejects configuration.
3. System highlights invalid field.
4. System displays corrective feedback.

#### FF-02 — Invalid Associativity
1. System detects invalid associativity value.
2. System rejects configuration.
3. System generates compatibility feedback.

#### FF-03 — Invalid Block Size
1. System detects invalid block size.
2. System rejects configuration.
3. System displays validation guidance.

#### FF-04 — Unsupported Replacement Policy
1. System detects unsupported replacement-policy selection.
2. System rejects configuration.
3. System generates policy compatibility feedback.

#### FF-05 — Incompatible Configuration Combination
1. System detects incompatible parameter combination.
2. System terminates validation workflow.
3. System preserves previous valid configuration.
4. System displays dependency conflict feedback.

## Business Rules

| ID    | Rule                                                                          |
| :---  | :---                                                                          |
| BR-01 | Cache size must remain compatible with associativity and block size.          |
| BR-02 | Block size must be a power of two.                                            |
| BR-03 | Associativity must remain greater than zero.                                  |
| BR-04 | Replacement-policy selection must map to a supported strategy implementation. |
| BR-05 | Configuration values must remain deterministic across repeated simulations.   |
| BR-06 | Invalid configurations must not propagate into runtime simulation workflows.  |

## Validation Rules

| ID    | Rule                                                                     |
| :---  | :---                                                                     |
| VR-01 | Cache size must remain within supported numeric limits.                  |
| VR-02 | Associativity must not exceed cache-line constraints.                    |
| VR-03 | Block size must support deterministic address decomposition.             |
| VR-04 | Replacement-policy identifiers must map to implemented strategies.       |
| VR-05 | Configuration combinations must preserve cache architecture consistency. |

## Special Requirements
1. Validation workflows must remain deterministic.
2. Validation logic must remain independent from visualization rendering.
3. Validation feedback must remain understandable to beginner systems students.
4. Validation workflows should complete within 100ms under standard execution conditions.
5. Validation structures must support future extensibility for additional cache architectures.

## Assumptions

| ID   | Assumption                                                          |
| :--- | :---                                                                |
| A-01 | Users understand basic cache-configuration terminology.             |
| A-02 | Supported replacement policies are predefined by the system.        |
| A-03 | Configuration validation occurs before simulation execution begins. |

## Frequency of Use
High

### This workflow executes:
1. during initial simulation setup
2. during configuration changes
3. during architecture experimentation workflows

## Related Use Cases

| Use Case ID | Relationship                                              |
| :---        | :---                                                      |
| UC-2.1      | Configure Cache	Precedes validation workflow              |
| UC-2.3      | Apply Cache Configuration	Follows successful validation |
| UC-2.5      | Translate Address	Depends on valid cache configuration  |

#### Subsystem Interactions
Subsystem	Interaction

#### Configuration Controller	
Coordinates validation workflow execution.
#### Cache Subsystem	
Receives validated parameters.
#### AddressMapper Subsystem	
Uses validated parameters for decomposition calculations.
#### Visualization Subsystem	
Synchronizes visualization constraints with validated configuration.

## Traceability Mapping
### Related Requirement	Mapping

| CFR-01 | Cache-size validation                |
| :---   | :---                                 |
| CFR-02 | Associativity validation             |
| CFR-03 | Block-size validation                |
| CFR-04 | Replacement-policy validation        |
| CFR-05 | Configuration consistency validation |
| CFR-06 | Deterministic simulation preparation |

## Acceptance Criteria
1. Cache-size validation requirements are documented.
2. Associativity validation requirements are documented.
3. Block-size validation requirements are documented.
4. Replacement-policy validation requirements are documented.
5. Alternate flows are documented.
6. Failure flows are documented.
7. Validation rules are documented.
8. Business rules are documented.
9. Traceability mappings are established.
10. Use case supports future SSD and sequence-diagram generation.
11. Use case supports GRASP responsibility analysis.

## Technical Notes
- Align validation workflows with future ConfigurationController subsystem design.
- Preserve separation between validation logic and rendering logic.
- Ensure compatibility with Strategy Pattern–based replacement-policy implementations.
- Maintain deterministic validation behavior across repeated executions.

## Deliverables
- Cache-configuration validation specification
- Validation rules documentation
- Alternate and failure flow documentation
- Business-rule documentation
- Traceability mappings
- Foundational inputs for SSDs
- Foundational inputs for sequence diagrams
- Foundational inputs for GRASP analysis

---

# UC-2.3 — Apply Cache Configuration
## Overview
Apply validated cache configuration parameters to the simulation environment and synchronize all dependent subsystems to ensure deterministic cache behavior, accurate address decomposition, and consistent visualization throughout CacheScope.

### This use case establishes the workflow for:
- applying validated cache parameters
- initializing cache structures
- synchronizing dependent subsystems
- preparing the simulation environment
- maintaining configuration consistency
- ensuring deterministic execution

## Goal
Apply a validated cache configuration and propagate the configuration to all dependent subsystems before simulation execution begins.

## Primary Actor
Configuration Controller

## Supporting Actors

| Actor                    | Responsibility                                                                 |
| :---                     | :---                                                                           |
| Cache Subsystem          | Creates and initializes cache structures using validated configuration values. |
| AddressMapper Subsystem  | Updates address decomposition calculations based on cache parameters.          |
| Visualization  Subsystem | Updates cache-grid and address-visualization layouts.                          |
| Metrics Subsystem        | Resets analytics state for the new simulation session.                         |
| User                     | Initiates configuration application workflow.                                  |

## Trigger
A cache configuration has successfully passed validation (UC-2.2).

## Preconditions
1. UC-2.2 Validate Cache Configuration completed successfully.
2. Configuration parameters are valid.
3. Simulation execution has not started.
4. Required subsystems are available.

## Postconditions
### Success
* Cache structures are initialized.
* Address decomposition settings are updated.
* Visualization components are synchronized.
* Analytics state is initialized.
* System is ready to execute simulation requests.

### Failure
* Previous valid configuration remains active.
* Partial updates are rolled back.
* System remains in a consistent state.
* Error feedback is generated.

### Main Success Scenario
1. System receives validated cache configuration.
2. Configuration Controller initiates configuration-application workflow.
3. Cache Subsystem initializes cache structures.
4. Cache Subsystem allocates cache sets and cache lines.
5. Cache Subsystem initializes replacement-policy metadata.
6. AddressMapper Subsystem recalculates address decomposition rules.
7. Visualization Subsystem updates cache-grid representation.
8. Visualization Subsystem updates address-bit visualization layout.
9. Metrics Subsystem resets runtime analytics counters.
10. System performs synchronization checks.
11. System verifies subsystem readiness.
12. System marks configuration as active.
13. System confirms successful configuration application.
14. System transitions to “Ready for Simulation” state.

### Alternate Flows
AF-01 — Reconfigure Existing Simulation
1. User modifies configuration before simulation execution.
2. System detects existing configuration.
3. System clears previous configuration state.
4. System applies updated configuration.
5. System synchronizes all dependent subsystems.
6. System activates new configuration.

### AF-02 — Visualization Deferred Update
1. Visualization subsystem is temporarily unavailable.
2. System applies cache configuration.
3. System queues visualization synchronization request.
4. System maintains simulation readiness.
5. Visualization updates are performed when subsystem becomes available.

### AF-03 — Analytics Reset Only
1. Configuration values remain unchanged.
2. User requests simulation restart.
3. System reuses existing configuration.
4. Metrics subsystem resets counters.
5. Simulation returns to ready state.

### Failure Flows
FF-01 — Cache Initialization Failure
1. Cache Subsystem fails to initialize.
2. System terminates configuration workflow.
3. System rolls back changes.
4. System restores previous stable configuration.
5. Error feedback is generated.

### FF-02 — AddressMapper Synchronization Failure
1. AddressMapper fails to update decomposition settings.
2. System halts configuration application.
3. System rolls back subsystem updates.
4. System restores previous stable configuration.
5. User receives synchronization error.

### FF-03 — Visualization Synchronization Failure
1. Visualization subsystem fails to synchronize.
2. System logs synchronization error.
3. System preserves previous visualization state.
4. System determines whether simulation can continue safely.
5. User receives warning notification.

### FF-04 — Metrics Initialization Failure
1. Metrics subsystem fails to initialize.
2. System aborts configuration activation.
3. System restores previous stable state.
4. Error information is logged.
5. User receives failure notification.

### FF-05 — Partial Subsystem Update Failure
1. One or more subsystems fail during synchronization.
2. System detects inconsistent state.
3. Rollback process begins.
4. All modified subsystems revert to previous stable state.
5. System reports configuration failure.

## Business Rules

| ID    | Rule                                                                        |
| :---  | :---                                                                        |
| BR-01 | Only validated configurations may be applied.                               |
| BR-02 | Configuration application must be atomic.                                   |
| BR-03 | All dependent subsystems must remain synchronized.                          |
| BR-04 | Configuration updates must preserve deterministic simulation behavior.      |
| BR-05 | Failed updates must not leave the system in a partially configured state.   |
| BR-06 | Active simulation execution must not begin until synchronization completes. |

## Validation Rules

| ID    | Rule                                                                         |
| :---  | :---                                                                         |
| VR-01 | Configuration values must originate from a successful validation workflow.   |
| VR-02 | Cache structures must match configured cache parameters.                     |
| VR-03 | Address decomposition calculations must reflect active configuration values. |
| VR-04 | Visualization layouts must align with active cache architecture.             |
| VR-05 | Runtime analytics must reset when a new configuration becomes active.        |

## Special Requirements
* Configuration application must remain deterministic.
* Configuration synchronization must complete within 500ms under normal operating conditions.
* Rollback operations must restore the last known stable state.
* Subsystem synchronization must support future extensibility.
* Configuration workflows must remain independent from simulation execution logic.

## Assumptions

| ID   | Assumption                                                                  |
| :--- | :---                                                                        |
| A-01 | Configuration values have already passed validation.                        |
| A-02 | All required subsystems are available.                                      |
| A-03 | Simulation execution has not yet started.                                   |
| A-04 | Supported replacement policies have corresponding strategy implementations. |

## Frequency of Use
### High
This workflow occurs:
* during initial simulation setup
* during cache reconfiguration
* during architecture experimentation
* before every simulation session

## Related Use Cases

| Use Case ID                         | Relationship                                    |
| :---                                | :---                                            |
| UC-2.1 Configure Cache              | Initiates configuration workflow                |
| UC-2.2 Validate Cache Configuration | Must complete successfully first                |
| UC-2.4 Input Memory Address         | Depends on active configuration                 |
| UC-2.5 Translate Address            | Uses configuration-derived decomposition values |

## Subsystem Interactions

| Subsystem                | Interaction                                            |
| :---                     | :---                                                   |
| Configuration Controller | Coordinates configuration application workflow.        |
| Cache Subsystem          | Initializes cache structures and replacement metadata. |
| AddressMapper Subsystem  | Updates tag/index/offset calculations.                 |
| Visualization Subsystem  | Updates visual representations.                        |
| Metrics Subsystem        | Resets analytics state.                                |

## Traceability Mapping

| Related Requirement | Mapping                          |
| :---                | :---                             |
| CFR-01              | Cache-size application           |
| CFR-02              | Associativity application        |
| CFR-03              | Block-size application           |
| CFR-04              | Replacement-policy activation    |
| CFR-05              | Configuration synchronization    |
| CFR-06              | Simulation readiness preparation |

## Acceptance Criteria
* Cache configuration is successfully applied after validation.
* Cache structures are initialized correctly.
* AddressMapper synchronization is completed.
* Visualization synchronization is completed.
* Metrics initialization is completed.
* Rollback behavior is documented and supported.
* Alternate flows are documented.
* Failure flows are documented.
* Business rules are documented.
* Traceability mappings are established.
* Use case supports future SSD development.
* Use case supports sequence-diagram generation.
* Use case supports GRASP responsibility analysis.

## Technical Notes
* Align workflow with future ConfigurationController implementation.
* Apply GRASP Controller principles when assigning responsibilities.
* Preserve low coupling between configuration and simulation execution subsystems.
* Use Strategy Pattern implementations for replacement-policy activation.
* Treat configuration application as a transaction-like operation to support rollback and consistency.

## Deliverables
* Configuration application specification
* Subsystem synchronization workflow documentation
* Rollback strategy documentation
* Alternate-flow documentation
* Failure-flow documentation
* Traceability mappings
* SSD inputs
* Sequence-diagram inputs
* GRASP-analysis inputs
* Future implementation guidance for ConfigurationController and subsystem orchestration

# UC-2.4 — Input Memory Address

## Overview
Allow users to submit memory addresses for analysis and cache simulation. This use case serves as the entry point into the address-processing workflow and ensures that submitted addresses are properly formatted, validated, and prepared for translation and cache lookup operations.

This use case establishes the workflow for:
- imemory-address submission
- address-format validation
- input sanitization
- error handling
- address-processing initiation
- preparation for address translation

## Goal
Allow a user to submit a memory address that can be safely processed, translated, and evaluated by the cache simulation system.

## Primary Actor
User

## Supporting Actors

| Actor                         | Responsibility                                     |
| :---                          | :---                                               |
| Address Processing Controller | Coordinates address-input workflow.                |
| AddressMapper Subsystem       | Receives validated addresses for decomposition.    |
| Visualization Subsystem       | Updates UI to reflect submitted address.           |
| Cache Subsystem               | Receives translated address data for cache lookup. |

## Trigger
User enters a memory address and submits it for analysis.

## Preconditions
- CacheScope application is running.
- A valid cache configuration has been applied (UC-2.3).
- Address-input interface is available.
- Simulation environment is initialized.

## Postconditions
### Success
- Address is accepted by the system.
- Address is sanitized and validated.
- Address is forwarded for translation.
- Address-processing workflow begins.

### Failure
- Invalid address is rejected.
- Translation workflow does not begin.
- Error feedback is displayed.
- System remains in a stable state.

### Main Success Scenario
1. User navigates to the address-input interface.
2. System displays address-entry controls.
3. User enters a memory address.
4. User submits the address.
5. System receives the address.
6. System sanitizes input.
7. System validates address format.
8. System verifies address length constraints.
9. System accepts the address.
10. System stores the submitted address.
11. System forwards the address to the translation workflow.
12. System confirms successful submission.

### Alternate Flows
#### AF-01 — Paste Address
1. User pastes an address from clipboard.
2. System sanitizes pasted input.
3. System validates address format.
4. Workflow continues with Main Success Scenario Step 8.

#### AF-02 — Reuse Previously Submitted Address
1. User selects a previously submitted address.
2. System loads address into input field.
3. User submits address.
4. Workflow continues with Main Success Scenario Step 5.

#### AF-03 — Batch Demonstration Mode (Future Enhancement)
1. User selects multiple addresses.
2. System queues addresses.
3. System processes addresses sequentially.
4. Results are displayed individually.

### Failure Flows
#### FF-01 — Empty Input
1. User submits an empty field.
2. System rejects request.
3. System displays validation message.
4. Workflow terminates.

#### FF-02 — Invalid Hexadecimal Format
1. User submits malformed hexadecimal address.
2. System detects invalid characters.
3. System rejects input.
4. System displays corrective guidance.

Example invalid values:
```txt
0xGH12
12XYZ
0x123G
```
#### FF-03 — Unsupported Address Length
1. User submits address exceeding supported length.
2. System rejects address.
3. System displays compatibility message.
4. Workflow terminates.

#### FF-04 — Configuration Not Initialized
1. User submits address before cache configuration exists.
2. System blocks address processing.
3. System requests cache configuration.
4. Workflow terminates.

#### FF-05 — Internal Processing Failure
1. System encounters unexpected processing error.
2. Address submission fails.
3. Error is logged.
4. User receives failure notification.
5. System remains operational.

## Business Rules

| ID    | Rule                                                              |
| :---  | :---                                                              |
| BR-01 | Memory addresses must be entered in supported hexadecimal format. |
| BR-02 | Addresses must satisfy configured address-width constraints.      |
| BR-03 | Invalid addresses must never enter translation workflows.         |
| BR-04 | Submitted addresses must remain unchanged during processing.      |
| BR-05 | Address input must remain independent from cache-lookup logic.    |

## Validation Rules

| ID    | Rule                                                    |
| :---  | :---                                                    |
| VR-01 | Address field cannot be empty.                          |
| VR-02 | Address must contain valid hexadecimal characters only. |
| VR-03 | Address must conform to supported address-width limits. |
| VR-04 | Leading and trailing whitespace must be removed.        |
| VR-05 | Address must be normalized before translation begins.   |

## Input Data

| Field          | Description                                |
| :---           | :---                                       |
| Memory Address | Hexadecimal address submitted by the user. |

## Output Data

| Output              | Description                                |
| :---                | :---                                       |
| Validated Address   | Sanitized address ready for translation.   |
| Validation Feedback | Information describing validation results. |

## Special Requirements
* Address validation should complete within 100ms.
* Validation feedback must be educational and beginner-friendly.
* Address input workflow must remain deterministic.
* Input handling must remain independent from cache-resolution logic.
* Future address formats should be extensible without major redesign.

## Assumptions

| ID   | Assumption                                                  |
| :--- | :---                                                        |
| A-01 | User understands basic hexadecimal notation.                |
| A-02 | Cache configuration already exists.                         |
| A-03 | Address-processing subsystem is operational.                |
| A-04 | Supported address width is defined by system configuration. |

## Frequency of Use
Very High
This use case executes:
* every simulation request
* every address analysis request
* every cache lookup operation
* every educational visualization workflow

## Related Use Cases

| Use Case ID                         | Relationship                            |
| :---                                | :---                                    |
| UC-2.1 Configure Cache              | Must occur before address processing.   |
| UC-2.2 Validate Cache Configuration | Must complete successfully first.       |
| UC-2.3 Apply Cache Configuration    | Establishes active cache configuration. |
| UC-2.5 Translate Address            | Follows successful address submission.  |
| UC-2.6 Visualize Address Bits       | Uses translated address data.           |

## Subsystem Interactions

| Subsystem                     | Interaction                                                |
| :---                          | :---                                                       |
| Address Processing Controller | Coordinates address-input workflow.                        |
| AddressMapper Subsystem       | Receives validated address.                                |
| Visualization Subsystem       | Displays address-processing feedback.                      |
| Cache Subsystem               | Receives translated address information later in workflow. |

## Traceability Mapping

| Related Requirement | Mapping                        |
| :---                | :---                           |
| CFR-07              | Address-input support          |
| CFR-08              | Hexadecimal address validation |
| CFR-09              | Invalid-input handling         |
| CFR-10              | Address-processing initiation  |
| CFR-11              | User feedback generation       |

## Acceptance Criteria
* Users can enter hexadecimal memory addresses.
* Invalid addresses are rejected.
* Valid addresses are accepted.
* Validation feedback is displayed.
* Alternate flows are documented.
* Failure flows are documented.
* Business rules are documented.
* Validation rules are documented.
* Addresses are forwarded to translation workflow.
* Use case supports future SSD creation.
* Use case supports sequence-diagram generation.
* Use case supports GRASP responsibility analysis.

## Technical Notes
* Align workflow with future AddressProcessingController.
* Preserve separation between input handling and translation logic.
* Follow GRASP Controller principles.
* Ensure low coupling between UI and backend processing.
* Design for future support of additional address formats.

## Deliverables
* Address-input use case specification
* Validation workflow documentation
* Alternate-flow documentation
* Failure-flow documentation
* Business-rule documentation
* Validation-rule documentation
* Traceability mappings
* SSD inputs
* Sequence-diagram inputs
* GRASP-analysis inputs
* Future implementation guidance for AddressProcessingController and address-processing workflows

---

# UC-2.5 — Translate Address
## Overview
Translate a validated memory address into its constituent cache-address components (tag, index, and block offset) based on the active cache configuration. This use case forms the core of the address-mapping subsystem and provides the information required for cache lookup, visualization, hit/miss determination, and replacement-policy execution.

This use case establishes the workflow for:
* hexadecimal-to-binary conversion
* address decomposition
* tag extraction
* index extraction
* offset extraction
* cache mapping preparation
* visualization data generation
* cache-resolution preparation

## Goal
Convert a validated memory address into tag, index, and offset components according to the active cache configuration.

## Primary Actor
Address Processing Controller

## Supporting Actors
| Actor                   | Responsibility                                           |
| :---                    | :---                                                     |
| AddressMapper Subsystem | Performs address decomposition calculations.             |
| Cache Subsystem         | Uses translated values for cache lookup.                 |
| Visualization Subsystem | Displays translated address components.                  |
| User                    | Initiates address processing through address submission. |

## Trigger
A valid memory address is received from UC-2.4 Input Memory Address.

## Preconditions
* UC-2.4 Input Memory Address completed successfully.
* UC-2.3 Apply Cache Configuration completed successfully.
* Active cache configuration exists.
* Address value has passed validation.
* AddressMapper subsystem is available.

## Postconditions
### Success
* Address is translated into binary representation.
* Tag bits are identified.
* Index bits are identified.
* Offset bits are identified.
* Translation results are stored.
* Results are forwarded to cache lookup and visualization workflows.

### Failure
* Translation process terminates safely.
* Invalid translation results are discarded.
* System remains in a stable state.
* Error feedback is generated.

### Main Success Scenario
1. System receives validated memory address.
2. System retrieves active cache configuration.
3. System converts hexadecimal address into binary format.
4. System calculates block-offset bit count.
5. System calculates cache-index bit count.
6. System calculates tag bit count.
7. System partitions binary address.
8. System extracts tag bits.
9. System extracts index bits.
10. System extracts offset bits.
11. System generates translation result object.
12. System stores translation results.
13. System forwards results to cache-resolution workflow.
14. System forwards results to visualization workflow.
15. System confirms successful translation.

### Alternate Flows
#### AF-01 — Cached Translation Result
1. System detects previously translated address.
2. System verifies cache configuration has not changed.
3. System retrieves cached translation result.
4. System skips recalculation.
5. Workflow continues at Step 12.

#### AF-02 — Direct Educational Mode
1. User enables educational mode.
2. System performs standard translation.
3. System generates intermediate calculations.
4. System displays decomposition process.
5. Workflow continues normally.

#### AF-03 — Step-by-Step Visualization Mode
1. User selects detailed visualization mode.
2. System performs translation incrementally.
3. System displays each decomposition stage.
4. Workflow continues normally.

### Failure Flows
#### FF-01 — Missing Cache Configuration
1. System requests active cache configuration.
2. Configuration is unavailable.
3. Translation workflow terminates.
4. User receives configuration error.

#### FF-02 — Invalid Bit Allocation
1. System calculates decomposition values.
2. Tag, index, and offset allocation is invalid.
3. Translation is rejected.
4. Error is logged.
5. User receives feedback.

#### FF-03 — Address Width Mismatch
1. Address width differs from expected architecture width.
2. Translation fails.
3. Address is discarded.
4. Workflow terminates.

#### FF-04 — Binary Conversion Failure
1. System attempts address conversion.
2. Conversion process fails.
3. Translation terminates.
4. Error is logged.
5. User receives notification.

#### FF-05 — Internal AddressMapper Failure
1. AddressMapper encounters unexpected error.
2. Translation process aborts.
3. Error information is logged.
4. System preserves stable state.
5. User receives failure notification.

## Business Rules

| ID    | Rule                                                                       |
| :---  | :---                                                                       |
| BR-01 | Translation must use the active cache configuration.                       |
| BR-02 | Address decomposition must be deterministic.                               |
| BR-03 | Tag, index, and offset calculations must be mathematically correct.        |
| BR-04 | Translation results must remain immutable during lookup processing.        |
| BR-05 | Invalid decomposition results must never reach cache-resolution workflows. |

## Validation Rules

| ID    | Rule                                                              |
| :---  | :---                                                              |
| VR-01 | Active cache configuration must exist.                            |
| VR-02 | Address must already be validated.                                |
| VR-03 | Bit allocations must sum to total address width.                  |
| VR-04 | Address decomposition must produce valid tag/index/offset values. |
| VR-05 | Translation output must match cache-architecture constraints.     |

## Mathematical Rules
### Offset Bits
The number of offset bits is determined by:

#### Number of Cache Sets
The number of sets is determined by:

$$ \text{Sets} = \frac{\text{Cache Size}}{\text{Block Size} \times \text{Associativity}} $$

#### Index Bits
The number of index bits is determined by:

#### Tag Bits
$$ \text{Tag Bits} = \text{Address Bits} - \text{Index Bits} - \text{Offset Bits} $$

## Input Data

| Input          | Description                          |
| :---           | :---                                 |
| Memory Address | Validated hexadecimal memory address |
| Cache Size     | Active cache size                    |
| Associativity  | Active associativity value           |
| Block Size     | Active block size                    |

## Output Data

| Output             | Description                      |
| :---               | :---                             |
| Binary Address     | Binary representation of address |
| Tag Value          | Tag portion of address           |
| Index Value        | Cache-set identifier             |
| Offset Value       | Block-offset identifier          |
| Translation Result | Complete decomposition object    |

## Special Requirements
* Translation must complete within 100ms under normal operating conditions.
* Translation results must remain deterministic across repeated executions.
* Address decomposition logic must remain independent from visualization rendering.
* Translation workflows must support future cache architectures.
* Mathematical calculations must remain implementation-independent.

## Assumptions
| ID   | Assumption                                              |
| :--- | :---                                                    |
| A-01 | Address has already passed validation.                  |
| A-02 | Cache configuration is active.                          |
| A-03 | AddressMapper subsystem is available.                   |
| A-04 | Supported cache architecture constraints are satisfied. |

## Frequency of Use
Very High
This use case executes:
* for every submitted memory address
* for every cache lookup
* for every visualization update
* for every simulation execution cycle

## Related Use Cases

| Use Case ID                   | Relationship                  |
| :---                          | :---                          |
| UC-2.4 Input Memory Address   | Precedes translation workflow |
| UC-2.6 Visualize Address Bits | Consumes translation output   |
| UC-2.7 Search Cache Set       | Uses translated index value   |
| UC-2.8 Detect Cache Hit       | Uses translation results      |
| UC-2.9 Detect Cache Miss      | Uses translation results      |

## Subsystem Interactions

| Subsystem                     | Interaction                                |
| :---                          | :---                                       |
| Address Processing Controller | Coordinates translation workflow.          |
| AddressMapper Subsystem       | Performs decomposition calculations.       |
| Cache Subsystem               | Receives tag/index/offset values.          |
| Visualization Subsystem       | Displays translated address information. |

## Traceability Mapping

| Related Requirement | Mapping                       |
| :---                | :---                          |
| CFR-12              | Address translation           |
| CFR-13              | Binary conversion             |
| CFR-14              | Tag extraction                |
| CFR-15              | Index extraction              |
| CFR-16              | Offset extraction             |
| CFR-17              | Translation-result generation |

## Acceptance Criteria
* Hexadecimal addresses are translated successfully.
* Binary conversion is documented.
* Tag extraction is documented.
* Index extraction is documented.
* Offset extraction is documented.
* Alternate flows are documented.
* Failure flows are documented.
* Mathematical rules are documented.
* Traceability mappings are established.
* Translation output supports cache-resolution workflows.
* Use case supports SSD creation.
* Use case supports sequence-diagram generation.
* Use case supports GRASP responsibility analysis.

## Technical Notes
* Align workflow with future AddressMapper implementation.
* Preserve separation between translation and visualization responsibilities.
* Follow GRASP Information Expert principles for address decomposition.
* Maintain low coupling between translation and cache-resolution logic.
* Design for future support of multi-level cache architectures.

## Deliverables
* Address-translation use case specification
* Address decomposition workflow documentation
* Mathematical decomposition rules
* Alternate-flow documentation
* Failure-flow documentation
* Business-rule documentation
* Validation-rule documentation
* Traceability mappings
* SSD inputs
* Sequence-diagram inputs
* GRASP-analysis inputs
* Future implementation guidance for AddressMapper subsystem

---

# UC-2.6 — Visualize Address Bits

## Overview
Visualize the binary representation of a translated memory address by clearly displaying the tag, index, and offset fields. This use case supports CacheScope's educational objectives by helping users understand how memory addresses are mapped into cache structures and how cache configuration parameters influence address decomposition.

This use case establishes the workflow for:
* binary address visualization
* tag-bit highlighting
* index-bit highlighting
* offset-bit highlighting
* cache-mapping education
* simulation feedback
* address-analysis presentation

## Goal
Present a translated memory address in a visual format that clearly identifies the tag, index, and offset portions used during cache mapping.

## Primary Actor
User

## Supporting Actors

| Actor                    | Responsibility                                    |
| :---                     | :---                                              |
| Visualization Controller | Coordinates rendering workflows.                  |
| AddressMapper Subsystem  | Provides address decomposition results.           |
| Visualization Subsystem  | Renders visual representations of address fields. |
| Cache Subsystem          | Provides cache-context information when required. |

## Trigger
Address translation completes successfully in UC-2.5 Translate Address.

## Preconditions
* UC-2.5 Translate Address completed successfully.
* Binary address representation exists.
* Tag, index, and offset values have been calculated.
* Visualization subsystem is available.
* Active cache configuration exists.

## Postconditions
### Success
* Binary address is displayed.
* Tag bits are highlighted.
* Index bits are highlighted.
* Offset bits are highlighted.
* User can identify cache-mapping boundaries.

### Failure
* Visualization is not updated.
* Previous stable visualization remains visible.
* Error feedback is generated.
* System remains operational.

### Main Success Scenario
1. System receives translated address information.
2. System retrieves binary address representation.
3. System retrieves tag boundaries.
4. System retrieves index boundaries.
5. System retrieves offset boundaries.
6. Visualization Controller initiates rendering workflow.
7. System displays binary address.
8. System highlights tag-bit region.
9. System highlights index-bit region.
10. System highlights offset-bit region.
11. System labels each address section.
12. System displays calculated values.
13. System updates visualization panel.
14. User reviews visualization.
15. System confirms successful rendering.

### Alternate Flows
#### AF-01 — Educational Walkthrough Mode
1. User enables educational mode.
2. System displays decomposition step-by-step.
3. System explains tag extraction.
4. System explains index extraction.
5. System explains offset extraction.
6. Visualization completes.

#### AF-02 — Compact Display Mode
1. User enables compact visualization.
2. System reduces visual spacing.
3. System preserves field boundaries.
4. Visualization completes.

#### AF-03 — Address Comparison Mode (Future Enhancement)
1. User selects multiple translated addresses.
2. System displays addresses side-by-side.
3. System highlights decomposition differences.
4. Visualization completes.

#### Failure Flows
FF-01 — Missing Translation Data
1. Visualization workflow begins.
2. Translation data cannot be located.
3. Rendering process terminates.
4. User receives error message.

#### FF-02 — Rendering Failure
1. Visualization subsystem encounters rendering error.
2. Rendering process aborts.
3. Previous stable visualization remains visible.
4. Error is logged.

#### FF-03 — Invalid Boundary Information
1. Visualization receives invalid decomposition boundaries.
2. Rendering is cancelled.
3. System reports inconsistency.
4. User receives feedback.

#### FF-04 — Visualization Subsystem Unavailable
1. Rendering request is initiated.
2. Visualization subsystem is unavailable.
3. Request is queued.
4. User receives notification.

## Business Rules

| ID    | Rule                                                                       |
| :---  | :---                                                                       |
| BR-01 | Visualization must reflect the active cache configuration.                 |
| BR-02 | Tag, index, and offset boundaries must be mathematically accurate.         |
| BR-03 | Visualization must remain synchronized with translation results.           |
| BR-04 | Address visualization must remain independent from cache-resolution logic. |
| BR-05 | Visual representations must preserve decomposition accuracy.               |

## Validation Rules

| ID    | Rule                                                                |
| :---  | :---                                                                |
| VR-01 | Translation data must exist before rendering begins.                |
| VR-02 | Bit boundaries must be valid.                                       |
| VR-03 | Total displayed bits must equal address width.                      |
| VR-04 | Visualization labels must match translated values.                  |
| VR-05 | Rendered output must remain synchronized with active configuration. |

## Visualization Model
Example decomposition:

Address: 0xABCD1234

Binary:
10101011110011010001001000110100

| ------- Tag ------- | --- Index --- | - Offset - |
| :---                | :---          | :---       |
| 1010101111001101000 | 10010         | 00110100   |

The exact field lengths are determined by the active cache configuration and UC-2.5 translation calculations.

## Input Data

| Input               | Description                                  |
| :---                | :---                                         |
| Binary Address      | Binary representation of submitted address   |
| Tag Value           | Tag field extracted during translation       |
| Index Value         | Cache-set index extracted during translation |
| Offset Value        | Block offset extracted during translation    |
| Cache Configuration | Active cache parameters                      |

## Output Data

| Output                    | Description                    |
| :---                      | :---                           |
| Address Visualization     | Rendered binary address        |
| Highlighted Tag Region    | Visual tag field               |
| Highlighted Index Region  | Visual index field             |
| Highlighted Offset Region | Visual offset field            |
| Address Mapping View      | Complete decomposition display |

## Special Requirements
* Visualization updates should complete within 100ms.
* Field boundaries must remain visually distinguishable.
* Visualization must remain responsive across screen sizes.
* Rendering logic must remain separate from simulation logic.
* Visual output should support educational usage.
* Future visualization enhancements should not require changes to translation logic.

## Assumptions

| ID   | Assumption                                              |
| :--- | :---                                                    |
| A-01 | Address translation completed successfully.             |
| A-02 | Binary address representation exists.                   |
| A-03 | Visualization subsystem is operational.                 |
| A-04 | Cache configuration remains unchanged during rendering. |

## Frequency of Use
Very High

This use case executes:
* after every address translation
* during educational demonstrations
* during cache-analysis workflows
* during simulation visualization updates

## Related Use Cases

| Use Case ID                 | Relationship                           |
| :---                        | :---                                   |
| UC-2.4 Input Memory Address | Originates address-processing workflow |
| UC-2.5 Translate Address    | Provides decomposition data            |
| UC-2.7 Search Cache Set     | Uses displayed index information       |
| UC-2.10 Update Cache State  | May trigger visualization refreshes    |

## Subsystem Interactions

| Subsystem                | Interaction                                        |
| :---                     | :---                                               |
| Visualization Controller | Coordinates rendering workflow.                    |
| AddressMapper Subsystem  | Supplies decomposition results.                    |
| Visualization Subsystem  | Produces rendered output.                          |
| Cache Subsystem          | Supplies contextual cache information when needed. |

## Traceability Mapping

| Related Requirement | Mapping                       |
| :---                | :---                          |
| CFR-18              | Binary address visualization  |
| CFR-19              | Tag-field visualization       |
| CFR-20              | Index-field visualization     |
| CFR-21              | Offset-field visualization    |
| CFR-22              | Visualization synchronization |
| CFR-23              | Educational rendering support |

## Acceptance Criteria
* Binary address is displayed.
* Tag region is highlighted.
* Index region is highlighted.
* Offset region is highlighted.
* Field labels are displayed.
* Alternate flows are documented.
* Failure flows are documented.
* Visualization rules are documented.
* Traceability mappings are established.
* Visualization accurately reflects translation results.
* Use case supports SSD generation.
* Use case supports sequence-diagram generation.
* Use case supports GRASP responsibility analysis.

## Technical Notes
* Align workflow with future VisualizationController implementation.
* Apply GRASP Controller principles for rendering coordination.
* Apply Information Expert principles by keeping decomposition logic within AddressMapper.
* Preserve low coupling between visualization and simulation subsystems.
* Support future enhancements such as animation, side-by-side comparisons, and multi-level cache visualizations.

## Deliverables
* Address-visualization use case specification
* Rendering workflow documentation
* Visualization rules documentation
* Alternate-flow documentation
* Failure-flow documentation
* Traceability mappings
* SSD inputs
* Sequence-diagram inputs
* GRASP-analysis inputs
* Future implementation guidance for VisualizationController and visualization subsystem design

---

# US-2.3 — Create Cache Resolution Use Cases
## Overview
Model cache-search, cache-hit detection, cache-miss detection, and cache-state update workflows to formally define how CacheScope determines whether a memory address exists within the cache and how the cache responds to lookup operations.

This user story establishes the behavioral foundation for:
* cache lookup operations
* cache-set selection
* tag comparison
* hit detection
* miss detection
* cache-line allocation
* replacement-policy execution
* cache-state updates
* simulation correctness
* future SSD development
* sequence-diagram modeling
* GRASP responsibility analysis

## User Story
As a computer architecture student,
I want CacheScope to determine whether a memory address results in a cache hit or cache miss,
so that I can understand cache behavior, replacement policies, and memory-access performance.

## Scope
This user story covers:
* cache-set lookup
* tag comparison
* cache-hit determination
* cache-miss determination
* cache-state updates
* replacement-policy invocation
* alternate execution paths
* failure scenarios
* subsystem interactions

### This user story does not cover:
* cache visualization rendering
* runtime metrics analytics
* multi-level cache hierarchies
* coherence protocols
* prefetching mechanisms
* speculative execution

## Actors

| Actor                       | Description                              |
| :---                        | :---                                     |
| User                        | Submits memory addresses for analysis.   |
| Cache Resolution Controller | Coordinates cache lookup workflows.      |
| Cache Subsystem             | Stores cache sets and cache lines.       |
| CacheSet                    | Performs set-level searches.             |
| Replacement Policy          | Determines eviction candidates.          |
| AddressMapper               | Provides translated address information. |

## Business Rules

| ID    | Rule                                                                    |
| :---  | :---                                                                    |
| BR-01 | Cache lookup must occur within the set identified by the address index. |
| BR-02 | Cache hits require matching valid tag values.                           |
| BR-03 | Cache misses must trigger cache-state updates.                          |
| BR-04 | Replacement policies must determine eviction behavior.                  |
| BR-05 | Cache-state updates must preserve simulation consistency.               |
| BR-06 | Lookup results must remain deterministic.                               |

## Use Cases

| Use Case ID | Use Case           |
| :---        | :---               |
| UC-2.7      | Search Cache Set   |
| UC-2.8      | Detect Cache Hit   |
| UC-2.9      | Detect Cache Miss  |
| UC-2.10     | Update Cache State |

## Traceability Mapping

| Use Case                   | Related Requirements               |
| :---                       | :---                               |
| UC-2.7 Search Cache Set    | CFR-24, CFR-25                     |
| UC-2.8 Detect Cache Hit    | CFR-26, CFR-27                     |
| UC-2.9                     | Detect Cache Miss	CFR-28, CFR-29 |
| UC-2.10 Update Cache State | CFR-30, CFR-31                     |

## Acceptance Criteria
* Cache-resolution use cases are documented.
* Main success scenarios are documented.
* Alternate execution paths are documented.
* Failure scenarios are documented.
* Business rules are documented.
* Actor/system responsibilities are clearly separated.
* Traceability mappings are established.
* Use cases support SSD generation.
* Use cases support sequence-diagram generation.
* Use cases support GRASP responsibility analysis.

## Technical Notes
* Align workflows with Cache, CacheSet, CacheLine, and ReplacementPolicy subsystems.
* Preserve separation between cache-resolution logic and visualization logic.
* Maintain deterministic simulation behavior.
* Use these workflows as the foundation for SSDs, sequence diagrams, and design-class diagrams.

## Deliverables
* Cache-resolution use-case specifications
* Alternate-flow documentation
* Failure-flow documentation
* Business-rule documentation
* Traceability mappings
* SSD inputs
* Sequence-diagram inputs
* GRASP-analysis inputs
* Future implementation guidance

---

# UC-2.7 — Search Cache Set
## Goal
Locate the cache set corresponding to the translated address and determine whether a matching cache line exists.

## Primary Actor
Cache Resolution Controller

## Trigger
A translated address becomes available from UC-2.5.

## Main Success Scenario
1. System receives translated address.
2. System extracts index value.
3. System locates corresponding cache set.
4. System retrieves cache lines within the set.
5. System forwards lines for tag comparison.
6. System completes cache-set search.

## Alternate Flows
### AF-01 — Empty Cache Set
* Cache set contains no valid lines.
* Workflow proceeds to UC-2.9 Detect Cache Miss.

## Failure Flows
### FF-01 — Invalid Set Index
* System detects invalid index.
* Search terminates.
* Error is logged.

## Related Use Cases
* UC-2.5 Translate Address
* UC-2.8 Detect Cache Hit
* UC-2.9 Detect Cache Miss

---

# UC-2.7 — Search Cache Set
## Goal
Locate the cache set corresponding to the translated address and determine whether a matching cache line exists.

## Primary Actor
Cache Resolution Controller

## Trigger
A translated address becomes available from UC-2.5.

## Main Success Scenario
1. System receives translated address.
2. System extracts index value.
3. System locates corresponding cache set.
4. System retrieves cache lines within the set.
5. System forwards lines for tag comparison.
6. System completes cache-set search.

## Alternate Flows
### AF-01 — Empty Cache Set
* Cache set contains no valid lines.
* Workflow proceeds to UC-2.9 Detect Cache Miss.

## Failure Flows
### FF-01 — Invalid Set Index
* System detects invalid index.
* Search terminates.
* Error is logged.

## Related Use Cases
* UC-2.5 Translate Address
* UC-2.8 Detect Cache Hit
* UC-2.9 Detect Cache Miss

---

# UC-2.8 — Detect Cache Hit
## Goal
Determine whether a cache line exists whose tag matches the translated address tag.

## Primary Actor
Cache Resolution Controller

## Trigger
Cache-set search completes successfully.

## Main Success Scenario
1. System receives candidate cache lines.
2. System compares line tags against address tag.
3. System identifies matching valid line.
4. System classifies lookup as cache hit.
5. System records hit result.
6. System invokes cache-state update workflow.
7. System reports hit outcome.

## Alternate Flows
### AF-01 — Multiple Tag Comparisons
* Multiple lines are inspected before a match is found.
* Workflow continues normally.

## Failure Flows
### FF-01 — Corrupted Tag Metadata
* Tag comparison cannot be completed.
* Lookup terminates.
* Error is generated.

## Business Rules
* Matching tag and valid bit are required.
* Hit classification must be deterministic.

## Related Use Cases
* UC-2.7 Search Cache Set
* UC-2.10 Update Cache State

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
