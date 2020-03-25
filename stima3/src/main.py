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

def Koordinat(puzzle, idx):
    for x in range(len(puzzle)):
        for y in range(len(puzzle[x])):
            if idx == puzzle[x][y]:
                return [x,y]

# $ ====================== MOVEMENT FUNCTIONS ======================
def moveUp(puzzle):
    koor = Koordinat(puzzle,16)
    koorNew = [koor[0]-1,koor[1]]
    temp = puzzle[koorNew[0]][koorNew[1]]
    puzzle[koorNew[0]].insert(koorNew[1],16)
    puzzle[koorNew[0]].remove(temp)
    puzzle[koor[0]].insert(koor[1],temp)
    puzzle[koor[0]].remove(16)

def moveDown(puzzle):
    koor = Koordinat(puzzle,16)
    koorNew = [koor[0]+1,koor[1]]
    temp = puzzle[koorNew[0]][koorNew[1]]
    puzzle[koorNew[0]].insert(koorNew[1],16)
    puzzle[koorNew[0]].remove(temp)
    puzzle[koor[0]].insert(koor[1],temp)
    puzzle[koor[0]].remove(16)

def moveLeft(puzzle):
    koor = Koordinat(puzzle,16)
    puzzle[koor[0]].remove(16)
    puzzle[koor[0]].insert(koor[1]-1,16)

def moveRight(puzzle):
    koor = Koordinat(puzzle,16)
    puzzle[koor[0]].remove(16)
    puzzle[koor[0]].insert(koor[1]+1,16)

# $ ====================== SOLVING FUNCTIONS ======================
def Ci(node):
    print("Ci")

def Gi(puzzle):
    count = 0
    idx = 1
    for x in puzzle:
        for y in x:
            if (y!=16 and y!=idx):
                count += 1
            idx += 1
    return count


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
    moveUp(puzzle)
    printPuzzle(puzzle)
    print("POSISI YANG SALAH: " + str(Gi(puzzle)))
    print("[]=====================[]")
    moveLeft(puzzle)
    printPuzzle(puzzle)
    print("[]=======================[]")
    moveDown(puzzle)
    printPuzzle(puzzle)
    print("[]=======================[]")
    moveRight(puzzle)
    printPuzzle(puzzle)
if solvable%2 == 0:
    print("===== Time Elapsed : " + str((time.time() - start_time)) + " s =====")
    printResult = input("Print Nodes? : (y/n*) ")
    if printResult == "y":
        print("Printed")
else:
    print("===== Time Elapsed : 0.00000000 s =====")



# $ ====================== BRANCH AND BOUND ======================


# $ ====================== PRINT ALL NODES ======================
