# Change Log

All notable changes to this project will be kept in this document.

## [1.0.0]

- Initial version of the TicTacToe game that was released.

## [1.1.0]

### Added
 - Main Menu at beginning of game
   - two options to choose from: 1) Player v. Player OR 2) Quit Game
 - Games ending in a tie/draw
   - before v1.1.0, games would never end if nobody won
   - games now end if nine (9) turns have been made and nobody had previously won
 - Makefile added to project
   - makefile allows for easier installation and setup of executable file across machines
 
### Changed
 - README.md Installation Steps
   - Installation instructions changed in order to reflect the correct way to run the game using the above makefile

## [1.2.0]

### Added
 - Prevention of overriding previously-selected positions

### Changed
 - src/main.cpp
   - Removed `unistd.h` since it was unused
   - In the `input()` function, changed the variable `int a` to `int userInput` for clarification

## [1.3.0]

### Added
 - Display of who's turn it is
 - Score-keeping functionality
 - Allow for multiple games to be played in a row

### Changed
 - src/main.cpp
   - Added comments to code for better readability
