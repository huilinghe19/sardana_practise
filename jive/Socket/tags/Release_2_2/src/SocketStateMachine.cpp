/*----- PROTECTED REGION ID(SocketStateMachine.cpp) ENABLED START -----*/
static const char *RcsId = "$Id: SocketStateMachine.cpp,v 1.3 2012-11-12 14:49:36 pascal_verdier Exp $";
//=============================================================================
//
// file :        SocketStateMachine.cpp
//
// description : C++ source for the �name� and its alowed
//               methods for commands and attributes
//
// project :     Socket.
//
// $Author: pascal_verdier $
//
// $Revision: 1.3 $
// $Date: 2012-11-12 14:49:36 $
//
// SVN only:
// $HeadURL:  $
//
// CVS only:
// $Source: /users/chaize/newsvn/cvsroot/Communication/Socket/src/SocketStateMachine.cpp,v $
// $Log: not supported by cvs2svn $
//
//=============================================================================
//                This file is generated by POGO
//        (Program Obviously used to Generate tango Object)
//=============================================================================



#include <Socket.h>
#include <SocketClass.h>

/*----- PROTECTED REGION END -----*/	//	Socket::SocketStateMachine.cpp

//================================================================
//  States  |  Description
//================================================================
//  ON      |  Normal state when everything is OK.
//  OFF     |  Disconnected from socket (or not yet connected to).


namespace Socket_ns
{
//=================================================
//		Attributes Allowed Methods
//=================================================

//--------------------------------------------------------
/**
 *	Method      : Socket::is_hostname_allowed()
 *	Description : Execution allowed for hostname attribute
 */
//--------------------------------------------------------
bool Socket::is_hostname_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Not any excluded states for hostname attribute in read access.
	/*----- PROTECTED REGION ID(Socket::hostnameStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	Socket::hostnameStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Socket::is_port_allowed()
 *	Description : Execution allowed for port attribute
 */
//--------------------------------------------------------
bool Socket::is_port_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Not any excluded states for port attribute in read access.
	/*----- PROTECTED REGION ID(Socket::portStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	Socket::portStateAllowed_READ
	return true;
}


//=================================================
//		Commands Allowed Methods
//=================================================

//--------------------------------------------------------
/**
 *	Method      : Socket::is_Reconnect_allowed()
 *	Description : Execution allowed for Reconnect attribute
 */
//--------------------------------------------------------
bool Socket::is_Reconnect_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Not any excluded states for Reconnect command.
	/*----- PROTECTED REGION ID(Socket::ReconnectStateAllowed) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	Socket::ReconnectStateAllowed
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Socket::is_Write_allowed()
 *	Description : Execution allowed for Write attribute
 */
//--------------------------------------------------------
bool Socket::is_Write_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::OFF)
	{
	/*----- PROTECTED REGION ID(Socket::WriteStateAllowed) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	Socket::WriteStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Socket::is_WriteAndRead_allowed()
 *	Description : Execution allowed for WriteAndRead attribute
 */
//--------------------------------------------------------
bool Socket::is_WriteAndRead_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::OFF)
	{
	/*----- PROTECTED REGION ID(Socket::WriteAndReadStateAllowed) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	Socket::WriteAndReadStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Socket::is_WriteReadUntil_allowed()
 *	Description : Execution allowed for WriteReadUntil attribute
 */
//--------------------------------------------------------
bool Socket::is_WriteReadUntil_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::OFF)
	{
	/*----- PROTECTED REGION ID(Socket::WriteReadUntilStateAllowed) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	Socket::WriteReadUntilStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Socket::is_WriteCharArray_allowed()
 *	Description : Execution allowed for WriteCharArray attribute
 */
//--------------------------------------------------------
bool Socket::is_WriteCharArray_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::OFF)
	{
	/*----- PROTECTED REGION ID(Socket::WriteCharArrayStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	Socket::WriteCharArrayStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Socket::is_Read_allowed()
 *	Description : Execution allowed for Read attribute
 */
//--------------------------------------------------------
bool Socket::is_Read_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::OFF)
	{
	/*----- PROTECTED REGION ID(Socket::ReadStateAllowed) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	Socket::ReadStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Socket::is_Readln_allowed()
 *	Description : Execution allowed for Readln attribute
 */
//--------------------------------------------------------
bool Socket::is_Readln_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::OFF)
	{
	/*----- PROTECTED REGION ID(Socket::ReadlnStateAllowed) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	Socket::ReadlnStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Socket::is_ReadUntil_allowed()
 *	Description : Execution allowed for ReadUntil attribute
 */
//--------------------------------------------------------
bool Socket::is_ReadUntil_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::OFF)
	{
	/*----- PROTECTED REGION ID(Socket::ReadUntilStateAllowed) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	Socket::ReadUntilStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Socket::is_ReadCharArray_allowed()
 *	Description : Execution allowed for ReadCharArray attribute
 */
//--------------------------------------------------------
bool Socket::is_ReadCharArray_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::OFF)
	{
	/*----- PROTECTED REGION ID(Socket::ReadCharArrayStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	Socket::ReadCharArrayStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Socket::is_WriteReadCharArray_allowed()
 *	Description : Execution allowed for WriteReadCharArray attribute
 */
//--------------------------------------------------------
bool Socket::is_WriteReadCharArray_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::OFF)
	{
	/*----- PROTECTED REGION ID(Socket::WriteReadCharArrayStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	Socket::WriteReadCharArrayStateAllowed
		return false;
	}
	return true;
}


/*----- PROTECTED REGION ID(Socket::SocketStateAllowed.AdditionalMethods) ENABLED START -----*/

//	Additional Methods

/*----- PROTECTED REGION END -----*/	//	Socket::SocketStateAllowed.AdditionalMethods

}	//	End of namespace