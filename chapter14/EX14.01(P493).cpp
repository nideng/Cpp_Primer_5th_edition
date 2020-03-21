/*
We can call an overloaded operator function directly.
An overloaded operator function must either be a member of
a class or have at least one parameter of class type.
A few operators guarantee the order in which operands are evaluated. These overloaded versions of these operators do not preserve order of evaluation and/or short-circuit evaluation, it is usually a bad idea to overload them.
In particular, the operand-evaluation guarantees of the logical AND,
logical OR, and comma operators are not preserved, Moreover,
overloaded versions of && or || operators do not preserve
short-circuit evaluation properties of the built-in operators.
Both operands are always evaluated.

Same
An overloaded operator has the same precedence and associativity
as the corresponding built-in operator.
*/