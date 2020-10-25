# Autoroll

Autoroll is a command-line C++ parser for D&D-style dice rolls. It can roll any number of arbitrary-sided dice and, as part of the roll, perform addition, subtraction, multiplication
or division between rolls, constant numbers or expressions contained within parenthesis (which may include more rolls). Autoroll uses the standard PMDAS order of operations for its
arithmetic.

## Usage

Here are some example commands:

`autoroll 1d6` rolls a single six-sided die.

`autoroll 4d6h3` rolls four six-sided dice and keeps the three highest results.

`autoroll 4d7+1` rolls four seven-sided dice and adds one to the result.

`autoroll (4d6+5)/2+1d4` rolls four six-sided dice, adds five, divides the result by two and then adds another four-sided die.

You can also specify a seed for the RNG. Currently, you do this by adding a number before the roll: `autoroll 29 1d6`.

Note that at the moment, Autoroll will always round down the result of a non-integer division. This is generally consistent with D&D 5e rules.
I plan to add an option to configure rounding rules, among other things, in the future.

Autoroll is implemented using a Context-Free Grammar. The CFG rules are as follows:

```
AS --> MD | AS + MD
MD --> R | MD * R
R  --> (AS) | n | ndm | ndmhk
```

`n`, `m` and `k` are integers. `d` and `h` are the tokens for die rolls. `AS` is an addition or subtraction token. `MD` is a multiplication or division token.
`R` may be a roll, a parenthetical, or an integer.
