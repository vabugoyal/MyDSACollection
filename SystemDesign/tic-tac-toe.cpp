#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "myprettyprint.hpp"
#else
#define dbg(...)
#endif

enum class PieceType {
    X, O
};

class Piece {
    PieceType type;
public:
    Piece(PieceType type) : type(type) {}

    PieceType getType() {
        return type;
    };

    string getName() {
        switch (type) {
            case PieceType::X :
                return "X";
            case PieceType::O :
                return "O";
            default:
                return "";
        }
    }
};

class Board {
    int size;
    vector<vector<Piece *>> board;
public:
    Board(int size) : size(size), board(vector<vector<Piece*>>(size, vector<Piece*>(size, NULL))) {}

    void printBoard() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << (board[i][j] ? board[i][j]->getName() : " ") << "  |";
            }
            cout << endl;
        }
    }

    bool setPiece(int x, int y, PieceType type) {
        if (board[x][y]) {
            cout << "Place already occupied";
            return false;
        }
        board[x][y] = new Piece(type);
        return true;
    }
    Piece * getPiecePtr(int x, int y) {
        return board[x][y];
    }

    int getSize() { return size; }
};

class Player {
    string name;
    PieceType type;
public:
    Player(string name, PieceType type) : name(name), type(type) {}

    PieceType getType() {
        return type;
    }

    string getName() {
        return name;
    }
};

class Game {
    Board board;
    deque<Player> playerTurns;

public:
    Game(): board(3) {
        Player playerX = Player("X", PieceType::X);
        Player playerO = Player("O", PieceType::O);
        playerTurns.push_back(playerX);
        playerTurns.push_back(playerO);
    }

    void startGame() {
        int winner = 0;
        while (not winner) {
            Player currPlayer = playerTurns.front();
            board.printBoard();
            cout << currPlayer.getName() << "'s turn" << endl;
            cout << "Chose a position to place your piece" << endl;
            int x, y; cin >> x >> y;
            int placed = board.setPiece(x, y, currPlayer.getType());
            dbg(placed);
            if (not placed) {
                continue;
            } else {
                playerTurns.pop_front();
                playerTurns.push_back(currPlayer);
            }

            if (checkIfTie()) {
                cout << "Game is a tie" << endl;
                break;
            };
            if (checkIfPlayerWon(currPlayer)) {
                cout << currPlayer.getName() << " has won" << endl;
                break;
            }
        }
    };

    bool checkIfPlayerWon(Player player) {
        PieceType type = player.getType();
        for (int i = 0; i < board.getSize(); i++) {
            bool rowMatch = true;
            for (int j = 0; j < board.getSize(); j++) {
                if (not board.getPiecePtr(i, j)) {rowMatch = false;
                    continue;}
                if (board.getPiecePtr(i, j)->getType() != type) rowMatch = false;
            }
            if (rowMatch) return true;
        }
    }

    bool checkIfTie() {
        for (int i = 0; i < board.getSize(); i++) {
            for (int j = 0; j < board.getSize(); j++) {
                if (board.getPiecePtr(i, j) == nullptr) return false;
            }
        }
        return true;
    }

};




int main() {

    Game game =  Game();
    game.startGame();





    return 0;
}
