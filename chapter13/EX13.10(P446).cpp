/*
When a StrBlob object destroyed, the use_count of the dynamic
object will decrement. It will be freed if no shared_ptr to that dynamic object.

When a StrBlobPter object is destroyed the object dynamically allocated 
will not be freed.

*/