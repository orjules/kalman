# About the simple matrix filter

## Goal

After gaining an understanding of the basic concepts of the kalman filter with the scalar examples I want to implement a very simple matrix version of it.
The example I want to use is an object falling in one dimension, which I will call `h` for height.
The state of the object will consist of `h` and `v` the velocity with which it is falling.
Because the state is a vector now, every other value like the Kalman Gain `K` must be a matrix now.

## Tools

As a guide I will continue to refer to the [YouTube series](https://www.youtube.com/watch?v=CaCcOwJPytQ&list=PLX2gX-ftPVXU3oUFNATxGXY90AULiqnWT&index=2) mentioned in the [scalar filter example](../scalar_filter/AboutScalarFilter.md).

Since this code will eventually run in c++ on an Arduino I am using c++ for this example with the [BasicLinearAlgebra library](https://github.com/tomstewart89/BasicLinearAlgebra).

## Theory 

## Implementation

## Running the simulation

## Lessons learned