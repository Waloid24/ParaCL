# ParaCL
A pet-project for the development of a programming language

## Install
```bash
$ git clone --single-branch --branch Vasily git@github.com:Waloid24/ParaCL.git
```

## Build
### Manual Build
```bash
$ cmake -S . -B release -DCMAKE_BUILD_TYPE=Release && cmake --build release
```

### Auto Build
```bash
$ ./bld 
```

### Auto Build debug mode
When you run the code, you will see ast tree in the console.
```bash
$ ./bld DEBUG_GRAMMAR
```

## Run
### App
```bash
    $./paracl < expression_file.dat
```
### Tests
```bash
    $./python3 tests/test.py
```

## Example of Debug mode:
#### Example 1:
Input:
```
1+2-3*2
```
Output:
```
        Num: 1
    OP: +
        Num: 2
OP: -
        Num: 3
    OP: *
        Num: 2
```
#### Example 2:
Input:
```
1+2-3*2
```
Output:
```
            Num: 1
        OP: -
            Num: 2
    OP: -
        Num: 3
OP: +
    Num: 2
```