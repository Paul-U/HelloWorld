#include <iostream>
#include "list.hpp"

/*
Narasimha Karumanchi　著、黒川 利明、木下 哲也　訳,
  "入門 データ構造とアルゴリズム", 2013, オライリー・ジャパン
  p.61 「問題3-2 連結リストの最後からn番目のノードを見つけよ。」の解をC++でコード。

  力任せ法による解法。
*/

class Q2List : public SinglyLinkedList{
public:
  typedef SinglyLinkedList Super;
  node* NthNodeFromEnd(int n){
    node *head = this->head, *p;
    int count;
    for(p = head,count=0; p ; count++, p = p->next);

    for(p = head, count = count - n;
	count > 0; count--, p = p->next);
    return p;
  }
  void show(){
    for(struct node* p=this->head; p; p=p->next){
      std::cout <<"address :" << p
		<< "\tdata :" << p->data << std::endl;
    }
  }
};

int main(int argc,char* argv[]){
  Q2List list;

  for(int i=0;i<20;i++){
    list.insert(i);
  }
  
  list.show();
  Q2List::node* p=list.NthNodeFromEnd(4);
  std::cout << std::endl <<  p << '\t' << p->data <<std::endl;
  return 0;
}
