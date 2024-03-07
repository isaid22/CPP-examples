## Time measurement

This example shows how to measure time it takes to add two integer vector arrays. In C++, `chrono` library has necessary functions.

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

## Notes

Addition is done element by element.