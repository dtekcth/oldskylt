// tdunwrite.cc. Test for -*- C++ -*- socket library
// Copyright (C) 1992,1993,1994 Gnanasekaran Swaminathan <gs4t@virginia.edu>
// 
// Permission is granted to use at your own risk and distribute this software
// in source and binary forms provided the above copyright
// notice and this paragraph are preserved on all copies.
// This software is provided "as is" with no express or implied warranty.
//
// Version: 17Oct95 1.10

#include <sockunix.h>

int main(int ac, char** av)
{
	if (ac < 2) {
		cerr << "USAGE: " << av[0] << " socket_path_name data...\n";
		return 1;
	}

	osockunix	su (sockbuf::sock_dgram);

	su->connect (av[1]);

	su << ac << ' ';
	while (*av) { su << *av << ' '; av++; }
	su << endl;

	return 0;
}

