# Sandbox

A place to store my small projects and pieces of code.

# Contents

- [passgen](#passgen)
  - [Usage](#usage)
  - [Example](#example)

# passgen

A simple, possibly naive password generator. You can choose how long the passwords should be, along with how many of them should be generated.

## Usage

```
$ passgen [-l length] [-a amount]
```

## Example

```
$ passgen
vC{(&nMFt7LE

$ passgen -l 5 
3##$d

$ passgen -a 5
!~5\T61A.CT@
yu2qI$-z$3WO
j),YEfwe$.=R
t-aXuJ(x9Da-
l53;X.T%1tNm

$ passgen -l 5 -a 5
TQ`p]
AwTJ)
W`lVz
k]c>P
```