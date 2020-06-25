#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct list {
    list* next;
    string data;
};

void init(list*&, string);
void add(list*&, string);
void print(list*&);
void cls(list*&);
void get(list*&);
void save(list*&);

int main() {
    list* head;
    get(head);


    print(head);
    save(head);
    cls(head);

    return 0;
}

void init(list*& l, string d) {
    l = new list;
    l->next = nullptr;
    l->data = d;
}

void add(list*& l, string d) {
    if (l->next == nullptr) {
        list* temp = new list;
        temp->data = d;
        temp->next = nullptr;
        l->next = temp;
    }
    else {
        add(l->next, d);
    }
}

void print(list*& l) {
    if (l->next == nullptr) {
        cout << l->data << endl;
        return;
    }
    cout << l->data << endl;
    print(l->next);
}

void cls(list*& l) {
    if (l->next != nullptr)
        cls(l->next);
    if (l->next == nullptr) {
        delete l;
        l = nullptr;
    }
}

void get(list*& l) {
    ifstream file("task3.txt");
    bool ac = false;
    while (!file.eof()) {
        string temp;
        getline(file, temp);
        if (!ac) {
            init(l, temp);
            ac = true;
        }
        else
            add(l, temp);
    }
    file.close();
}

void save(list*& l) {
    if (l == nullptr)
        return;
    
    ofstream file("task3.txt", ios::app);
    file << l->data <<"\n";
    file.close();
    save(l->next);
}
