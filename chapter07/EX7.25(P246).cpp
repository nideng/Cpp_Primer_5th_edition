/*
The class below can rely on it.It goes in Section 7.1.5 :
  ..the synthesized versions are unlikely to work correctly for classes 
  that allocate resources that reside outside the class objects themselves.

  Moreover, the synthesized versions for copy, assignment, and destruction 
  work correctly for classes that have vector or string members.

  Hence the class below which used only built - in type and strings can rely on 
  the default version of copyand assignment. 

  */
