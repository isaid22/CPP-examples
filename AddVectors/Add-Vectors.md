## Time measurement

This example shows how to measure time it takes to add two integer vector arrays element-wise. In C++, `chrono` library has necessary functions. 
Also, as a comparison, I also provided a solution using array instead of vector.

This example runs on Intel i9 CPU in a Mac Book Pro 16.

### Instruction

In `source-code` directory, there is [add-vectors.cpp](./source-code/add-vectors.cpp). Run

`g++ -o add-vectors add-vectors.cpp -Wall -std=c++17`

This should generate an executable:

`add-vectors`

in the same directory.

Now run the executable:

`./add-vectors`

and the output should be similar to this:

```
Adding two integer vector arrays of size: 4096
Elapse time in 38 microseconds 
Elapse time in 0 milliseconds 
```

## Using array instead of vector
Another way to do element-wise addition is using array instead of vector. The source code for array addition is [here](./source-code/add-array.cpp)

The compilation command is 

`g++ -o add-arrays add-arrays.cpp -Wall -std=c++17`

in the same directory.

Now run the executable:

`./add-arrays`

and expect output to be similar to:
```
Adding two integer vector arrays of size: 4096
Elapse time in 8 microseconds 
Print some results to show addition is executed...
2222222222%  
```

## Notes
This example demonstrates that when doing element-wise operations, you have two choices of data structures to use: vector and array. Array is the more efficient one, since it is much quicker to complete job.