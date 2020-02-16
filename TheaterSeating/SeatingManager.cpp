
/*****************************************************/
/**       ASSIGNMENT: Theater Seating Program       **/
/**             NAME: Learning Team B               **/
/**            CLASS: PRG 410                       **/
/**         DUE DATE: 03/19/2018                    **/
/**       INSTRUCTOR: Jibing Xiao                   **/
/*****************************************************/

// Includes ///////////////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"

// Name space resolutions /////////////////////////////////////////////////////////////////////////

using std::cout;
using std::cin;
using std::endl;

// Constructor ////////////////////////////////////////////////////////////////////////////////////

CSeatingManager::CSeatingManager() {
	// Initialize all seats to available (the constant value of SEAT_AVAILABLE as defined in TheaterSeating.h)
	for ( int x = 0 ; x < THEATER_TOTAL_ROWS; x++ ) {
		for ( int y = 0; y < THEATER_SEATS_PER_ROW; y++ ) {
			m_Seating[x][y] = SEAT_AVAILABLE;
		}
	}

	return;
}

// Deconstructor //////////////////////////////////////////////////////////////////////////////////

CSeatingManager::~CSeatingManager() {
	return;
}

// Display a splash screen / welcome message //////////////////////////////////////////////////////

void CSeatingManager::WelcomeMsg( void ) {
	cout << "/*****************************************************/\n";
	cout << "/**       ASSIGNMENT: Theater Seating Program       **/\n";
	cout << "/**             NAME: Learning Team B               **/\n";
	cout << "/**            CLASS: PRG 410                       **/\n";
	cout << "/**         DUE DATE: 03/26/2018                    **/\n";
	cout << "/**       INSTRUCTOR: Jibing Xiao                   **/\n";
	cout << "/*****************************************************/\n";

	return;
}

// Main menu logic ////////////////////////////////////////////////////////////////////////////////

void CSeatingManager::runMainMenu( void ) {
	// Variables
	bool selectionMade = false;		// to break from main menu into another branch of logic
	int input = 0;					// for storing input from user
	
	// Start main menu loop
	do {
		// Show seating chart
		cout << "Current Seating Chart - Available = #   Sold = *\n";
		showSeatingMap();
		cout << "\n";

		// Display main menu
		cout << "Theater Seating Program - Main Menu\n";
		cout << "1) Sell ticket(s)\n";
		cout << "2) Seating Statistics\n";
		cout << "3) Sales Statistics\n";
		cout << "4) Quit Seating Program\n";
		cout << "Enter your selection (1-4): ";

		// Get selection from user
		input = getInputInt();

		// Act on input
		switch ( input ) {
		case 1:				// sell tickets
			runSellSeatsMenu();
			break;

		case 2:				// seating stats
			runSeatingStatsMenu();
			break;

		case 3:				// sales stats
			runSalesStatsMenu();
			break;

		case 4:				// quit program
			cout << "Are you sure you want to quit? (y = yes, n = no)\n";
			selectionMade = getInputYesNo();
			break;

		default:
			cout << "You did not make a valid selection, try again.\n\n";
			continue;
		}
	} while ( !selectionMade );

	return;
}

// Menu for selling one or more tickets ///////////////////////////////////////////////////////////

void CSeatingManager::runSellSeatsMenu( void ) {
	return;
}

// Menu for seeing seating statistics /////////////////////////////////////////////////////////////

void CSeatingManager::runSeatingStatsMenu( void ) {
	// Variables
	int counter = 0;

	// Redraw seating map
	cout << "\nSeating Statistics - Current Seating Chart\n";
	showSeatingMap();

	// Display seats sold
	for ( int row = 0; row < THEATER_TOTAL_ROWS; row++ ) {
		for ( int seat = 0; seat < THEATER_SEATS_PER_ROW; seat++ ) {
			// See if seat is sold
			if ( m_Seating[row][seat] == SEAT_SOLD )
				counter++;
		}
	}

	cout << "\nSeats sold: " << counter << endl;

	// Display seats available per row
	for ( int row = 0; row < THEATER_TOTAL_ROWS; row++ ) {
		counter  = 0;

		for ( int seat = 0; seat < THEATER_SEATS_PER_ROW; seat++ ) {
			// See if seat is available
			if ( m_Seating[row][seat] == SEAT_AVAILABLE )
				counter++;
		}

		cout << "Seats available in row " << (row+1) << " : " << counter << endl;
	}

	// Display total unsold seats
	counter = 0;

	for ( int row = 0; row < THEATER_TOTAL_ROWS; row++ ) {
		for ( int seat = 0; seat < THEATER_SEATS_PER_ROW; seat++ ) {
			// See if seat is available
			if ( m_Seating[row][seat] == SEAT_AVAILABLE )
				counter++;
		}
	}

	cout << "Total unsold seats: " << counter << endl;

	// Pause before returning to main menu
	system( "pause" );
	cout << endl;

	return;
}

