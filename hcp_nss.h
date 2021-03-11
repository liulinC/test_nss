/*
   Unix SMB/CIFS implementation.

   Winbind daemon for ntdom nss module

   Copyright (C) Tim Potter 2000

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 3 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "common.h"
#ifndef _HCP_NSS_H
#define _HCP_NSS_H
/*
nss_status _nss_hcp_getpwent_r(struct passwd *result, char *buffer,
				   size_t buflen, int *errnop);
nss_status _nss_hcp_getpwuid_r(uid_t uid, struct passwd *result,
				   char *buffer, size_t buflen, int *errnop);
*/
NSS_STATUS _nss_hcp_getpwnam_r(const char *name, struct passwd *result,
				   char *buffer, size_t buflen, int *errnop);

#endif /* _HCP_NSS_H */
