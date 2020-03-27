/*
BinaryQuery a = Query("fiery") & Query("bird");//Illegal.Because BinaryQuery is an abstract class.

AndQuery b = Query("fiery") & Query("bird");//Illegal.Because operator & returns a Query which can not convert to an AndQuery object.

OrQuery c = Query("fiery") & Query("bird");//Illegal.Because operator & returns a Query which can not convert to an OrQuery object.
*/