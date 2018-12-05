/*----- PROTECTED REGION ID(Socket.cpp) ENABLED START -----*/
static const char *RcsId = "$Id: Socket.cpp,v 1.6 2012-11-12 14:49:36 pascal_verdier Exp $";
//=============================================================================
//
// file :        Socket.cpp
//
// description : C++ source for the Socket and its commands.
//               The class is derived from Device. It represents the
//               CORBA servant object which will be accessed from the
//               network. All commands which can be executed on the
//               Socket are implemented in this file.
//
// project :     Socket.
//
// $Author: pascal_verdier $
//
// $Revision: 1.6 $
// $Date: 2012-11-12 14:49:36 $
//
// SVN only:
// $HeadURL:  $
//
// CVS only:
// $Source: /users/chaize/newsvn/cvsroot/Communication/Socket/src/Socket.cpp,v $
// $Log: not supported by cvs2svn $
//
//=============================================================================
//                This file is generated by POGO
//        (Program Obviously used to Generate tango Object)
//=============================================================================


#include <tango.h>
#include <Socket.h>
#include <SocketClass.h>
#include "ClientSocket.h"
#include "SocketException.h"
#include <netdb.h>

/*----- PROTECTED REGION END -----*/	//	Socket.cpp

/**
 *  Socket class description:
 *    This class implements basic `socket` IPC.
 */

//================================================================
//  The following table gives the correspondence
//  between command and method names.
//
//  Command name    |  Method name
//================================================================
//  State           |  Inherited (no method)
//  Status          |  Inherited (no method)
//  Reconnect       |  reconnect
//  Write           |  write
//  WriteAndRead    |  write_and_read
//  WriteReadUntil  |  write_read_until
//  WriteCharArray  |  write_char_array
//  Read            |  read
//  Readln          |  readln
//  ReadUntil       |  read_until
//  ReadCharArray   |  read_char_array
//================================================================

//================================================================
//  Attributes managed is:
//================================================================
//================================================================

namespace Socket_ns
{
/*----- PROTECTED REGION ID(Socket::namespace_starting) ENABLED START -----*/

	//	static initializations

