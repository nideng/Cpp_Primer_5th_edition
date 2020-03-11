#include<iostream>
#include<memory>
#include<string>
using namespace std;
struct connection
{
	string ip;
	int port;
	connection(string ip_, int port_):ip(ip_),port(port_){}
};
struct destination
{
	string ip;
	int port;
	destination(string ip_,int port_):ip(ip_),port(port_){}
};
connection connect(destination* des)
{
	shared_ptr<connection>p(new connection(des->ip, des->port));
	std::cout << "creating connection(" << p.use_count() << ")" << std::endl;
	return *p;
}
void disconnect(connection p)
{
	std::cout << "connection close(" << p.ip << ":" << p.port << ")" << std::endl;
}

void end_connection(connection* p)
{
	disconnect(*p);
}

void f(destination& d)
{
	connection conn = connect(&d);
	std::shared_ptr<connection> p(&conn, end_connection);
	std::cout << "connecting now(" << p.use_count() << ")" << std::endl;
}

int main()
{
	destination dest("202.118.176.67", 3316);
	f(dest);
}