import sys;
import re;
import cStringIO
import TowersOfHanoi;

class Towers:
    def __init__(self):
        self._pegs = [[],[],[]];
        self._acts = [];

    def setN(self, n):
        self._n = n;
        
    def analyze(self, strings):
        p = re.compile(r"Move disk \d from peg (\d) to peg (\d)\.");
        for line in strings.split("\n"):
            m = p.match(line);
            if m:
                self._acts.append((int(m.group(1)),int(m.group(2))));

    def update(self):
        print "\r",
        N = self._n;
        print ((" "*N)+"|"+(" "*(N+1)))*3
        for i in range(N):
            for j in range(3):
                w = 0;
                l = len(self._pegs[j]);
                if (N-i) < l+1:
                    w = (self._pegs[j])[(N-i)-l-1]
                print (" "*(N-w))+("="*w)+"|"+("="*w)+(" "*(N-w)),
            print ""
        print ""
                
        
    def show(self):
        for i in range(self._n):
            self._pegs[0].append(self._n-i);
            
        self.update();
        print self._acts;
        for act in self._acts:
            print act[0],act[1]
            self._pegs[act[1]-1].append(self._pegs[act[0]-1].pop());
            self.update();

def TowersOfHanoiGraphic(n):
    stdout = sys.stdout;
    iobuf = cStringIO.StringIO();
    sys.stdout = iobuf;
    TowersOfHanoi.TowersOfHanoi(n, 1, 2, 3);
    
    sys.stdout = stdout;
    towers= Towers();
    towers.setN(n);
    towers.analyze(iobuf.getvalue())
    towers.show()
    
if __name__=="__main__":
    n_disk=3;
    
    argv = sys.argv;
    if len(argv) > 1:
        n_disk = int(argv[1]) if argv[1].isdigit() else n_disk;
    TowersOfHanoiGraphic(n_disk);
