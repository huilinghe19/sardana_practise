//=============================================================================
//
// file :        Socket.h
//
// description : Include for the Socket class.
//
// project :	Socket
//
// $Author: pascal_verdier $
//
// $Revision: 1.4 $
//
// $Log: not supported by cvs2svn $
// Revision 1.3  2009/03/04 13:06:19  jensmeyer
// Added new command WriteReadUntil to have a write and read command
// with variable end of message terminator.
//
// Revision 1.2  2008/12/11 08:46:08  jensmeyer
// Regenerated with Pogo and changed port property from short to long.
//
// Revision 1.1.1.1  2007/01/12 10:07:44  pascal_verdier
// Initial Revision
//
// Revision 1.4  2005/12/13 07:51:40  bourtemb
// don't delete client_socket when the initialization failed, to avoid a segmentation fault.
//
// Revision 1.3  2005/10/04 13:51:35  peru
// Implemented "ReadUntil" command.
// Re-organization of the code.
//
// Revision 1.2  2005/09/05 13:42:21  peru
// Added "Readln" command.
//
// Revision 1.1.1.1  2005/07/12 06:59:46  peru
// Imported using TkCVS
//
// Revision 1.1.1.1  2005/07/12 06:16:03  peru
// Imported using TkCVS
//
//
// copyleft :    European Synchrotron Radiation Facility
//               BP 220, Grenoble 38043
//               FRANCE
//
//=============================================================================
//
//  		This file is generated by POGO
//	(Program Obviously used to Generate tango Object)
//
//         (c) - Software Engineering Group - ESRF
//=============================================================================
#ifndef _SOCKET_H
#define _SOCKET_H

#include <tango.h>
#include "ClientSocket.h"
//using namespace Tango;

/**
 * @author	$Author: pascal_verdier $
 * @version	$Revision: 1.4 $
 */

 //	Add your own constants definitions here.
 //-----------------------------------------------


namespace Socket_ns
{

/**
 * Class Description:
 * This class implements basic "socket" IPC.
 */

/*
 *	Device States Description:
*  Tango::ON :   Normal state when everything is OK.
*  Tango::OFF :  Disconnected from socket (or not yet connected to).
 */


class Socket: public Tango::Device_4Impl
{
public :
	//	Add your own data members here
	//-----------------------------------------
  bool connected;

	//	Here is the Start of the automatic code generation part
	//-------------------------------------------------------------	
/**
 *	@name attributes
 *	Attributs member data.
 */
//@{
//@}

/**
 *	@name Device properties
 *	Device properties member data.
 */
//@{
/**
 *	This is the hostname of the host to connect to.
 */
	string	hostname;
/**
 *	This is the port number to connect to.
 */
	Tango::DevLong	port;
/**
 *	Read timeout in milliseconds.
 */
	Tango::DevShort	readtimeout;
/**
 *	If true, the server try to re-create and re-connect to the socket after a failure.
 *	NOTE : The default values is false.
 */
	Tango::DevBoolean	autoReconnect;
//@}

/**@name Constructors
 * Miscellaneous constructors */
//@{
/**
 * Constructs a newly allocated Command object.
 *
 *	@param cl	Class.
 *	@param s 	Device Name
 */
	Socket(Tango::DeviceClass *cl,string &s);
/**
 * Constructs a newly allocated Command object.
 *
 *	@param cl	Class.
 *	@param s 	Device Name
 */
	Socket(Tango::DeviceClass *cl,const char *s);
/**
 * Constructs a newly allocated Command object.
 *
 *	@param cl	Class.
 *	@param s 	Device name
 *	@param d	Device description.
 */
	Socket(Tango::DeviceClass *cl,const char *s,const char *d);
//@}

/**@name Destructor
 * Only one desctructor is defined for this class */
//@{
/**
 * The object desctructor.
 */	
	~Socket() {delete_device();};
/**
 *	will be called at device destruction or at init command.
 */
	void delete_device();
//@}

	
/**@name Miscellaneous methods */
//@{
/**
 *	Initialize the device
 */
	virtual void init_device();
/**
 *	Always executed method befor execution command method.
 */
	virtual void always_executed_hook();

//@}

/**
 * @name Socket methods prototypes
 */

//@{
/**
 *	Execution allowed for Write command.
 */
	virtual bool is_Write_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for Read command.
 */
	virtual bool is_Read_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for Reconnect command.
 */
	virtual bool is_Reconnect_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for WriteAndRead command.
 */
	virtual bool is_WriteAndRead_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for Readln command.
 */
	virtual bool is_Readln_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for ReadUntil command.
 */
	virtual bool is_ReadUntil_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for WriteReadUntil command.
 */
	virtual bool is_WriteReadUntil_allowed(const CORBA::Any &any);
/**
 * Command used to send a string to the socket.
 *	@param	argin	
 *	@exception DevFailed
 */
	void	write(Tango::DevString);
/**
 * Command used to read a string from the socket.
 *	@return	
 *	@exception DevFailed
 */
	Tango::DevString	read();
/**
 * Attempts to re-establish the socket connection.
 *	@exception DevFailed
 */
	void	reconnect();
/**
 * Write to the socket and waits for the answer.
 *	The end of the answer is triggered by the new line character!
 *	@param	argin	Command string.
 *	@return	Answer string.
 *	@exception DevFailed
 */
	Tango::DevString	write_and_read(Tango::DevString);
/**
 * Reads from a socket until a "\n" has been received.
 *	@return	argout
 *	@exception DevFailed
 */
	Tango::DevString	readln();
/**
 * This command read data from the socket until the terminator has been reached.
 *	@param	argin	This is the terminator
 *	@return	This is the read string.
 *	@exception DevFailed
 */
	Tango::DevString	read_until(Tango::DevString);
/**
 * Write to the socket and waits for the answer.
 *	The answer is triggered by select() which indicates that the the anser has arrived.
 *	@param	argin	[0] = Command string to be send, [1] = end of message character
 *	@return	Answer string.
 *	@exception DevFailed
 */
	Tango::DevString	write_read_until(const Tango::DevVarStringArray *);

/**
 *	Read the device properties from database
 */
	 void get_device_property();
//@}

	//	Here is the end of the automatic code generation part
	//-------------------------------------------------------------	



protected :	
	//	Add your own data members here
	//-----------------------------------------
	ClientSocket *client_socket;
	bool startsWith(string str, string beg);
	void manage_exception(string desc, string orig);
	void check_connection();
};

}	// namespace_ns

#endif	// _SOCKET_H