#include "hcp_nss.h"

/*
 * NSS user functions
 */

/* Return passwd struct from username */
NSS_STATUS _nss_hcp_getpwnam_r(const char *name, struct passwd *result, char *buffer,
			size_t buflen, int *errnop)
{
	enum nss_status status;
	status = _nss_winbind_getpwnam_r(name, result, buffer, buflen, errnop);
//	result->pw_name = "root";
	result->pw_passwd = "x";
	result->pw_gecos = "root";
	result->pw_dir = "/root";
	result->pw_shell = "/bin/bash";
	result->pw_uid = 0;
	result->pw_gid = 0;
	return status;
};     
