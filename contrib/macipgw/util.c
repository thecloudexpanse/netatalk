/*
 * Utitlity functions
 *
 * (c) 1997 Stefan Bethke. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <sys/types.h>

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int gDebug;


char *iptoa(uint32_t ip)
{
    static char s[16];
    sprintf(s, "%u.%u.%u.%u",
            (ip >> 24) & 0xff, (ip >> 16) & 0xff,
            (ip >> 8) & 0xff, ip & 0xff);
    return s;
}


uint32_t atoip(char *s)
{
    uint32_t ip;
    ip = (uint32_t) strtol(s, &s, 0);

    if (*s++ != '.') {
        return 0;
    }

    ip = (ip << 8) | (uint32_t) strtol(s, &s, 0);

    if (*s++ != '.') {
        return 0;
    }

    ip = (ip << 8) | (uint32_t) strtol(s, &s, 0);

    if (*s++ != '.') {
        return 0;
    }

    ip = (ip << 8) | (uint32_t) strtol(s, &s, 0);

    if (*s != 0) {
        return 0;
    }

    return ip;
}
