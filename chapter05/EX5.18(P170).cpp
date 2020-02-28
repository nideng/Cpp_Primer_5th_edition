/*
(a) 
do { // added bracket.
        int v1, v2;
        cout << "Please enter two numbers to sum:" ;
        if (cin >> v1 >> v2)
            cout << "Sum is: " << v1 + v2 << endl;
    }while (cin);
(b) 
int ival;
    do {
        // . . .
    } while (ival = get_response()); // should not declared in this scope.
(c) 
int ival = get_response();
    do {
        ival = get_response();
    } while (ival); // ival is not declared in this scope.
*/