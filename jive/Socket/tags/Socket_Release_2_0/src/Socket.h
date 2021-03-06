/*----- PROTECTED REGION ID(Socket.h) ENABLED START -----*/
//=============================================================================
//
// file :        Socket.h
//
// description : Include for the Socket class.
//
// project :     Socket.
//
// $Author: pascal_verdier $
//
// $Revision: 1.5 $
// $Date: 2012-11-12 14:49:36 $
//
// SVN only:
// $HeadURL:  $
//
// CVS only:
// $Source: /users/chaize/newsvn/cvsroot/Communication/Socket/src/Socket.h,v $
// $Log: not supported by cvs2svn $
//
//=============================================================================
//                This file is generated by POGO
//        (Program Obviously used to Generate tango Object)
//=============================================================================


#ifndef SOCKET_H
#define SOCKET_H


#include <tango.h>
#include "ClientSocket.h"





/*----- PROTECTED REGION END -----*/	//	Socket.h

/**
 *  Socket class description:
 *    This class implements basic `socket` IPC.
 */

namespace Socket_ns
{
/*----- PROTECTED REGION ID(Socket::Additional Class Declarations) ENABLED START -----*/

		//		Additional Class Declarations

	/*----- PROTECTED REGION END -----*/	//	Socket::Additional Class Declarations

class Socket : public Tango::Device_4Impl
{

/*----- PROTECTED REGION ID(Socket::Data Members) ENABLED START -----*/

	//		Add your own data members
public:
  bool connected;


	/*----- PROTECTED REGION END -----*/	//	Socket::Data Members

//	Device property data members
public:
	//	Hostname:	This is the hostname of the host to connect to.
	string	hostname;
	//	Port:	This is the port number to connect to.
	Tango::DevLong	port;
	//	Readtimeout:	Read timeout in milliseconds.
	Tango::DevShort	readtimeout;
	//	AutoReconnect:	If true, the server try to re-create and re-connect to the socket after a failure.
	//  NOTE : The default values is false.
	Tango::DevBoolean	autoReconnect;


//	Constructors and destructors
public:
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device Name
	 */
	Socket(Tango::DeviceClass *cl,string &s);
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device Name
	 */
	Socket(Tango::DeviceClass *cl,const char *s);
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device name
	 *	@param d	Device description.
	 */
	Socket(Tango::DeviceClass *cl,const char *s,const char *d);
	/**
	 * The device object destructor.
	 */	
	~Socket() {delete_device();};


//	Miscellaneous methods
public:
	/**
	 *	will be called at device destruction or at init command.
	 */
	void delete_device();
	/**
	 *	Initialize the device
	 */
	virtual void init_device();
	/**
	 *	Read the device properties from database
	 */
	void get_device_property();
	/**
	 *	Always executed method before execution command method.
	 */
	virtual void always_executed_hook();


//	Attribute methods
public:
	//--------------------------------------------------------
	/**
	 *	Method      : Socket::read_attr_hardware()
	 *	Description : Hardware acquisition for attributes.
	 */
	//--------------------------------------------------------
	virtual void read_attr_hardware(vector<long> &attr_list);


	//--------------------------------------------------------
	/**
	 *	Method      : Socket::add_dynamic_attributes()
	 *	Description : Add dynamic attributes if any.
	 */
	//--------------------------------------------------------
	void add_dynamic_attributes();



//	Command related methods
public:
	/**
	 *	Command Write related method
	 *	Description: Command used to send a string to the socket.
	 *
	 *	@param argin 
	 *	@returns 
	 */
	virtual void write(Tango::DevString argin);
	virtual bool is_Write_allowed(const CORBA::Any &any);
	/**
	 *	Command Read related method
	 *	Description: Command used to read a string from the socket.
	 *
	 *	@param argin 
	 *	@returns 
	 */
	virtual Tango::DevString read();
	virtual bool is_Read_allowed(const CORBA::Any &any);
	/**
	 *	Command Reconnect related method
	 *	Description: Attempts to re-establish the socket connection.
	 *
	 *	@param argin 
	 *	@returns 
	 */
	virtual void reconnect();
	virtual bool is_Reconnect_allowed(const CORBA::Any &any);
	/**
	 *	Command WriteAndRead related method
	 *	Description: Write to the socket and waits for the answer.
	 *               The end of the answer is triggered by the new line character!
	 *
	 *	@param argin Command string.
	 *	@returns Answer string.
	 */
	virtual Tango::DevString write_and_read(Tango::DevString argin);
	virtual bool is_WriteAndRead_allowed(const CORBA::Any &any);
	/**
	 *	Command Readln related method
	 *	Description: Reads from a socket until a "\n" has been received.
	 *
	 *	@param argin 
	 *	@returns argout
	 */
	virtual Tango::DevString readln();
	virtual bool is_Readln_allowed(const CORBA::Any &any);
	/**
	 *	Command ReadUntil related method
	 *	Description: This command read data from the socket until the terminator has been reached.
	 *
	 *	@param argin This is the terminator
	 *	@returns This is the read string.
	 */
	virtual Tango::DevString read_until(Tango::DevString argin);
	virtual bool is_ReadUntil_allowed(const CORBA::Any &any);
	/**
	 *	Command WriteReadUntil related method
	 *	Description: Write to the socket and waits for the answer.
	 *               The answer is triggered by select() which indicates that the the anser has arrived.
	 *
	 *	@param argin [0] = Command string to be send, [1] = end of message character
	 *	@returns Answer string.
	 */
	virtual Tango::DevString write_read_until(const Tango::DevVarStringArray *argin);
	virtual bool is_WriteReadUntil_allowed(const CORBA::Any &any);


/*----- PROTECTED REGION ID(Socket::Additional Method prototypes) ENABLED START -----*/

	//	Additional Method prototypes
protected :	
	ClientSocket *client_socket;
	bool startsWith(string str, string beg);
	void manage_exception(string desc, string orig);
	void check_connection();

	/*----- PROTECTED REGION END -----*/	//	Socket::Additional Method prototypes
};

/*----- PROTECTED REGION ID(Socket::Additional Classes Definitions) ENABLED START -----*/

	//	Additional Classes definitions

	/*----- PROTECTED REGION END -----*/	//	Socket::Additional Classes Definitions

}	//	End of namespace

#endif   //	Socket_H
