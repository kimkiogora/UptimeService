/**
   @Usage: Uptime Client
   @uthor: kim kiogora	<kimkiogora@gmail.com>
*/
using namespace std;
#define CID_CMD "connection_id"
#define STAT_CMD "stats"

class NetworkManager {
private:
	string server;
	int connection_id;
	
	short port;
public:
	void setConnectionID(int id);
	int getConnectionID();
	NetworkManager();
protected:
	void sendInfo(string msg);
};

NetworkManager::NetworkManager(){
}