// Menu for seeing sales statistics ///////////////////////////////////////////////////////////////

void CSeatingManager::runSalesStatsMenu( void ) {
	// Variables
	int counter = 0;

	// Set precision to only show 2 decimal places (for dollar amounts)
	std::cout << std::fixed;
	std::cout << std::setprecision( 2 );

	// Redraw seating map
	cout << "\nSales Statistics - Current Seating Chart\n";
	showSeatingMap();

	// Display ticket price
	cout << "\nCurrent ticket price : " << PRICE_PER_SEAT << endl;

	// Display unsold seats $ total
	counter = 0;

	for ( int row = 0; row < THEATER_TOTAL_ROWS; row++ ) {
		for ( int seat = 0; seat < THEATER_SEATS_PER_ROW; seat++ ) {
			// See if seat is available
			if ( m_Seating[row][seat] == SEAT_AVAILABLE )
				counter++;
		}
	}

	cout << "Unsold seats total dollar amount : " << static_cast<double>(counter * PRICE_PER_SEAT) << endl;
	
	// Display sold seats $ total
	counter = 0;

	for ( int row = 0; row < THEATER_TOTAL_ROWS; row++ ) {
		for ( int seat = 0; seat < THEATER_SEATS_PER_ROW; seat++ ) {
			// See if seat is sold
			if ( m_Seating[row][seat] == SEAT_SOLD )
				counter++;
		}
	}

	cout << "Sold seats total dollar amount : " << static_cast<double>(counter * PRICE_PER_SEAT) << endl;

	// Pause before returning to the main menu
	system( "pause" );
	cout << endl;

	return;
}

// Helper function to get an integer from keyboard from user //////////////////////////////////////

int CSeatingManager::getInputInt( void ) {
	int x = 0;

	// Try to get a number
	cin >> x;

	// Ensure a number was entered
	while ( cin.fail() ) {
		cin.clear();
		cin.ignore( 1000, '\n' );

		// Try again
		cout << "Try again; enter a valid number: ";
		cin >> x;
	}

	return x;
}

// Helper function to get a y or n answer from user ///////////////////////////////////////////////

bool CSeatingManager::getInputYesNo( void ) {
	// Variables
	char input;

	// Try to get an answer
	cin >> input;

	// Ensure y or n was entered
	while ( cin.fail() && (input != 'y' || input != 'n') ) {
		cin.clear();
		cin.ignore( 1000, '\n' );

		// Try again
		cout << "Try again, enter \"y\" for yes, or \"n\" for no: ";
		cin >> input;
	}

	// Return yes(true) or no(false)
	if ( input == 'y' )
		return true;
	else
		return false;
}

// Helper function to draw the current seating chart //////////////////////////////////////////////

void CSeatingManager::showSeatingMap( void ) {
	// Draw header
	cout << "     | A | B | C | D | E | F | G | H | I |\n";
	
	// Draw each row
	for ( int row = 0; row < THEATER_TOTAL_ROWS; row++ ) {
		cout << "ROW" << (row+1);

		// See if we need a space for a single-digit row (1-9)
		if ( row < 9 )
			cout << " ";

		// Draw all the # and * symbols for the row
		for ( int seat = 0; seat < THEATER_SEATS_PER_ROW; seat++ ) {
			cout << "| " << m_Seating[row][seat] << " ";
		}

		// End the row, new line
		cout << "|\n";
	}

	return;
}

