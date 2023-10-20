import random

referenceTable =[" 1 " , " 2 " , " 3 " ,
                 " 4 " , " 5 " , " 6" ,
                 " 7 " , " 8 " , " 9 " ]
table = [" _ " , " _ " , " _ " ,
         " _ " , " _ " , " _ " ,
         " _ " , " _ " , " _ "  ]    

Player = "X"
Winner = None
Running = True                     #global variables

print("Welcome to a game of tic tac toe!")
print("The rules of the game are simple!")
print("The gameboard has 9 spaces.")
print("Each player must take turns by putting their mark of 'X' or 'O' in the empty spaces")
print("The first player to get 3 of their marks in a row vertically, horizontally or diagonalluy wins!")

#printing reference table for users
print("This is what the table looks like.")
print("The number you input will be inserted in its respective spot")
print("------------------------------------------------")
print(referenceTable[0] + "       |       " + referenceTable[1] + "       |       " + referenceTable[2])
print("------------------------------------------------")
print(referenceTable[3] + "       |       " + referenceTable[4] + "       |       " + referenceTable[5])
print("------------------------------------------------")
print(referenceTable[6] + "       |       " + referenceTable[7] + "       |       " + referenceTable[8])
print("------------------------------------------------")

#printing the table
def printTable(table):
    print("------------------------------------------------")
    print(table[0] + "       |       " + table[1] + "       |       " + table[2])
    print("------------------------------------------------")
    print(table[3] + "       |       " + table[4] + "       |       " + table[5])
    print("------------------------------------------------")
    print(table[6] + "       |       " + table[7] + "       |       " + table[8])
    print("------------------------------------------------")

#take player input
def playerInput(table):
    playerinp = int(input("Please enter a number from 1-9: "))
    if playerinp >= 1 and playerinp <= 9 and table[playerinp - 1] == " _ ":
        table[playerinp-1] = Player
    else:
        print("Whoops! It seems like that spot is akready taken or that is not a valid number!")
        playerInput(table)

#check for win or tie
def checkHorizontal(table):
    global Winner
    if table[0] == table[1] == table[2] and table[1] != " _ ":
        Winner = table[0]
        return True

    elif table[3] == table[4] == table[5] and table[4] != " _ ":
        Winner = table[3]
        return True
    elif table[6] == table[7] == table[8] and table[6] != " _ ":
        Winner = table[3]
        return True

def checkVertical(table):
    global Winner
    if table[0] == table[3] == table[6] and table[3] != " _ ":
        Winner = table[0]
        return True
    elif table[1] == table[4] == table[7] and table[4] != " _ ":
        Winner = table[1]
        return True
    elif table[2] == table[5] == table[8] and table[5] != " _ ":
        Winner = table[2]
        return True

def checkDiagonal(table):
    global Winner
    if table[2] == table[4] == table[6] and table[2] != " _ ":
        Winner = table[2]
        return True
    elif table[0] == table[4] == table[8] and table[4] != " _ ":
        Winner = table[0]
        return True

def checkTie(table):
    global Running
    if " _ " not in table and Winner == None:
        printTable(table)
        print("There has been a tie")
        return True
    return False   

#switch the player
def switchPlayer():
    global Player
    if Player == "X":
        Player = "O"
    else:
        Player = "X"

#computer generated answer
def computer(table):
    while Player == "O":
        spot = random.randint(0,8)
        if table[spot] == " _ ":
            table[spot] = "O"
            switchPlayer()
    

def checkWin():
    if checkHorizontal(table) or checkVertical(table) or checkDiagonal(table) == True:
        print("The winner is " + Winner)
        return True
    Running = True
    
    return False 

while Running:
    printTable(table)
    playerInput(table)
    if checkWin() == True:
        printTable(table)
        break
    if checkTie(table) == True:
        printTable(table)
        break
    switchPlayer()
    computer(table)
    if checkWin() == True:
        printTable(table)
        break
    if checkTie(table) == True:
        printTable(table)
        break
    