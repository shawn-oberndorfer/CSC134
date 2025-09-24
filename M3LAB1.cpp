#include <iostream>
using namespace std;


int Tavern();
int Forest();
int Mountains1();
int Mountains2();
int invalidInput();
int gameOver();
int victory();

bool validInput = true;
bool hasBeenForest = false;
bool hasKey = false;
int playerChoice;
int playerDialougeChoice;
int locationChoice;


int main(){

    Tavern();
    do{
    if(locationChoice == 1){
        Forest();
    }
    else if(locationChoice == 2){
        Mountains1();
    }
    else{
        invalidInput();
        validInput = false;
    }
    }while(validInput == false);

    if(locationChoice == 1 && hasBeenForest == true){
        Mountains2();
    }
    else if(locationChoice == 2 && hasBeenForest == false){
        Forest();
    }
    if(locationChoice == 2 && hasBeenForest == true){
        Mountains2();
    }
    return 0;
}
int Tavern(){
    cout << "Your adventure begins in a small tavern right on the edge of Ashbrooke, the bustling capital of the land." << endl;
    cout << "You are lurking in one of the dark corners of the tavern, devising a plan to get inside the city. When suddenly you feel " << endl;
    cout << "the presence of watching eyes on your back. You look around and notice the taverkeep staring at you." << endl;
    cout << endl;
    cout << "What do you do?" << endl;
    cout << "1. Approach the man." << endl;
    cout << "2. Stay where you are." << endl;
    do{
    cin >> playerChoice;
    if(playerChoice == 1){
        do{
        cout << "You get up slowly and approach the tavernkeep." << endl;
        cout << endl;
        cout << "Tavernkeep: Why hello adventurer what brings you to my lovely tavern?" << endl;
        cout << endl;
        cout << "Your Response:" << endl;
        cout << "1. I have come to town on buisness and stopped to rest." << endl;
        cout << "2. That is none of your buisness." << endl;
        cin >> playerDialougeChoice;
        if(playerDialougeChoice == 1){
            cout << "Tavernkeep: Well I have been in need of someone to help me with some buisness of my own." << endl;
            cout << "Two days ago a bandit robbed a transport of mine that had ale and food in it. My tavern can't survie withoout the extra resources." << endl;
            cout << "So what do you say adventure will you help me?" << endl;
            cout << endl;
            cout << "Your Response:" << endl;
            cout << "1. Yes I will help you." << endl;
            cout << "2. What is in it for me?" << endl;
            cin >> playerDialougeChoice;
            do{
            if(playerDialougeChoice == 1){
                cout << "Tavernkeep: Thank you adventurer. The areas they are seen the most would be the Mountains and the Forest." << endl;
                cout << "I am sure you will find their hideout at one of those spots. And if you can bring my goods back I can even help you get into the city" << endl;
                validInput = true;
            }
            else if(playerDialougeChoice == 2){
                cout << "Tavernkeep: I can help you get into the city if you can retreive the goods for me." << endl;
                cout << "The areas they are seen the most would be the Mountains and the Forest. I am sure you will find their hideout at one of those spots." << endl;
            }
            else{
                cout << "That is not a Valid input. Enter the number that corresponds to your choice." << endl;
                validInput = false;
            }
            }while(validInput == false);
        }
        else if(playerDialougeChoice == 2){
            cout << "Tavernkeep: Whoa! Someone is feisty. Even if your not willing to share your buisness mine helping me out with some of mine?" << endl;
            cout << "Two days ago a bandit robbed a transport of mine that had ale and food in it. My tavern can't survie withoout the extra resources." << endl;
            cout << "So what do you say adventure will you help me?" << endl;
            cout << endl;
            cout << "Your Response:" << endl;
            cout << "1. Yes I will help you." << endl;
            cout << "2. What is in it for me?" << endl;
            do{
            if(playerDialougeChoice == 1){
                cout << "Tavernkeep: Thank you adventurer. The areas they are seen the most would be the Mountains and the Forest." << endl;
                cout << "I am sure you will find their hideout at one of those spots. And if you can bring my goods back I can even help you get into the city" << endl;
                validInput = true;
            }
            else if(playerDialougeChoice == 2){
                cout << "Tavernkeep: I can help you get into the city if you can retreive the goods for me." << endl;
                cout << "The areas they are seen the most would be the Mountains and the Forest. I am sure you will find their hideout at one of those spots." << endl;
            }
            else{
                cout << "That is not a Valid input. Enter the number that corresponds to your choice." << endl;
                validInput = false;
            }
            }while(validInput == false);
        }
        else{
            cout << "That is not a Valid input. Enter the number that corresponds to your choice." << endl;
        validInput = false;
        }
        }while(validInput == false);
    } 
    else if(playerChoice == 2){
        cout << "You stay seated where you are." << endl;
        cout << "After a few minutes the tavernkeep walks over to your table and sits down." << endl;
        cout << "Tavernkeep: Hello adventurer. Do you think you would have some time to assist me with some buisness of mine." << endl;
        cout << "Two days ago a bandit robbed a transport of mine that had ale and food in it. My tavern can't survie withoout the extra resources." << endl;
        cout << "So what do you say adventure will you help me?" << endl;
        cout << endl;
        cout << "Your Response:" << endl;
        cout << "1. Yes I will help you." << endl;
        cout << "2. What is in it for me?" << endl;
        cin >> playerDialougeChoice;
        do{
        if(playerDialougeChoice == 1){
            cout << "Tavernkeep: Thank you adventurer. The areas they are seen the most would be the Mountains and the Forest." << endl;
            cout << "I am sure you will find their hideout at one of those spots. And if you can bring my goods back I can even help you get into the city" << endl;
            validInput = true;
        }
        else if(playerDialougeChoice == 2){
            cout << "Tavernkeep: I can help you get into the city if you can retreive the goods for me." << endl;
            cout << "The areas they are seen the most would be the Mountains and the Forest. I am sure you will find their hideout at one of those spots." << endl;
            validInput = true;
        }
        else{
            cout << "That is not a Valid input. Enter the number that corresponds to your choice." << endl;
            validInput = false;
        }
        }while(validInput == false);
    }
    else {
        cout << "That is not a Valid input. Enter the number that corresponds to your choice." << endl;
        validInput = false;
    }
    }while(validInput == false);
    cout << endl;
    cout << endl;
    cout << "As you leave the tavern where do you decide to explore first." << endl;
    cout << "1. The Forest" << endl;
    cout << "2. The Mountains" << endl;
    cin >> locationChoice;
    return 0;
}


