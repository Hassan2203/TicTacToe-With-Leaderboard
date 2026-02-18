#include<iostream>
#include<fstream>
#include<sstream>
#include <vector>
#include <iomanip>
#include <cstdlib>
using namespace std;

void sleep(int hasa)
{
    for(int i=0; i<200*hasa; i++)
    {

    }
}

void displayBoard(char A[3][3])
{
    char ch=176;
    system("cls"); // Clear screen
    sleep(10000);
    cout<<"                                 "<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<endl;
    sleep(10000);
    cout << "                                 "<<ch <<ch  <<ch <<" 0" <<ch <<" 1" <<ch <<" 2" <<ch<<endl;
    sleep(10000);
    cout<<"                                 "<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<endl;
    sleep(10000);
    for (int i = 0; i < 3; ++i)                  // loop to print the board
    {
        ch=178;
        sleep(10000);
        cout << "                                 "<<ch  << i  << ch;
        sleep(10000);
        for (int j = 0; j < 3; ++j)
        {
            cout << " " << A[i][j] << ch;
        }
        ch=176;
        sleep(10000);
        cout << "\n                                 "<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<endl;
    }
}

bool winner(char A[3][3], char player)                  // function which decides the winner
{
    for (int i = 0; i < 3; i++)
    {
        if (A[0][i] == player && A[1][i] == player && A[2][i] == player ||
                A[i][0] == player && A[i][1] == player && A[i][2] == player)

            return true;
    }
    if ((A[0][0] == player && A[1][1] == player && A[2][2] == player) ||
            (A[0][2] == player && A[1][1] == player && A[2][0] == player)                                                      )
        return true;
    else
        return false;

}
bool draw(char A[3][3])                              // function which checks if the game has been draw or not
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (A[i][j] == '_')
            {
                return false;
            }
        }
    }
    return true;
}

struct players                                    // structure for the players name
{
    string player1;
    string player2;
    string temp_player;
};

void computerMove(char A[3][3],char Player)                            // function for the computer's move
{
    int row, col;
    //  srand(time(0));
    while (true)
    {
        row = rand() % 3;
        sleep(200000);
        cout<<"Row :"<<row<<endl;
        col = rand() % 3;
        sleep(200000);
        cout<<"coloumn :"<<col<<endl;
        sleep(1000000);
        if (A[row][col] == '_')
        {
            A[row][col] =Player;
            break;
        }
    }
}

void save_game(char A[3][3], char Player, string player1, string player2, string temp_player)      // it saves the game in a file for 2 human players gameplay
{
    ofstream kinza("2human.txt");
    if (!kinza.is_open())
    {
        cout << "ERROR : Unable to open file to save the game.\n";
    }
    else
    {
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                kinza << A[i][j];
                if (j < 2)
                {
                    kinza << " ";
                }
            }
            kinza << "\n";
        }
        kinza << Player << "\n";
        kinza << temp_player << "\n";
        kinza << player1 << "\n";
        kinza << player2 << "\n";
        kinza.close();
        cout << "Game saved successfully.\n";
    }
}

void save_gamepc(char A[3][3], char Player, string player1, string player2, string temp_player)  // it saves the game in file for human vs pc gameplay
{
    ofstream basit("humanvspc.txt");
    if (!basit.is_open())
    {
        cout << "ERROR : Unable to open file to save the game.\n";
    }
    else
    {
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                basit << A[i][j];
                if (j < 2)
                {
                    basit << " ";
                }
            }
            basit << "\n";
        }
        basit << Player << "\n";
        basit << temp_player << "\n";
        basit << player1 << "\n";
        basit << player2 << "\n";
        basit.close();
        cout << "Game saved successfully.\n";
    }
}

struct Leaderboard
{
    vector<string> names;
    vector<int> wins;
};

