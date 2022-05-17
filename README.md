# Kalman Filter experiments

During my University courses I learned about the Kalman filter. Or rather I heard of it because I never actually understood it. 
To remedy this I decided to implement the filter myself.

## Goal

In the end I would like to have code that can run on a microcontroller (like arduino) and use IMU sensor data to calculate a position and orientation.
Because this is very ambitious and complex I decided to write out some subgoals as steps towards the final code.

## Roadmap

1. Implement [scalar kalman filter](./scalar_filter/AboutScalarFilter.md) - done
    - The example I found online was of a temperate reading with some uncertainty
    - This removes all complexity of matrix math and simply shows the underlying principles
    - This first implementation was done in rust since I was learning it at that point
2. Implement [simple matrix filter](./simple_matrix_filter/AboutSimpleMatrixFilter.md) - done
    - The example from one of my courses is an object falling in one dimension
    - This includes some 2x2 matrices because position and velocity will be important
    - For the language I changed over to c++ because there is a useful library for matrix operations
3. Implement filter for 2D problem
    - The example here is not yet decided, but it should include rotation and acceleration in 2D
    - Since orientation in 3D uses complex matrices or 4D numbers I want to limit the problem 
    - Acceleration is important for the accelerometers I want to use later
    - The resulting code might be run on actual hardware to test it
4. Understand Quaternions and/or direction cosine matrices 
    - The kalman filter requires a description of the system, which includes orientation
    - Orientation in 3D requires complex math which I must familiarize myself first
5. Implement filter for 3D problem
    - This should be the final code that can run on the microcontroller
6. Modularize if possible
    - To build on the code base at this stage I would like to break it up into modules that can be turned on or off, dependant on the kinds of sensors which are in use
