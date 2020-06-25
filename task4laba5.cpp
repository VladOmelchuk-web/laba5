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
void get(list*&, string);
void add_ch(list*&, list*&, string);

int main() {
    list* head1, *head2;
    get(head1, "task4_1.txt");
    get(head2, "task4_2.txt");

    print(head1);
    print(head2);
    string word;
    cout << "Enter word: ";
    getline(cin, word);
    add_ch(head1, head2, word);

    cout << endl;
    print(head1);
    cls(head1);
    cls(head2);

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

void get(list*& l, string fname) {
    ifstream file(fname);
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

void add_ch(list*& l, list*& l2, string c) {
    if (l->next == nullptr)
        return;
    if (l->next->data == c) {
        list* temp = new list;
        temp->next = l->next;
        temp->data = l2->data;
        l->next = temp;
        if (l2->next == nullptr)
            return;
        add_ch(l->next, l2->next, c);
    }
    else {
        if (l->next == nullptr)
            return;
        add_ch(l->next, l2, c);
    }
}
