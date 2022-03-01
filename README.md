# Chess 100
 
  Authors: [Adolfo Bugarin](https://github.com/TrueKing2002), [Megan Samn](https://github.com/megansamn), [Justin Chen](https://github.com/jc51001), [Nick Sandburg](https://github.com/njsandburg)
 

 
 > ## Expectations
 > * Incorporate **at least one** design pattern
 >   * It is recommended that you include a design pattern that we will teach this session (Composite, Strategy, or Visitor)
 > * Your project should be implemented in C++. If you wish to choose anoher programming language (e.g. Java, Python), please discuss with your lab TA to obtain permission.
 > * You can incorporate additional technologies/tools but they must be approved (in writing) by the instructor or the TA.
 > * Each member of the group **must** be committing code regularly and make sure their code is correctly attributed to them. We will be checking attributions to determine if there was equal contribution to the project.
 > * Each member of the group must actively participate in the Github Project board and reviewing commited code.
> * All project phases are to be submitted to this GitHub repository. You should modify this README file to reflect the different phases of the project. In addition, you should regularly hold sprint meetings with your group. You will need to hold two scrum/check-in meetings with your lab TA/reader in two different weeks in addition to the final demo.


## Project Description
  * Chess has always been a favorite game of mine ever since I learned how to play it. It's both fun and strategic and every game is different but sure to excite.
  * I plan to code this game in C++
  * The user will be able to start a game, selecting whether to play the computer or another player, or load an incomplete game and continue playing. The user will input the coordinates of the piece they want to move and the coordinates of where they want to move it. They will have the option to undo a move and to save the game.


## Class Diagram
 <img width="820" alt="Screen Shot 2022-02-21 at 9 29 46 PM" src="https://user-images.githubusercontent.com/50130189/156101012-1b241a03-34cd-4607-a310-2542f0fd06af.png">

 The ChessProgram class is responsible for accepting and handling user input and provides all the differenct options the player can choose to make. Each ChessGame object will contain its own chess game. To interact with the board, ChessGame will make calls to the ChessBoard class which will manage and store the chess board. All the changes to the board will be through calls to this class. Each ChessBoard square will hold a pointer to a ChessPiece object, which itself is an abstract superclass with each type of chess piece being its own instantiable subclass.
 
 The ChessPiece class uses the Strategy design pattern to allow for all chess pieces to share the same exact interface. Each chess piece has two functions that will behave differently depending on what piece it is. This class declares that interface, and each individual chess piece forms its own concrete class that implements its own algorithms for each function in the interface. Thanks to this design pattern, using and storing each chess piece is a lot simpler and intuitive than it would have been if a completely different class for each chess piece was used.



 
 > ## Final deliverable
 > All group members will give a demo to the TA/reader during lab time. The TA/reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
