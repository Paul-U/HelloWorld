#include <cstdlib>
#include "list.hpp"

/*
Narasimha Karumanchi　著、黒川 利明、木下 哲也　訳,
  "入門 データ構造とアルゴリズム", 2013, オライリー・ジャパン
  p.62 「問題3-1 連結リストを使ってスタックを実装せよ。」
*/


class StackByList : public SinglyLinkedList{
public:
  typedef SinglyLinkedList Super;
  
  StackByList():Super(){}
  ~StackByList(){}

  void push(int data){
    insert(data,0);
  }
  int pop(){
    struct node*& head = this->head;
    if(!head){
      std::cerr << "Stack is empty." << std::endl;
      abort();
    }

    int ret = head->data;
    this->remove(0);
    return ret;
  }
};

int main(int argc, char* argv[]){
  typedef StackByList Stack;

  Stack *stack=new Stack();

  stack->push(10);
  stack->push(20);
  stack->push(30);

  std::cout << "Stack::pop() returns " << stack->pop() << std::endl;
  std::cout << "Stack::pop() returns " << stack->pop() << std::endl;
  std::cout << "Stack::pop() returns " << stack->pop() << std::endl;
  stack->pop();
  
  return 0;
}
