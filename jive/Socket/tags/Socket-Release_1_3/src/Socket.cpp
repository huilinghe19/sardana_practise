static const char *RcsId = "$Header: /users/chaize/newsvn/cvsroot/Communication/Socket/src/Socket.cpp,v 1.4 2009-03-04 13:06:18 jensmeyer Exp $";
//+=============================================================================
//
// file :         Socket.cpp
//
// description :  C++ source for the Socket and its commands. 
//                The class is derived from Device. It represents the
//                CORBA servant object which will be accessed from the
//                network. All commands which can be executed on the
//                Socket are implemented in this file.
//
// project :      TANGO Device Server
//
// $Author: jensmeyer $
//
// $Revision: 1.4 $
//
// $Log: not supported by cvs2svn $
// Revision 1.3  2008/12/11 08:46:08  jensmeyer
// Regenerated with Pogo and changed port property from short to long.
//
// Revision 1.2  2007/01/24 13:15:17  pascal_verdier
// Bug in Read command (throwing exception) fixed.
//
// Revision 1.1.1.1  2007/01/12 10:07:44  pascal_verdier
// Initial Revision
//
// Revision 1.11  2007/01/05 15:22:07  peru
// TCP_NODELAY modification.
//
// Revision 1.10  2005/12/16 09:53:02  peru
// When "init_device" fails an exception is thrown.
//
// Revision 1.9  2005/12/13 07:51:40  bourtemb
// don't delete client_socket when the initialization failed, to avoid a segmentation fault.
//
// Revision 1.8  2005/12/07 08:04:50  bourtemb
// Readln and ReadUntil commands not allowed when in OFF state
//
// Revision 1.7  2005/11/17 13:20:44  peru
// Use of "CORBA::string_dup" everywhere it is required.
//
// Revision 1.6  2005/10/05 07:13:17  bourtemb
// use CORBA::string_dup function to allocate memory in read_until function
//
// Revision 1.5  2005/10/04 13:51:35  peru
// Implemented "ReadUntil" command.
// Re-organization of the code.
//
// Revision 1.4  2005/09/28 08:08:12  peru
// Added closing of socket connexion.
//
// Revision 1.3  2005/09/05 13:42:21  peru
// Added "Readln" command.
//
// Revision 1.2  2005/08/12 12:34:33  peru
// Improved connect algorithm in order to avoid long timeouts.
//
// Revision 1.1.1.1  2005/07/12 06:59:46  peru
// Imported using TkCVS
//
// Revision 1.1.1.1  2005/07/12 06:16:03  peru
// Imported using TkCVS
//
//
// copyleft :     European Synchrotron Radiation Facility
//                BP 220, Grenoble 38043
//                FRANCE
//
//-=============================================================================
//
//  		This file is generated by POGO
//	(Program Obviously used to Generate tango Object)
//
//         (c) - Software Engineering Group - ESRF
//=============================================================================



//===================================================================
//
//	The following table gives the correspondence
//	between commands and method name.
//
//  Command name    |  Method name
//	----------------------------------------
//  State           |  dev_state()
//  Status          |  dev_status()
//  Write           |  write()
//  Read            |  read()
//  Reconnect       |  reconnect()
//  WriteAndRead    |  write_and_read()
//  Readln          |  readln()
//  ReadUntil       |  read_until()
//  WriteReadUntil  |  write_read_until()
//
//===================================================================


#include <tango.h>
#include <Socket.h>
#include <SocketClass.h>

#include "ClientSocket.h"
#include "SocketException.h"
#include <netdb.h>

namespace Socket_ns
{

  //+----------------------------------------------------------------------------
  //
  // method : 		Socket::Socket(string &s)
  // 
  // description : 	constructor for simulated Socket
  //
  // in : - cl : Pointer to the DeviceClass object
  //      - s : Device name 
  //
  //-----------------------------------------------------------------------------
  Socket::Socket(Tango::DeviceClass *cl,string &s)
    :Tango::Device_3Impl(cl,s.c_str())
  {
    init_device();
  }

