#!/usr/bin/env python
# coding: utf-8 

""" 
Narasimha Karumanchi　著、黒川 利明、木下 哲也　訳,
  "入門 データ構造とアルゴリズム", 2013, オライリー・ジャパン
  p.35 「問題2-1 ハノイの塔を論ぜよ」の解をPythonでコード。

Usage: python TowersOfHanoi.py [NUMBER_OF_DISKS]
"""

def TowersOfHanoi(n, frompeg, topeg, auxpeg):
    print "TowersOfHanoi(%d, %d, %d, %d)"%(n, frompeg, topeg, auxpeg);
    
    if(n==1):
        print "Move disk 1 from peg %d to peg %d.\n"%(frompeg, topeg);
        return;

    TowersOfHanoi(n-1, frompeg, auxpeg, topeg);

    print "Move disk %d from peg %d to peg %d.\n"%(n, frompeg, topeg);

    TowersOfHanoi(n-1, auxpeg, topeg, frompeg);

if __name__=="__main__":
    print "-"*60
    print __doc__
    print "-"*60,"\n"
    
    n_disk=3;
    
    import sys;
    argv = sys.argv;
    if len(argv) > 1:
        n_disk = int(argv[1]) if argv[1].isdigit() else n_disk;

    TowersOfHanoi(n_disk, 1, 3, 2);
