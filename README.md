# Soft-Drink-Vending-Machine
A C program for a simple Pop Machine that calculates change and dispenses a beverage when the correct amount is inserted.
## Table of Contents
  * [Introduction](#introduction)  
  * [Getting Started](#getting_started)  
  * [Customization](#customization)
## Introduction
This C program simulates a basic Pop Machine, developed using Agile methodology. It provides flexibility by allowing sellers to customize money values and currencies. Users can insert nickels, dimes, or pentes, and the program dispenses a beverage when the required amount is reached. The program calculates change in dimes and nickels and provides a user-friendly interface.

## Getting Started
To compile and run this program, make sure you have a C compiler installed on your system.  
You can use the `gcc` compiler to build the program.
### Compilation

```
gcc pop.c -o pop
```

### Usage
To run the program, execute it with the desired pop price as a command-line argument. For example, to set the pop price to 75 centimes:

```
./pop 75
```

Once the program is running, follow the on-screen instructions to insert coins (N for nickels, D for dimes, P for pentes), request coin return (R), or shut down the machine (E).

## Customization
The Pop Machine allows sellers to customize money values and currencies to meet specific needs. This feature ensures compatibility with various regions and payment systems, making it a versatile solution for different environments.

To customize the program for different money values and currencies, modify the constants defined in the code (e.g., COIN1, COIN2, COIN3) according to your requirements.