  Socket::Socket(Tango::DeviceClass *cl,const char *s)
    :Tango::Device_3Impl(cl,s)
  {
    init_device();
  }

  Socket::Socket(Tango::DeviceClass *cl,const char *s,const char *d)
    :Tango::Device_3Impl(cl,s,d)
  {
    init_device();
  }
  //+----------------------------------------------------------------------------
  //
  // method : 		Socket::delete_device()
  // 
  // description : 	will be called at device destruction or at init command.
  //
  //-----------------------------------------------------------------------------
  void Socket::delete_device()
  {
    //	Delete device's allocated object
	if (connected == true)
    	delete client_socket;
  }

  //+----------------------------------------------------------------------------
  //
  // method : 		Socket::init_device()
  // 
  // description : 	will be called at device initialization.
  //
  //-----------------------------------------------------------------------------
  void Socket::init_device()
  {
    INFO_STREAM << "Socket::Socket() create device " << device_name << endl;

    // Initialise variables to default values
    //--------------------------------------------
	connected = false;
    get_device_property();
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
  }


  //+----------------------------------------------------------------------------
  //
  // method : 		Socket::readDeviceProperies()
  // 
  // description : 	Read the device properties from database.
  //
  //-----------------------------------------------------------------------------
  void Socket::get_device_property()
  {
    //	Initialize your default values here.
    //------------------------------------------

    hostname="";
    port = 9999;
    readtimeout = 9999;


    //	Read device properties from database.(Automatic code generation)
    //-------------------------------------------------------------
	Tango::DbData	dev_prop;
	dev_prop.push_back(Tango::DbDatum("Hostname"));
	dev_prop.push_back(Tango::DbDatum("Port"));
	dev_prop.push_back(Tango::DbDatum("Readtimeout"));
	dev_prop.push_back(Tango::DbDatum("AutoReconnect"));

	//	Call database and extract values
	//--------------------------------------------
	if (Tango::Util::instance()->_UseDb==true)
		get_db_device()->get_property(dev_prop);
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



    //	End of Automatic code generation
    //-------------------------------------------------------------

    cout << "hostname.......: " << hostname << endl;
    cout << "port...........: " << port << endl;
    cout << "readtimeout....: " << readtimeout << endl;
	cout << "autoReconnect..: " << ((autoReconnect)? "true":"false") << endl;
  }
//+----------------------------------------------------------------------------
//
// method : 		Socket::always_executed_hook()
// 
// description : 	method always executed before any command is executed
//
//-----------------------------------------------------------------------------
void Socket::always_executed_hook()
{
}

//+------------------------------------------------------------------
/**
 *	method:	Socket::write
 *
 *	description:	method to execute "Write"
 *	Command used to send a string to the socket.
 *
 * @param	argin	
 *
 */
//+------------------------------------------------------------------
void Socket::write(Tango::DevString argin)
{
	DEBUG_STREAM << "Socket::write(): entering... !" << endl;

	check_connection();
	try
	{
		*client_socket << argin;
		*client_socket << "\r\n";
	}
	catch ( SocketException& e )
	{
		manage_exception(e.description(), "Socket::write()");
	}
}

