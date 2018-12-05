//=============================================================================
//
// file :        ClientSocket.h
//
// description : Definition of the ClientSocket class.
//               From an article in "Linux gazette" by Rob Tougher
//               And modified later.
//
// project :	Socket
//
// $Author: pascal_verdier $
//
// $Revision: 1.1.1.1 $
// $Log: not supported by cvs2svn $
//
// copyleft :    European Synchrotron Radiation Facility
//               BP 220, Grenoble 38043
//               FRANCE
//
//         (c) - Software Engineering Group - ESRF
//=============================================================================

#ifndef ClientSocket_class
#define ClientSocket_class

#include <string>
#include "SocketAccess.h"


#include <sys/time.h>


class ClientSocket : private SocketAccess
{
 public:
  ClientSocket ( std::string host, int port );
  virtual ~ClientSocket(){};

  void set_non_blocking(const bool);

  const ClientSocket& operator << ( const std::string& ) const;
  const ClientSocket& operator << ( const Tango::DevVarCharArray& ) const;
  const ClientSocket& operator >> ( std::string& ) const;
  void readln(std::string&, short);
  void readCharArray(Tango::DevVarCharArray& ,long , short );
  void readuntil(std::string&, char *, short);
  void readchar(char &, short);
};

#endif
