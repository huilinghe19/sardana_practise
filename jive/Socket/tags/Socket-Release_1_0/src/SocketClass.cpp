static const char *RcsId     = "$Header: /users/chaize/newsvn/cvsroot/Communication/Socket/src/SocketClass.cpp,v 1.1.1.1 2007-01-12 10:07:43 pascal_verdier Exp $";
static const char *TagName   = "$Name: not supported by cvs2svn $";
static const char *HttpServer= "http://www.esrf.fr/computing/cs/tango/tango_doc/ds_doc/";
//+=============================================================================
//
// file :        SocketClass.cpp
//
// description : C++ source for the SocketClass. A singleton
//               class derived from DeviceClass. It implements the
//               command list and all properties and methods required
//               by the Socket once per process.
//
// project :     TANGO Device Server
//
// $Author: pascal_verdier $
//
// $Revision: 1.1.1.1 $
//
// $Log: not supported by cvs2svn $
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
// copyleft :   European Synchrotron Radiation Facility
//              BP 220, Grenoble 38043
//              FRANCE
//
//-=============================================================================
//
//  		This file is generated by POGO
//	(Program Obviously used to Generate tango Object)
//
//         (c) - Software Engineering Group - ESRF
//=============================================================================


#include <tango.h>

#include <Socket.h>
#include <SocketClass.h>


