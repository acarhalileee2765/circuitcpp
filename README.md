# Resistor Circuit Calculator

A simple C++ console program that calculates the total resistance and total current of a circuit made of a group of parallel resistors connected in series with additional series resistors. All inputs and results are also saved to a text file.

## Features

- Calculates the equivalent resistance of any number of parallel resistors
- Calculates the total resistance of any number of series resistors
- Combines both into the total circuit resistance
- Calculates the total current using Ohm's law (I = V / R)
- Supports decimal resistance values (e.g. 4.7 ohms)
- Logs every input and result to `circuit.txt`

## How It Works

The program models the circuit as a parallel resistor group in series with a set of series resistors:

```
Parallel group (R1 || R2 || ... || Rn) --- Rs1 --- Rs2 --- ... --- Rst
```

Formulas used:

| Quantity | Formula |
|---|---|
| Parallel resistance | 1 / R_parallel = 1/R1 + 1/R2 + ... + 1/Rn |
| Series resistance | R_series = Rs1 + Rs2 + ... + Rst |
| Total resistance | R_total = R_parallel + R_series |
| Total current | I = V / R_total |

## Requirements

- A C++ compiler with C++11 support or later (g++, clang++, MSVC)

## Build and Run

Linux / macOS:

```bash
g++ -o circuit main.cpp
./circuit
```

Windows:

```bash
g++ -o circuit.exe main.cpp
circuit.exe
```

## Usage

The program asks for the following inputs in order:

1. Number of parallel resistors
2. Resistance value (in ohms) of each parallel resistor
3. Number of series resistors
4. Resistance value (in ohms) of each series resistor
5. Source voltage (in volts)

### Example Session

```
Enter the number of parallel resistors: 2
Enter the parallel resistance value for resistor 1 (in ohms): 10
Enter the parallel resistance value for resistor 2 (in ohms): 10
enter the series resistance number: 1
Enter the series resistance value for resistor 1 (in ohms): 5
Enter the voltage (in volts): 10
```

### Example Output File (`circuit.txt`)

```
********circuit********
Number of resistors: 2
Resistor 1: 10 ohms
Resistor 2: 10 ohms
Total parallel resistance: 5 ohms
Series Resistor 1: 5 ohms
Total series resistance: 5 ohms
Total resistance of the circuit: 10 ohms
Total current through the circuit: 1 amperes
```

Here, two 10 ohm resistors in parallel give 5 ohms. Adding the 5 ohm series resistor gives 10 ohms in total, so a 10 V source drives 1 A.

## Output

Results are written to `circuit.txt` in the working directory. The file is overwritten on every run.

## Limitations

- Resistance values must be non-zero (a value of 0 causes a division by zero in the parallel calculation).
- There is no input validation for negative or non-numeric values.
- Only one topology is supported: a single parallel group in series with a chain of series resistors.

## Possible Improvements

- Add input validation
- Support more complex circuit topologies (e.g. multiple parallel groups)
- Replace the global variables with local variables and function parameters

## License

This project is open source. Feel free to use and modify it.
