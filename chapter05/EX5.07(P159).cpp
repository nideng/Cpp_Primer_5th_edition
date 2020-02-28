/*
(a) if (ival1 != ival2) 
         ival1 = ival2;  // Need to add semicolon.
     else ival1 = ival2 = 0;
(b) if (ival < minval)                  // Braces needed to include both satetments in scope.
   {
         minval = ival;
          occurs = 1;
    }
(c) if (int ival = get_value())         //Second if statement should be else-if.
        cout << "ival = " << ival << endl;
    else if (!ival)
        cout << "ival = 0\n";
(d) if (ival == 0)                      //Expression changed from assignment to "equal to";
        ival = get_value();
*/