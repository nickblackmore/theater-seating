#pragma once

// Seating manager class //////////////////////////////////////////////////////////////////////////

class CSeatingManager {
public:

	// Constructor / deconstructor
	CSeatingManager();								// constructor that sets all seats in m_Seating[][] to SEAT_AVAILABLE
	~CSeatingManager();

	// Menu logic
	void WelcomeMsg( void );						// show splash screen
	void runMainMenu( void );						// shows main menu, selection branches to other menus
	void runSellSeatsMenu( void );					// shows seating map, asks for seats to be sold, and confirms
	void runSeatingStatsMenu( void );				// shows statistics about seating
	void runSalesStatsMenu( void );					// shos dollar statistics about sales

	// Helpers
	int getInputInt( void );						// gets a number from user, won't return with value until # is entered
	bool getInputYesNo( void );						// gets 'y' or 'n' from user, won't return with true/yes or false/no until 'y' or 'n' is entered

	void showSeatingMap( void );					// draws the seating map when called

private:

	// Variables
	char m_Seating[THEATER_TOTAL_ROWS][THEATER_SEATS_PER_ROW];	// holds a char to represent the status of each seat; SEAT_SOLD and
																// SEAT_AVAILABLE constants from TheaterSeating.h are the characters
																// to use for checking/setting a seat sold or available
};
