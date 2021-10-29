#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node *next;
};

class linkstack{
public:
    linkstack();
    ~linkstack();
    void push(int x);
    int pop();
    int getTop();
    int isEmpty();
private:
    node *top;
};

linkstack::linkstack(){
    top = new node;
    top->next = NULL;
}

linkstack::~linkstack(){
    node *s = top;
    while(top->next != NULL){
        s = top->next;
        delete(top);
    }
}

void linkstack::push(int x){
    node *p = NULL;
    p = new node;
    p->data = x;
    p->next = top;
    top = p;
}

int linkstack::pop(){
    node *s = top;
    int x = s->data;
    top = s->next;
    delete(s);
    return x;
}

int linkstack::getTop(){
    return top->data;
}

int linkstack::isEmpty(){
    if(top->next == NULL) return -1;
    else return 0;
}

int main(){
    linkstack ls;
    int x;
    for(int i = 0; i < 100; i++) ls.push(i);
    cout << "Top element is: " << ls.getTop() << endl;

    try{
        x = ls.pop();
        cout << "Linkstack pop. Delete " << x << endl;
    }catch(char*str){ cout << str << endl; }

    try{
        cout << "Input x:" << endl;
        cin >> x;
        ls.push(x);
    }catch(char*str){ cout << str << endl; }

    if(ls.isEmpty() == -1) cout << "Linkstack is empty." << endl;
    else cout << "Linkstack is not empty" << endl;
    for(int i = 0; i < 100, ls.isEmpty() != -1; i++){
        cout << ls.pop() << " ";
    }
    return 0;
}
