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
        print("|", end="")
        for y in x:
            out = " "
            num = y
            if (num == 16):
                out += "   "
            elif (num < 10):
                out += ("  "+str(num))
            else:
                out += (" "+str(num))
            print(out, end=" |")
        print()

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
def Ci(node, trail):
    return Fi(trail) + Gi(node)

def Fi(trail):
    return trail+1

def Gi(puzzle):
    count = 0
    idx = 1
    for x in puzzle:
        for y in x:
            if (y!=16 and y!=idx):
                count += 1
            idx += 1
    return count

def generateNodes(node):
    new = []
    koor = Koordinat(node[0],16)
    trail = node[1] + 1
    if (koor[0] != 0) and node[3] != "down":
        up = moveUp(node[0])
        new.append([up,trail,Ci(up,trail),"up"])
    if (koor[0] != 3) and node[3] != "up":
        down = moveDown(node[0])
        new.append([down,trail,Ci(down,trail),"down"])
    if (koor[1] != 0) and node[3] != "right":
        left = moveLeft(node[0])
        new.append([left,trail,Ci(left,trail),"left"])
    if (koor[1] != 3) and node[3] != "left":
        right = moveRight(node[0])
        new.append([right,trail,Ci(right,trail),"right"])
    return new

def joinList(list, newlist):
    for i in range (len(newlist)):
        arr = []
        for node in newlist:
            arr.append(node[2])
        print(arr)
        lowCost = min(arr)
        print(lowCost)
        idxMin = arr.index(lowCost)
        print(idxMin)
        j = 0
        if len(list) == 0:
            list.append(newlist.pop(idxMin))
        while j!=len(list):
            if list[j][2] > lowCost:
                list.insert(i,newlist.pop(idxMin))
                break
            if j==len(list):
                list.append(newlist.pop(idxMin))
                break
            j += 1
    return list

def solve(puzzle):
    path = []
    nodeCount = 0
    if Gi(puzzle) != 0:
        trail = -1
        nodes = [[puzzle,trail,Ci(puzzle,trail),"null"]]
        while 1:
            evalNode = nodes.pop(0)
            if (Gi(evalNode[0]) == 0):
                break
            newQueue = generateNodes(evalNode)
            nodeCount += len(newQueue)
            for i in newQueue:
                printPuzzle(i[0])
                print("=============")
            nodes = joinList(nodes,newQueue)
    print("===== GOAL STATE REACHED =====")
    printPuzzle(puzzle)
    return [nodeCount,path]
        
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
puzzleInit = copyPuzzle(puzzle)
# $ ====================== POSISI AWAL ======================
print("=====  Posisi Awal ======")
printPuzzle(puzzle)
print()

# $ ====================== KURANG(i) ======================
print("==  Reachable Goal ==")
print("| i\t| Kurang(i) |")
sumKurang = 0
for idx in range(16):
    kur = Kurang(puzzle,idx+1)
    sumKurang += kur
    print("| " + str(idx+1) + "\t| " + str(kur) +"\t    |")
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
    answers = solve(puzzle)
    print("===== Time Elapsed : " + str((time.time() - start_time)) + " seconds =====")
    printResult = input("=====[] Visualise Path? : (y/n*) ")
    if printResult == "y":
        print("Printed")
else:
    print("===== Time Elapsed : 0.00000000 seconds =====")



# $ ====================== BRANCH AND BOUND ======================


# $ ====================== PRINT ALL NODES ======================
