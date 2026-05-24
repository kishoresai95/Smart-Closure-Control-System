# Layer 7 — Code Generation Report Summary
## SCCS_AntiPinch_SM_03 | ert.tlc | R2024a | 05/24/2026

## Build Configuration
- Target: ert.tlc (Embedded Real-Time)
- Solver: Fixed-step, ode3, step size 0.01
- Tasking Mode: SingleTasking
- MISRA C:2012 objectives registered

## Static Code Metrics
- .c files: 1 | .h files: 4
- Main file LOC: 106 (SCCS_AntiPinch_SM_03.c)
- Total LOC: 237

## Memory Footprint
- Global RAM: 67 bytes total
  - ExtU (inputs):  32 bytes — 7 reads/writes
  - ExtY (outputs): 24 bytes — 33 reads/writes
  - DW (state):      3 bytes — 18 reads/writes
- Max Stack: 0 bytes (no dynamic allocation)

## Function Complexity
- _initialize: complexity 1 (trivial)
- _step:       complexity 14 ⚠ above ≤10 guideline
- _terminate:  complexity 1 (trivial)

## Findings
- Step function complexity = 14, exceeds MISRA recommended ≤10
- Cause: 5-state FSM with nested current spike + fault conditions
- Disposition: Documented deviation — acceptable for portfolio model
- No dynamic memory allocation — compliant

## Traceability
- Bidirectional traceability verified — <S1> links navigate to Stateflow chart
- 7 transitions eliminated by optimization (expected for 5-state FSM)