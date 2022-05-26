# About 1D acceleration filter

A simplified version of the [2d Filter](../2d_filter/About2DFilter.md).

## Goal

Only one dimension in which the object can move.
The state `x` will contain a distance `d`, a velocity `v` and an acceleration `a`.
The transition functions are as follows:

```
x_k = x_k-1  +  Δt * v_k-1  +  0.5 * Δt^2 * a_k-1
v_k = Δt * a_k-1
```

## Running the simulation

First you need to build the c code.
For this run `cmake -S . -B target/` in the `c_code` directory.
(This step is only necessary once)
Afterwards go into the `target` directory and run `make`.
Now you have an executable named `1dKalmanFilter`.

Run `./1dKalmanFilter > ../../plotting/c_out.txt`.