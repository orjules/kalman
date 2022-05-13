# About the scalar filter

## Inspiration

On my journey to finding good learning resources about kalman filters I stumbled upon this [series of YouTube videos](https://www.youtube.com/watch?v=CaCcOwJPytQ&list=PLX2gX-ftPVXU3oUFNATxGXY90AULiqnWT&index=2).
In it the first examples (episodes 5 and 6) are of a temperature reading with some uncertainty in the measurement. 
With this example I finally understood the basic principles of the kalman filter

## Goal

To really understand these basic principles I want to implement a simulation of the temperature measurements and play around with some filter parameters.
During this process I will write my learned lessons in this document to reference later or show someone who might want to learn about this themself. 

## Tools

Because I want to learn rust, this first implementation will be written in it.
To visualize the behavior I will use R to plot it.

## Theory 

First some notation has to established.
The following notation is an amalgamation of the aforementioned YouTube videos and one of my University courses.
Note that K, P and R are uppercase, because they will later be matrices. For now everything is a scalar value.

- x: State
- z: Measurement 
- K: Kalman Gain
- P: Process uncertainty
- R: Measurement uncertainty
- k: running sample number (written like function because subscript might not render)

The basic idea is to estimate the state of a system with measurements of it and the uncertainty of these measurements.

(Image of block plan)

There is a formula associated with each of the three steps.

`K = P / (P + R)`

`x_k = x_k-1 + K * (z - x_k-1)`

`P_k = (1 - K) * P_k-1`