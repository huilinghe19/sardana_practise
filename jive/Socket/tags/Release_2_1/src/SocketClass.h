/*----- PROTECTED REGION ID(SocketClass.h) ENABLED START -----*/
//=============================================================================
//
// file :        SocketClass.h
//
// description : Include for the SocketClass root class.
//               This class is the singleton class for.
//               the Socket device class..
//               It contains all properties and methods which the .
//               Socket requires only once e.g. the commands.
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
// $Source: /users/chaize/newsvn/cvsroot/Communication/Socket/src/SocketClass.h,v $
// $Log: not supported by cvs2svn $
//
//=============================================================================
//                This file is generated by POGO
//        (Program Obviously used to Generate tango Object)
//=============================================================================


#ifndef SOCKETCLASS_H
#define SOCKETCLASS_H

#include <tango.h>
#include <Socket.h>

/*----- PROTECTED REGION END -----*/	//	SocketClass.h


namespace Socket_ns
{
/*----- PROTECTED REGION ID(SocketClass::classes for dynamic creation) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	SocketClass::classes for dynamic creation

//=========================================
//	Define classes for commands
//=========================================
//	Command Reconnect class definition
class ReconnectClass : public Tango::Command
{
public:
	ReconnectClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	ReconnectClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~ReconnectClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<Socket *>(dev))->is_Reconnect_allowed(any);}
};

//	Command Write class definition
class WriteClass : public Tango::Command
{
public:
	WriteClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	WriteClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~WriteClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<Socket *>(dev))->is_Write_allowed(any);}
};

//	Command WriteAndRead class definition
class WriteAndReadClass : public Tango::Command
{
public:
	WriteAndReadClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	WriteAndReadClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~WriteAndReadClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<Socket *>(dev))->is_WriteAndRead_allowed(any);}
};

//	Command WriteReadUntil class definition
class WriteReadUntilClass : public Tango::Command
{
public:
	WriteReadUntilClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	WriteReadUntilClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~WriteReadUntilClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<Socket *>(dev))->is_WriteReadUntil_allowed(any);}
};

//	Command WriteCharArray class definition
class WriteCharArrayClass : public Tango::Command
{
public:
	WriteCharArrayClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	WriteCharArrayClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~WriteCharArrayClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<Socket *>(dev))->is_WriteCharArray_allowed(any);}
};

//	Command Read class definition
class ReadClass : public Tango::Command
{
public:
	ReadClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	ReadClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~ReadClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<Socket *>(dev))->is_Read_allowed(any);}
};

//	Command Readln class definition
class ReadlnClass : public Tango::Command
{
public:
	ReadlnClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	ReadlnClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~ReadlnClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<Socket *>(dev))->is_Readln_allowed(any);}
};

//	Command ReadUntil class definition
class ReadUntilClass : public Tango::Command
{
public:
	ReadUntilClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	ReadUntilClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~ReadUntilClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<Socket *>(dev))->is_ReadUntil_allowed(any);}
};

//	Command ReadCharArray class definition
class ReadCharArrayClass : public Tango::Command
{
public:
	ReadCharArrayClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	ReadCharArrayClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~ReadCharArrayClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<Socket *>(dev))->is_ReadCharArray_allowed(any);}
};


/**
 *	The SocketClass singleton definition
 */

#ifdef _TG_WINDOWS_
class __declspec(dllexport)  SocketClass : public Tango::DeviceClass
#else
class SocketClass : public Tango::DeviceClass
#endif
{
	/*----- PROTECTED REGION ID(SocketClass::Additionnal DServer data members) ENABLED START -----*/
public:
	

	/*----- PROTECTED REGION END -----*/	//	SocketClass::Additionnal DServer data members

	public:
		//	write class properties data members
		Tango::DbData	cl_prop;
		Tango::DbData	cl_def_prop;
		Tango::DbData	dev_def_prop;
	
		//	Method prototypes
		static SocketClass *init(const char *);
		static SocketClass *instance();
		~SocketClass();
		Tango::DbDatum	get_class_property(string &);
		Tango::DbDatum	get_default_device_property(string &);
		Tango::DbDatum	get_default_class_property(string &);
	
	protected:
		SocketClass(string &);
		static SocketClass *_instance;
		void command_factory();
		void attribute_factory(vector<Tango::Attr *> &);
		void pipe_factory();
		void write_class_property();
		void set_default_property();
		void get_class_property();
		string get_cvstag();
		string get_cvsroot();
	
	private:
		void device_factory(const Tango::DevVarStringArray *);
		void create_static_attribute_list(vector<Tango::Attr *> &);
		void erase_dynamic_attributes(const Tango::DevVarStringArray *,vector<Tango::Attr *> &);
		vector<string>	defaultAttList;
		Tango::Attr *get_attr_object_by_name(vector<Tango::Attr *> &att_list, string attname);
};

}	//	End of namespace

#endif   //	Socket_H