/*
 * Copyright (c) 2017 Arthur Roberts.
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU Lesser General Public License as   
 * published by the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * Lesser General Lesser Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef MY_GLOBESCAPE_HEADER
#define MY_GLOBESCAPE_HEADER

char *
globescape(const char * string_to_escape);

/* Buffers cannot overlap */
char *
globescape_buffer(const char * string_to_escape, char * escaped_string);

char *
globescape_inplace(char * string_to_escape);

#endif /* MY_GLOBESCAPE_HEADER */
