# Muxi-CS103
# Stanford-CS106


### Part A: Word Ladder

 <p>A word ladder is a connection from one word to another formed by changing one letter at a time with the constraint that at each step the sequence of letters still forms a valid word. For example, here is a word ladder connecting the word "code" to the word "data". Each changed letter is underlined as an illustration:</p>

 <p>code → cade → cate → date → data</p>

 <p>There are many other word ladders that connect these two words, but this one is the shortest. That is, there might be others of the same length, but none with fewer steps than this one.</p>

 <p>In the first part of this assignment, write a program that repeatedly prompts the user for two words and finds a minimum-length ladder between the words. You must use the Stack and Queue collections from Chapter 5, along with following a particular provided algorithm to find the shortest word ladder. This part is simpler than Part B. Here is an example log of interaction between your program and the user (with console input underlined):</p>

 ```
 Welcome to CS 106B Word Ladder.
 Please give me two English words, and I will change the
 first into the second by changing one letter at a time.

 Dictionary file name? dictionary.txt

 Word #1 (or Enter to quit): code
 Word #2 (or Enter to quit): data
 A ladder from data back to code:
 data date cate cade code

 Word #1 (or Enter to quit):
 Have a nice day.
 ```


### Part B: Random Writter

<p>In the second part of this assignment, you will write a program that reads an input file and uses it to build a large data structure of word groups called "N- grams" as a basis for randomly generating new text that sounds like it came from the same author as that file. You will use the Map and Vector collections from Chapter 5. Bellow is an example log of interaction between your program and the user (console input underlined). But what, you may ask, is an N-gram?</p>

```
Welcome to CS 106B Random Writer ('N-Grams').
This program makes random text based on a document.
Give me an input file and an 'N' value for groups
of words, and I'll create random text for you.

Input file name? hamlet.txt
Value of N? 3

# of random words to generate (0 to quit)? 40
... chapel. Ham. Do not believe his tenders, as you
go to this fellow. Whose grave's this, sirrah?
Clown. Mine, sir. [Sings] O, a pit of clay for to
the King that's dead. Mar. Thou art a scholar; speak
to it. ...

# of random words to generate (0 to quit)? 20
... a foul disease, To keep itself from noyance; but
much more handsome than fine. One speech in't I
chiefly lov'd. ...

# of random words to generate (0 to quit)? 0
Exiting.
```
