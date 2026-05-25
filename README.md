\# Smart Closure Control System

\## Author: Sai Kishore Nadakuditi

\## Version: 1.0

\## Date: May 2026



\---



\## Project Overview

Model-Based Design implementation of a Smart Closure Control System.

Combines 5.5 years of mechanical actuator design experience with

Simulink-based control design. Plant modelled from first principles

based on physical systems designed and validated in DVP testing.



\---



\## System Description

BLDC motor-driven door and tailgate closure system with:

\- Position PID controller

\- Anti-pinch detection (Stateflow FSM)

\- Fault handling and safe state logic

\- Full system integration with feature arbitration

\- MIL verified test harness



\---



\## Signal Interface



\### Plant Inputs

\- Voltage\_Command : real\_T : Volts  : -12 to +12

\- Load\_Torque     : real\_T : Nm     : 0 to 5



\### Plant Outputs

\- Motor\_Speed     : real\_T : RPM    : -500 to +500

\- Door\_Position   : real\_T : mm     : 0 to 400



\### Anti-Pinch Inputs

\- Door\_Position   : real\_T : mm     : 0 to 400

\- Motor\_Current   : real\_T : Amps   : 0 to 15

\- Close\_Command   : boolean\_T       : 0 or 1

\- Open\_Command    : boolean\_T       : 0 or 1



\### Anti-Pinch Outputs

\- Motor\_Voltage   : real\_T : Volts  : -12 to +12

\- Pinch\_Detected  : boolean\_T       : 0 or 1

\- Door\_State      : real\_T          : 1=IDLE 2=OPENING 3=CLOSING 4=PINCH 5=REVERSING



\### Fault Handler Inputs

\- Door\_Position   : real\_T : mm     : 0 to 400

\- Motor\_Current   : real\_T : Amps   : 0 to 15

\- Motor\_Running   : boolean\_T       : 0 or 1

\- Fault\_Reset     : boolean\_T       : 0 or 1



\### Fault Handler Outputs

\- Fault\_Active    : boolean\_T       : 0 or 1

\- Safe\_State\_Cmd  : boolean\_T       : 0 or 1

\- Fault\_Code      : real\_T          : 0=none 1=pos\_sensor 2=curr\_sensor 3=overrun



\---



\## Architecture



Feature arbitration priority:

1\. Fault detected    -> Safe\_State\_Cmd = 1 -> Motor voltage forced to 0

2\. Pinch detected    -> Anti-pinch voltage overrides PID

3\. Normal operation  -> PID controls door position



\---



\## Layer Status



\- \[x] Layer 1: Plant model — BLDC back-EMF feedback, speed settles at steady state

\- \[x] Layer 2: PID controller — settles at 400mm in 5 seconds, zero overshoot

\- \[x] Layer 3: Anti-pinch Stateflow — 5 states, current spike detection, reversal

\- \[x] Layer 4: Fault handling — 3 fault states, sensor dropout, overrun detection

\- \[x] Layer 5: Integration — all 4 subsystems connected, PID closed loop verified

\- \[x] Layer 6: MIL test harness — TC\_001 PASS

\- \[x] Layer 7: Code generation — ert.tlc, MISRA review

\- \[x] Layer 8: Requirements traceability



\---



\## PID Tuning Parameters



| Parameter          | Value | Notes                        |

|--------------------|-------|------------------------------|

| P (Proportional)   | 0.5   | Drives fast initial response |

| I (Integral)       | 0.01  | Eliminates steady-state error|

| D (Derivative)     | 0.3   | Damps oscillations           |

| Speed\_to\_Position  | 1000  | Plant scaling factor         |

| Back\_EMF\_Feedback  | 0.2   | Limits motor speed naturally |

| Settling time      | \~5s   | Door open 400mm              |

| Overshoot          | 0%    | Clean first-order response   |

| Steady-state error | \~0mm  | Reaches exactly 400mm        |



\---



\## MIL Test Results



\### TC\_001 — Anti-pinch Response Time

\- Status: PASS

\- Stimulus: Motor\_Current spikes from 3A to 10A at t=2s

\- Detection time: <= 10ms (within one simulation step)

\- Pass criteria: Detection < 100ms — MET

\- Reversal commanded: within 10ms of detection — MET

\- Reversal duration: 600ms (100ms PINCH\_DETECTED + 500ms REVERSING)

\- Test date: May 2026



\---



\## Solver Configuration

\- Type: Fixed-step

\- Solver: ode3

\- Step size: 0.01s

\- Target: ert.tlc (Embedded Coder)



\---



\## Git History

\- Initial project setup - signal interface defined

\- Layer 1 complete - BLDC plant model with back-EMF feedback

\- Layer 2 complete - PID position controller tuned

\- Layer 3 complete - Anti-pinch Stateflow verified

\- Layer 3 - clean deployable interface

\- Layer 4 complete - fault handling verified

\- Layer 5 complete - integration model

\- Layer 6 complete - MIL test TC\_001 PASS

