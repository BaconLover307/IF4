'''
Gregorius Jovan Kresnadi - 13518135
Nama program : 15 Puzzle Solver
Deskripsi program:
Program yang menerima sebuah puzzle matriks 16 kotak, dan 
menyelesaikannya. Program menerima masukan berupa teks 
yang berisi matriks, menggunakan Algoritma Branch and Bound
untuk menyelesaikan puzzle tersebut.
Final goalnya adalah sebagai berikut
| 1 | 2 | 3 | 4 |
| 5 | 6 | 7 | 8 |
| 9 | 10| 11| 12|
| 13| 14| 15|   |
'''
import time
# $ ====================== FUNCTIONS & METHODS ======================
def readPuzzle(menu):
    filein = "puzzle.txt"
    if menu == 1:
        filein = "../test/puzzle.txt"
    elif menu == 2:
        filein = str(input("File to read (without .txt): "))
        filein = "../test/" + filein + ".txt"
    try:
        f = open(filein,"r")
    except:
        print("File not found, using default file...")
        f = open("../test/puzzle.txt","r")
    return f

def printPuzzle(puzzle):
    for x in puzzle:
        print("+----+----+----+----+")
        print("|", end="")
        for y in x:
            out = ""
            num = y
            if (num == 16):
                out += "   "
            elif (num < 10):
                out += ("  "+str(num))
            else:
                out += (" "+str(num))
            print(out, end=" |")
        print()
    print("+----+----+----+----+")

def Posisi(puzzle, idx):
    pos = 1
    for x in puzzle:
        for y in x:
            if idx == y:
                return pos
            else:
                pos += 1
    return pos

def Kurang(puzzle, idx):
    if idx == 1:
        return 0
    else:
        j = 1
        count = 0
        idxPos = Posisi(puzzle,idx)
        while (j < idx):
            if Posisi(puzzle,j) > idxPos:
                count += 1
            j += 1
        return count

def Koordinat(puzzle, x):
    for i in range(len(puzzle)):
        for j in range(len(puzzle[i])):
            if x == puzzle[i][j]:
                return [i,j]

def copyPuzzle(puzzle):
    temp = []
    for i in range(len(puzzle)):
        tempI = puzzle[i].copy()
        temp.append(tempI)
    return temp

# $ ====================== MOVEMENT FUNCTIONS ======================
def moveUp(puzzle):
    koor = Koordinat(puzzle,16)
    koorNew = [koor[0]-1,koor[1]]
    temp = copyPuzzle(puzzle)
    t = temp[koorNew[0]][koorNew[1]]
    temp[koorNew[0]][koorNew[1]] = 16
    temp[koor[0]][koor[1]] = t
    return temp

def moveDown(puzzle):
    koor = Koordinat(puzzle,16)
    koorNew = [koor[0]+1,koor[1]]
    temp = copyPuzzle(puzzle)
    t = temp[koorNew[0]][koorNew[1]]
    temp[koorNew[0]][koorNew[1]] = 16
    temp[koor[0]][koor[1]] = t
    return temp

def moveLeft(puzzle):
    koor = Koordinat(puzzle,16)
    temp = copyPuzzle(puzzle)
    temp[koor[0]].remove(16)
    temp[koor[0]].insert(koor[1]-1,16)
    return temp

def moveRight(puzzle):
    koor = Koordinat(puzzle,16)
    temp = copyPuzzle(puzzle)
    temp[koor[0]].remove(16)
    temp[koor[0]].insert(koor[1]+1,16)
    return temp

# $ ====================== SOLVING FUNCTIONS ======================
def Ci(node, depth):
    return depth + Gi(node)

def Gi(puzzle):
    count = 0
    idx = 1
    for x in puzzle:
        for y in x:
            if (y!=16 and y!=idx):
                count += 1
            idx += 1
    return count

def generateNodes(node, vis):
    new = []
    koor = Koordinat(node[0],16)
    depth = node[1] + 1
    if (koor[0] != 0) and node[3][-1] != "d": # MOVEUP
        up = moveUp(node[0])
        if not(str(up) in vis):
            new.append([up,depth,Ci(up,depth),node[3]+"u"])
            vis.append(str(up))
    if (koor[1] != 0) and node[3][-1] != "r": # MOVELEFT
        left = moveLeft(node[0])
        if not(str(left) in vis):
            new.append([left,depth,Ci(left,depth),node[3]+"l"])
            vis.append(str(left))
    if (koor[0] != 3) and node[3][-1] != "u": # MOVEDOWN
        down = moveDown(node[0])
        if not(str(down) in vis):
            new.append([down,depth,Ci(down,depth),node[3]+"d"])
            vis.append(str(down))
    if (koor[1] != 3) and node[3][-1] != "l": # MOVERIGHT
        right = moveRight(node[0])
        if not(str(right) in vis):
            new.append([right,depth,Ci(right,depth),node[3]+"r"])
            vis.append(str(right))
    return new

