/*
Pros

more explicit
less scope for misreading
can use the member function parameter which name is same as the member name.
 
 void setAddr(const std::string &addr) { this->addr = addr; }

Cons
more to read
sometimes redundant
  
std::string getAddr() const { return this->addr; } // unnecessary
*/