/******************************************************************************
 *  CVS version:
 *     $Id: error.c,v 1.2 2004/05/05 22:00:08 nickie Exp $
 ******************************************************************************
 *
 *  C code file : error.c
 *  Project     : PCL Compiler
 *  Version     : 1.0 alpha
 *  Written by  : Nikolaos S. Papaspyrou (nickie@softlab.ntua.gr)
 *  Date        : May 14, 2003
 *  Description : Generic symbol table in C, simple error handler
 *
 *  Comments: (in Greek iso-8859-7)
 *  ---------
 *  Åèíéêü Ìåôóüâéï Ðïëõôå÷íåßï.
 *  Ó÷ïëÞ Çëåêôñïëüãùí Ìç÷áíéêþí êáé Ìç÷áíéêþí Õðïëïãéóôþí.
 *  ÔïìÝáò Ôå÷íïëïãßáò ÐëçñïöïñéêÞò êáé Õðïëïãéóôþí.
 *  ÅñãáóôÞñéï Ôå÷íïëïãßáò Ëïãéóìéêïý
 */


/* ---------------------------------------------------------------------
   ---------------------------- Header files ---------------------------
   --------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "general.hpp"
#include "error.hpp"

/* ---------------------------------------------------------------------
   --------- Õëïðïßçóç ôùí óõíáñôÞóåùí ôïõ ÷åéñéóôÞ óöáëìÜôùí ----------
   --------------------------------------------------------------------- */

void internal (const char * fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	if (fmt[0] == '\r')
		fmt++;
	else
		fprintf(stderr, "%s:%d: ", filename, linecount);
	fprintf(stderr, "\033[1;31minternal:\033[0m ");
	vfprintf(stderr, fmt, ap);
	fprintf(stderr, "\n");
	va_end(ap);
	exit(1);
}

void fatal (const char * fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	if (fmt[0] == '\r')
		fmt++;
	else
		fprintf(stderr, "%s:%d: ", filename, linecount);
	fprintf(stderr, "\033[1;31mfatal:\033[0m ");
	vfprintf(stderr, fmt, ap);
	fprintf(stderr, "\n");
	va_end(ap);
	exit(1);
}

void error (const char * fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	if (fmt[0] == '\r')
		fmt++;
	else
		//fprintf(stderr, "%s:%d: ", filename, linecount);
		fprintf(stderr, "\033[1;31merror:\033[0m ");
	vfprintf(stderr, fmt, ap);
	fprintf(stderr, "\n");
	va_end(ap);
	fprintf(stderr, "The alan compiler is lazy and aborts...\n");
	exit(1);
}

void warning (const char * fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	if (fmt[0] == '\r')
		fmt++;
	else
		fprintf(stderr, "%s:%d: ", filename, linecount);
	fprintf(stderr, "\033[1;33mwarning:\033[0m ");
	vfprintf(stderr, fmt, ap);
	fprintf(stderr, "\n");
	va_end(ap);
}