  //+------------------------------------------------------------------
/**
 *	method:	Socket::read
 *
 *	description:	method to execute "Read"
 *	Command used to read a string from the socket.
 *
 * @return	
 *
 */
//+------------------------------------------------------------------
Tango::DevString Socket::read()
{
    DEBUG_STREAM << "Socket::read(): entering... !" << endl;
  
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
	Tango::DevString argout = CORBA::string_dup(reply.c_str());
	return argout;
}

//+------------------------------------------------------------------
/**
 *	method:	Socket::reconnect
 *
 *	description:	method to execute "Reconnect"
 *	Attempts to re-establish the socket connection.
 *
 *
 */
//+------------------------------------------------------------------
void Socket::reconnect()
{
    DEBUG_STREAM << "Socket::reconnect(): entering... !" << endl;
	if (client_socket!=NULL)
		delete 	client_socket;
	connected = false;
	check_connection();
}

//+------------------------------------------------------------------
/**
 *	method:	Socket::write_and_read
 *
 *	description:	method to execute "WriteAndRead"
 *	Write to the socket and waits for the answer.
 *	The end of the answer is triggered by the new line character!
 *
 * @param	argin	Command string.
 * @return	Answer string.
 *
 */
//+------------------------------------------------------------------
Tango::DevString Socket::write_and_read(Tango::DevString argin)
{
    DEBUG_STREAM << "Socket::write_and_read(): entering... !" << endl;

	check_connection();
    // Write command to socket.
	try
	{
		*client_socket << argin;
		*client_socket << "\r\n";
	}
	catch ( SocketException& e )
	{
		manage_exception(e.description(), "Socket::write_and_read()");
	}

	try
	{
		string reply;
		client_socket->readln(reply, readtimeout);
		Tango::DevString argout = CORBA::string_dup(reply.c_str());
		return argout;
	}
	catch ( SocketException& e )
	{
		manage_exception(e.description(), "Socket::write_and_read()");
	}
}

//+------------------------------------------------------------------
/**
 *	method:	Socket::readln
 *
 *	description:	method to execute "Readln"
 *	Reads from a socket until a "\n" has been received.
 *
 * @return	argout
 *
 */
//+------------------------------------------------------------------
Tango::DevString Socket::readln()
{
	DEBUG_STREAM << "Socket::readln(): entering... !" << endl;

	check_connection();
	try
	{
		string reply; 
		client_socket->readln(reply, readtimeout);
		Tango::DevString argout = CORBA::string_dup(reply.c_str());
		return argout;
	}
	catch ( SocketException& e )
	{
		manage_exception(e.description(), "Socket::readln()");
	}
}
  
//+------------------------------------------------------------------
/**
 *	method:	Socket::read_until
 *
 *	description:	method to execute "ReadUntil"
 *	This command read data from the socket until the terminator has been reached.
 *
 * @param	argin	This is the terminator
 * @return	This is the read string.
 *
 */
//+------------------------------------------------------------------
Tango::DevString Socket::read_until(Tango::DevString argin)
{
	DEBUG_STREAM << "Socket::read_until(): entering... !" << endl;

	check_connection();
	try
	{
		string reply;
		client_socket->readuntil(reply, argin, readtimeout);
		Tango::DevString argout = CORBA::string_dup(reply.c_str());
		return argout;
	}
	catch ( SocketException& e )
	{
		manage_exception(e.description(), "Socket::read_until()");
	}
}
  
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
			manage_exception(e.description(), "Socket::always_executed_hook()");
		}
	}
}
//+------------------------------------------------------------------
//+------------------------------------------------------------------
void Socket::manage_exception(string desc, string orig)
{
	//	Check the description
	if (desc!="Socket Timeout")
	{
		set_state(Tango::OFF);
		set_status(desc.c_str());

		if (autoReconnect)
		{
			//	If not timeout, delete sockect
			if (client_socket!=NULL)
			{
				delete 	client_socket;
				client_socket = NULL;
			}
			connected = false;
		}
	}

	//	Build a DevFailed with exception
	ERROR_STREAM << orig.c_str() << ":   " << desc.c_str() << endl;
	Tango::Except::throw_exception(
					(const char *) "SocketError",
					desc.c_str(),
					orig.c_str());
}



//+------------------------------------------------------------------
/**
 *	method:	Socket::write_read_until
 *
 *	description:	method to execute "WriteReadUntil"
 *	Write to the socket and waits for the answer.
 *	The answer is triggered by select() which indicates that the the anser has arrived.
 *
 * @param	argin	[0] = Command string to be send, [1] = end of message character
 * @return	Answer string.
 *
 */
//+------------------------------------------------------------------
Tango::DevString Socket::write_read_until(const Tango::DevVarStringArray *argin)
{
    DEBUG_STREAM << "Socket::write_read_until(): entering... !" << endl;

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
		Tango::DevString argout = CORBA::string_dup(reply.c_str());
		return argout;
	}
	catch ( SocketException& e )
	{
		manage_exception(e.description(), "Socket::write_and_read()");
	}
}


}	//	namespace
