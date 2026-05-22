## Non-Functional Requirements

| Requirements            |
| :---:                   |
| ID                      | Core Funcitonal Requirements                                      | ID       | Low Level Core Requirements                                             |
| :---:                   |
| Cache Access Simulation |
| CFR-1                   | The system shall simulate cache memory access                     | CLFR-1.1 | The system shall process sequential memory access requests              |
| :---                    |
|                         |                                                                   | CLFR-1.2 | The system shall update cache state after each access                   |
| :---                    |
|                         |                                                                   | CLFR-1.3 | The system shall maintain deterministic simulation execution            |
| :---:                   |
| Cache Configuration     |
| CFR-2                   | The system shall support configurable cache parameters            | CLFR-2.1 | The system shall support configurable cache sizes                       |
| :---                    |
|                         |                                                                   | CLFR-2.2 | The system shall support configurable block sizes                       |
| :---                    |
|                         |                                                                   | CLFR-2.3 | The system shall support configurable associativity levels              |
| Address Translation     |
| CFR-3                   | The system shall determin ache hits and cache misses              | CLFR-3.1 | The system shall accept hexacecimal memory addresses                    |
| :---                    |
|                         |                                                                   | CLFR-3.2 | The system shall decompose addresses into tag, index, and offset fields |
| :---                    |
|                         |                                                                   | CLFR-3.3 | The system shall visualize binary address decomposition                 |
| Hit/Miss Resolution     |
| CFR-4                   | The system shall apply cache replacement policies during eviction | CLFR-4.1 | The system shall search cache sets for matching tags                    |
| :---                    |
|                         |                                                                   | CLFR-4.2 | The system shall shall classify accesses as hits or misses              |
| :---                    |
|                         |                                                                   | CLFR-4.3 | The system shall shall update cache metadata after each access          |
| Replacement Policies    |
| CFR-3                   | The system shall                                                  | CLFR-5.1 | The system shall support Least Recently Used (LRU) eviction             |
| :---                    |
|                         |                                                                   | CLFR-5.2 | The system shall support First-In First-Out (FIFO) eviction             |
| :---                    |
|                         |                                                                   | CLFR-5.3 | The system shall replace cache lines during misses when sets are full   |
| Cache Visualization     |
| CFR-6                   | The system shall visually render cache state changes              | CLFR-6.1 | The system shall render cache-line states visually                      |
| :---                    |
|                         |                                                                   | CLFR-6.2 | The system shall highligt cache hits and misses                         |
| :---                    |
|                         |                                                                   | CLFR-6.3 | The system shall animate cache evictions                                |
| Cache Analytics         |
| CFR-7                   | The system shall display cache analytics in real time             | CLFR-7.1 | The system shall calculate cache hit rates                              |
| :---                    |
|                         |                                                                   | CLFR-7.2 | The system shall calculate cache miss rates                             |
| :---                    |
|                         |                                                                   | CLFR-7.3 | The system shall display real-time simulation metrics                   |










