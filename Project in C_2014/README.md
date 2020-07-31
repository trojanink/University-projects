
# Programming in C - Implementation of a game.
Sept 2014 - Jan 2015

Use Data Structures, Lists, Memory(Malloc-Realloc), Structs, Recursion.

In every folder there is a more detailed description of each project in Greek langueage.

Abstract

Implementation of a game where the computer chooses two words (of the same length) from the dictionary, and the player
tries to find a path from one to the other so that at each step exactly one letter changes,
the new word of each step also belongs to the dictionary, and the target word has been found in a limited
number of steps.
At the beginning of the game the player determines how many letters he wants to have the words that the player will choose
computer, in how many steps the path should be found as well as the name of the file that
contains the dictionary.

After the program randomly selects the two words of the desired size (if any), it displays in
player all words in the dictionary that are one letter away from the word starting point. The player chooses one
From these. In the next step, the program shows the player all the words in the dictionary that are far away
by one letter from the last word selected. Options may include words
which have already been selected, and are already on the path.
If the word destination is found before the allowed steps are exhausted, a success message is printed
If the steps are exhausted before the word destination is found, the program prints a failure message.

Optionally, you can add the following functionality at this point: if the player does not have one
find the word destination, then the program only searches retrospectively (using backtracking) to see if
there is a solution, and if so, it displays it on the screen. Note: If you add this extra
functionality will need an extra field in the struct for your lists: In order for
The words that have already been checked must be marked back so that they do not return to the path and
create a "circle". A boolean variable is enough for this.

In any case, the program asks the player if he wants to play again. If so, choose two new words and
repeats the game (with the same or different word length / number of steps, depending on preference
you), otherwise terminates.
