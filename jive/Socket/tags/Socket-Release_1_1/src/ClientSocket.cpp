//============================================================
// 
// file: ClientSocket.cpp
//
// description: From an article in "Linux gazette" by Rob Tougher
//              Implementation of the ClientSocket class.
//              And modified later.
//
// project :      TANGO Device Server.
//
// $Author: pascal_verdier $
//
// $Revision: 1.1.1.1 $
// $Log: not supported by cvs2svn $
//
// copyleft :     European Synchrotron Radiation Facility
//                BP 220, Grenoble 38043
//                FRANCE
//
//         (c) - Software Engineering Group - ESRF
//=============================================================================



#include "ClientSocket.h"
#include "SocketException.h"

//#include <iostream>
//#include <string>
#include <tango.h>

using namespace std;

//------------------------------------------------------------
/**
 *	ClientSocket constructor
 */
//------------------------------------------------------------
ClientSocket::ClientSocket(std::string host, int port)
{
	if (! SocketAccess::create())
	{
		throw SocketException ("Cannot create client socket.");
	}

	if (! SocketAccess::connect (host, port))
	{
 		TangoSys_MemStream	tms;
 		tms << "Cannot connect to " << host << ":" << port;
		throw SocketException (tms.str());
	}
}

//------------------------------------------------------------
/**
 *	ClientSocket operator overload
 */
//------------------------------------------------------------
const ClientSocket& ClientSocket::operator << (const std::string& s) const
{
	if (! SocketAccess::send(s))
	{
		throw SocketException ("Write Socket Failed.");
	}

	return *this;

}

//------------------------------------------------------------
/**
 *	ClientSocket operator overload
 */
//------------------------------------------------------------
const ClientSocket& ClientSocket::operator >> (std::string& s) const
{
	if (SocketAccess::recv(s) == 0)
	{
		throw SocketException ("Read Socket Failed.");
	}

	return *this;
}

//------------------------------------------------------------
/**
 *	ClientSocket set non blocking state
 */
//------------------------------------------------------------
void ClientSocket::set_non_blocking(const bool b)
{
	SocketAccess::set_non_blocking (b);
}

//------------------------------------------------------------
/**
 *	ClientSocket read line (until '\n')
 */
//------------------------------------------------------------
void ClientSocket::readln(std::string& s, short timeout)
{
	string	buf("");
	char	c = 0;

	while(c != '\n')
	{
		readchar(c, timeout);
		buf += c;
	}

	s = buf;
}
//------------------------------------------------------------
/**
 *	ClientSocket read until terminator received
 */
//------------------------------------------------------------
void ClientSocket::readuntil(std::string& s, char *terminator, short timeout)
{
	string	buff("");
	string	s_term(terminator);
	int		nb = 0;
	int		term_len = strlen(terminator);
	char	term_last_char = terminator[term_len-1];
	char 	c;
	bool	found = false;
	while (!found)
	{
		readchar(c, timeout);	// Try to get a char.
		//	OK add to buffer
		buff += c;
		nb++;
		if (c==term_last_char  &&  nb>term_len)	//	Check with terminator
		{
			//	get the end of buffer.
			string::size_type	pos = nb - term_len;
			string	s = buff.substr(pos, nb);
			//	compare with terminator
			found = (s == s_term);
		}
	}
	s = buff;
}

//------------------------------------------------------------
/**
 *	ClientSocket read char with a timeout
 */
//------------------------------------------------------------
void ClientSocket::readchar(char &c, short timeout)
{
	switch (SocketAccess::recv(c, timeout))
	{
	case 1:
		return;	//	Ok on char read
	case -1:
		throw SocketException ("Socket Timeout");
	default:
		throw SocketException ("Read Socket Failed");
	}
}
