# Tic-Tac-Toe

This is a Project of simple implementation of the vintage Tic-Tac-Toe game, where a player fills an 'X' or 'O' in the 9 spaces of the board.

The game board is stored as a 3x3 2D array of characters, and each player takes turns selecting a cell to place their token ('X' or 'O') until either one player wins or the game ends in a tie.

The program starts by prompting the user to enter the names of the two players. It then enters a loop where it repeatedly displays the game board, asks the current player to select a cell to place their token, and checks if the game has ended.

The function functionTwo() is responsible for getting the player's input and updating the game board. It first prompts the user to enter a number between 1 and 9 corresponding to the cell they want to place their token in. It then uses a series of if-else statements to convert this number into the row and column indices of the game board. If the selected cell is already occupied, the function calls itself recursively to prompt the user to enter a different number.

Once it has determined the row and column indices, the function checks if the selected cell is empty and places the appropriate token there. It also updates the token variable to indicate whose turn it is.

The function functionThree() is responsible for checking if the game has ended. It does this by checking all possible winning combinations of cells and returning true if any one of them is occupied by the same token ('X' or 'O'). If no winning combination is found, it checks if the game has ended in a tie by iterating over all cells and returning false if any empty cell is found. If no empty cells are found, it sets the global variable tie to true to indicate a tie.

The main loop in the main() function repeatedly calls the functionOne(), functionTwo(), and functionThree() functions until the game ends. Once the game has ended, it prints a message indicating which player has won, or that the game has ended in a tie.
