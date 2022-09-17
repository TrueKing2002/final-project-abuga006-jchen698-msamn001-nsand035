# Chess 100
 
  Authors: [Adolfo Bugarin](https://github.com/TrueKing2002), [Megan Samn](https://github.com/megansamn), [Justin Chen](https://github.com/jc51001), [Nick Sandburg](https://github.com/njsandburg)
 




## Project Description
  * Chess has always been a favorite game of mine ever since I learned how to play it. It's both fun and strategic and every game is different but sure to excite.
  * This game is written in C++ and fully playable on a terminal window
  * The user is able to start a game, selecting whether to play the computer or another player, or load an incomplete game and continue playing. The user inputs the coordinates of the piece they want to move and the coordinates of where they want to move it. They have the option to undo a move and to save the game.
  * Supports all legal moves except for castling and en passant
  * Game ends in either checkmate or stalemate


## Class Diagram
<img width="817" alt="Screen Shot 2022-03-10 at 12 04 42 PM" src="https://user-images.githubusercontent.com/50130189/157745685-a95c17eb-607a-4b23-b0fe-71d3ac550bf6.png">



 The ChessProgram class is responsible for accepting and handling user input and provides all the different options the player can choose to make. Each ChessGame object will contain its own chess game. To interact with the board, ChessGame will make calls to the ChessBoard class which will manage and store the chess board. All the changes to the board will be through calls to this class. Each ChessBoard square will hold a pointer to a ChessPiece object, which itself is an abstract superclass with each type of chess piece being its own instantiable subclass.
 
 The ChessPiece class uses the Strategy design pattern to allow for all chess pieces to share the same exact interface. Each chess piece has two functions that will behave differently depending on what piece it is. This class declares that interface, and each individual chess piece forms its own concrete class that implements its own algorithms for each function in the interface. Thanks to this design pattern, using and storing each chess piece is a lot simpler and intuitive than it would have been if a completely different class for each chess piece was used.




 
 ## Screenshots
 <img width="692" alt="Screen Shot 2022-03-10 at 11 15 54 AM" src="https://user-images.githubusercontent.com/50130189/157738077-65e9af3f-7c36-44f1-8aae-18f6291de712.png">
 
 <img width="693" alt="Screen Shot 2022-03-10 at 12 09 04 PM" src="https://user-images.githubusercontent.com/50130189/157746313-072fa56a-fa48-422a-b855-612c545d29a0.png">



<img width="437" alt="Screen Shot 2022-03-10 at 11 37 06 AM" src="https://user-images.githubusercontent.com/50130189/157741347-ad74ce8a-1737-4ef4-aad4-f7d7b5e6d2db.png">


 ## Installation/Usage
Type in terminal: 

```
g++ main.cpp
./a.out
```

 ## Testing
As we added new features, they were tested using the features we previously implemented. All new features were tested rigorously to make sure they didn't break under any circumstances, including edge cases and extreme inputs. Additionally, in all instances where user input was expected, it was fully tested to verify that all types of inputs were handled and treated appropriately.
 
