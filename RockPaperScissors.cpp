#include<iostream>
#include<time.h>
#include<vector>
#include<string>
using namespace std;

/**
 * @brief function to fetch player choice from terminal input
 * 
 * @param userChoice 
 */
void getUserChoice(int &userChoice){
    cin>>userChoice;
}

/**
 * @brief Get the Computer Choice using random number Generator
 * 
 * @param computerChoice 
 */
void getComputerChoice(int &computerChoice){
    srand(time(0));
    computerChoice = rand()%3;
}

/**
 * @brief function to initialise Result Matrix 
 *  i -> userChoice 
 *  j -> computerChoice
 *  resultMatrix[i][j] = 1 means User WON
 *  resultMatrix[i][j] = 0 means TIE
 *  resultMatrix[i][j] = -1 means User LOST
 */
vector<vector<int> >initialiseResultMatrix(){
    vector<vector<int> >resultMatrix(3,vector<int>(3,0));
    // User - Rock, Computer Paper 
    resultMatrix[0][1]= -1; 
    //User - Scissors, Computer- Paper
    resultMatrix[1][0] = 1;
    // User- Rock, Computer - Scissors
    resultMatrix[0][2] = 1;
    // User- Scissors, Computer - Rock
    resultMatrix[2][0] = -1;
    // User- Paper, Computer- Scissors
    resultMatrix[1][2] = -1;
    // User- Scissors, Computer - Paper
    resultMatrix[2][1] = 1;
    return resultMatrix;
}

/**
 * @brief display all the Rock/Paper/Scissors options to user
 * 
 */
void displayOptions(){
    cout<<"Welcome to the Rock Paper Scissors Game!!"<<endl;
    cout<<"Press 1 for Rock"<<endl;
    cout<<"Press 2 for Paper"<<endl;
    cout<<"Press 3 for Scissors"<<endl;
}

/**
 * @brief Display what options user and computer have choosen
 * 
 * @param computerChoice 
 * @param userChoice 
 */
void displayChoices(int &computerChoice, int &userChoice){
    cout<<"Computer Picked - "<<computerChoice+1<<endl;
    cout<<"You Picked - "<<userChoice<<endl;
}

/**
 * @brief Contains the logic to find the winner of the game and output to the terminal
 * 
 * @param computerChoice 
 * @param userChoice 
 * @param resultMatrix 
 */
void winner(int &computerChoice, int &userChoice, vector<vector<int> >&resultMatrix){
    int result = resultMatrix[userChoice-1][computerChoice];
    if(!result){
        cout<<"It's a TIE!!!"<<endl;
    }else if(result ==1){
        cout<<"Yayy, You WON!!!"<<endl;
    }else{
        cout<<"Ohh No, You Lost:("<<endl;
    }
}

bool playAgain(){
    cout<<"Press 1 if you want to play Again"<<endl;
    int input;
    cin>>input;
    if(input==1)return true;
    return false;

}

// 0 - Rock
// 1 - Paper
// 2 - Scissors

int main(){
    while(true){
        // Display options to the user
        displayOptions();

        // initialise result matrix 
        vector<vector<int> >resultMatrix = initialiseResultMatrix();

        //declare variables for user's choice and computers' choice
        int userChoice, computerChoice;

        // get users's choice from terminal input
        getUserChoice(userChoice);
        
        // get computer's choice using random number generator
        getComputerChoice(computerChoice);

        // display what choices both have made 
        displayChoices(computerChoice, userChoice);

        // decides winner on basis of choices and display it on terminal
        winner(computerChoice, userChoice, resultMatrix);

        //
        bool shouldPlay = playAgain();
        if(!shouldPlay)break;
    }
    

    return 0;
}
