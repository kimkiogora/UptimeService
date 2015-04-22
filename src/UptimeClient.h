/**
   @Usage: Uptime Client
   @uthor: kim kiogora	<kimkiogora@gmail.com>
*/

#include "UptimeHeaders.h"

#define EXIT_SUCCESS 0

using namespace std;

class Uptime {
public:
	void init();
	string str_input;
	Uptime();
	//static int connection_id=1; --retrieved from UptimeServer
private:
	string LOGIN_MSG;
	string CMD_ENTRY_ERROR;
	string STAT_HEADERS;
	void message(string);
	void message_input(string);
	void screen();
	void input();
	void do_process_input();
};

/**
  * Constructor.
*/
Uptime::Uptime() {
	LOGIN_MSG="Welcome to Uptime Monitor.  Commands end with ;\nYour Uptime connection id is 47\n";
	CMD_ENTRY_ERROR="Command not listed; Try stats;help;quit;\n";
	STAT_HEADERS="|ID\t\t|Service\t\t|Uptime\t\t|Downtime\t\t|Date";
}

/**
 * Initialize Client.
*/
void Uptime::init() {
	this->message(LOGIN_MSG);

	/* loop forever */
	while(1) {
		this->screen();		
		this->do_process_input();
	}
}

/**
 * Log a message.
*/
void Uptime::message(string out){
	cout<<out<<endl;
}

/**
 * Log a message.
*/
void Uptime::message_input(string out){
	cout<<out;
}

/**
 * Start the process.
*/
void Uptime::screen(){
	this->message_input("Uptime> ");
	this->input();
}

/**
 * Get the command.
*/
void Uptime::input(){
	cin >> str_input;
}

/**
 * Process the input.
*/
void Uptime::do_process_input() {
	if(str_input.length() > 0 ){
		if (str_input.compare("stats") == 0) {
			this->message(STAT_HEADERS);
		} else if(str_input.compare("quit") == 0) {
			exit(EXIT_SUCCESS);
		} else {			
			this->message(CMD_ENTRY_ERROR);
		}
	}
}
