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
3. Implement [1D acceleration filter](1d_acc_filter/About1dAcc.md) - done
   - I really wanted to implement the 2D problem from point 4 but some weird results forced me to go back a step
   - This example is of an object which moves along 1 axis and has acceleration as the measured value
4. Implement [2D acc and rot filter](2d_filter/About2DFilter.md) - done
    - The example is of an object limited to the x-y-plane 
    - It can rotate around the z axis
    - The measured values are the acceleration and rotation speed
    - The sample path has it move forward, turn 90 degree and move in the new forward direction
5. Understand Quaternions and/or direction cosine matrices 
    - The kalman filter requires a description of the system, which includes orientation
    - Orientation in 3D requires complex math which I must familiarize myself first
6. Implement filter for 3D problem
    - This should be the final code that can run on the microcontroller
7. Modularize if possible
    - To build on the code base at this stage I would like to break it up into modules that can be turned on or off, dependant on the kinds of sensors which are in use
