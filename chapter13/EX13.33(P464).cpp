/*
Because these operations must also update the given Folder.
Updating a Folder is a job that the Folder class controls
through its addMsg and remMsg members, which will add or
remove a pointer to a given Message, respectively.
so we can not use Folder or const Folder&;
*/