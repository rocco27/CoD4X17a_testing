#include <string.h>
#include "cmd.h"
#include "cvar.h"

/*
========================================================================

Command line parsing

========================================================================
*/



#define		MAX_CONSOLE_LINES	32
int		com_numConsoleLines;
char		*com_consoleLines[MAX_CONSOLE_LINES];


/*
===============
Com_StartupVariable

Searches for command line parameters that are set commands.
If match is not NULL, only that cvar will be looked for.
That is necessary because cddir and basedir need to be set
before the filesystem is started, but all other sets should
be after execing the config and default.
===============
*/
void Com_StartupVariable( const char *match ) {
	int		i;
	for (i=0 ; i < com_numConsoleLines ; i++) {
		Cmd_TokenizeString( com_consoleLines[i] );

		if(!match || !strcmp(Cmd_Argv(1), match))
		{
			if ( !strcmp( Cmd_Argv(0), "set" )){
				Cvar_Set_f();
				Cmd_EndTokenizeString();
				continue;
			}else if( !strcmp( Cmd_Argv(0), "seta" ) ) {
				Cvar_SetA_f();
			}
		}
		Cmd_EndTokenizeString();
	}
}

/*
=================
Com_AddStartupCommands

Adds command line parameters as script statements
Commands are seperated by + signs

Returns qtrue if any late commands were added, which
will keep the demoloop from immediately starting
=================
*/
qboolean Com_AddStartupCommands( void ) {
	int		i;
	qboolean	added;
	char		buf[1024];
	added = qfalse;
	// quote every token, so args with semicolons can work
	for (i=0 ; i < com_numConsoleLines ; i++) {
		if ( !com_consoleLines[i] || !com_consoleLines[i][0] ) {
			continue;
		}

		// set commands already added with Com_StartupVariable
		if ( !Q_stricmpn( com_consoleLines[i], "set", 3 )) {
			continue;
		}

		added = qtrue;
		Com_sprintf(buf,sizeof(buf),"%s\n",com_consoleLines[i]);
		Cbuf_ExecuteBuffer( 0,0, buf);
	}

	return added;
}

/*
==================
Com_ParseCommandLine

Break it up into multiple console lines
==================
*/
void Com_ParseCommandLine( char *commandLine ) {
    int inq = 0;
    com_consoleLines[0] = commandLine;
    com_numConsoleLines = 1;

    while ( *commandLine ) {
        if (*commandLine == '"') {
            inq = !inq;
        }
        // look for a + seperating character
        // if commandLine came from a file, we might have real line seperators
        if ( (*commandLine == '+' && !inq) || *commandLine == '\n'  || *commandLine == '\r' ) {
            if ( com_numConsoleLines == MAX_CONSOLE_LINES ) {
                return;
            }
            com_consoleLines[com_numConsoleLines] = commandLine + 1;
            com_numConsoleLines = (com_numConsoleLines)+1;
            *commandLine = 0;
        }
        commandLine++;
    }
}