def findLowestCost(nodes):
    costArr=[]
    for node in nodes:
        costArr.append(node[2])
    lowCost = min(costArr)
    return costArr.index(lowCost)
    

def solve(puzzle):
    vis = []
    nodeCount = 1
    if Gi(puzzle) != 0:
        depth = 0
        nodes = [[puzzle,depth,Ci(puzzle,depth),"."]]
        while len(nodes)!=0:
            idxMin = findLowestCost(nodes)
            evalNode = nodes.pop(idxMin)
            if (Gi(evalNode[0]) == 0):
                sol = evalNode
                break
            newQueue = generateNodes(evalNode,vis)
            if len(newQueue) == 0:
                continue
            nodeCount += len(newQueue)
            nodes.extend(newQueue)
    print("===== GOAL STATE REACHED =====")
    printPuzzle(sol[0])
    return [nodeCount,sol[3][1:]]

# $ ====================== PRINT RESULTS ======================

def traceback(puzzle,path):
    printPuzzle(puzzle)
    for c in path:
        print()
        print("V    V    V    V   V")
        print()
        if c == "u":
            puzzle = moveUp(puzzle)
            printPuzzle(puzzle)
        elif c == "d":
            puzzle = moveDown(puzzle)
            printPuzzle(puzzle)
        elif c == "l":
            puzzle = moveLeft(puzzle)
            printPuzzle(puzzle)
        elif c == "r":
            puzzle = moveRight(puzzle)
            printPuzzle(puzzle)
        time.sleep(.2)

def printPath(path):
    for c in path:
        if c == "u":
            print("Up ", end="")
        elif c == "d":
            print("Down ", end="")
        elif c == "l":
            print("Left ", end="")
        elif c == "r":
            print("Right ", end="")
    print()

# $ ========================================================
# $ ====================== INPUT FILE ======================
print("[]=======================[]")
print("||    15 Puzzle Solver   ||")
print("|| - - - - - - - - - - - ||")
print("||         File :        ||")
print("||    1. Use Default     ||")
print("||      (puzzle.txt)     ||")
print("||    2. Input file      ||")
print("[]=======================[]")
print("||")
try:
    menu = int(input("[]=>> "))
except:
    print("Reading default file...")
    menu = 1
puzzleFile = readPuzzle(menu)
print()
# $ ====================== READ & PROCESS FILE ======================
puzzle=[] # Menyimpan matrix
for line in puzzleFile.readlines():
    puzzle.append( [ int (x) for x in line.split(' ') ] )
# $ ====================== POSISI AWAL ======================
print("=====  Posisi Awal ======")
printPuzzle(puzzle)
print()

# $ ====================== KURANG(i) ======================
print("==  Reachable Goal ==")
print("+-------+-----------+")
print("| i\t| Kurang(i) |")
print("+-------+-----------+")
sumKurang = 0
for idx in range(16):
    kur = Kurang(puzzle,idx+1)
    sumKurang += kur
    print("| " + str(idx+1) + "\t| " + str(kur) +"\t    |")
print("+-------+-----------+")
if (Posisi(puzzle, 16) in [2,4,5,7,10,12,13,15]):
    X = 1
else:
    X = 0

# $ ====================== SIGMA KURANG(i) + X ======================
solvable = sumKurang + X
print("SIGMA(Kurang(i)) + X = " + str(solvable))
print()

if (solvable%2 == 1):
    print("Sayang sekali, puzzle tidak bisa diselesaikan")
    print("dengan metode Branch and Bound :(")
else: # $ ================== SOLVE =====================
    start_time = time.time() # $ ================== MEASURE TIME =====================
if solvable%2 == 0:
    ans = solve(puzzle)
    print("=== Simpul yang dibangkitkan: " + str(ans[0]))
    print("=== Path: ", end="")
    printPath(ans[1])
    print("=== Path Length: " + str(len(ans[1])))
    time_elapsed = time.time() - start_time
    print("=== Time Elapsed : " + str(time_elapsed) + " seconds =====")
    print()
    printResult = input("=====[] Visualise Path? : (y/n) ")
# $ ====================== PRINT ALL NODES ======================
    if printResult == "y":
        traceback(puzzle,ans[1])
        print()
        print("=== Simpul yang dibangkitkan: " + str(ans[0]))
        print("=== Path: ", end="")
        printPath(ans[1])
        print("=== Path Length: " + str(len(ans[1])))
        print("=== Time Elapsed : " + str(time_elapsed) + " seconds =====")
else:
    print("=== Simpul yang dibangkitkan: 0")
    print("=== Path: ")
    print("=== Path Length: 0")
    print("=== Time Elapsed : 0.00000000 seconds =====")
