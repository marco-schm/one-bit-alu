# 1-BIT ALU Simulator
![ALU](https://upload.wikimedia.org/wikipedia/commons/1/17/Simplified-ALU.svg)


This project is a simple ALU (Arithmetic Logic Unit) simulator implemented in C. The purpose of this project is to provide a hands-on learning experience for the "Grundlagen Informatik" (Fundamentals of Computer Science) module. The simulator allows users to input boolean values for 'a' and 'b' and select an ALU operation from a predefined set.

## Usage

To run the simulator, use the following command:

```
./one_bit_alu <value_for_a> <value_for_b> <alu_operation>
```

- <value_for_a> and <value_for_b> should be either '0' or '1'.
- <alu_operation> is a number between 0 and 7, representing different ALU operations.

### Possible ALU Operations:
- 0: DEACTIVATE
- 1: A
- 2: NOT A
- 3: A AND B
- 4: A OR B
- 5: A XOR B
- 6: A + B
- 7: B - A

### Example 
```
./one_bit_alu 1 0 3
```
This example sets 'a' to true, 'b' to false, and performs the ALU operation 'A AND B'. The result will be displayed as 'R: &lt;result&gt;, D: <carry_out>'.

## Building the project
To build the project, follow these steps:

1) Clone the repository to your local machine:
```
git clone https://github.com/marco-schm/one-bit-alu.git
```

2) Navigate to the project directory:
```
cd one-bit-alu
```

3) Compile the source code using a C compiler. For example, using gcc:
```
gcc -o one_bit_alu main.c
```

4) Run the compiled executable:
```
./one_bit_alu <value_for_a> <value_for_b> <alu_operation>
```

## Purpose
This project is intended for educational purposes, specifically for the "Grundlagen Informatik" module. 
It provides a practical illustration of basic digital logic concepts and ALU operations.

## License

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

