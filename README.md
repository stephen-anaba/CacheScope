# CacheScope

CacheScope is an interactive CPU cache simulation and visualization platform designed to help students, educators, and systems programmers better understand cache architecture, memory mapping, and runtime cache behavior.

The project combines computer architecture concepts with formal software engineering practices, including requirements-driven development, UML modeling, GRASP-based design, and modular simulation architecture.

---

## Features

### Cache Configuration
- Configurable cache size
- Configurable block size
- Direct-mapped, set-associative, and fully associative cache support
- Replacement policies:
  - LRU
  - FIFO
- Validation for invalid cache configurations

### Address Mapping & Visualization
- Hexadecimal memory-address input
- Tag / Index / Offset decomposition
- Binary address visualization
- Cache-set mapping simulation

### Cache Simulation
- Cache-hit and cache-miss detection
- Deterministic cache lookup behavior
- Cache-line eviction simulation
- Runtime cache-state updates

### Visualization & Feedback
- Cache-grid visualization
- Hit/miss highlighting
- Eviction visualization
- Runtime simulation logs

### Metrics & Analytics
- Hit-rate calculation
- Miss-rate calculation
- Live simulation metrics
- Cache-efficiency analytics

---

## Software Engineering & Architecture

CacheScope is intentionally being developed using an architecture-first workflow.

The project includes:
- Functional and non-functional requirements
- CFR → CLFR → Use Case traceability
- System Sequence Diagrams (SSDs)
- UML Sequence Diagrams
- Design Class Diagrams
- GRASP responsibility analysis
- Modular subsystem design

This project emphasizes maintainability, extensibility, and educational clarity.

---

## Project Structure

```txt
CacheScope/
│
├── frontend/
│   ├── src/
│   │   ├── components/
│   │   ├── services/
│   │   ├── styles/
│   │   ├── types/
│   │   └── utils/
│
├── backend/
│   ├── src/
│   │   ├── api/
│   │   ├── cache/
│   │   ├── hash/
│   │   ├── simulation/
│   │   ├── visualization/
│   │   └── utils/
│
├── docs/
│
└── README.md
```
## Planned Architecture
```txt
CacheScope follows a layered modular-monolith architecture with strong subsystem separation.

Frontend (Presentation Layer)
        ↓
Backend API Layer
        ↓
Simulation/Application Layer
        ↓
Cache Domain Layer
        ↓
Infrastructure/Data Structure Layer
```

### Core Subsystems
- Cache Engine
- Address Mapper
- Replacement Policy Engine
- Metrics Engine
- Visualization Layer

### Design Principles
- Low Coupling
- High Cohesion
- Strategy Pattern for replacement policies
- Separation of simulation and visualization concerns

## Tech Stack (current/planned)
### Frontend
- TypeScript
- Vite
- Web Components
- HTML/CSS
- SVG/Canvas Visualization

### Backend
- C++
- CMake
- Custom hashSet implementation
- REST API architecture
- GitHub Actions
- Markdown-based architecture documentation

### Software Engineering Practices
- Agile Development
- Requirements-Driven Design
- UML Modeling
- GRASP Principles
- Traceability Mapping

## Educational Goals
CacheScope aims to make CPU cache behavior more understandable through:
- interactive simulation
- visual learning
- deterministic execution
- architecture-level transparency

The platform is designed to bridge the gap between theoretical computer architecture and practical systems understanding.

## Roadmap
### Phase 1
- Requirements engineering
- Use cases
- UML & GRASP modeling

### Phase 2
- Core cache simulation engine
- Address decomposition
- Replacement-policy execution

### Phase 3
- Interactive visualization
- Metrics & analytics
- Runtime feedback systems

### Phase 4
- Advanced cache architectures
- Multi-level cache support
- Export/reporting capabilities

## Status
Currently in active architecture and requirements-design phase.

## Author
Built publicly as part of a software engineering and systems architecture learning journey.
