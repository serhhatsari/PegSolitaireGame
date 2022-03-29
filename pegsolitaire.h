#ifndef PEGSOLITAIRE_H
#define PEGSOLITAIRE_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

/* This is a enum that has 3 different types of cells. */
enum class cellTypes
{
    NONCELL,
    EMPTY,
    PEG,
};

class PegSolitaire
{

public:
    PegSolitaire();
    PegSolitaire(int board_type);
    PegSolitaire(string gameName);
    PegSolitaire(int row_side, int column_side);
    /* peg solitaire class constructers */

    class Cell
    {
    public:
        Cell(char column_letter, int row_number, cellTypes cell_type);
        Cell(cellTypes cell_type);
        Cell();
        /* cell class constructers */

        void set_type(cellTypes cell_type) { cellType = cell_type; };
        cellTypes get_type() const { return cellType; };
        /* getter setter of cell type */

        void set_row_num(int row_num) { rowNumber = row_num; };
        int get_row_num() const { return rowNumber; };
        /* getter setter of row number */

        void set_column_letter(char col_letter) { columnLetter = col_letter; };
        char get_column_letter() const { return columnLetter; };
        /* getter setter of column letter */

    private:
        char columnLetter;
        int rowNumber;
        cellTypes cellType;
    };

    int number_of_pegs() const;
    int number_of_empty() const;
    int number_of_taken_pegs() const;

    /* information methods */

    static int num_of_all_pegs(vector<PegSolitaire> games);

    string string_parse(string user_input);

    void print_board() const;
    /* display board method */

    void play();
    void play(string move);
    void playGame();
    /* move methods and playgame func */

    void save_board(string file_name) const;
    void load_board(string file_name);
    /* save and load methods */

    bool check_input(int input_type, string user_input, const vector<PegSolitaire> &existingGames);
    bool check_finished() const;
    bool check_move(int col_ind, int row_ind, char direction, char side, int flag);
    bool compare_games(PegSolitaire other_game) const;

    /* some check methods */

    void set_board(int board_type);
    vector<vector<Cell>> get_board() const { return board; };
    /* getter setter of board */

    void set_cell(char column_letter, int row_number, cellTypes cell_type);
    Cell get_cell() { return cell; };
    /* getter setter of cell */

    void set_board_side();
    int get_board_side() const { return boardSide; };
    /* getter setter of board side */

    void set_max_row();
    int get_max_row() const { return max_row; };
    /* getter setter of max_row */

    void set_board_type(int board_type) { boardType = board_type; };
    int get_board_type() { return boardType; };
    /* getter setter of board type */

    void set_max_column();
    int get_max_column() const { return max_column; };
    /* getter setter of max column */

    void set_upper(string upper_input) { upper_word = upper_input; };
    string get_upper() { return upper_word; };
    /* getter setter of upper string */

    void set_name(string gameName) { game_name = gameName; };
    string get_name() const { return game_name; };
    /* getter setter of game name */

    void set_game_type(char g_type) { gameType = g_type; };
    char get_game_type() const { return gameType; };
    /* getter setter of game type */

    int find_column_index(char column_letter);

private:
    Cell cell;
    vector<vector<Cell>> board;
    int boardSide, max_row, max_column, boardType;
    string upper_word, game_name;
    char gameType;
    static int num_all_pegs;
};

#endif