int Forest(){
    cout << "You venture into the forest in search of the bandits." << endl;
    cout << endl;
    cout << endl;
    cout << "You stumble upon the wreck of the tavernkeep's shipment and decide to investigate for clues." << endl;
    cout << endl;
    cout << "What Do You Do?" << endl;
    cout << "1. Investigate the bodies." << endl;
    cout << "2. Investigate the rumbling in the bushes." << endl;
    cout << "3. Investigate the carriage." << endl;
    cin >> playerChoice;
    do{
    if(playerChoice == 1){
        cout << "As you approach the bodies of what appear to be a bandit and three of the shipment's guards you notice marks on the ground that lead to a nearby bush." << endl;
        cout << "What Do You Do" << endl;
        cout << "1. Investigate the bush." << endl;
        cout << "2. Investigate the carriage." << endl;
        do{
        cin >> playerChoice;
        if(playerChoice == 1){
            cout << "As you look into the bush a bandit jumps out at you and attacks you. He slashes at you arm and hits your sleeve ripping your cloak." << endl;
            cout << "You respond quickly and end the bandit swiftly before he can cause your attire more harm. As you are searching his body you find an old rusty key." << endl;
            hasKey = true;
            cout << endl;
            cout << "With the key in hand and no sight of the bandit hideout you decide to head to the mountains to search." << endl;
             
        } 
        else if(playerChoice == 2){
            cout << "As you search the inside of the carriage a bandit jumps out of the bushes and cuts you down" << endl;
            gameOver();
        }
        else{
            cout << "That is not a Valid input. Enter the number that corresponds to your choice." << endl;
            validInput = false;
        }
        }while(validInput == false);

    } 
    else if(playerChoice == 2){
        cout << "As you search the bush you find a bandit resting. Beside him lies a rusty key. You grab the key from him and decide to go to the mountains " << endl;
        cout << "to search for the bandit hideout." << endl;
    }
    else if(playerChoice == 3){
        cout << "You approach the carriage to investigate." << endl;
        cout << "All you find in the carriage is destroyed barrels and the body of a guard." << endl;
        cout << "What Do You Do" << endl;
        cout << "1. Investigate the bush." << endl;
        cout << "2. Investigate the bodies." << endl;
        do{
        cin >> playerChoice;
        if(playerChoice == 1){
            cout << "As you look into the bush a bandit jumps out at you and attacks you. He slashes at you arm and hits your sleeve ripping your cloak." << endl;
            cout << "You respond quickly and end the bandit swiftly before he can cause your attire more harm. As you are searching his body you find an old rusty key." << endl;
            hasKey = true;
            cout << endl;
            cout << "With the key in hand and no sight of the bandit hideout you decide to head to the mountains to search." << endl;
             
        } 
        else if(playerChoice == 2){
            cout << "As you search around the bodies a bandit jumps out of the bushes and cuts you down" << endl;
            gameOver();
        }
        else{
            cout << "That is not a Valid input. Enter the number that corresponds to your choice." << endl;
            validInput = false;
        }
        }while(validInput == false);


    }
    else{
        cout << "That is not a Valid input. Enter the number that corresponds to your choice." << endl;
        validInput = false;
    }
    }while(validInput == false);
    hasBeenForest = true;
    return 0;
}
int Mountains1(){

    return 0;
}
int Mountains2(){

    return 0;
}
int invalidInput(){
    cout << "Enter a valid number that corresponds to your choice." << endl;
    cin >> locationChoice;
    return 0;
}
int gameOver(){
    cout << "------------" << endl;
    cout << "| You Lose |" << endl;
    cout << "------------" << endl;
    cout << endl;
    cout << "Thanks for playing." << endl;
    return 0;
}
int victory(){
    cout << "------------" << endl;
    cout << "| You Win! |" << endl;
    cout << "------------" << endl;
    cout << endl;
    cout << "Thanks for playing." << endl;
    return 0;
}