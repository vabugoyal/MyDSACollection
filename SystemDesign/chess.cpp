/*
 * Can the game be spectated?
 * Will there be any statics stored for users?
 * Tournaments?
 * Ratings?
 *
 * chessGame :
 *      - track moves made
 *      - store users
 *
 * players
 * chessboard
 * chessBlocks
 * move
 * timer
 * scoreboard
 * gameStatus
 *
 */




class Chess {
public:
    ChessBoard chessBoard;
    Player player[];
    Player currentPlayer;
    GameStatus gameStatus;
    vector<Move> moves;

    bool makeMove(CellPosition start, CellPosition end, Piece piece);
    bool endGame();

private:
    void changeTurn();

};



class Player {
public:
    User user;
    Color color;
    Time timeLeft;

};


class User {
    string username;
    string password;
    string name;
    string phone;
    string email;
};

enum class Color {
    BLACK, WHITE
};

class Time {
    int min, sec;
};

enum class GameStatus {
    ACTIVE, PAUSED, FORTFEIGHT, BLACK_WIN, WHITE_WIN
};

class ChessBoard {
public:
    vector<vector<Cell>> board;
    void resetBoard();
    void updateBoard(Move move);
};


class Cell {
    Color color;
    Piece piece;
    CellPosition cellPosition;
};


class CellPosition {
    char ch;
    int i;
};


class Move {
    Player turn;
    Piece piece;
    Piece killedPiece;
    CellPosition startPosition;
    CellPosition endPosition;
};


class Piece {
    Color color;
    State state;
    virtual vector<CellPosition> possibleMoves(CellPosition fromPosition) = 0;
    virtual bool isValid(CellPosition fromPosition, CellPosition toPosition) = 0;
};










