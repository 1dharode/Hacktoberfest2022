from random import choice

WRONG_LOSE = 6

# Complete these functions.

def hideLetters(answer, guesses):
    """
    Hides unguessed letters in the answer with '*', leaves punctuation and spaces visible.
    
    Returns:
        str: The answer with unguessed letters hidden.
    """
    result = ""
    for char in answer:
        if char.upper() in guesses.upper() or not char.isalpha():
            result += char  # Show the letter or punctuation
        else:
            result += "*"  # Hide the letter
    return result


def askPlayer(clue, display, guesses, wrong):
    """
    Asks the player for a letter and ensures valid input.
    
    Returns:
        str: A valid letter guessed by the player.
    """
    while True:
        print(f"Clue: {clue}")
        print(f"Puzzle: {display}")
        print(f"Guessed letters: {guesses}")
        print(f"Wrong guesses: {wrong}/{WRONG_LOSE}")
        
        guess = input("Guess a letter: ").strip().upper()
        
        if len(guess) == 1 and guess.isalpha():
            if guess in guesses.upper():
                print(f"You already guessed '{guess}'. Try again.")
            else:
                return guess
        else:
            print("Invalid input. Please guess a single letter.")



# Edit this function to add more choices...

def puzzle():
    """
    Randomly choose a clue and answer for the puzzle.
    
    Returns:
        tuple: A tuple containing the clue and the answer.
    """
    puzzles = [
        ("Sports Team", "TORONTO RAPTORS"),
        ("80's Movie", "RAIDERS OF THE LOST ARK"),
        ("Canadian City", "HALIFAX, NOVA SCOTIA")
    ]
    return choice(puzzles)



# DO NOT EDIT any of the code below.

def play():
    # Initialize the game
    clue, answer = puzzle()
    guesses = ""
    wrong = 0
    display = hideLetters(answer, guesses)

    # Letter guessing loop
    while wrong < WRONG_LOSE and "*" in display:
        letter = askPlayer(clue, display, guesses, wrong)
        guesses += letter
        if letter in answer:
            display = hideLetters(answer, guesses)
        else:
            wrong += 1

    # End the game
    if wrong == WRONG_LOSE:
        print("You lose!")
    else:
        print("You win!")
    print(answer)


# Play the game!
play()