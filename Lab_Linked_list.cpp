#include <iostream>
#include <string>
using namespace std;

struct Music{
public:
    string title;
    string artist;
    int mem;         //size of file in MBs
    Music(Music const &m1){
        title = m1.title;
        artist = m1.artist;
        mem = m1.mem;
    }
    Music(string t, string a, int size)
      :  title(t), artist(a), mem(size)
    {}

    Music(){};
};

ostream& operator<<(ostream& os, const Music& music)
{
    os << music.title << " - " << music.artist << " - " << music.mem << "MBs" << endl;
    return os;
}

class Node{
public:
    Music music;
    Node* next;
    Node(){
        next = nullptr;
    };
};

class LinkedList {
public:
    Node *head, *tail;
    LinkedList()  {
        head = nullptr;
    }
    void addNode(Music);
    void deleteNode();
    void display();
};

void LinkedList :: addNode(Music m){
    Node *newNode = new Node;
    newNode->music = m;
    newNode->next = nullptr;
    if(head == nullptr){
        head = newNode;
        tail = head;
    }
    else{
        tail->next = newNode;
        tail = tail->next;
    }
}
void LinkedList :: display(){
    int i = 1;
    Node *current = head;
    if(head == nullptr){
        cout << "Your playlist is empty" << endl << endl;
        return;
    }
    cout << "Your playlist is:" << endl;
    while(current != nullptr){
        cout << "Track " << i << ") " << current->music;
        current = current->next;
        i++;
    }
    delete current;
    cout << endl;
}
void LinkedList :: deleteNode(){
    if(head != nullptr) {
        if(head->next == nullptr) {
            head = nullptr;
        } else {
            Node* temp = head;
            while(temp->next->next != nullptr)
                temp = temp->next;
            Node* lastNode = temp->next;
            temp->next = nullptr;
            free(lastNode);
        }
    }
}

int main() {

    LinkedList L;
    L.display(); // Створення й додавання даних, виведення списку
    L.addNode({"Smells like teen spirit", "Nirvana", 8});
    L.addNode({"Radioactive", "Imagine Dragons", 6});
    L.addNode({"In the end", "Linkin Park", 15});
    L.display();

    L.deleteNode(); // Видалення даних
    L.display();

    L.deleteNode(); // Очищення зв'яного списку
    L.deleteNode();
    L.display();


    return 0;
}
