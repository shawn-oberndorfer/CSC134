#include <iostream>
using namespace std;


int startArea();
int areaTwo1();
int areaTwo2();

bool validInput = true;
int playerChoice;
int playerDialougeChoice;
int locationChoice;


int main(){

    startArea();
    if(locationChoice == 1){

    }
    else if(locationChoice == 2){

    }
    else{
        
    }


    return 0;
}
int startArea(){
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
}
int areaTwo1(){

}
int areaTwo2(){

}
