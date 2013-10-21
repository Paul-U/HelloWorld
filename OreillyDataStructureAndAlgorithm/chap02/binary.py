#!/bin/python
# coding: utf-8

"""
 Narasimha Karumanchi　著、黒川 利明、木下 哲也　訳,
   "入門 データ構造とアルゴリズム", 2013, オライリー・ジャパン
  p.36 「問題2-2 nビットのすべての列を生成せよ。」の解をPythonでコード。
"""

class Binary:
    def __init__(self,n):
        self.n = n;
        self.A = [0]*n;
        self.__binary(len(self.A));
        
    def __binary(self,n):
        if(n < 1):
            print self.A;

        else:
            self.A[n-1] = 0;
            self.__binary(n-1);
            self.A[n-1] = 1;
            self.__binary(n-1);

if __name__=="__main__":
    print "-"*60
    print __doc__
    print "-"*60,"\n"
    
    Binary(10);