	/*----- PROTECTED REGION END -----*/	//	Socket::namespace_starting

//--------------------------------------------------------
/**
 *	Method      : Socket::Socket()
 *	Description : Constructors for a Tango device
 *                implementing the classSocket
 */
//--------------------------------------------------------
Socket::Socket(Tango::DeviceClass *cl, string &s)
 : Tango::Device_4Impl(cl, s.c_str())
{
	/*----- PROTECTED REGION ID(Socket::constructor_1) ENABLED START -----*/

	init_device();

	/*----- PROTECTED REGION END -----*/	//	Socket::constructor_1
}
//--------------------------------------------------------
Socket::Socket(Tango::DeviceClass *cl, const char *s)
 : Tango::Device_4Impl(cl, s)
{
	/*----- PROTECTED REGION ID(Socket::constructor_2) ENABLED START -----*/

	init_device();

	/*----- PROTECTED REGION END -----*/	//	Socket::constructor_2
}
//--------------------------------------------------------
Socket::Socket(Tango::DeviceClass *cl, const char *s, const char *d)
 : Tango::Device_4Impl(cl, s, d)
{
	/*----- PROTECTED REGION ID(Socket::constructor_3) ENABLED START -----*/

	init_device();

	/*----- PROTECTED REGION END -----*/	//	Socket::constructor_3
}

//--------------------------------------------------------
/**
 *	Method      : Socket::delete_device()
 *	Description : will be called at device destruction or at init command
 */
//--------------------------------------------------------
void Socket::delete_device()
{
	DEBUG_STREAM << "Socket::delete_device() " << device_name << endl;
	/*----- PROTECTED REGION ID(Socket::delete_device) ENABLED START -----*/

	//	Delete device allocated objects
	//	Delete device's allocated object
	if (connected == true)
    	delete client_socket;

	/*----- PROTECTED REGION END -----*/	//	Socket::delete_device
}

//--------------------------------------------------------
/**
 *	Method      : Socket::init_device()
 *	Description : will be called at device initialization.
 */
//--------------------------------------------------------
void Socket::init_device()
{
	DEBUG_STREAM << "Socket::init_device() create device " << device_name << endl;
	/*----- PROTECTED REGION ID(Socket::init_device_before) ENABLED START -----*/

	//	Initialization before get_device_property() call
    	connected = false;


	/*----- PROTECTED REGION END -----*/	//	Socket::init_device_before
	

	//	Get the device properties from database
	get_device_property();
	

	/*----- PROTECTED REGION ID(Socket::init_device) ENABLED START -----*/

	//	Initialize device
	client_socket = NULL;

	try
	{
		client_socket = new ClientSocket(hostname, port);
		client_socket->set_non_blocking(true);

		set_state(Tango::ON);
		set_status("Connected to socket");
		connected = true;
	}
	catch ( SocketException& e )
	{
		set_state(Tango::OFF);
		connected = false;
		TangoSys_MemStream	tms;
		tms << "Failed to create socket:" << endl << e.description() << ends;
		set_status(tms.str());
		cout << tms.str() << endl;
		//	Do not send exception any more !
	}

	/*----- PROTECTED REGION END -----*/	//	Socket::init_device
}

//--------------------------------------------------------
/**
 *	Method      : Socket::get_device_property()
 *	Description : Read database to initialize property data members.
 */
//--------------------------------------------------------
void Socket::get_device_property()
{
	/*----- PROTECTED REGION ID(Socket::get_device_property_before) ENABLED START -----*/

	//	Initialize property data members
	hostname="";
    port = 9999;
    readtimeout = 9999;

	/*----- PROTECTED REGION END -----*/	//	Socket::get_device_property_before


	//	Read device properties from database.
	Tango::DbData	dev_prop;
	dev_prop.push_back(Tango::DbDatum("Hostname"));
	dev_prop.push_back(Tango::DbDatum("Port"));
	dev_prop.push_back(Tango::DbDatum("Readtimeout"));
	dev_prop.push_back(Tango::DbDatum("AutoReconnect"));

	//	is there at least one property to be read ?
	if (dev_prop.size()>0)
	{
		//	Call database and extract values
		if (Tango::Util::instance()->_UseDb==true)
			get_db_device()->get_property(dev_prop);
	
		//	get instance on SocketClass to get class property
		Tango::DbDatum	def_prop, cl_prop;
		SocketClass	*ds_class =
			(static_cast<SocketClass *>(get_device_class()));
		int	i = -1;

		//	Try to initialize Hostname from class property
		cl_prop = ds_class->get_class_property(dev_prop[++i].name);
		if (cl_prop.is_empty()==false)	cl_prop  >>  hostname;
		else {
			//	Try to initialize Hostname from default device value
			def_prop = ds_class->get_default_device_property(dev_prop[i].name);
			if (def_prop.is_empty()==false)	def_prop  >>  hostname;
		}
		//	And try to extract Hostname value from database
		if (dev_prop[i].is_empty()==false)	dev_prop[i]  >>  hostname;

		//	Try to initialize Port from class property
		cl_prop = ds_class->get_class_property(dev_prop[++i].name);
		if (cl_prop.is_empty()==false)	cl_prop  >>  port;
		else {
			//	Try to initialize Port from default device value
			def_prop = ds_class->get_default_device_property(dev_prop[i].name);
			if (def_prop.is_empty()==false)	def_prop  >>  port;
		}
		//	And try to extract Port value from database
		if (dev_prop[i].is_empty()==false)	dev_prop[i]  >>  port;

		//	Try to initialize Readtimeout from class property
		cl_prop = ds_class->get_class_property(dev_prop[++i].name);
		if (cl_prop.is_empty()==false)	cl_prop  >>  readtimeout;
		else {
			//	Try to initialize Readtimeout from default device value
			def_prop = ds_class->get_default_device_property(dev_prop[i].name);
			if (def_prop.is_empty()==false)	def_prop  >>  readtimeout;
		}
		//	And try to extract Readtimeout value from database
		if (dev_prop[i].is_empty()==false)	dev_prop[i]  >>  readtimeout;

		//	Try to initialize AutoReconnect from class property
		cl_prop = ds_class->get_class_property(dev_prop[++i].name);
		if (cl_prop.is_empty()==false)	cl_prop  >>  autoReconnect;
		else {
			//	Try to initialize AutoReconnect from default device value
			def_prop = ds_class->get_default_device_property(dev_prop[i].name);
			if (def_prop.is_empty()==false)	def_prop  >>  autoReconnect;
		}
		//	And try to extract AutoReconnect value from database
		if (dev_prop[i].is_empty()==false)	dev_prop[i]  >>  autoReconnect;

	}

	/*----- PROTECTED REGION ID(Socket::get_device_property_after) ENABLED START -----*/

	//	Check device property data members init
	cout << "hostname.......: " << hostname << endl;
    cout << "port...........: " << port << endl;
    cout << "readtimeout....: " << readtimeout << endl;
	cout << "autoReconnect..: " << ((autoReconnect)? "true":"false") << endl;

	/*----- PROTECTED REGION END -----*/	//	Socket::get_device_property_after
}

//--------------------------------------------------------
/**
 *	Method      : Socket::always_executed_hook()
 *	Description : method always executed before any command is executed
 */
//--------------------------------------------------------
void Socket::always_executed_hook()
{
	INFO_STREAM << "Socket::always_executed_hook()  " << device_name << endl;
	/*----- PROTECTED REGION ID(Socket::always_executed_hook) ENABLED START -----*/

	//	code always executed before all requests
	

	/*----- PROTECTED REGION END -----*/	//	Socket::always_executed_hook
}

//--------------------------------------------------------
/**
 *	Method      : Socket::read_attr_hardware()
 *	Description : Hardware acquisition for attributes
 */
//--------------------------------------------------------
void Socket::read_attr_hardware(TANGO_UNUSED(vector<long> &attr_list))
{
	DEBUG_STREAM << "Socket::read_attr_hardware(vector<long> &attr_list) entering... " << endl;
	/*----- PROTECTED REGION ID(Socket::read_attr_hardware) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	Socket::read_attr_hardware
}


//--------------------------------------------------------
/**
 *	Method      : Socket::add_dynamic_attributes()
 *	Description : Create the dynamic attributes if any
 *                for specified device.
 */
//--------------------------------------------------------
void Socket::add_dynamic_attributes()
{
	/*----- PROTECTED REGION ID(Socket::add_dynamic_attributes) ENABLED START -----*/
	
	//	Add your own code to create and add dynamic attributes if any
	
	/*----- PROTECTED REGION END -----*/	//	Socket::add_dynamic_attributes
}

//--------------------------------------------------------
/**
 *	Command Reconnect related method
 *	Description: Attempts to re-establish the socket connection.
 *
 */
//--------------------------------------------------------
void Socket::reconnect()
{
	DEBUG_STREAM << "Socket::Reconnect()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(Socket::reconnect) ENABLED START -----*/

	//	Add your own code
	if (client_socket!=NULL)
		delete 	client_socket;
	connected = false;
	check_connection();

	/*----- PROTECTED REGION END -----*/	//	Socket::reconnect
}
//--------------------------------------------------------
/**
 *	Command Write related method
 *	Description: Command used to send a string to the socket.
 *
 *	@param argin 
 */
//--------------------------------------------------------
void Socket::write(Tango::DevString argin)
{
	DEBUG_STREAM << "Socket::Write()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(Socket::write) ENABLED START -----*/

	//	Add your own code
	check_connection();
	try
	{
		*client_socket << argin;
		*client_socket << "\r\n";
	}
	catch ( SocketException& e )
	{
		TangoSys_MemStream	tms;
		tms << "Socket::write(" << argin << ")";
		manage_exception(e.description(), tms.str());
	}

	/*----- PROTECTED REGION END -----*/	//	Socket::write
}
//--------------------------------------------------------
/**
 *	Command WriteAndRead related method
 *	Description: Write to the socket and waits for the answer.
 *               The end of the answer is triggered by the new line character!
 *
 *	@param argin Command string.
 *	@returns Answer string.
 */
//--------------------------------------------------------
Tango::DevString Socket::write_and_read(Tango::DevString argin)
{
	Tango::DevString argout;
	DEBUG_STREAM << "Socket::WriteAndRead()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(Socket::write_and_read) ENABLED START -----*/

	//	Add your own code
	#ifdef TRACE_TIME
	static bool		first = true;
	static struct	timeval	t0;
 	struct timeval	t1;

	if (first)
	{
		gettimeofday(&t0, NULL);
		first = false;
	}
	gettimeofday(&t1, NULL);
	cout << ( (1000.0*(t1.tv_sec-t0.tv_sec) + \
			((double)t1.tv_usec-t0.tv_usec) / 1000) / 1000) << endl;
	
	t0.tv_sec  = t1.tv_sec;
	t0.tv_usec = t1.tv_usec;
#endif
	check_connection();
    // Write command to socket.
	try
	{
		*client_socket << argin;
		*client_socket << "\r\n";
	}
	catch ( SocketException& e )
	{
		TangoSys_MemStream	tms;
		tms << "Socket::write_and_read(" << argin << ")";
		manage_exception(e.description(), tms.str());
	}

	try
	{
		string reply;
		client_socket->readln(reply, readtimeout);
		argout = CORBA::string_dup(reply.c_str());
	}
	catch ( SocketException& e )
	{
		TangoSys_MemStream	tms;
		tms << "Socket::write_and_read(" << argin << ")";
		manage_exception(e.description(), tms.str());
	}

	/*----- PROTECTED REGION END -----*/	//	Socket::write_and_read
	return argout;
}
//--------------------------------------------------------
/**
 *	Command WriteReadUntil related method
 *	Description: Write to the socket and waits for the answer.
 *               The answer is triggered by select() which indicates that the the anser has arrived.
 *
 *	@param argin [0] = Command string to be send, [1] = end of message character
 *	@returns Answer string.
 */
//--------------------------------------------------------
Tango::DevString Socket::write_read_until(const Tango::DevVarStringArray *argin)
{
	Tango::DevString argout;
	DEBUG_STREAM << "Socket::WriteReadUntil()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(Socket::write_read_until) ENABLED START -----*/

	//	Add your own code
	// Check input array length
	
	if ( argin->length() < 2 )
	{
	    TangoSys_OMemStream o;
    	o << "Not enough input strings!\n[0] = command to write, [1] = end of message character" << ends;
    	Tango::Except::throw_exception(
						(const char *)"Wrong input parameters",                    
						o.str(),
						(const char *)"Socket::write_read_until");
	}
	
	check_connection();
    // Write command to socket.
	try
	{
		string cmd;
		cmd = (*argin)[0];
		
		*client_socket << cmd;
		*client_socket << "\r\n";
	}
	catch ( SocketException& e )
	{
		manage_exception(e.description(), "Socket::write_read()");
	}

	try
	{
		string terminator;
		terminator = (*argin)[1];
		
		string reply;
		client_socket->readuntil(reply, (char *)terminator.c_str(), readtimeout);
		argout = CORBA::string_dup(reply.c_str());
	}
	catch ( SocketException& e )
	{
		manage_exception(e.description(), "Socket::write_and_read()");
	}

	/*----- PROTECTED REGION END -----*/	//	Socket::write_read_until
	return argout;
}
//--------------------------------------------------------
/**
 *	Command WriteCharArray related method
 *	Description: write on socket input Argument.
 *
 *	@param argin array to write
 */
//--------------------------------------------------------
void Socket::write_char_array(const Tango::DevVarCharArray *argin)
{
	DEBUG_STREAM << "Socket::WriteCharArray()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(Socket::write_char_array) ENABLED START -----*/
	
	//	Add your own code
        check_connection();
	try
	{
		*client_socket << *argin;
		*client_socket << "\r\n";
	}
	catch ( SocketException& e )
	{
		TangoSys_MemStream	tms;
		tms << "Socket::write(" << argin << ")";
		manage_exception(e.description(), tms.str());
	}
	
	/*----- PROTECTED REGION END -----*/	//	Socket::write_char_array
}
//--------------------------------------------------------
/**
 *	Command Read related method
 *	Description: Command used to read a string from the socket.
 *
 *	@returns 
 */
//--------------------------------------------------------
Tango::DevString Socket::read()
{
	Tango::DevString argout;
	DEBUG_STREAM << "Socket::Read()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(Socket::read) ENABLED START -----*/

	//	Add your own code
	check_connection();
	bool	empty = false;
	string	reply("");
	while (!empty)
	{
		try
		{
			string	tmp;
	    	*client_socket >> tmp;
			reply += tmp;
		}
		catch ( SocketException& e )
		{
			empty = true;
		}
	}
	argout = CORBA::string_dup(reply.c_str());

	/*----- PROTECTED REGION END -----*/	//	Socket::read
	return argout;
}
//--------------------------------------------------------
/**
 *	Command Readln related method
 *	Description: Reads from a socket until a "\n" has been received.
 *
 *	@returns argout
 */
//--------------------------------------------------------
Tango::DevString Socket::readln()
{
	Tango::DevString argout;
	DEBUG_STREAM << "Socket::Readln()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(Socket::readln) ENABLED START -----*/

	//	Add your own code
	check_connection();
	try
	{
		string reply; 
		client_socket->readln(reply, readtimeout);
		argout = CORBA::string_dup(reply.c_str());
	}
	catch ( SocketException& e )
	{
		manage_exception(e.description(), "Socket::readln()");
	}

	/*----- PROTECTED REGION END -----*/	//	Socket::readln
	return argout;
}
//--------------------------------------------------------
/**
 *	Command ReadUntil related method
 *	Description: This command read data from the socket until the terminator has been reached.
 *
 *	@param argin This is the terminator
 *	@returns This is the read string.
 */
//--------------------------------------------------------
Tango::DevString Socket::read_until(Tango::DevString argin)
{
	Tango::DevString argout;
	DEBUG_STREAM << "Socket::ReadUntil()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(Socket::read_until) ENABLED START -----*/

	//	Add your own code
	check_connection();
	try
	{
		string reply;
		client_socket->readuntil(reply, argin, readtimeout);
		argout = CORBA::string_dup(reply.c_str());
	}
	catch ( SocketException& e )
	{
		TangoSys_MemStream	tms;
		tms << "Socket::write(" << argin << ")";
		manage_exception(e.description(), tms.str());
	}

	/*----- PROTECTED REGION END -----*/	//	Socket::read_until
	return argout;
}
//--------------------------------------------------------
/**
 *	Command ReadCharArray related method
 *	Description: read on socket and return output Argument.
 *
 *	@param argin number of char to read
 *	@returns char read on socket
 */
//--------------------------------------------------------
Tango::DevVarCharArray *Socket::read_char_array(Tango::DevLong argin)
{
	Tango::DevVarCharArray *argout;
	DEBUG_STREAM << "Socket::ReadCharArray()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(Socket::read_char_array) ENABLED START -----*/
	
	//	Add your own code
        check_connection();
        
        argout = new Tango::DevVarCharArray();
        
	try
	{
                client_socket->readCharArray(*argout, argin, readtimeout);
	}
	catch ( SocketException& e )
	{
                delete argout;
		TangoSys_MemStream	tms;
		tms << "Socket::write(" << argin << ")";
		manage_exception(e.description(), tms.str());
	}
	
	/*----- PROTECTED REGION END -----*/	//	Socket::read_char_array
	return argout;
}

/*----- PROTECTED REGION ID(Socket::namespace_ending) ENABLED START -----*/

	//	Additional Methods
//+------------------------------------------------------------------
//+------------------------------------------------------------------
void Socket::check_connection()
{
	if (!connected)
	{
		// If not connected -> try to do it
		try
		{
			client_socket = new ClientSocket(hostname, port);
			client_socket->set_non_blocking(true);

			set_state(Tango::ON);
			set_status("Connected to socket");
			connected = true;
		}
		catch (SocketException& e){
			manage_exception(e.description(), "Socket::check_connection()");
		}
	}
}
//+------------------------------------------------------------------
/**
 *	Returs true if str begins by beg parameter
 */
//+------------------------------------------------------------------
bool Socket::startsWith(string str, string beg)
{
	string::size_type	pos = str.find(beg);
	return (pos==0);
}
//+------------------------------------------------------------------
//+------------------------------------------------------------------
void Socket::manage_exception(string desc, string orig)
{
	cout << "erno = " << errno << endl;

	//	Build a DevFailed with exception
	//cout << "Socket error - " << errno << endl;
	TangoSys_MemStream	tms;
	tms << desc << endl;
	switch(errno)
	{
	case EAGAIN:	//	11
		tms << "EAGAIN: Socket timeout";
		//tms << " (" << dt << " ms)";
		break;
	case ETIMEDOUT:	//	110
		tms << "ETIMEDOUT: Socket timeout";
		//tms << " (" << dt << " ms)";
		break;
	case EBADF:		//	9
		tms << "EBADF: The socket argument is not a valid file descriptor.";
		break;

	case ECONNRESET://	104
		tms << "ECONNRESET: Connection reset by peer.";
		break;

	case EINTR:		//	4
		tms << "EINTR: The recv() function was interrupted by a signal that was caught, before any data was available.";
		break;

	case EINVAL:	//	22
		tms << "EINVAL: The MSG_OOB flag is set and no out-of-band data is available";
		break;

	case ENOTCONN:	//	107
		tms << "ENOTCONN: A receive is attempted on a connection-mode socket that is not connected.";
		break;

	case ENOTSOCK:	//	88
		tms << "ENOTSOCK: The socket argument does not refer to a socket.";
		break;

	case EOPNOTSUPP://	95
		tms << "EOPNOTSUPP: The specified flags are not supported for this socket type or protocol.";
		break;

	case EIO:		//	5
		tms << "EIO: An I/O error occurred while reading from or writing to the file system.";
		break;

	case ENOBUFS:	//	105
		tms << "ENOBUFS: Insufficient resources were available in the system to perform the operation.";
		break;

	case ENOMEM:	//	12
		tms << "ENOMEM: Insufficient memory was available to fulfill the request.";
		break;

	case EACCES:	//	13
		tms << "EACCES: Write permission is denied on the destination socket";
		break;

	case EDESTADDRREQ://	89
		tms << "EDESTADDRREQ: The socket is not connection-mode, and no peer address is set. ";
		break;

	case EISCONN:	//	106
		tms << "EISCONN: The connection-mode socket was connected already but a recipient was specified.";
		break;

	case EPIPE:		//	32
		tms << "The local end has been shut down on a connection oriented socket.";
		break;

	case EMFILE:	//	24
		tms << "";
		break;

	default:
		tms << "Socket error - " << errno << " (unknown)";
		break;
	}

	//	Check the description
	if (errno==ECONNRESET ||
		errno==EINTR      ||
		errno==ENOTCONN   ||
		errno==EPIPE      )
	{
		set_state(Tango::OFF);
		set_status(desc.c_str());

		if (connected && autoReconnect)
		{
			//	If not timeout, delete sockect
			if (client_socket!=NULL)
			{
 				struct timeval	t;
				gettimeofday(&t, NULL);
				cerr << ctime(&t.tv_sec) << 
					//"and " << (t.tv_usec/1000) <<" ms - " <<
					"DECONNECTION (err=" << errno <<"): " <<
						tms.str() << " from " << orig << endl;
				delete 	client_socket;
				client_socket = NULL;
			}
			connected = false;
		}
	}
	ERROR_STREAM << orig.c_str() << ":   " << desc.c_str() << endl;
	Tango::Except::throw_exception(
					(const char *) "SocketError",
					tms.str().c_str(),
					orig.c_str());
}


	/*----- PROTECTED REGION END -----*/	//	Socket::namespace_ending
} //	namespace
