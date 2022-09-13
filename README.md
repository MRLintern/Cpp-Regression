### Linear & Gaussian Regression with C++

A basic piece of Software written in C++ that performs Linear and Gaussian Regression.
(Data supplied in .txt format).
### Requirements

1. Build Generator:`CMake`
2. Compiler:`gcc/g++ (9.4.0)`
3. OS:`Ubuntu 20.04`. However, `Windows 10` can be used providing `wsl` is used within `MS VScode`
4. Text Editor:`MS VScode`

### Instructions

1. Clone the project: $ git clone https://github.com/MRLintern/C++_Regression.git
2. Build the project and executable:
* `$ mkdir build && cd build`
* `$ cmake ..`
* `$ cmake --build .`
* `$./regression`

### TODO

The results are generated and displayed to the console.
These results are also saved to the original .txt (input data) files; the results are already generated in the .txt files.
Consider writing the results to separate .txt files.
These results can then be visualised using a plotting library such as `Matplotlib`.