namespace Socket_ns
{
//+----------------------------------------------------------------------------
//
// method : 		ReadUntilClass::execute()
// 
// description : 	method to trigger the execution of the command.
//                PLEASE DO NOT MODIFY this method core without pogo   
//
// in : - device : The device on which the command must be excuted
//		- in_any : The command input data
//
// returns : The command output data (packed in the Any object)
//
//-----------------------------------------------------------------------------
CORBA::Any *ReadUntilClass::execute(Tango::DeviceImpl *device,const CORBA::Any &in_any)
{

	cout2 << "ReadUntilClass::execute(): arrived" << endl;

	Tango::DevString	argin;
	extract(in_any, argin);

	return insert((static_cast<Socket *>(device))->read_until(argin));
}

//+----------------------------------------------------------------------------
//
// method : 		ReadlnClass::execute()
// 
// description : 	method to trigger the execution of the command.
//                PLEASE DO NOT MODIFY this method core without pogo   
//
// in : - device : The device on which the command must be excuted
//		- in_any : The command input data
//
// returns : The command output data (packed in the Any object)
//
//-----------------------------------------------------------------------------
CORBA::Any *ReadlnClass::execute(Tango::DeviceImpl *device,const CORBA::Any &in_any)
{

	cout2 << "ReadlnClass::execute(): arrived" << endl;

	return insert((static_cast<Socket *>(device))->readln());
}

//+----------------------------------------------------------------------------
//
// method : 		WriteAndReadClass::execute()
// 
// description : 	method to trigger the execution of the command.
//                PLEASE DO NOT MODIFY this method core without pogo   
//
// in : - device : The device on which the command must be excuted
//		- in_any : The command input data
//
// returns : The command output data (packed in the Any object)
//
//-----------------------------------------------------------------------------
CORBA::Any *WriteAndReadClass::execute(Tango::DeviceImpl *device,const CORBA::Any &in_any)
{

	cout2 << "WriteAndReadClass::execute(): arrived" << endl;

	Tango::DevString	argin;
	extract(in_any, argin);

	return insert((static_cast<Socket *>(device))->write_and_read(argin));
}


//+----------------------------------------------------------------------------
//
// method : 		WriteClass::execute()
// 
// description : 	method to trigger the execution of the command.
//                PLEASE DO NOT MODIFY this method core without pogo   
//
// in : - device : The device on which the command must be excuted
//		- in_any : The command input data
//
// returns : The command output data (packed in the Any object)
//
//-----------------------------------------------------------------------------
CORBA::Any *WriteClass::execute(Tango::DeviceImpl *device,const CORBA::Any &in_any)
{

	cout2 << "WriteClass::execute(): arrived" << endl;

	Tango::DevString	argin;
	extract(in_any, argin);

	((static_cast<Socket *>(device))->write(argin));
	return new CORBA::Any();
}

//+----------------------------------------------------------------------------
//
// method : 		ReadClass::execute()
// 
// description : 	method to trigger the execution of the command.
//                PLEASE DO NOT MODIFY this method core without pogo   
//
// in : - device : The device on which the command must be excuted
//		- in_any : The command input data
//
// returns : The command output data (packed in the Any object)
//
//-----------------------------------------------------------------------------
CORBA::Any *ReadClass::execute(Tango::DeviceImpl *device,const CORBA::Any &in_any)
{

	cout2 << "ReadClass::execute(): arrived" << endl;

	return insert((static_cast<Socket *>(device))->read());
}

//+----------------------------------------------------------------------------
//
// method : 		ReconnectClass::execute()
// 
// description : 	method to trigger the execution of the command.
//                PLEASE DO NOT MODIFY this method core without pogo   
//
// in : - device : The device on which the command must be excuted
//		- in_any : The command input data
//
// returns : The command output data (packed in the Any object)
//
//-----------------------------------------------------------------------------
CORBA::Any *ReconnectClass::execute(Tango::DeviceImpl *device,const CORBA::Any &in_any)
{

	cout2 << "ReconnectClass::execute(): arrived" << endl;

	((static_cast<Socket *>(device))->reconnect());
	return new CORBA::Any();
}

//
//----------------------------------------------------------------
//	Initialize pointer for singleton pattern
//----------------------------------------------------------------
//
SocketClass *SocketClass::_instance = NULL;

//+----------------------------------------------------------------------------
//
// method : 		SocketClass::SocketClass(string &s)
// 
// description : 	constructor for the SocketClass
//
// in : - s : The class name
//
//-----------------------------------------------------------------------------
SocketClass::SocketClass(string &s):DeviceClass(s)
{

	cout2 << "Entering SocketClass constructor" << endl;
	get_class_property();
	set_default_property();
	write_class_property();
	
	cout2 << "Leaving SocketClass constructor" << endl;

}
//+----------------------------------------------------------------------------
//
// method : 		SocketClass::~SocketClass()
// 
// description : 	destructor for the SocketClass
//
//-----------------------------------------------------------------------------
SocketClass::~SocketClass()
{
	_instance = NULL;
}

//+----------------------------------------------------------------------------
//
// method : 		SocketClass::instance
// 
// description : 	Create the object if not already done. Otherwise, just
//			return a pointer to the object
//
// in : - name : The class name
//
//-----------------------------------------------------------------------------
SocketClass *SocketClass::init(const char *name)
{
	if (_instance == NULL)
	{
		try
		{
			string s(name);
			_instance = new SocketClass(s);
		}
		catch (bad_alloc)
		{
			throw;
		}		
	}		
	return _instance;
}

SocketClass *SocketClass::instance()
{
	if (_instance == NULL)
	{
		cerr << "Class is not initialised !!" << endl;
		exit(-1);
	}
	return _instance;
}

//+----------------------------------------------------------------------------
//
// method : 		SocketClass::command_factory
// 
// description : 	Create the command object(s) and store them in the 
//			command list
//
//-----------------------------------------------------------------------------
void SocketClass::command_factory()
{
	command_list.push_back(new WriteClass("Write",
		Tango::DEV_STRING, Tango::DEV_VOID,
		"",
		"",
		Tango::OPERATOR));
	command_list.push_back(new ReadClass("Read",
		Tango::DEV_VOID, Tango::DEV_STRING,
		"",
		"",
		Tango::OPERATOR));
	command_list.push_back(new ReconnectClass("Reconnect",
		Tango::DEV_VOID, Tango::DEV_VOID,
		"",
		"",
		Tango::OPERATOR));
	command_list.push_back(new WriteAndReadClass("WriteAndRead",
		Tango::DEV_STRING, Tango::DEV_STRING,
		"Command string.",
		"Answer string.",
		Tango::OPERATOR));
	command_list.push_back(new ReadlnClass("Readln",
		Tango::DEV_VOID, Tango::DEV_STRING,
		"",
		"argout",
		Tango::OPERATOR));
	command_list.push_back(new ReadUntilClass("ReadUntil",
		Tango::DEV_STRING, Tango::DEV_STRING,
		"This is the terminator",
		"This is the read string.",
		Tango::OPERATOR));

	//	add polling if any
	for (unsigned int i=0 ; i<command_list.size(); i++)
	{
	}
}

//+----------------------------------------------------------------------------
//
// method : 		SocketClass::get_class_property
// 
// description : 	Get the class property for specified name.
//
// in :		string	name : The property name
//
//+----------------------------------------------------------------------------
Tango::DbDatum SocketClass::get_class_property(string &prop_name)
{
	for (unsigned int i=0 ; i<cl_prop.size() ; i++)
		if (cl_prop[i].name == prop_name)
			return cl_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}
//+----------------------------------------------------------------------------
//
// method : 		SocketClass::get_default_device_property()
// 
// description : 	Return the default value for device property.
//
//-----------------------------------------------------------------------------
Tango::DbDatum SocketClass::get_default_device_property(string &prop_name)
{
	for (unsigned int i=0 ; i<dev_def_prop.size() ; i++)
		if (dev_def_prop[i].name == prop_name)
			return dev_def_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}

//+----------------------------------------------------------------------------
//
// method : 		SocketClass::get_default_class_property()
// 
// description : 	Return the default value for class property.
//
//-----------------------------------------------------------------------------
Tango::DbDatum SocketClass::get_default_class_property(string &prop_name)
{
	for (unsigned int i=0 ; i<cl_def_prop.size() ; i++)
		if (cl_def_prop[i].name == prop_name)
			return cl_def_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}
//+----------------------------------------------------------------------------
//
// method : 		SocketClass::device_factory
// 
// description : 	Create the device object(s) and store them in the 
//			device list
//
// in :		Tango::DevVarStringArray *devlist_ptr : The device name list
//
//-----------------------------------------------------------------------------
void SocketClass::device_factory(const Tango::DevVarStringArray *devlist_ptr)
{

	//	Create all devices.(Automatic code generation)
	//-------------------------------------------------------------
	for (unsigned long i=0 ; i < devlist_ptr->length() ; i++)
	{
		cout4 << "Device name : " << (*devlist_ptr)[i].in() << endl;
						
		// Create devices and add it into the device list
		//----------------------------------------------------
		device_list.push_back(new Socket(this, (*devlist_ptr)[i]));							 

		// Export device to the outside world
		// Check before if database used.
		//---------------------------------------------
		if ((Tango::Util::_UseDb == true) && (Tango::Util::_FileDb == false))
			export_device(device_list.back());
		else
			export_device(device_list.back(), (*devlist_ptr)[i]);
	}
	//	End of Automatic code generation
	//-------------------------------------------------------------

}


//+----------------------------------------------------------------------------
//
// method : 		SocketClass::get_class_property()
// 
// description : 	Read the class properties from database.
//
//-----------------------------------------------------------------------------
void SocketClass::get_class_property()
{
	//	Initialize your default values here (if not done with  POGO).
	//------------------------------------------------------------------

	//	Read class properties from database.(Automatic code generation)
	//------------------------------------------------------------------

	//	Call database and extract values
	//--------------------------------------------
	if (Tango::Util::instance()->_UseDb==true)
		get_db_class()->get_property(cl_prop);
	Tango::DbDatum	def_prop;
	int	i = -1;


	//	End of Automatic code generation
	//------------------------------------------------------------------

}

//+----------------------------------------------------------------------------
//
// method : 	SocketClass::set_default_property
// 
// description: Set default property (class and device) for wizard.
//              For each property, add to wizard property name and description
//              If default value has been set, add it to wizard property and
//              store it in a DbDatum.
//
//-----------------------------------------------------------------------------
void SocketClass::set_default_property()
{
	string	prop_name;
	string	prop_desc;
	string	prop_def;

	vector<string>	vect_data;
	//	Set Default Class Properties
	//	Set Default Device Properties
	prop_name = "Hostname";
	prop_desc = "This is the hostname of the host to connect to.";
	prop_def  = "";
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

	prop_name = "Port";
	prop_desc = "This is the port number to connect to.";
	prop_def  = "";
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

	prop_name = "Readtimeout";
	prop_desc = "Read timeout in milliseconds.";
	prop_def  = "";
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

	prop_name = "AutoReconnect";
	prop_desc = "If true, the server try to re-create and re-connect to the socket after a failure.\nNOTE : The default values is false.";
	prop_def  = "false";
	vect_data.clear();
	vect_data.push_back("false");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

}
//+----------------------------------------------------------------------------
//
// method : 		SocketClass::write_class_property
// 
// description : 	Set class description as property in database
//
//-----------------------------------------------------------------------------
void SocketClass::write_class_property()
{
	//	First time, check if database used
	//--------------------------------------------
	if (Tango::Util::_UseDb == false)
		return;

	Tango::DbData	data;
	string	classname = get_name();
	string	header;
	string::size_type	start, end;

	//	Put title
	Tango::DbDatum	title("ProjectTitle");
	string	str_title("Socket");
	title << str_title;
	data.push_back(title);

	//	Put Description
	Tango::DbDatum	description("Description");
	vector<string>	str_desc;
	str_desc.push_back("This class implements basic \"socket\" IPC.");
	description << str_desc;
	data.push_back(description);
		
	//	put cvs location
	string	rcsId(RcsId);
	string	filename(classname);
	start = rcsId.find("/");
	if (start!=string::npos)
	{
		filename += "Class.cpp";
		end   = rcsId.find(filename);
		if (end>start)
		{
			string	strloc = rcsId.substr(start, end-start);
			//	Check if specific repository
			start = strloc.find("/cvsroot/");
			if (start!=string::npos && start>0)
			{
				string	repository = strloc.substr(0, start);
				if (repository.find("/segfs/")!=string::npos)
					strloc = "ESRF:" + strloc.substr(start, strloc.length()-start);
			}
			Tango::DbDatum	cvs_loc("cvs_location");
			cvs_loc << strloc;
			data.push_back(cvs_loc);
		}
	}

	//	Get CVS tag revision
	string	tagname(TagName);
	header = "$Name: ";
	start = header.length();
	string	endstr(" $");
	end   = tagname.find(endstr);
	if (end!=string::npos && end>start)
	{
		string	strtag = tagname.substr(start, end-start);
		Tango::DbDatum	cvs_tag("cvs_tag");
		cvs_tag << strtag;
		data.push_back(cvs_tag);
	}

	//	Get URL location
	string	httpServ(HttpServer);
	if (httpServ.length()>0)
	{
		Tango::DbDatum	db_doc_url("doc_url");
		db_doc_url << httpServ;
		data.push_back(db_doc_url);
	}

	//  Put inheritance
	Tango::DbDatum	inher_datum("InheritedFrom");
	vector<string> inheritance;
	inheritance.push_back("Device_3Impl");
	inher_datum << inheritance;
	data.push_back(inher_datum);

	//	Call database and and values
	//--------------------------------------------
	get_db_class()->put_property(data);
}

}	// namespace