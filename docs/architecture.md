# Functional Rquirements
--

## FR-1: Simulate Memory Accesses
The system shall simulate read/write to memory addresses.

## FR-2: Support Multiple Cache Types
The simulator shall support: 
- Direct-mapped cache
- Set-associative cache
- Fully associative cache.

## FR-3: Configureable Cache Parameters
Users shall configure: 
- Cache size
- block size
- Associativity
- Replacement policy

## FR-4: Replacement Policies
The system shall support:
- LRU
- FIFO
- Random replacement.

## FR-5: Hit/Miss Detection
The simulator shall determine:
- Cache hits,
- Cache misses,
- Compulsory misses,
- Conflict misses,
- Capacity misses (advanced).

## FR-6: Performance Metrics
The system shall display:
- Hit rate,
- Miss rate,
- Total accesses,
- Average access time,
- Eviction count.

## FR-7: Step-by-Step Visualization
Users shall visualize:
- Block placement,
- Evictions,
- Address mapping,
- Cache state transitions.

## FR-8: Import Memory Traces
Users shall upload:
- Text trace files,
- Address sequences.

## FR-9: Reset Simulation
Users shall reset cache state and rerun simulations.

## FR-10: Export Results
Users shall export:
- Metrics,
- Logs,
- Simulation summaries.

--

# Non-Functional Requirements:
## 1. Performance
### NFR-1
The simulator should process large traces efficiently.
Target:

100,000+ accesses with low latency


## 2. Scalability
### NFR-2
The architecture should allow new:
- Cache policies,
- Memory hierarchies,
- Visualization modules without major rewrites.

## 3. Maintainability
### NFR-3
The system should follow modular architecture:
- Simulation engine,
- API layer,
- Visualization layer,
- Utilities.

## 4. Reliability
### NFR-4
The system should avoid:
- Memory leaks
- Invalid accesses
- Crashes
Use:
- RAII,
- Smart pointers
- Sanitizers
- Unit tests

## 5. Usability
### NFR-5
The frontend should provide intuitive controls and clear visual feedback.

## 6. Portability
### NFR-6
The backend should compile on:
- macOS
- Linux
- Windows

## 7. Observability
### NFR-7
The backend should provide:
- Logs
- Metrics
- Debugging traces

## 8. Testability
### NFR-8
Core simulation logic should be unit-testable independently from UI.

--

# CacheScope File Structure
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
