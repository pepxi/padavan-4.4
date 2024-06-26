######################################################################
##
## autogenerated file of smb.conf parameters
## generate_parm_table <..../param/loadparm.c>
##
##  Copyright (C) Gerald Carter		       2004.
##
##  This program is free software; you can redistribute it and/or modify
##  it under the terms of the GNU General Public License as published by
##  the Free Software Foundation; either version 2 of the License, or
##  (at your option) any later version.
##
##  This program is distributed in the hope that it will be useful,
##  but WITHOUT ANY WARRANTY; without even the implied warranty of
##  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
##  GNU General Public License for more details.
##
##  You should have received a copy of the GNU General Public License
##  along with this program; if not, write to the Free Software
##  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
##
######################################################################

from SambaParm import SambaParmString, SambaParmBool, SambaParmBoolRev

## boolean defines for parm_table
P_LOCAL    = 0
P_GLOBAL   = 1

parm_table = {
	"PRELOADMODULES"         : ("preload modules", SambaParmString, P_GLOBAL, ""),
	"ONLYGUEST"              : ("guest only", SambaParmBool, P_LOCAL, "No"),
	"PRIVATEDIR"             : ("private dir", SambaParmString, P_GLOBAL, "/etc/samba/private"),
	"HIDESPECIALFILES"       : ("hide special files", SambaParmBool, P_LOCAL, "No"),
	"WINBINDENUMUSERS"       : ("winbind enum users", SambaParmBool, P_GLOBAL, "Yes"),
	"TIMESTAMPLOGS"          : ("debug timestamp", SambaParmBool, P_GLOBAL, "Yes"),
	"LDAPPASSWDSYNC"         : ("ldap passwd sync", SambaParmString, P_GLOBAL, "no"),
	"READBMPX"               : ("read bmpx", SambaParmBool, P_GLOBAL, "No"),
	"PASSWORDSERVER"         : ("password server", SambaParmString, P_GLOBAL, "*"),
	"COPY"                   : ("copy", SambaParmString, P_LOCAL, ""),
	"MAXXMIT"                : ("max xmit", SambaParmString, P_GLOBAL, "16644"),
	"MINPRINTSPACE"          : ("min print space", SambaParmString, P_LOCAL, "0"),
	"CASESENSITIVE"          : ("case sensitive", SambaParmString, P_LOCAL, "Auto"),
	"LDAPIDMAPSUFFIX"        : ("ldap idmap suffix", SambaParmString, P_GLOBAL, ""),
	"NAMECACHETIMEOUT"       : ("name cache timeout", SambaParmString, P_GLOBAL, "660"),
	"MAPARCHIVE"             : ("map archive", SambaParmBool, P_LOCAL, "Yes"),
	"LANMANAUTH"             : ("lanman auth", SambaParmBool, P_GLOBAL, "Yes"),
	"NETBIOSSCOPE"           : ("netbios scope", SambaParmString, P_GLOBAL, ""),
	"MAXREPORTEDPRINTJOBS"   : ("max reported print jobs", SambaParmString, P_LOCAL, "0"),
	"CREATEMODE"             : ("create mask", SambaParmString, P_LOCAL, "0744"),
	"READLIST"               : ("read list", SambaParmString, P_LOCAL, ""),
	"WINBINDNESTEDGROUPS"    : ("winbind nested groups", SambaParmBool, P_GLOBAL, "No"),
	"COMMENT"                : ("comment", SambaParmString, P_LOCAL, ""),
	"PRINTER"                : ("printer name", SambaParmString, P_LOCAL, ""),
	"LMANNOUNCE"             : ("lm announce", SambaParmString, P_GLOBAL, "Auto"),
	"SYSLOGONLY"             : ("syslog only", SambaParmBool, P_GLOBAL, "No"),
	"LMINTERVAL"             : ("lm interval", SambaParmString, P_GLOBAL, "60"),
	"MANGLINGMETHOD"         : ("mangling method", SambaParmString, P_GLOBAL, "hash2"),
	"PROFILEACLS"            : ("profile acls", SambaParmBool, P_LOCAL, "No"),
	"LDAPGROUPSUFFIX"        : ("ldap group suffix", SambaParmString, P_GLOBAL, ""),
	"MAPTOGUEST"             : ("map to guest", SambaParmString, P_GLOBAL, "Never"),
	"NULLPASSWORDS"          : ("null passwords", SambaParmBool, P_GLOBAL, "No"),
	"ONLYUSER"               : ("only user", SambaParmBool, P_LOCAL, "No"),
	"UTMP"                   : ("utmp", SambaParmBool, P_GLOBAL, "No"),
	"DONTDESCEND"            : ("dont descend", SambaParmString, P_LOCAL, ""),
	"PRINTING"               : ("printing", SambaParmString, P_LOCAL, "cups"),
	"SOCKETOPTIONS"          : ("socket options", SambaParmString, P_GLOBAL, "TCP_NODELAY"),
	"CLIENTUSESPNEGO"        : ("client use spnego", SambaParmBool, P_GLOBAL, "Yes"),
	"USESPNEGO"              : ("use spnego", SambaParmBool, P_GLOBAL, "Yes"),
	"FAKEOPLOCKS"            : ("fake oplocks", SambaParmBool, P_LOCAL, "No"),
	"FORCECREATEMODE"        : ("force create mode", SambaParmString, P_LOCAL, "00"),
	"SETDIRECTORY"           : ("set directory", SambaParmBoolRev, P_LOCAL, "No"),
	"SMBPORTS"               : ("smb ports", SambaParmString, P_GLOBAL, "445 139"),
	"LOCKDIR"                : ("lock directory", SambaParmString, P_GLOBAL, "/var/lib/samba"),
	"BROWSEABLE"             : ("browseable", SambaParmBool, P_LOCAL, "Yes"),
	"WINSPROXY"              : ("wins proxy", SambaParmBool, P_GLOBAL, "No"),
	"FORCEGROUP"             : ("force group", SambaParmString, P_LOCAL, ""),
	"NTSTATUSSUPPORT"        : ("nt status support", SambaParmBool, P_GLOBAL, "Yes"),
	"EXEC"                   : ("preexec", SambaParmString, P_LOCAL, ""),
	"DOMAINLOGONS"           : ("domain logons", SambaParmBool, P_GLOBAL, "No"),
	"TEMPLATESHELL"          : ("template shell", SambaParmString, P_GLOBAL, "/bin/false"),
	"USESENDFILE"            : ("use sendfile", SambaParmBool, P_LOCAL, "No"),
	"USEMMAP"                : ("use mmap", SambaParmBool, P_GLOBAL, "Yes"),
	"VALIDUSERS"             : ("valid users", SambaParmString, P_LOCAL, ""),
	"DEBUGLEVEL"             : ("log level", SambaParmString, P_GLOBAL, "0"),
	"PRINTCAPCACHETIME"      : ("printcap cache time", SambaParmString, P_GLOBAL, "0"),
	"SOCKETADDRESS"          : ("socket address", SambaParmString, P_GLOBAL, "0.0.0.0"),
	"FORCEDIRECTORYMODE"     : ("force directory mode", SambaParmString, P_LOCAL, "00"),
	"MSDFSROOT"              : ("msdfs root", SambaParmBool, P_LOCAL, "No"),
	"ROOTPREEXEC"            : ("root preexec", SambaParmString, P_LOCAL, ""),
	"WRITEOK"                : ("read only", SambaParmBoolRev, P_LOCAL, "Yes"),
	"MAXLOGSIZE"             : ("max log size", SambaParmString, P_GLOBAL, "5000"),
	"FORCESECURITYMODE"      : ("force security mode", SambaParmString, P_LOCAL, "00"),
	"VFSOBJECT"              : ("vfs objects", SambaParmString, P_LOCAL, ""),
	"CHECKPASSWORDSCRIPT"    : ("check password script", SambaParmString, P_GLOBAL, ""),
	"DELETEPRINTERCOMMAND"   : ("deleteprinter command", SambaParmString, P_GLOBAL, ""),
	"OSLEVEL"                : ("os level", SambaParmString, P_GLOBAL, "20"),
	"ENUMPORTSCOMMAND"       : ("enumports command", SambaParmString, P_GLOBAL, ""),
	"DELETEUSERFROMGROUPSCRIPT": ("delete user from group script", SambaParmString, P_GLOBAL, ""),
	"IDMAPGID"               : ("idmap gid", SambaParmString, P_GLOBAL, ""),
	"PREEXECCLOSE"           : ("preexec close", SambaParmBool, P_LOCAL, "No"),
	"UTMPDIRECTORY"          : ("utmp directory", SambaParmString, P_GLOBAL, ""),
	"DOSFILEMODE"            : ("dos filemode", SambaParmBool, P_LOCAL, "No"),
	"LOGFILE"                : ("log file", SambaParmString, P_GLOBAL, ""),
	"WORKGROUP"              : ("workgroup", SambaParmString, P_GLOBAL, "WORKGROUP"),
	"DIRECTORYSECURITYMASK"  : ("directory security mask", SambaParmString, P_LOCAL, "0777"),
	"ENCRYPTPASSWORDS"       : ("encrypt passwords", SambaParmBool, P_GLOBAL, "Yes"),
	"PRINTABLE"              : ("printable", SambaParmBool, P_LOCAL, "No"),
	"MAXPROTOCOL"            : ("max protocol", SambaParmString, P_GLOBAL, "NT1"),
	"KERNELOPLOCKS"          : ("kernel oplocks", SambaParmBool, P_GLOBAL, "Yes"),
	"NETBIOSALIASES"         : ("netbios aliases", SambaParmString, P_GLOBAL, ""),
	"ANNOUNCEAS"             : ("announce as", SambaParmString, P_GLOBAL, "NT"),
	"DIRECTORYMASK"          : ("directory mask", SambaParmString, P_LOCAL, "0755"),
	"MAPSYSTEM"              : ("map system", SambaParmBool, P_LOCAL, "No"),
	"CHANGENOTIFYTIMEOUT"    : ("change notify timeout", SambaParmString, P_GLOBAL, "60"),
	"WINBINDTRUSTEDDOMAINSONLY": ("winbind trusted domains only", SambaParmBool, P_GLOBAL, "No"),
	"SHUTDOWNSCRIPT"         : ("shutdown script", SambaParmString, P_GLOBAL, ""),
	"FOLLOWSYMLINKS"         : ("follow symlinks", SambaParmBool, P_LOCAL, "Yes"),
	"MAPHIDDEN"              : ("map hidden", SambaParmBool, P_LOCAL, "No"),
	"GROUP"                  : ("force group", SambaParmString, P_LOCAL, ""),
	"DENYHOSTS"              : ("hosts deny", SambaParmString, P_LOCAL, ""),
	"WINBINDCACHETIME"       : ("winbind cache time", SambaParmString, P_GLOBAL, "300"),
	"DELETEVETOFILES"        : ("delete veto files", SambaParmBool, P_LOCAL, "No"),
	"DISABLESPOOLSS"         : ("disable spoolss", SambaParmBool, P_GLOBAL, "No"),
	"MAXCONNECTIONS"         : ("max connections", SambaParmString, P_LOCAL, "0"),
	"WRITERAW"               : ("write raw", SambaParmBool, P_GLOBAL, "Yes"),
	"SERVERSIGNING"          : ("server signing", SambaParmString, P_GLOBAL, "No"),
	"VOLUME"                 : ("volume", SambaParmString, P_LOCAL, ""),
	"UNIXPASSWORDSYNC"       : ("unix password sync", SambaParmBool, P_GLOBAL, "No"),
	"OBEYPAMRESTRICTIONS"    : ("obey pam restrictions", SambaParmBool, P_GLOBAL, "No"),
	"PASSWDCHATTIMEOUT"      : ("passwd chat timeout", SambaParmString, P_GLOBAL, "2"),
	"USER"                   : ("username", SambaParmString, P_LOCAL, ""),
	"HIDEDOTFILES"           : ("hide dot files", SambaParmBool, P_LOCAL, "Yes"),
	"ROOTPOSTEXEC"           : ("root postexec", SambaParmString, P_LOCAL, ""),
	"PROTOCOL"               : ("max protocol", SambaParmString, P_GLOBAL, "NT1"),
	"LDAPADMINDN"            : ("ldap admin dn", SambaParmString, P_GLOBAL, ""),
	"DNSPROXY"               : ("dns proxy", SambaParmBool, P_GLOBAL, "Yes"),
	"OS2DRIVERMAP"           : ("os2 driver map", SambaParmString, P_GLOBAL, ""),
	"QUEUERESUMECOMMAND"     : ("queueresume command", SambaParmString, P_LOCAL, ""),
	"SERVERSCHANNEL"         : ("server schannel", SambaParmString, P_GLOBAL, "Auto"),
	"IDMAPUID"               : ("idmap uid", SambaParmString, P_GLOBAL, ""),
	"WINBINDENABLELOCALACCOUNTS": ("winbind enable local accounts", SambaParmBool, P_GLOBAL, "No"),
	"PRINTERNAME"            : ("printer name", SambaParmString, P_LOCAL, ""),
	"NTACLSUPPORT"           : ("nt acl support", SambaParmBool, P_LOCAL, "Yes"),
	"LOGLEVEL"               : ("log level", SambaParmString, P_GLOBAL, "0"),
	"STATCACHE"              : ("stat cache", SambaParmBool, P_GLOBAL, "Yes"),
	"LPQCACHETIME"           : ("lpq cache time", SambaParmString, P_GLOBAL, "30"),
	"LEVEL2OPLOCKS"          : ("level2 oplocks", SambaParmBool, P_LOCAL, "Yes"),
	"LARGEREADWRITE"         : ("large readwrite", SambaParmBool, P_GLOBAL, "Yes"),
	"LDAPREPLICATIONSLEEP"   : ("ldap replication sleep", SambaParmString, P_GLOBAL, "1000"),
	"SECURITYMASK"           : ("security mask", SambaParmString, P_LOCAL, "0777"),
	"LDAPUSERSUFFIX"         : ("ldap user suffix", SambaParmString, P_GLOBAL, ""),
	"NETBIOSNAME"            : ("netbios name", SambaParmString, P_GLOBAL, "PANTHER"),
	"LOCKSPINCOUNT"          : ("lock spin count", SambaParmString, P_GLOBAL, "3"),
	"OPLOCKS"                : ("oplocks", SambaParmBool, P_LOCAL, "Yes"),
	"MINWINSTTL"             : ("min wins ttl", SambaParmString, P_GLOBAL, "21600"),
	"HOMEDIRMAP"             : ("homedir map", SambaParmString, P_GLOBAL, ""),
	"REMOTEANNOUNCE"         : ("remote announce", SambaParmString, P_GLOBAL, ""),
	"PREFERREDMASTER"        : ("preferred master", SambaParmString, P_GLOBAL, "Auto"),
	"SECURITY"               : ("security", SambaParmString, P_GLOBAL, "USER"),
	"AUTHMETHODS"            : ("auth methods", SambaParmString, P_GLOBAL, ""),
	"ENABLERIDALGORITHM"     : ("enable rid algorithm", SambaParmBool, P_GLOBAL, "Yes"),
	"LPRMCOMMAND"            : ("lprm command", SambaParmString, P_LOCAL, ""),
	"KERNELCHANGENOTIFY"     : ("kernel change notify", SambaParmBool, P_GLOBAL, "Yes"),
	"LOGONSCRIPT"            : ("logon script", SambaParmString, P_GLOBAL, ""),
	"PRESERVECASE"           : ("preserve case", SambaParmBool, P_LOCAL, "Yes"),
	"UNIXCHARSET"            : ("unix charset", SambaParmString, P_GLOBAL, "UTF-8"),
	"FORCEPRINTERNAME"       : ("force printername", SambaParmBool, P_LOCAL, "No"),
	"LDAPFILTER"             : ("ldap filter", SambaParmString, P_GLOBAL, "(uid"),
	"DELETEREADONLY"         : ("delete readonly", SambaParmBool, P_LOCAL, "No"),
	"ABORTSHUTDOWNSCRIPT"    : ("abort shutdown script", SambaParmString, P_GLOBAL, ""),
	"DFREECOMMAND"           : ("dfree command", SambaParmString, P_GLOBAL, ""),
	"VETOFILES"              : ("veto files", SambaParmString, P_LOCAL, ""),
	"LOCKING"                : ("locking", SambaParmBool, P_LOCAL, "Yes"),
	"EASUPPORT"              : ("ea support", SambaParmBool, P_LOCAL, "No"),
	"MAXSMBDPROCESSES"       : ("max smbd processes", SambaParmString, P_GLOBAL, "0"),
	"HIDEFILES"              : ("hide files", SambaParmString, P_LOCAL, ""),
	"PASSWDCHATDEBUG"        : ("passwd chat debug", SambaParmBool, P_GLOBAL, "No"),
	"SMBPASSWDFILE"          : ("smb passwd file", SambaParmString, P_GLOBAL, "/etc/samba/private/smbpasswd"),
	"GETQUOTACOMMAND"        : ("get quota command", SambaParmString, P_GLOBAL, ""),
	"OPLOCKCONTENTIONLIMIT"  : ("oplock contention limit", SambaParmString, P_LOCAL, "2"),
	"DOMAINMASTER"           : ("domain master", SambaParmString, P_GLOBAL, "Auto"),
	"DELETESHARECOMMAND"     : ("delete share command", SambaParmString, P_GLOBAL, ""),
	"INVALIDUSERS"           : ("invalid users", SambaParmString, P_LOCAL, ""),
	"POSIXLOCKING"           : ("posix locking", SambaParmBool, P_LOCAL, "Yes"),
	"INCLUDE"                : ("include", SambaParmString, P_LOCAL, ""),
	"ALGORITHMICRIDBASE"     : ("algorithmic rid base", SambaParmString, P_GLOBAL, "1000"),
	"FORCEDIRECTORYSECURITYMODE": ("force directory security mode", SambaParmString, P_LOCAL, "00"),
	"ANNOUNCEVERSION"        : ("announce version", SambaParmString, P_GLOBAL, "4.9"),
	"USERNAMEMAP"            : ("username map", SambaParmString, P_GLOBAL, ""),
	"MANGLEDNAMES"           : ("mangled names", SambaParmBool, P_LOCAL, "Yes"),
	"ROOTDIRECTORY"          : ("root directory", SambaParmString, P_GLOBAL, ""),
	"DEBUGHIRESTIMESTAMP"    : ("debug hires timestamp", SambaParmBool, P_GLOBAL, "No"),
	"LOGONDRIVE"             : ("logon drive", SambaParmString, P_GLOBAL, ""),
	"LOCALMASTER"            : ("local master", SambaParmBool, P_GLOBAL, "Yes"),
	"ROOTPREEXECCLOSE"       : ("root preexec close", SambaParmBool, P_LOCAL, "No"),
	"CONFIGFILE"             : ("config file", SambaParmString, P_GLOBAL, ""),
	"USECLIENTDRIVER"        : ("use client driver", SambaParmBool, P_LOCAL, "No"),
	"MINPROTOCOL"            : ("min protocol", SambaParmString, P_GLOBAL, "CORE"),
	"ADDUSERTOGROUPSCRIPT"   : ("add user to group script", SambaParmString, P_GLOBAL, ""),
	"MAPACLINHERIT"          : ("map acl inherit", SambaParmBool, P_LOCAL, "No"),
	"DELETEUSERSCRIPT"       : ("delete user script", SambaParmString, P_GLOBAL, ""),
	"WINBINDUID"             : ("idmap uid", SambaParmString, P_GLOBAL, ""),
	"READRAW"                : ("read raw", SambaParmBool, P_GLOBAL, "Yes"),
	"WINBINDENUMGROUPS"      : ("winbind enum groups", SambaParmBool, P_GLOBAL, "Yes"),
	"PASSWORDLEVEL"          : ("password level", SambaParmString, P_GLOBAL, "0"),
	"MAXPRINTJOBS"           : ("max print jobs", SambaParmString, P_LOCAL, "1000"),
	"PRINTCAP"               : ("printcap name", SambaParmString, P_GLOBAL, ""),
	"LOADPRINTERS"           : ("load printers", SambaParmBool, P_GLOBAL, "Yes"),
	"DEFAULT"                : ("default service", SambaParmString, P_GLOBAL, ""),
	"GUESTACCOUNT"           : ("guest account", SambaParmString, P_GLOBAL, "nobody"),
	"AUTOSERVICES"           : ("preload", SambaParmString, P_GLOBAL, ""),
	"WRITEABLE"              : ("read only", SambaParmBoolRev, P_LOCAL, "Yes"),
	"CLIENTLANMANAUTH"       : ("client lanman auth", SambaParmBool, P_GLOBAL, "Yes"),
	"MESSAGECOMMAND"         : ("message command", SambaParmString, P_GLOBAL, ""),
	"UNIXEXTENSIONS"         : ("unix extensions", SambaParmBool, P_GLOBAL, "Yes"),
	"LDAPPASSWORDSYNC"       : ("ldap passwd sync", SambaParmString, P_GLOBAL, "no"),
	"AFSUSERNAMEMAP"         : ("afs username map", SambaParmString, P_GLOBAL, ""),
	"SYSLOG"                 : ("syslog", SambaParmString, P_GLOBAL, "1"),
	"SETPRIMARYGROUPSCRIPT"  : ("set primary group script", SambaParmString, P_GLOBAL, ""),
	"DEADTIME"               : ("deadtime", SambaParmString, P_GLOBAL, "0"),
	"RESTRICTANONYMOUS"      : ("restrict anonymous", SambaParmString, P_GLOBAL, "0"),
	"USERNAMELEVEL"          : ("username level", SambaParmString, P_GLOBAL, "0"),
	"DISPLAYCHARSET"         : ("display charset", SambaParmString, P_GLOBAL, "LOCALE"),
	"FORCEUSER"              : ("force user", SambaParmString, P_LOCAL, ""),
	"HOSTSDENY"              : ("hosts deny", SambaParmString, P_LOCAL, ""),
	"HIDEUNWRITEABLEFILES"   : ("hide unwriteable files", SambaParmBool, P_LOCAL, "No"),
	"DOSCHARSET"             : ("dos charset", SambaParmString, P_GLOBAL, "CP850"),
	"DOSFILETIMES"           : ("dos filetimes", SambaParmBool, P_LOCAL, "No"),
	"REALM"                  : ("realm", SambaParmString, P_GLOBAL, ""),
	"LDAPSUFFIX"             : ("ldap suffix", SambaParmString, P_GLOBAL, ""),
	"LPPAUSECOMMAND"         : ("lppause command", SambaParmString, P_LOCAL, ""),
	"FAKEDIRECTORYCREATETIMES": ("fake directory create times", SambaParmBool, P_LOCAL, "No"),
	"MAGICSCRIPT"            : ("magic script", SambaParmString, P_LOCAL, ""),
	"WRITECACHESIZE"         : ("write cache size", SambaParmString, P_LOCAL, "0"),
	"BLOCKSIZE"              : ("block size", SambaParmString, P_LOCAL, "1024"),
	"LOCKSPINTIME"           : ("lock spin time", SambaParmString, P_GLOBAL, "10"),
	"ACLCOMPATIBILITY"       : ("acl compatibility", SambaParmString, P_GLOBAL, ""),
	"MSDFSPROXY"             : ("msdfs proxy", SambaParmString, P_LOCAL, ""),
	"POSTEXEC"               : ("postexec", SambaParmString, P_LOCAL, ""),
	"HIDEUNREADABLE"         : ("hide unreadable", SambaParmBool, P_LOCAL, "No"),
	"WIDELINKS"              : ("wide links", SambaParmBool, P_LOCAL, "Yes"),
	"STRICTSYNC"             : ("strict sync", SambaParmBool, P_LOCAL, "No"),
	"PRINTCAPNAME"           : ("printcap name", SambaParmString, P_GLOBAL, ""),
	"PREFEREDMASTER"         : ("preferred master", SambaParmString, P_GLOBAL, "Auto"),
	"MAXMUX"                 : ("max mux", SambaParmString, P_GLOBAL, "50"),
	"VETOOPLOCKFILES"        : ("veto oplock files", SambaParmString, P_LOCAL, ""),
	"WINBINDSEPARATOR"       : ("winbind separator", SambaParmString, P_GLOBAL, "\\"),
	"NISHOMEDIR"             : ("NIS homedir", SambaParmBool, P_GLOBAL, "No"),
	"AVAILABLE"              : ("available", SambaParmBool, P_LOCAL, "Yes"),
	"KEEPALIVE"              : ("keepalive", SambaParmString, P_GLOBAL, "300"),
	"USERNAME"               : ("username", SambaParmString, P_LOCAL, ""),
	"PRINTCOMMAND"           : ("print command", SambaParmString, P_LOCAL, ""),
	"LPRESUMECOMMAND"        : ("lpresume command", SambaParmString, P_LOCAL, ""),
	"USEKERBEROSKEYTAB"      : ("use kerberos keytab", SambaParmBool, P_GLOBAL, "No"),
	"HOSTSALLOW"             : ("hosts allow", SambaParmString, P_LOCAL, ""),
	"MAXOPENFILES"           : ("max open files", SambaParmString, P_GLOBAL, "10000"),
	"PARANOIDSERVERSECURITY" : ("paranoid server security", SambaParmBool, P_GLOBAL, "Yes"),
	"WTMPDIRECTORY"          : ("wtmp directory", SambaParmString, P_GLOBAL, ""),
	"ADDPRINTERCOMMAND"      : ("addprinter command", SambaParmString, P_GLOBAL, ""),
	"PRINTERADMIN"           : ("printer admin", SambaParmString, P_LOCAL, ""),
	"WINSSERVER"             : ("wins server", SambaParmString, P_GLOBAL, ""),
	"LDAPTIMEOUT"            : ("ldap timeout", SambaParmString, P_GLOBAL, "15"),
	"LOCKDIRECTORY"          : ("lock directory", SambaParmString, P_GLOBAL, "/var/lib/samba"),
	"LOGONHOME"              : ("logon home", SambaParmString, P_GLOBAL, "\\%N\%U"),
	"MINPASSWDLENGTH"        : ("min password length", SambaParmString, P_GLOBAL, "5"),
	"CLIENTPLAINTEXTAUTH"    : ("client plaintext auth", SambaParmBool, P_GLOBAL, "Yes"),
	"CSCPOLICY"              : ("csc policy", SambaParmString, P_LOCAL, "manual"),
	"ADDSHARECOMMAND"        : ("add share command", SambaParmString, P_GLOBAL, ""),
	"MANGLINGCHAR"           : ("mangling char", SambaParmString, P_LOCAL, "~"),
	"DIRECTORY"              : ("path", SambaParmString, P_LOCAL, ""),
	"DEBUGTIMESTAMP"         : ("debug timestamp", SambaParmBool, P_GLOBAL, "Yes"),
	"ALLOWHOSTS"             : ("hosts allow", SambaParmString, P_LOCAL, ""),
	"FSTYPE"                 : ("fstype", SambaParmString, P_LOCAL, "NTFS"),
	"BLOCKINGLOCKS"          : ("blocking locks", SambaParmBool, P_LOCAL, "Yes"),
	"LDAPSSL"                : ("ldap ssl", SambaParmString, P_GLOBAL, ""),
	"PAMPASSWORDCHANGE"      : ("pam password change", SambaParmBool, P_GLOBAL, "No"),
	"GUESTOK"                : ("guest ok", SambaParmBool, P_LOCAL, "No"),
	"DEFAULTDEVMODE"         : ("default devmode", SambaParmBool, P_LOCAL, "No"),
	"MAXDISKSIZE"            : ("max disk size", SambaParmString, P_GLOBAL, "0"),
	"ADDMACHINESCRIPT"       : ("add machine script", SambaParmString, P_GLOBAL, ""),
	"MANGLEPREFIX"           : ("mangle prefix", SambaParmString, P_GLOBAL, "1"),
	"DISABLENETBIOS"         : ("disable netbios", SambaParmBool, P_GLOBAL, "No"),
	"LOGONPATH"              : ("logon path", SambaParmString, P_GLOBAL, "\\%N\%U\profile"),
	"IDMAPBACKEND"           : ("idmap backend", SambaParmString, P_GLOBAL, ""),
	"SHORTPRESERVECASE"      : ("short preserve case", SambaParmBool, P_LOCAL, "Yes"),
	"CUPSSERVER"             : ("cups server", SambaParmString, P_GLOBAL, ""),
	"NTPIPESUPPORT"          : ("nt pipe support", SambaParmBool, P_GLOBAL, "Yes"),
	"READONLY"               : ("read only", SambaParmBool, P_LOCAL, "Yes"),
	"MACHINEPASSWORDTIMEOUT" : ("machine password timeout", SambaParmString, P_GLOBAL, "604800"),
	"PIDDIRECTORY"           : ("pid directory", SambaParmString, P_GLOBAL, "/var/run"),
	"PUBLIC"                 : ("guest ok", SambaParmBool, P_LOCAL, "No"),
	"DEBUGPID"               : ("debug pid", SambaParmBool, P_GLOBAL, "No"),
	"GUESTONLY"              : ("guest only", SambaParmBool, P_LOCAL, "No"),
	"DELETEGROUPSCRIPT"      : ("delete group script", SambaParmString, P_GLOBAL, ""),
	"CUPSOPTIONS"            : ("cups options", SambaParmString, P_LOCAL, ""),
	"PASSWDCHAT"             : ("passwd chat", SambaParmString, P_GLOBAL, "*new*password* %n\n *new*password* %n\n *changed*"),
	"STRICTLOCKING"          : ("strict locking", SambaParmString, P_LOCAL, "Yes"),
	"TEMPLATEHOMEDIR"        : ("template homedir", SambaParmString, P_GLOBAL, "/home/%D/%U"),
	"WINBINDGID"             : ("idmap gid", SambaParmString, P_GLOBAL, ""),
	"INHERITPERMISSIONS"     : ("inherit permissions", SambaParmBool, P_LOCAL, "No"),
	"TIMESERVER"             : ("time server", SambaParmBool, P_GLOBAL, "No"),
	"BROWSELIST"             : ("browse list", SambaParmBool, P_GLOBAL, "Yes"),
	"HOSTNAMELOOKUPS"        : ("hostname lookups", SambaParmBool, P_GLOBAL, "No"),
	"DOSFILETIMERESOLUTION"  : ("dos filetime resolution", SambaParmBool, P_LOCAL, "No"),
	"CREATEMASK"             : ("create mask", SambaParmString, P_LOCAL, "0744"),
	"WINSHOOK"               : ("wins hook", SambaParmString, P_GLOBAL, ""),
	"DEFAULTCASE"            : ("default case", SambaParmString, P_LOCAL, "lower"),
	"PATH"                   : ("path", SambaParmString, P_LOCAL, ""),
	"SHOWADDPRINTERWIZARD"   : ("show add printer wizard", SambaParmBool, P_GLOBAL, "Yes"),
	"WINSPARTNERS"           : ("wins partners", SambaParmString, P_GLOBAL, ""),
	"ENABLEPRIVILEGES"       : ("enable privileges", SambaParmBool, P_GLOBAL, "No"),
	"VFSOBJECTS"             : ("vfs objects", SambaParmString, P_LOCAL, ""),
	"STRICTALLOCATE"         : ("strict allocate", SambaParmBool, P_LOCAL, "No"),
	"PREEXEC"                : ("preexec", SambaParmString, P_LOCAL, ""),
	"WINSSUPPORT"            : ("wins support", SambaParmBool, P_GLOBAL, "No"),
	"HOSTMSDFS"              : ("host msdfs", SambaParmBool, P_GLOBAL, "No"),
	"AFSTOKENLIFETIME"       : ("afs token lifetime", SambaParmString, P_GLOBAL, "604800"),
	"PRINTOK"                : ("printable", SambaParmBool, P_LOCAL, "No"),
	"TEMPLATEPRIMARYGROUP"   : ("template primary group", SambaParmString, P_GLOBAL, "nobody"),
	"PASSWDPROGRAM"          : ("passwd program", SambaParmString, P_GLOBAL, ""),
	"SYNCALWAYS"             : ("sync always", SambaParmBool, P_LOCAL, "No"),
	"QUEUEPAUSECOMMAND"      : ("queuepause command", SambaParmString, P_LOCAL, ""),
	"BINDINTERFACESONLY"     : ("bind interfaces only", SambaParmBool, P_GLOBAL, "No"),
	"MAXWINSTTL"             : ("max wins ttl", SambaParmString, P_GLOBAL, "518400"),
	"GETWDCACHE"             : ("getwd cache", SambaParmBool, P_GLOBAL, "Yes"),
	"MAGICOUTPUT"            : ("magic output", SambaParmString, P_LOCAL, ""),
	"ADMINUSERS"             : ("admin users", SambaParmString, P_LOCAL, ""),
	"DIRECTORYMODE"          : ("directory mask", SambaParmString, P_LOCAL, "0755"),
	"CLIENTSIGNING"          : ("client signing", SambaParmString, P_GLOBAL, "auto"),
	"PASSDBBACKEND"          : ("passdb backend", SambaParmString, P_GLOBAL, "smbpasswd"),
	"CASESIGNAMES"           : ("case sensitive", SambaParmString, P_LOCAL, "Auto"),
	"SETQUOTACOMMAND"        : ("set quota command", SambaParmString, P_GLOBAL, ""),
	"LPQCOMMAND"             : ("lpq command", SambaParmString, P_LOCAL, ""),
	"SERVERSTRING"           : ("server string", SambaParmString, P_GLOBAL, "Samba 3.0.11pre2-SVN-build-4840"),
	"DEFAULTSERVICE"         : ("default service", SambaParmString, P_GLOBAL, ""),
	"WINBINDUSEDEFAULTDOMAIN": ("winbind use default domain", SambaParmBool, P_GLOBAL, "No"),
	"INTERFACES"             : ("interfaces", SambaParmString, P_GLOBAL, ""),
	"ROOTDIR"                : ("root directory", SambaParmString, P_GLOBAL, ""),
	"ADDUSERSCRIPT"          : ("add user script", SambaParmString, P_GLOBAL, ""),
	"CLIENTNTLMV2AUTH"       : ("client NTLMv2 auth", SambaParmBool, P_GLOBAL, "No"),
	"FORCEUNKNOWNACLUSER"    : ("force unknown acl user", SambaParmBool, P_LOCAL, "No"),
	"MANGLEDMAP"             : ("mangled map", SambaParmString, P_LOCAL, ""),
	"NTLMAUTH"               : ("ntlm auth", SambaParmBool, P_GLOBAL, "Yes"),
	"INHERITACLS"            : ("inherit acls", SambaParmBool, P_LOCAL, "No"),
	"HOSTSEQUIV"             : ("hosts equiv", SambaParmString, P_GLOBAL, ""),
	"ALLOWTRUSTEDDOMAINS"    : ("allow trusted domains", SambaParmBool, P_GLOBAL, "Yes"),
	"MINPASSWORDLENGTH"      : ("min password length", SambaParmString, P_GLOBAL, "5"),
	"USERS"                  : ("username", SambaParmString, P_LOCAL, ""),
	"PRELOAD"                : ("preload", SambaParmString, P_GLOBAL, ""),
	"DEBUGUID"               : ("debug uid", SambaParmBool, P_GLOBAL, "No"),
	"CHANGESHARECOMMAND"     : ("change share command", SambaParmString, P_GLOBAL, ""),
	"BROWSABLE"              : ("browseable", SambaParmBool, P_LOCAL, "Yes"),
	"ENHANCEDBROWSING"       : ("enhanced browsing", SambaParmBool, P_GLOBAL, "Yes"),
	"PANICACTION"            : ("panic action", SambaParmString, P_GLOBAL, ""),
	"LDAPMACHINESUFFIX"      : ("ldap machine suffix", SambaParmString, P_GLOBAL, ""),
	"UPDATEENCRYPTED"        : ("update encrypted", SambaParmBool, P_GLOBAL, "No"),
	"MAXTTL"                 : ("max ttl", SambaParmString, P_GLOBAL, "259200"),
	"WRITABLE"               : ("read only", SambaParmBoolRev, P_LOCAL, "Yes"),
	"SHAREMODES"             : ("share modes", SambaParmBool, P_LOCAL, "Yes"),
	"REMOTEBROWSESYNC"       : ("remote browse sync", SambaParmString, P_GLOBAL, ""),
	"STOREDOSATTRIBUTES"     : ("store dos attributes", SambaParmBool, P_LOCAL, "No"),
	"CLIENTSCHANNEL"         : ("client schannel", SambaParmString, P_GLOBAL, "Auto"),
	"WRITELIST"              : ("write list", SambaParmString, P_LOCAL, ""),
	"ADDGROUPSCRIPT"         : ("add group script", SambaParmString, P_GLOBAL, ""),
	"OPLOCKBREAKWAITTIME"    : ("oplock break wait time", SambaParmString, P_GLOBAL, "0"),
	"TIMEOFFSET"             : ("time offset", SambaParmString, P_GLOBAL, "0"),
	"LDAPDELETEDN"           : ("ldap delete dn", SambaParmBool, P_GLOBAL, "No"),
	"AFSSHARE"               : ("afs share", SambaParmBool, P_LOCAL, "No"),
	"ROOT"                   : ("root directory", SambaParmString, P_GLOBAL, ""),
	"NAMERESOLVEORDER"       : ("name resolve order", SambaParmString, P_GLOBAL, "lmhosts wins host bcast"),
}
##### end of smbparm.y ##########################################
#################################################################
