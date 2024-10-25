board = [["0", "1", "2"],
         ["3", "4", "5"],
         ["6", "7", "8"]]

def print_board():
    for row in board:
        print(row)
        print()

def check_game(mark):
    # Check rows
    for i in range(3):
        if board[i][0] == mark and board[i][1] == mark and board[i][2] == mark:
            return True

    # Check columns
    for i in range(3):
        if board[0][i] == mark and board[1][i] == mark and board[2][i] == mark:
            return True

    # Check diagonals
    if board[0][0] == mark and board[1][1] == mark and board[2][2] == mark:
        return True
    if board[0][2] == mark and board[1][1] == mark and board[2][0] == mark:
        return True

    return False

def play_tic():
    current_player = "1"
    mark = "X"
    moves = 0

    while moves < 9:
        print_board()
        print("Player " + current_player + "'s Move.")
        print("Enter the cell number (0-8): ")

        cell = int(input())
        
        row = cell // 3
        col = cell % 3

        if board[row][col] != "X" and board[row][col] != "O":
            board[row][col] = mark
            moves += 1
            
            if check_game(mark):
                print_board()
                print("Player " + current_player + " Wins!!!!!")
                break
            
            # Switch players
            if current_player == "1":
                current_player = "2"
                mark = "O"
            else:
                current_player = "1"
                mark = "X"
        else:
            print("This cell is already occupied, Try another one!")
            continue

    if moves == 9:
        print_board()
        print("No one has won the game, it's a Draw!!!!!!!!")

play_tic()
