/*
Shawn Oberndorfer
CSC 134 - M6LAB2
11/24/2025
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// Define constants for directions
enum Direction {
    NORTH = 0,
    EAST = 1,
    SOUTH = 2,
    WEST = 3,
    NUM_DIRECTIONS = 4
};

// Direction strings for output
const string DIRECTION_NAMES[NUM_DIRECTIONS] = {
    "north", "east", "south", "west"
};

// Define constants for rooms
enum Room {
    ENTRANCE_HALL = 0,
    LIBRARY = 1,
    KITCHEN = 2,
    GARDEN = 3,
    BASEMENT = 4,
    STUDY = 5,
    OBSERVATORY = 6,
    VAULT = 7,
    NUM_ROOMS = 8
};


int main() {
     bool hasKey = false;
    // Room names array
    string roomNames[NUM_ROOMS] = {
        "Entrance Hall",
        "Library",
        "Kitchen",
        "Garden",
        "Basement",
        "Study",
        "Observatory",
        "Vault"
    };

    string roomDescriptions[NUM_ROOMS] = {
        "A grand entrance hall with a dusty chandelier hanging above.",
        "Walls lined with ancient books. The air smells of old paper.",
        "A spacious kitchen with an old stove and wooden counter.",
        "An overgrown garden with stone pathways and a small fountain.",
        "A dark, damp basement with cobwebs in the corners.",
        "A quiet study with a large oak desk and shelves of journals.",
        "A circular observatory with a cracked telescope pointing skyward.",
        "You step into the vault, its shelves lined with ancient treasures glinting faintly in the dim light and discover the secrets of this house."
    };

    
    // Adjacency list using a 2D array
    // connections[from_room][direction] = to_room or -1 if no connection
    int connections[NUM_ROOMS][NUM_DIRECTIONS];
    
    // Initialize all connections to -1 (no connection)
    for (int i = 0; i < NUM_ROOMS; i++) {
        for (int j = 0; j < NUM_DIRECTIONS; j++) {
            connections[i][j] = -1;
        }
    }
    
    // Define the connections between rooms using the Room enum
    // Entrance Hall connections
    connections[ENTRANCE_HALL][NORTH] = LIBRARY;    // Entrance Hall -> North -> Library
    connections[ENTRANCE_HALL][EAST] = KITCHEN;     // Entrance Hall -> East -> Kitchen
    connections[ENTRANCE_HALL][SOUTH] = -1;         // No connection south
    connections[ENTRANCE_HALL][WEST] = GARDEN;      // Entrance Hall -> West -> Garden
    
    // Library connections
    connections[LIBRARY][NORTH] = -1;               // No connection north
    connections[LIBRARY][EAST] = STUDY;                // No connection east
    connections[LIBRARY][SOUTH] = ENTRANCE_HALL;    // Library -> South -> Entrance Hall
    connections[LIBRARY][WEST] = -1;                // No connection west
    
    // Kitchen connections
    connections[KITCHEN][NORTH] = -1;               // No connection north
    connections[KITCHEN][EAST] = -1;                // No connection east
    connections[KITCHEN][SOUTH] = BASEMENT;         // Kitchen -> South -> Basement
    connections[KITCHEN][WEST] = ENTRANCE_HALL;     // Kitchen -> West -> Entrance Hall
    
    // Garden connections
    connections[GARDEN][NORTH] = -1;                // No connection north
    connections[GARDEN][EAST] = ENTRANCE_HALL;      // Garden -> East -> Entrance Hall
    connections[GARDEN][SOUTH] = -1;                // No connection south
    connections[GARDEN][WEST] = -1;                 // No connection west
    
    // Basement connections
    connections[BASEMENT][NORTH] = KITCHEN;         // Basement -> North -> Kitchen
    connections[BASEMENT][EAST] = -1;               // No connection east
    connections[BASEMENT][SOUTH] = -1;              // No connection south
    connections[BASEMENT][WEST] = -1;               // No connection west

    // Study connections
    connections[STUDY][NORTH] = OBSERVATORY;
    connections[STUDY][EAST] = -1;
    connections[STUDY][SOUTH] = -1;
    connections[STUDY][WEST] = LIBRARY;

    // Observatory connections
    connections[OBSERVATORY][NORTH] = -1;
    connections[OBSERVATORY][EAST] = -1;    
    connections[OBSERVATORY][SOUTH] = STUDY;
    connections[OBSERVATORY][WEST] = VAULT;

    // Vault connections (locked)
    connections[VAULT][NORTH] = -1;
    connections[VAULT][EAST] = OBSERVATORY;
    connections[VAULT][SOUTH] = -1;
    connections[VAULT][WEST] = -1;

    // Game state
    int currentRoom = ENTRANCE_HALL; // Start in the Entrance Hall
    bool gameRunning = true;
    
    // Game loop
    while (gameRunning) {
        // Display current room information
        cout << "\nYou are in the " << roomNames[currentRoom] << endl;
        cout << roomDescriptions[currentRoom] << endl;

        if (currentRoom == BASEMENT) {
            cout << "You notice a rusty key on the floor. Type 'take' to pick it up." << endl;
            string command;
            cout << "\nWhat would you like to do? ";
            cin >> command;
            if (command == "take" || command == "take key") {
                if (currentRoom == BASEMENT) {
                    hasKey = true;
                    cout << "You picked up the rusty key." << endl;
                } else {
                    cout << "You leave the key where it is." << endl;
                }
            }
        }


        
        // Show available exits
        cout << "Exits: ";
        bool hasExits = false;
        for (int dir = 0; dir < NUM_DIRECTIONS; dir++) {
            if (connections[currentRoom][dir] != -1) {
                cout << DIRECTION_NAMES[dir] << " ";
                hasExits = true;
            }
        }
        if (!hasExits) {
            cout << "none";
        }
        cout << endl;
        
        // Get player input
        string command;
        cout << "\nWhat would you like to do? ";
        cin >> command;
        
        // Process movement commands
        if (command == "north" || command == "n") {
            if (connections[currentRoom][NORTH] != -1) {
                currentRoom = connections[currentRoom][NORTH];
            } else {
                cout << "You can't go that way." << endl;
            }
        } else if (command == "east" || command == "e") {
            if (connections[currentRoom][EAST] != -1) {
                currentRoom = connections[currentRoom][EAST];
            } else {
                cout << "You can't go that way." << endl;
            }
        } else if (command == "south" || command == "s") {
            if (connections[currentRoom][SOUTH] != -1) {
                currentRoom = connections[currentRoom][SOUTH];
            } else {
                cout << "You can't go that way." << endl;
            }
        } else if (command == "west" || command == "w") {
        int nextRoom = connections[currentRoom][WEST];
        if (nextRoom != -1) {
            if (nextRoom == VAULT && !hasKey) {
                cout << "The vault door is locked. You need a key." << endl;
                // Do NOT change currentRoom
            } else {
                currentRoom = nextRoom;
            }
        } else {
        cout << "You can't go that way." << endl;
    }
} else if (command == "quit" || command == "q") {
            gameRunning = false;
        } else {
            cout << "I don't understand that command." << endl;
        }
    }
    cout << "Thanks for playing!" << endl;
    return 0;

}