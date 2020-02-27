/*
sizeof x + y equal to (sizeof x)+y . "sizeof" has higher precedence than binary `+`.
sizeof p->mem[i] equal to sizeof(p->mem[i])
sizeof a < b equal to sizeof(a) < b
sizeof f() : If `f()` returns `void`, this statement is undefined,
                                          otherwise it returns the size of return type
*/