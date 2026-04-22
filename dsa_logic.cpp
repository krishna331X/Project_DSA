#include <iostream>
using namespace std;

class Node{
public:

string name;
Node* next;

Node(string n){
name=n;
next=NULL;
}

};

int main(){

Node* head = new Node("Riya");
head->next = new Node("Sneha");

Node* temp=head;

while(temp!=NULL){

cout<<temp->name<<endl;

temp=temp->next;

}

}