\# Smart Closure Control System

\## Author: Sai Kishore Nadakuditi

\## Version: 0.1

\## Date: May 2026



\## Project Overview

Model-Based Design implementation of a Smart Closure Control System.

Combines mechanical domain expertise with Simulink-based control design.



\## System Description

BLDC motor-driven door and tailgate closure system with:

\- Position PID controller

\- Anti-pinch detection (Stateflow)

\- Fault handling and safe state logic



\## Signal Interface

\### Inputs

\- Voltage\_Command : real\_T : Volts : -12 to +12

\- Load\_Torque     : real\_T : Nm    : 0 to 5

\- Sensor\_Enable   : boolean\_T      : 0 or 1



\### Outputs

\- Motor\_Speed     : real\_T : RPM   : -500 to +500

\- Door\_Position   : real\_T : mm    : 0 to 400

\- Motor\_Current   : real\_T : Amps  : 0 to 15

\- Pinch\_Detected  : boolean\_T      : 0 or 1

\- Fault\_Active    : boolean\_T      : 0 or 1



\## Build Status

\- \[ ] Layer 1: Plant model

\- \[ ] Layer 2: Position PID controller

\- \[ ] Layer 3: Anti-pinch state machine

\- \[ ] Layer 4: Fault handling

\- \[ ] Layer 5: Integration

\- \[ ] Layer 6: MIL test harness

\- \[ ] Layer 7: Code generation

\- \[ ] Layer 8: Requirements traceability

