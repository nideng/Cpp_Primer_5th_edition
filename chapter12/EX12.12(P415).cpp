/*
(a) legal. Just copy sp which is a shared_ptr to process().
(b) illegale.plain pointer can not convert to smart pointer implicitly.
(c) illegale.plain pointer can not convert to smart pointer implicitly.
(d) Legal. But it's a bad practice to do so.
    Because using smart pointer together with raw pointer could potentially
    cause problems.
*/