#ifndef MESSAGE_H
#define MESSAGE_H
#include <string>
#include <set>

class Folder;

class Message {
    friend void swap(Message&, Message&);
    friend class Folder;
public:
    explicit Message(const std::string& str = "") :contents(str) { }
    Message(const Message&);
    Message(Message&&);
    Message& operator=(const Message&);
    Message& operator=(Message&&);
    ~Message();
    void save(Folder&);
    void remove(Folder&);
    
    void print_debug();

private:
    std::string contents;
    std::set<Folder*> folders;

    void add_to_Folders(const Message&);
    void remove_from_Folders();
    void move_Folders(Message* m);
    void addFldr(Folder* f) { folders.insert(f); }
    void remFldr(Folder* f) { folders.erase(f); }
};

void swap(Message&, Message&);

class Folder {
    friend void swap(Folder&, Folder&);
    friend class Message;
public:
    Folder() = default;
    Folder(const Folder&);
    Folder(Folder&&);
    Folder& operator=(const Folder&);
    Folder& operator=(Folder&&);
    ~Folder();

    void print_debug();

private:
    std::set<Message*> msgs;

    void add_to_Message(const Folder&);
    void remove_from_Message();
    void move_Messages(Folder* f);
    void addMsg(Message* m) { msgs.insert(m); }
    void remMsg(Message* m) { msgs.erase(m); }
};

void swap(Folder&, Folder&);

#endif
