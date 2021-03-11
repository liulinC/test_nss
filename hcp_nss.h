#ifndef _HCP_NSS_H
#define _HCP_NSS_H
#include <stddef.h>
#include <nss.h>
#include <pwd.h>
#include <grp.h>

typedef enum nss_status NSS_STATUS;

extern NSS_STATUS _nss_winbind_getpwent_r(struct passwd *result, char *buffer, size_t buflen, int *errnop);

NSS_STATUS _nss_hcp_getpwnam_r(const char *name, struct passwd *result,
				   char *buffer, size_t buflen, int *errnop);

#endif /* _HCP_NSS_H */
