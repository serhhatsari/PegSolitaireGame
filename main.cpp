#include "pegsolitaire.h"

int main()
{

    int board_type, i;
    string board_number, wh_side;
    string option, move, game_type;
    string gameName, fileName;
    vector<PegSolitaire> allGames;
    int play_type;
    bool check_inp = true, flag = false, check_f = true;

    int current_game = 0, other_game = 0;

    allGames.push_back(PegSolitaire("main_game"));

    while (check_f)
    { /* checking if there is any loadable file */

        while (check_inp)
        { /* checking input */
            cout << "\n WELCOME TO THE GAME! \n";
            cout << "To be able to play the game you should choose one of these \n";
            cout << "1: You can to create a new game \n";
            cout << "2: You can load a game from a file \n";
            cout << "Choose a option (1 or 2): ";
            cin >> option;
            check_inp = allGames[current_game].check_input(7, option, allGames);
        }

        check_inp = true;

        if (option[0] == '1')
        { /* if user wants to create a game */

            cout << "\n*You can put any name you want to your new game. \n";
            cout << "*You will use it when you want to switch games or compare games\n";
            cout << "Enter the name of the game you are going to create: ";
            cin >> gameName;
            allGames.pop_back();
            allGames.push_back(PegSolitaire(gameName));
            current_game = allGames.size() - 1;

            while (check_inp)
            { /* taking game mode from the user  */
                cout << "\n\nGAME MODE \n\n";
                cout << "1: HUMAN (you make the moves and if you want computer can play one step for you)\n";
                cout << "2: COMPUTER (Computer plays the game until it ends \n";
                cout << "Choose a option (1 or 2): ";
                cin >> game_type;
                check_inp = allGames[current_game].check_input(7, game_type, allGames);
            }

            allGames[current_game].set_game_type(game_type[0]);
            /* assigning game type */

            check_inp = true;

            while (check_inp)
            { /* taking board type from the user */
                cout << "\nWhich board do you wanna play in (1 to 6):  ";
                cin >> board_number;
                check_inp = (allGames[current_game]).check_input(1, board_number, allGames);
            }

            check_inp = true;
            /* assigning board type */
            allGames[current_game].set_board(board_number[0] - '0');

            check_f = false;
        }

        else if (option[0] == '2')
        {
            /*if user wants to load a game */
            while (check_inp)
            {
                cout << "\n\nIf you dont have any loadable file, just enter q \n";
                cout << "If you file ends with .txt, you should write that too\n";
                cout << "What is the name of the file you are going to load?: ";
                cin >> fileName;
                check_inp = (allGames[current_game]).check_input(5, fileName, allGames);
            }
            check_inp = true;

            if (fileName == "q")
            { /* if there is no loadable game */
                continue;
            }
            else
            {
                check_f = false;
            }
        }
    }

    while (1)
    {

        check_inp = true;

        if (allGames[current_game].get_game_type() == '1')
        { /* if game type is 1 */

            while (allGames[current_game].check_finished())
            {

                while (check_inp)
                {
                    cout << "\tMENU \n";
                    cout << "1: CREATE GAME \n";
                    cout << "2: SWITCH TO ANOTHER GAME \n";
                    cout << "3: COMPARE CURRENT GAME WITH ANOTHER GAME \n";
                    cout << "4: SHOW GAME INFO (number of pegs, number of empty etc...) \n";
                    cout << "5: LOAD A GAME \n";
                    cout << "6: SAVE THE CURRENT GAME \n";
                    cout << "7: EXIT GAME \n";
                    cout << "* When you choose option 4, check the top of the MENU in the terminal, you will see the info \n\n";
                    cout << "Current Board: \n\n";
                    allGames[current_game].print_board();

                    cout << "MOVE OPTIONS: \n";
                    cout << "8: You can enter the move like E4-D , A2-U , C5-R , F3-L by yourself. \n";
                    cout << "9: Computer plays a single step for you. \n";
                    cout << "Choose a option (1 to 9): ";
                    cin >> option;
                    check_inp = allGames[current_game].check_input(2, option, allGames);
                }
                check_inp = true;

                if (option[0] == '1')
                { /* create a game */
                    cout << "\nEnter the name of the game you are going to create: ";
                    cin >> gameName;
                    allGames.push_back(PegSolitaire(gameName));
                    current_game = allGames.size() - 1;

                    while (check_inp)
                    { /* choosing game type */
                        cout << "\nGAME MODE \n";
                        cout << "1: HUMAN (you play and computer can play one step for you)\n";
                        cout << "2: COMPUTER (Computer plays the game until it ends \n";
                        cout << "Choose a option (1 or 2): ";
                        cin >> game_type;
                        check_inp = allGames[current_game].check_input(7, game_type, allGames);
                    }

                    check_inp = true;
                    /* assigning game type to the board */
                    allGames[current_game].set_game_type(game_type[0]);

                    while (check_inp)
                    {
                        cout << "\nWhich board do you wanna play in (1 to 6):  ";
                        cin >> board_number;
                        check_inp = (allGames[current_game]).check_input(1, board_number, allGames);
                    }
                    allGames[current_game].set_board(board_number[0] - '0');

                    /*asking user to enter board type */
                    check_inp = true;

                    flag = true;
                    break;
                }

                else if (option[0] == '2')
                { /* switch to another game */
                    cout << "Existing Games: \n";
                    for (i = 0; i < allGames.size(); i++)
                    {
                        cout << i + 1 << ": " << (allGames[i]).get_name() << endl;
                    }

                    while (check_inp)
                    { /*  taking game name from the user */
                        cout << "Enter the name of the game you are going to switch to: ";
                        cin >> gameName;
                        check_inp = (allGames[current_game]).check_input(3, gameName, allGames);
                    }

                    check_inp = true;

                    for (i = 0; i < allGames.size(); i++)
                    {

                        if ((allGames[i]).get_name() == gameName)
                        { /* finding the index of the game */
                            current_game = i;
                            break;
                        }
                    }

                    flag = true;
                    break;
                }

                else if (option[0] == '3')
                { /* compare games */
                    cout << "Existing Games:\n";
                    for (i = 0; i < allGames.size(); i++)
                    { /* printing the existing games */
                        cout << i + 1 << ": " << (allGames[i]).get_name() << endl;
                    }

                    while (check_inp)
                    {
                        cout << "Enter the name of the game you are going to compare with the current game: ";
                        cin >> gameName;
                        check_inp = (allGames[current_game]).check_input(3, gameName, allGames);
                    }

                    check_inp = true;

                    for (i = 0; i < allGames.size(); i++)
                    { /*  finding the index of the game */

                        if ((allGames[i]).get_name() == gameName)
                        {
                            other_game = i;
                            break;
                        }
                    }

                    if ((allGames[current_game]).compare_games(allGames[other_game]))
                    { /* printing result */
                        cout << "\n\n**************************";
                        cout << "\nTHE RESULT: \n ";
                        cout << "CURRENT GAME HAS MORE PEGS THAN THE COMPARED GAME \n";
                        cout << endl;
                    }
                    else
                    { /* printing the result */
                        cout << "\n\n**************************";
                        cout << "\nTHE RESULT: \n";
                        cout << "COMPARED GAME HAS MORE PEGS THAN THE CURRENT GAME \n";
                        cout << endl;
                    }
                }

                else if (option[0] == '4')
                { /* showing  info about current game */
                    cout << "\n\n ***************************\n";
                    cout << "CURRENT GAME INFO: \n";
                    cout << "NUMBER OF PEGS: " << allGames[current_game].number_of_pegs() << endl;
                    cout << "NUMBER OF EMPTY CELLS: " << allGames[current_game].number_of_empty() << endl;
                    cout << "NUMBER OF PEGS TAKEN: " << allGames[current_game].number_of_taken_pegs() << endl;
                    cout << "NUMBER OF PEGS IN ALL GAMES: " << allGames[current_game].num_of_all_pegs(allGames) << endl;
                    cout << endl;
                }

                else if (option[0] == '5')
                {
                    while (check_inp)
                    { /* taking file name from the user */
                        cout << "\n\nIf you dont have any loadable file, just enter q \n";
                        cout << "What is the name of the file you are going to load?: ";
                        cin >> fileName;
                        check_inp = (allGames[current_game]).check_input(5, fileName, allGames);
                    }
                    check_inp = true;
                    flag = true;
                    break;
                }

                else if (option[0] == '6')
                { /* taking file name from the user */
                    cout << "\n\nValid name formats: serhat.txt , serhat , SERHAT , serhat123\n";
                    cout << "What should be the name of the file? ";
                    cin >> fileName;
                    allGames[current_game].save_board(fileName);
                    cout << "\n\n!!! GAME HAS BEEN SAVED TO THE FILE!!! \n\n";
                }

                else if (option[0] == '7')
                { /* terminating the program */
                    return 1;
                }

                else if (option[0] == '8')
                { /* making a move */
                    while (check_inp)
                    {
                        while (check_inp)
                        { /* making a move */
                            cout << "Examples:  E4-D , A2-U , C5-R , F3-L \n";
                            cout << "Enter your move according to examples: ";
                            cin >> move;
                            check_inp = allGames[current_game].check_input(4, move, allGames);
                        }
                        check_inp = true;

                        if (allGames[current_game].get_board_type() == 6)
                        { /* checking board type */
                            while (check_inp)
                            {
                                if (move[3] == 'D' || move[3] == 'd')
                                { /* if it is down */
                                    cout << "Right(R) or Left(L) \n";
                                    cout << "Enter your direction (R or L): ";
                                    cin >> wh_side;
                                }
                                else if (move[3] == 'U' || move[3] == 'u')
                                { /* if it is up */
                                    cout << "Right(R) or Left(L) \n";
                                    cout << "Enter your direction (R or L): ";
                                    cin >> wh_side;
                                }

                                check_inp = allGames[current_game].check_input(6, wh_side, allGames);
                            }

                            check_inp = true;
                        }
                        else
                        {
                            wh_side = "1";
                        } /*checking input */

                        check_inp = allGames[current_game].check_move(allGames[current_game].find_column_index(move[0]), move[1] - '0', move[3], wh_side[0], 0);
                    }

                    check_inp = true;

                    move += wh_side[0];

                    allGames[current_game].play(move);
                    allGames[current_game].print_board();
                }

                else if (option[0] == '9')
                {
                    /* computer play one step */
                    allGames[current_game].play();
                    allGames[current_game].print_board();
                }
            }

            if (flag)
            {
                flag = false;
                continue;
            }
            /* printing the game result */
            cout << "\n\n ***************************\n";
            cout << "GAME RESULT: \n";
            cout << "NUMBER OF PEGS: " << allGames[current_game].number_of_pegs() << endl;
            cout << "NUMBER OF EMPTY CELLS: " << allGames[current_game].number_of_empty() << endl;
            cout << "NUMBER OF PEGS TAKEN: " << allGames[current_game].number_of_taken_pegs() << endl;
            cout << "\n*NUMBER OF PEGS IN ALL GAMES: " << allGames[current_game].num_of_all_pegs(allGames) << endl;
            cout << endl;
        }

        else if (allGames[current_game].get_game_type() == '2')
        {
            /* computer finishes the game */
            allGames[current_game].playGame();
        }

        while (check_inp)
        { /* showing the menu */
            cout << "\tMENU \n";
            cout << "1: CREATE GAME \n";
            cout << "2: SWITCH TO ANOTHER GAME \n";
            cout << "3: COMPARE GAMES \n";
            cout << "4: SHOW GAME INFO (number of pegs, number of empty etc...) \n";
            cout << "5: LOAD A GAME \n";
            cout << "6: SAVE THE CURRENT GAME \n";
            cout << "7: EXIT GAME \n";
            cout << "* When you choose option 4, check the top of the MENU in the terminal, you will see the info \n\n";
            cout << "Choose a option (1 to 7): ";
            cin >> option;
            check_inp = allGames[current_game].check_input(8, option, allGames);
        }

        check_inp = true;

        if (option[0] == '1')
        { /* if user wants to create a game */
            cout << "Enter the name of the game you are going to create: ";
            cin >> gameName;
            allGames.push_back(PegSolitaire(gameName));
            current_game = allGames.size() - 1;

            while (check_inp)
            { /* it will ask the game mode */
                cout << "\nGAME MODE \n";
                cout << "1: HUMAN (you play and computer can play one step for you)\n";
                cout << "2: COMPUTER (Computer plays the game until it ends \n";
                cout << "Choose a option (1 or 2): ";
                cin >> game_type;
                check_inp = allGames[current_game].check_input(7, game_type, allGames);
            }

            check_inp = true;

            allGames[current_game].set_game_type(game_type[0]);

            while (check_inp)
            { /* taking board number from the user */
                cout << "\nWhich board do you wanna play in (1 to 6):  ";
                cin >> board_number;
                check_inp = (allGames[current_game]).check_input(1, board_number, allGames);
            }

            allGames[current_game].set_board(board_number[0] - '0');

            check_inp = true;
        }

        else if (option[0] == '2')
        { /* printing the existing game names */
            cout << "Existing Games: \n";
            for (i = 0; i < allGames.size(); i++)
            {
                cout << i + 1 << ": " << (allGames[i]).get_name() << endl;
            }

            while (check_inp)
            { /* taking the name of the game which user is gping to switch */
                cout << "Enter the name of the game you are going to switch to: ";
                cin >> gameName;
                check_inp = (allGames[current_game]).check_input(3, gameName, allGames);
            }

            check_inp = true;

            for (i = 0; i < allGames.size(); i++)
            {
                /* finding the index of the game */
                if ((allGames[i]).get_name() == gameName)
                {
                    current_game = i;
                    break;
                }
            }
        }

        else if (option[0] == '3')
        {
            cout << "Existing Games:\n";
            for (i = 0; i < allGames.size(); i++)
            { /* printşng the existing games */
                cout << i + 1 << ": " << (allGames[i]).get_name() << endl;
            }

            while (check_inp)
            {
                cout << "Enter the name of the game you are going to compare with the current game: ";
                cin >> gameName;
                check_inp = (allGames[current_game]).check_input(3, gameName, allGames);
            }

            check_inp = true;

            for (i = 0; i < allGames.size(); i++)
            {

                if ((allGames[i]).get_name() == gameName)
                {
                    other_game = i;
                    break;
                }
            }

            if ((allGames[current_game]).compare_games(allGames[other_game]))
            { /* comparison */
                cout << "\n\n**************************\n\n";
                cout << "\nTHE RESULT: \n ";
                cout << "CURRENT GAME HAS MORE PEGS THAN THE COMPARED GAME \n";
                cout << endl;
            }
            else
            { /* comparison */
                cout << "\n\n**************************\n\n";
                cout << "\nTHE RESULT: \n ";
                cout << "COMPARED GAME HAS MORE PEGS THAN THE CURRENT GAME \n";
                cout << endl;
            }
        }

        else if (option[0] == '4')
        { /* printing info */
            cout << "\n\n ***************************\n";
            cout << "CURRENT GAME INFO: \n";
            cout << "NUMBER OF PEGS: " << allGames[current_game].number_of_pegs() << endl;
            cout << "NUMBER OF EMPTY CELLS: " << allGames[current_game].number_of_empty() << endl;
            cout << "NUMBER OF PEGS TAKEN: " << allGames[current_game].number_of_taken_pegs() << endl;
            cout << "\n*NUMBER OF PEGS IN ALL GAMES: " << allGames[current_game].num_of_all_pegs(allGames) << endl;
            cout << endl;
        }

        else if (option[0] == '5')
        {
            /* taking file name from the user and load a game */
            while (check_inp)
            {
                cout << "\n\nIf you dont have any loadable file, just enter q \n";
                cout << "What is the name of the file you are going to load?: ";
                cin >> fileName;
                check_inp = (allGames[current_game]).check_input(5, fileName, allGames);
            }
            check_inp = true;
        }

        else if (option[0] == '6')
        {
            /* taking file name from the user and save the game */
            cout << "\n\nValid name formats: serhat.txt , serhat , SERHAT , serhat123\n";
            cout << "What should be the name of the file? ";
            cin >> fileName;
            allGames[current_game].save_board(fileName);
            cout << "\n\n!!! GAME HAS BEEN SAVED TO THE FILE!!! \n\n";
        }

        else if (option[0] == '7')
        {
            return 1;
        }
    }
}