void display(string temp_player, const vector<string>& names, const vector<int>& wins)  // it displays the leaderboard in a sorted form
{
    char ch;
    ch=27;
    ch=178;
    cout<<endl;
    for(int i=0; i<34; i++)
    {
        cout<<ch;
    }
    cout<<" Tic Tac Toe ";
    for(int i=0; i<31; i++)
    {
        cout<<ch;
    }
    cout<<endl;
    cout<<endl;
    for(int i=0; i<34; i++)
    {
        cout<<ch;
    }
    cout<<" Leaderboard ";
    for(int i=0; i<31; i++)
    {
        cout<<ch;
    }
    cout<<endl;
    cout<<endl;
    ch=219;
    for(int i=0; i<78; i++)
    {
        cout<<ch;
        sleep(1000);
    }
    cout<<endl;
    cout<<ch<<"\t\tPlayer Names "<<"\t\t"<< ch <<"\t " << "No.of wins \t\t     "<<ch<<endl;
    for(int i=0; i<78; i++)
    {
        cout<<ch;
        sleep(1000);
    }
    cout<<endl;
    for (int i = 0; i < names.size(); ++i)
    {
        cout<< setw(25) << names[i] << setw(25) << wins[i] << " wins \t\t     " << endl;
        cout<<ch<<"----------------------------------------------------------------------------"<<ch<<endl;
    }
    for(int i=0; i<78; i++)
    {
        sleep(1000);
        cout<<ch;
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;

}

void saveToFile(vector<string>& names, vector<int>& wins)    //It saves the winner in file in sorted form
{
    ofstream file("2human_leaderboard.txt");
    if (file.is_open())
    {
        int temp=0;
        string name_temp;
        for (int i = 0; i < names.size(); ++i)   // loop to sort the players with greater number of wins
        {
            for(int j=(i+1); j<names.size(); j++)
            {
                if(wins[i]<wins[j])
                {
                    temp=wins[j];
                    wins[j]=wins[i];
                    wins[i]=temp;

                    name_temp=names[j];
                    names[j]=names[i];
                    names[i]=name_temp;
                }
            }
        }
        for (int i = 0; i < names.size(); ++i)
        {
            file << names[i] << "\t\t " << wins[i] << endl;
        }
        cout<<"The player has been added to the leaderboard successfully "<<endl;
        file.close();
    }
    else
    {
        cout << "Unable to open file to save leaderboard." << endl;
    }
}


void saveToFile1(vector<string>& names, vector<int>& wins)        // It saves the winner in file in sorted form
{
    ofstream file("human_vs_pc_leaderboard.txt");
    if (file.is_open())
    {
        int temp=0;
        string name_temp;

        for (int i = 0; i < names.size(); ++i)    // loop to sort the players with greater number of wins
        {
            for(int j=(i+1); j<names.size(); j++)
            {
                if(wins[i]<wins[j])
                {
                    temp=wins[j];
                    wins[j]=wins[i];
                    wins[i]=temp;

                    name_temp=names[j];
                    names[j]=names[i];
                    names[i]=name_temp;
                }
            }
        }
        for (int i = 0; i < names.size(); ++i)
        {
            file << names[i] << "\t\t\t " << wins[i] << endl;
        }
        cout<<"The player has been added to the leaderboard successfully "<<endl;
        file.close();
    }
    else
    {
        cout << "Unable to open file to save leaderboard." << endl;
    }
}
human_mode()                   // Function for 2 human players gameplay
{
    char A[3][3] = { {'_','_','_'},{'_','_','_'},{'_','_','_'} };
    char Player = 'X';
    bool check = false;
    int row,col;
    players p;
    string again;
    Leaderboard leader;
    ifstream file("2human_leaderboard.txt");    // It open the file where the winners and their number of wins is stored
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            stringstream ss(line);
            string name;
            int win;

            getline(ss, name, '\t'); // Read the complete name until tab character
            ss >> win;               // Read the number of wins

            leader.names.push_back(name);
            leader.wins.push_back(win);
        }
        file.close();
    }
    else
    {
        cout << "No saved leaderboard found." << endl;
    }
    char ch1=178;
    do
    {
    cout<<"------------------------------------------------------------------------"<<endl;
    cout<<ch1<<"\t\t\t\t\t\t\t\t\t" <<ch1<< endl;
    cout << ch1<<"\t\t\t 1- start a new game \t\t\t\t" <<ch1<< endl;
    cout << ch1<<"\t\t\t 2- load the previous game\t\t\t" <<ch1<< endl;
    cout << ch1<<"\t\t\t 3- Display leaderboard \t\t\t" <<ch1<< endl;
    cout << ch1<<"\t\t\t 4- Exit this mode \t\t\t\t" <<ch1<< endl;
    cout<<ch1<<"\t\t\t\t\t\t\t\t\t" <<ch1<< endl;
    cout<<"------------------------------------------------------------------------"<<endl;
    cout<<"Enter your coice : "<<endl;
    int option;
    cin>>option;
    system("cls"); // Clear screen
    if(option==3)                      // if the user selects 3 so it displays the leaderboard
    {
        display(p.temp_player, leader.names, leader.wins);
        human_mode();
        break;
    }
    else if (option==2)           // if the user selects 2 so it loads the previous game
    {
        ifstream hassan("2human.txt");
        if (hassan.is_open())
        {
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    hassan >> A[i][j];
                }
            }
            hassan >> Player;
            hassan.ignore(); // Ignore newline character
            getline(hassan, p.temp_player);
            getline(hassan, p.player1);
            getline(hassan, p.player2);
            cout << "Game loaded successfully.\n";
            hassan.close();
        }
    }
    else if(option==1)                // if the user selects 1 so it starts the new game
    {
        cin.ignore();                 // ignores the buffer
        cout<<"Enter the name of first player : ";
        getline(cin,p.player1);
        cout<<endl;
        cout<<"Enter the name of second player : ";
        getline(cin,p.player2);
        cout<<endl;
        char a;
        int b,symbol;
        string c;
        cout<<"Toss is going to be happen :"<<p.player1<<" enter your choice (H/T) ";
        cin>>a;
        sleep(20000);
        b = rand() % 2;
        sleep(20000);
        if(b==1)
        {
            c="HEAD";
        }
        else if(b==0)
        {
            c="TAIL";
        }
        cout<<"The toss result is : "<< c <<endl;
        sleep(1000000);
        if((b==1  && (a=='H') || a=='h')|| (b==0  && (a=='T' || a=='t')))
        {
            cout<< p.player1 <<" won the toss "<<endl;
            p.temp_player=p.player1;
            cout<<"What symbol do you want to select ? "<<endl;
            cout<<"1- X "<<endl;
            cout<<"2- O "<<endl;
            cin>>symbol;
            if(symbol==1)
            {
                Player='X';
            }
            else if(symbol==2)
            {
                Player='O';
            }
        }
        else if((b==1  && (a=='t') || a=='T')|| (b==1  && (a=='h' || a=='H')))
        {
            cout<< p.player2 <<" won the toss "<<endl;
            p.temp_player=p.player2;
            cout<<"What symbol do you want to select ? "<<endl;
            cout<<"1- X "<<endl;
            cout<<"2- O "<<endl;
            cin>>symbol;
            if(symbol==1)
            {
                Player='X';
            }
            else if(symbol==2)
            {
                Player='O';
            }
        }
        sleep(2000);
    }
    else if(option==4)      // it will exit this mode
    {
        return 1;
    }
    else
    {
        cout<<"Wrong command "<<endl;
        human_mode();
    }
    do
    {
        displayBoard(A);                  // this function call displays the board
        cout<<"______________________________"<<endl;
        cout << "player "<<p.temp_player<<"(" << Player<<")" << " turn   \n";
        cout<<"______________________________"<<endl;
        cout << endl;
        cout << "Enter Row: ";
        cin >> row;
        cout << endl;
        cout << "Enter Col:";
        cin >> col;
        if ((row < 0 || col < 0) || (row >= 3 || col >= 3) || A[row][col] != '_'  )  // if the user provide a wrong input so these conditions are fulfill and he is said to provide the input again
        {
            cout << "invaid Value\n";
            continue; // it skips the loop and restarts
        }
        A[row][col]=Player;
        check =  winner(A, Player);             // function call which checks the condition that whether the player is winner or not
        if (check == true)
        {
            displayBoard(A);
            cout << "Player " << p.temp_player << "(" << Player << ") is Winner\n";
            bool found = false;
            for (int i = 0; i < leader.names.size(); i++)
            {
                if (leader.names[i] == p.temp_player)    // condition to check if the winner is already present in leader board or not
                {
                    leader.wins[i]++;
                    found = true;
                    cout << "Player " << p.temp_player << " exists in leaderboard " << endl;
                    break;
                }
            }
            if (found==false)                                     // if the player is not present in the leader board so his name is placed in the leader board with wins==1
            {
                leader.names.push_back(p.temp_player);
                leader.wins.push_back(1);
                cout << "Player " << p.temp_player << " does not exist in leaderboard " << endl;
            }
            saveToFile(leader.names, leader.wins);   // it saves the winners to file
            break;
        }
        check = draw(A);
        if (check==true)  // function call to check if the game has been drawn or not
        {
            displayBoard(A);
            cout << "Game got Draw\n";
            break;
        }
        string temp;
        if ((Player == 'X') && (p.temp_player==p.player1))   // conditions to change the turn of players
        {
            p.temp_player=p.player2;
            Player = 'O';
        }
        else if ((Player == 'X') && (p.temp_player==p.player2))
        {
            p.temp_player=p.player1;
            Player = 'O';
        }
        else if ((Player == 'O') && (p.temp_player==p.player1))
        {
            p.temp_player=p.player2;
            Player = 'X';
        }
        else if ((Player == 'O') && (p.temp_player==p.player2))
        {
            p.temp_player=p.player1;
            Player = 'X';
        }
        save_game(A,Player,p.player1,p.player2,p.temp_player);
    }
    while (true);
    for(int i=0; i<3; i++)                  // loop to print the character line '_' for a new game play
    {
        for(int j=0; j<3; j++)
        {
            A[i][j]='_';
        }
    }
    cout<<"Do you want to play again?(yes/no)"<<endl;
    cin>>again;
    if(again=="no")
    {
        cout<<endl;
        cout<<"Thanks for playing the game "<<endl;
        return 1;
    }
}while(again=="yes");
}
pc_mode()
{
    char A[3][3] = { {'_','_','_'},{'_','_','_'},{'_','_','_'} };
    char Player = 'X';
    bool check = false;
    int row,col;
    players p;
    string again;
    //system("cls"); // Clear screen
    Leaderboard leader1;
    ifstream file("human_vs_pc_leaderboard.txt");               // It open the file where the winners and their number of wins is stored
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            stringstream ss(line);
            string name;
            int win;

            getline(ss, name, '\t'); // Read the complete name until tab character
            ss >> win;               // Read the number of wins

            leader1.names.push_back(name);
            leader1.wins.push_back(win);
        }
        file.close();
    }
    else
    {
        cout << "No saved leaderboard found." << endl;
    }
    cin.ignore();
    char ch1=178;
    do
    {
    cout<<"------------------------------------------------------------------------"<<endl;
    cout<<ch1<<"\t\t\t\t\t\t\t\t\t" <<ch1<< endl;
    cout << ch1<<"\t\t\t 1- start a new game \t\t\t\t" <<ch1<< endl;
    cout << ch1<<"\t\t\t 2- load the previous game\t\t\t" <<ch1<< endl;
    cout << ch1<<"\t\t\t 3- Display leaderboard \t\t\t" <<ch1<< endl;
    cout << ch1<<"\t\t\t 4- Exit this mode \t\t\t\t" <<ch1<< endl;
    cout<<ch1<<"\t\t\t\t\t\t\t\t\t" <<ch1<< endl;
    cout<<"------------------------------------------------------------------------"<<endl;
    cout<<"Enter your coice : "<<endl;
    int option;
    cin>>option;
    system("cls"); // Clear screen
    if(option==3)                      // if the user selects 3 so it displays the leaderboard
    {
        display(p.temp_player, leader1.names, leader1.wins);
        pc_mode();
        break;
    }
    else if (option==2)             // if the user selects 2 so it loads the previous game
    {
        ifstream saliha("humanvspc.txt");
        if (saliha.is_open())
        {
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    saliha >> A[i][j];
                }
            }
            saliha >> Player;
            saliha.ignore(); // Ignore newline character
            getline(saliha, p.temp_player);
            getline(saliha, p.player1);
            getline(saliha, p.player2);
            cout << "Game loaded successfully.\n";
            saliha.close();
        }
    }
    else if(option==1)           // if the user selects 1 so it starts the new game
    {
        cin.ignore();
        cout<<"Enter your name : ";
        getline(cin,p.player1);
        cout<<endl;
        p.player2="PC";
        cout<<endl;
        p.temp_player=p.player1;
        char a;
        int b,symbol;
        string c;
        cout<<"Toss is going to be happen :"<<p.player1<<" enter your choice (H/T) ";
        cin>>a;
        sleep(10000);
        b = rand() % 2  ;
        sleep(10000);
        if(b==1)
        {
            c="HEAD";
        }
        else if(b==0)
        {
            c="TAIL";
        }
        cout<<"The toss result is : "<< c <<endl;
        sleep(10000);
        if((b==1  && (a=='H') || a=='h')|| (b==0  && (a=='T' || a=='t')))
        {
            cout<< p.player1 <<" won the toss "<<endl;
            p.temp_player=p.player1;
            cout<<"What symbol do you want to select ? "<<endl;
            cout<<"1- X "<<endl;
            cout<<"2- O "<<endl;
            cin>>symbol;
            if(symbol==1)
            {
                Player='X';
            }
            else if(symbol==2)
            {
                Player='O';
            }
        }
        else if((b==1  && (a=='t') || a=='T')|| (b==1  && (a=='h' || a=='H')))
        {
            cout<< p.player2 <<" won the toss "<<endl;
            p.temp_player=p.player2;
            cout<<"What symbol do you want to select ? "<<endl;
            cout<<"0- X "<<endl;
            cout<<"1- O "<<endl;
            sleep(200000);
            symbol =rand()% 2;
            cout<<"Player "<< p.player2 << " choice is :"<<symbol<<endl;
            sleep(200000);
            if(symbol==0)
            {
                Player='X';
            }
            else if(symbol==1)
            {
                Player='O';
            }
        }
        sleep(10000);
    }
    else if(option==4)
    {
        return 1;
    }
    else
    {
        cout<<"Wrong command "<<endl;
        pc_mode();
        break;
    }
    do
    {
        displayBoard(A);            // this function call displays the board
        cout<<"______________________________"<<endl;
        cout << "player "<<p.temp_player<<"(" << Player<<")" << " turn   \n";
        cout<<"______________________________"<<endl;
        if(/*Player == 'X'*/ p.temp_player==p.player1 )
        {
            cout << endl;
            cout << "Enter Row: ";
            cin >> row;
            cout << endl;
            cout << "Enter Col:";
            cin >> col;
            if ((row < 0 || col < 0) || (row >= 3 || col >= 3) || A[row][col] != '_')   // if the user provide a wrong input so these conditions are fulfill and he is said to provide the input again
            {
                cout << "invaid Value\n";
                continue; // it skips the loop and restarts
            }
            A[row][col]=Player;
        }
        else if( p.temp_player==p.player2)
        {
            computerMove(A,Player);                  // function call for computer's move
        }
        check =  winner(A, Player);         // function call which checks the condition that whether the player is winner or not
        if (check == true)
        {
            displayBoard(A);
            cout << "Player " << p.temp_player << "(" << Player << ") is Winner\n";
            bool found = false;
            for (size_t i = 0; i < leader1.names.size(); i++)
            {
                if (leader1.names[i] == p.temp_player)    // condition to check if the winner is already present in leader board or not
                {
                    leader1.wins[i]++;
                    found = true;
                    cout << "Player " << p.temp_player << " exists in leaderboard " << endl;
                    break;
                }
            }
            if (found==false)                                     // if the player is not present in the leader board so his name is placed in the leader board with wins==1
            {
                leader1.names.push_back(p.temp_player);
                leader1.wins.push_back(1);
                cout << "Player " << p.temp_player << " does not exist in leaderboard " << endl;
            }
            saveToFile1(leader1.names, leader1.wins);   // it saves the winners to file
            break;
        }
        check = draw(A);                 // function call to check if the game has been drawn or not
        if (check==true)
        {
            displayBoard(A);
            cout << "Game got Draw\n";
            break;
        }
        if ((Player == 'X') && (p.temp_player==p.player1))       // conditions to change the turn of players
        {
            p.temp_player=p.player2;
            Player = 'O';
        }
        else if ((Player == 'X') && (p.temp_player==p.player2))
        {
            p.temp_player=p.player1;
            Player = 'O';
        }
        else if ((Player == 'O') && (p.temp_player==p.player1))
        {
            p.temp_player=p.player2;
            Player = 'X';
        }
        else if ((Player == 'O') && (p.temp_player==p.player2))
        {
            p.temp_player=p.player1;
            Player = 'X';
        }
        save_gamepc(A,Player,p.player1,p.player2,p.temp_player);

    }
    while (true);
    for(int i=0; i<3; i++)         // loop to print the character line '_' for a new game play
    {
        for(int j=0; j<3; j++)
        {
            A[i][j]='_';
        }
    }
    cout<<"Do you want to play again?(yes/no)"<<endl;
    cin>>again;
    if(again=="no")
    {
        cout<<endl;
        cout<<"Thanks for playing the game "<<endl;
        return 1;
    }
    }while(again=="yes");
}
int main()
{
    char ch1=178;
    int option;
    cout<<"-----------------------NOUGHTS AND CROSSES GAME--------------------------------"<<endl;
    cout<<"------------DEVELOPED By: HASSAN ALI AHMAD  &   KINZA WAJID--------------------"<<endl;
    cout<<endl;
    cout<<"-------------------------------------------------------------------------------"<<endl;
    cout<<ch1<<"Rules of the game :                                                         "<<ch1<<endl;
    cout<<ch1<<"1.Only empty spaces can be filled, Over writing is not allowed              "<<ch1<<endl;
    cout<<ch1<<"2.Matching 3 noughts or crosses in horizontal, vertical or diagonal will win"<<ch1<<endl;
    cout<<"-------------------------------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<"-------------------------------------------------------------------------------"<<endl;
    cout<<ch1<<" \t\t\t\t\t\t\t                "<<ch1<<endl;
    cout<<ch1<<" what action do you want to perform ?                                  "<<ch1<<endl;
    cout<<ch1<<" \t\t\t\t\t\t\t                "<<ch1<<endl;
    while (1)
    {
        cout << ch1<<"\t\t\t 1-Human vs Human \t\t\t\t" <<ch1<< endl;
        cout << ch1<<"\t\t\t 2-Human vs Computer \t\t\t\t" <<ch1<< endl;
        cout << ch1<<"\t\t\t 3-Exit \t\t\t\t\t" <<ch1<< endl;
        cout<<ch1<<" \t\t\t\t\t\t\t                "<<ch1<<endl;
        cout<<"-------------------------------------------------------------------------------"<<endl;
        cout << "Enter your choice : "<<endl;
        int choi;
        cin >> choi;
        system("cls"); // Clear screen
        switch (choi)
        {
        case (1):
        {
            system("cls"); // Clear screen
            human_mode();      // function call to play the game for human vs human mode
            break;
        }
        case (2):
        {
            system("cls"); // Clear screen
            pc_mode();      // function call to play the game for human vs PC mode
            break;
        }
        case (3):
        {
            cout<<"Thanks for playing the game "<<endl;
            return 0;
        }
        default:
            cout << "Invalid choice, try again." << endl;
        }
    }
}




//                                   References
//               1)   Ascii value
//                         https://theasciicode.com.ar/extended-ascii-code/black-square-ascii-code-254.html
//               2)   clear screen
//                         https://www.sololearn.com/en/Discuss/1897226/how-can-i-clear-screen-when-user-input-something-in-c
//               3)   Code with harry
//                         https://www.codewithharry.com/tutorial/cplusplus/

