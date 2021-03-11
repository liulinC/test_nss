#include "hcp_nss.h"
#include "winbind_nss_linux.h"
#include <nss.h>
#include <pwd.h>

/*
struct passwd rootpw_static = {
	.pw_name = "root",
	.pw_passwd = "x",
	.pw_gecos = "root",
	.pw_dir = "/root",
	.pw_shell = "/bin/bash",
	.pw_uid = 0,
	.pw_gid = 0,
};     
*/
/*
 * NSS user functions
 */

/* Fetch the next password entry from ntdom password database */
/*
nss_status
_nss_hcp_getpwent_r(struct passwd *result, char *buffer,
			size_t buflen, int *errnop)
{
}
*/
/* Return passwd struct from uid */
/*
nss_status
_nss_hcp_getpwuid_r(uid_t uid, struct passwd *result, char *buffer,
			size_t buflen, int *errnop)
{
}
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
