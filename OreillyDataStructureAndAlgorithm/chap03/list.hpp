#pragma once

#include<iostream>

class SinglyLinkedList{
public:
  class node{
  public:
    node* next;
    int data;
  };

  SinglyLinkedList();
  virtual ~SinglyLinkedList();

  void insert(int data, int position=0);
  void remove(int position);
protected:
  node* head;
};
