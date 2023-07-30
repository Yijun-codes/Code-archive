### Archive of codes in C++
 
I have written codes for several mini-game programs, a lite work timer, and a self-implemented Stack for Reverse Polish Notation evaluation. The mini-game programs and the self-implementation of Stack are the challenging tasks I found to evaluate my programming skills, while the lite work timer is a useful tool that I developed to help me in my real work and study. These programs are briefly described below

+ Mini-game 1: [```Dots_and_Triangles```](https://github.com/Yijun-codes/Code-archive/tree/main/c%2B%2B/Dots_and_Triangles)
  + A two-player paper-and-pencil game
  + Starting with an empty diamond grid of dots, two players take turns adding one line between two un-joined adjacent dots.
  + Completing a third side of a size-1 triangle earns one point and takes an extra step.
  + Game end when the grid is full, the player with the more point (score) wins!

+ Mini-game 2: [```Connect_Four```](https://github.com/Yijun-codes/Code-archive/tree/main/c%2B%2B/Connect_Four)
  + Starting with a vertically-suspended board with the size of 6 rows and 7 columns.
  + Two players X and O take turns to drop their discs on the board.
  + The player who first forms a line of four or more of his/her discs wins.
  + The game is a draw when the board is full but no player wins.
    
+ Mini-game 3: [```Gomoku```](https://github.com/Yijun-codes/Code-archive/tree/main/c%2B%2B/Gomoku)
  + Starting with an empty N x N square board.
  + Two players take turns putting discs on the board.
  + The player who first forms a line of five or more consecutive discs wins.
  + A line can be along 4 directions: horizontal '—', vertical '|', northwest-southeast diagonal '\\', and the northeast-southwest diagonal '/'.
  + The game is a draw when the board is full but no player wins.
    
+ Mini-game 4: [```Hex```](https://github.com/Yijun-codes/Code-archive/tree/main/c%2B%2B/Hex)
  + A two-player game played on an initially empty diamond game board, with the size 11x11.
  + Two players take turns placing their pieces on empty cells of the board.
  + The goal of the first player is to form a chain of his/her pieces connecting the left and right border of the board, while the goal of the second player is to form a chain of his/her pieces connecting the top and bottom border of the board.
  + The player who first achieves his/her goal is the winner (no draw game).
    
+ Self-implemented Stack for RPN evaluation: [```Stack(RPN_calculation)```](https://github.com/Yijun-codes/Code-archive/tree/main/c%2B%2B/Stack)
  + First, I implemented a Stack with a class, which supports pop and push functions and stores a sequence of values in the last-in-first-out order.
  + Then, as a small challenge, I wrote a client program to apply the Stack class to evaluate the postfix notation or reverse polish notation (RPN).
  + If the input is a legal RPN, the program returns the value. Otherwise, print out errors and exit.
    
+ Work timer: [```Work_Time_Record```](https://github.com/Yijun-codes/Code-archive/tree/main/c%2B%2B/Work_Time_Record)
  + This program was developed to record my actual work/study time each day.
  + It supports 'pause' and 'resume' functions so that I can precisely record the time I spent on my work/study.
  + When the program is terminated, it will output all records (including when I start the job, when I pause/resume it, and how long in total I spend on it) into a daily log file.

Should you have any questions about the programs, please [contact me](yijun8909@gmail.com)
