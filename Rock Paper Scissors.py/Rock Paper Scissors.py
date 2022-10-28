# your code goes here



import sys



T = int(sys.stdin.readline())





def winningMove(a, b):

    if a == b:

        return a

    if a == 'R' and b == 'S':

        return 'R'

    if a == 'R' and b == 'P':

        return 'P'



    if a == 'P' and b == 'S':

        return 'S'

    if a == 'P' and b == 'R':

        return 'P'



    if a == 'S' and b == 'P':

        return 'S'

    if a == 'S' and b == 'R':

        return 'R'





for _ in range(T):

    N = int(sys.stdin.readline())

    Move = sys.stdin.readline()

    Moves = [i for i in Move]

    Moves = Moves[:-1]

    myList = []

    for _ in range(N + 1):

        myList.append({})

    if N == 1:

        print(Moves[0])

        continue



    result = ""



    for i in range(len(Moves)):

        temp = Moves[i]

        cat = len(Moves)

        for j in range(i + 1, len(Moves)):

            if temp in myList[j]:

                temp = myList[j][Moves[j - 1]]

                cat = j

                break

            myList[j][temp] = "HERE"

            myList[j]["HERE"] = temp

            temp = winningMove(temp, Moves[j])

        result += temp

        for j in range(i+1,cat):

            if "HERE" in myList[j]:

                myList[j][myList[j]["HERE"]] = temp

                del myList[j]["HERE"]



    print(result)

