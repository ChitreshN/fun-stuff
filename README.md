# C based compiler for a lox language


## 15.1.2

1. Stack based vm
2. Emulates the way computers are architected

## 15.2.1

1. Implement a stack
2. Include it in the VM

## 15.2.2

1. Implement debug functionality for the VM stack
2. Add push to the constant case instruction
3. And pop while returning

## 15.3
1. Add arithematic operators to the vm


### Design docs
* Another possible imlplementation is register based vm
* They are much more efficient since we can directly
  load and store values instead of repeatedly pushing
  and popping


## 16

1. Here we start implementing the lexical part of the compiler
2. We cahnge the siganture of interpret function to acept strings

## 16.1.2

1. Start implementation of scanner
2. has fields start, current and line

## 16.2

1. Here we scan a token only when the compiler needs one
2. Implement token type to contain the necessary values

## 16.3

1. Add enum to hold possible tokens
2. And make the scanner return the appropriate token
