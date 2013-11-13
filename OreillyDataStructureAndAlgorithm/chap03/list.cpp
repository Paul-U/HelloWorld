#include "list.hpp"

/*
Narasimha Karumanchi　著、黒川 利明、木下 哲也　訳,
  "入門 データ構造とアルゴリズム", 2013, オライリー・ジャパン
  pp.43,46 「3.6.3 単一連結リストの挿入」，「3.6.4 単一連結リストの削除」をC++でコード。
*/


SinglyLinkedList::SinglyLinkedList(): head(0){}

SinglyLinkedList::~SinglyLinkedList(){
  while(head){
    remove(0);
  }
}

void SinglyLinkedList::insert(int data, int position){
  int k = 0;
  node *p, *q, *newnode;
  newnode = new node();
  if(!newnode){
    std::cerr << "Memory Error" << std::endl;
    return;
  }
  newnode->data = data;
  p=head;
  if(position == 0){
    newnode->next = p;
    head = newnode;
  }
  else{
    while( p && k < position){
      k++;
      q = p;
      p = p->next;
    }
    q->next = newnode;
    newnode->next = p;
  }
}

void SinglyLinkedList::remove(int position){
  int k = 0;
  node *p,*q;
  if(!head){
    std::cerr << "List Empty." << std::endl;
    return;
  }
  p = head;
  if(position == 0){
    head = p->next;
    delete p;
  }
  else{
    while( p && k < position ){
      k++;
      q = p;
      p = p->next;
    }
    if( !p ){
      std::cerr << "Position does not exist." << std::endl;
    }
    else{
      q->next = p->next;
      delete p;
    }
  }
}
