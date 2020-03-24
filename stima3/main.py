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
# $ ====================== FUNCTIONS & METHODS ======================
def readPuzzle(menu):
    filein = "puzzle.txt"
    if menu == 2:
        filein = str(input("File to read (without .txt): "))
        filein = filein + ".txt"
    elif menu == 1:
        filein = "puzzle.txt"
    try:
        f = open(filein,"r")
    except:
        print("File not found, using default file...")
        f = open("puzzle.txt","r")
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


# $ ====================== INPUT FILE ======================
print("[]  / \ / \ / \ / \ / \  []")
print(" \    15 Puzzle Solver   /")
print(" \ - - - - - - - - - - - /")
print(" \         File :        /")
print(" \    1. Use Default     /")
print(" \      (puzzle.txt)     /")
print(" \    2. Input file      /")
print("[]  \ / \ / \ / \ / \ /  []")
print("||")
try:
    menu = int(input("[]=>> "))
except:
    print("Reading default file...")
    menu = 1
puzzleFile = readPuzzle(menu)
print();
# $ ====================== READ & PROCESS FILE ======================
puzzle=[] # Menyimpan matrix
for line in puzzleFile.readlines():
    puzzle.append( [ int (x) for x in line.split(' ') ] )

# $ ====================== POSISI AWAL ======================
print("=====  Posisi Awal =====")
printPuzzle(puzzle);
print()

# $ ====================== KURANG(i) ======================
print("==  Reachable Goal ==")
print("| i\t| Kurang(i) |")
sumKurang = 0
for idx in range(16):
    kur = Kurang(puzzle,idx+1)
    sumKurang += kur
    print("| " + str(idx+1) + "\t| " + str(kur) +"\t    |")
if (Posisi(puzzle, 16)%2 in [2,4,5,7,10,12,13,15]):
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
    printResult = input("Print Nodes? : (y/n*) ")
    if printResult == "y":
        print("Printed")



# $ ====================== BRANCH AND BOUND ======================


# $ ====================== PRINT ALL NODES ======================