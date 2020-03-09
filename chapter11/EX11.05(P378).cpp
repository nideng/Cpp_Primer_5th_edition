/*
Both std::set and std::map are associative containers.
The difference is that std::sets contain only the key,
while in std::map there is an associated value. Choosing
one over the other depends mainly on what the task at hand is.
If you want to build a dictionary of all the words that appear
in a text, you could use a std::set<std::string>,
but if you also want to count how many times each 
word appeared (i.e. associate a value to the key) 
then you would need an std::map<std::string,int>. 
If you don't need to associate that count, it does not make
sense to have the int that is unnecessary.
*/