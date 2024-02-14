# ParaCL
## Description
Hello everyone! Here you will find my implementation of the lexer and parser of the ParaCL (Para = "Paralympics", C = "C", L = "Language") programming language, which is currently C-like.
The project is written in C++ using the following generators: Flex for the lexer, Bison for the parser, which is different from my first fully handwritten Scielang language.
## Opportunities
The language supports 
* standard arithmetic and logical operations;
```
a = 2;
c = a + b;
c = a - b;
c = a * b;
c = a / b;

c = a == b;
c = a != b;
c = a > b;
c = a < b;
c = a >= b;
c = a <= b;

c = (a == 2 && b == 3);
c = (a == 1 || b == 4);

c = -(a+10);
```
*  if/else expressions;
```
a = 1;
b = -4;
if (a == 0)
    a = b + 5;
else
    a = b;
```
* while loops;
```
a = 4;
while (a != 0)
{
    a = a - 1;
}
```
* input and output functions
```
a = ?;
print a;
```

Added the ability to handle syntactic (and a few semantic) errors.
![Unknown variable](/images/var_error.jpg)
![Syntax error](/images/syntax_err.jpg)

## Future updates
Support for functions