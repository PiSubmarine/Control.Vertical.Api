# Control.Vertical.Api

`PiSubmarine.Control.Vertical.Api` defines the low-level vertical movement control boundary.

## Responsibility

An `IController` implementation is responsible for:

- accepting a validated vertical target in the form of `Control::Vertical::Api::Command`

The interface is intentionally narrow so that concrete implementations remain free to choose their own strategy, for example:

- depth-hold control based on pressure sensing
- ballast-position control
- controller switching based on the selected vertical mode

## Non-responsibilities

`IController` does not expose transport concerns, ticking mechanics, or raw actuator wiring.

If a concrete controller needs ticking, it may additionally implement `Time::ITickable`, but that capability is intentionally kept outside this API boundary.

Concrete implementations are expected to use composition for dependencies such as:

- telemetry/state providers
- ballast and thruster actuator interfaces
- estimator or stabilization components
