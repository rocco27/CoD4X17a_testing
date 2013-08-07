/*
===========================================================================

Return to Castle Wolfenstein multiplayer GPL Source Code
Copyright (C) 1999-2010 id Software LLC, a ZeniMax Media company. 

This file is part of the Return to Castle Wolfenstein multiplayer GPL Source Code (RTCW MP Source Code).  

RTCW MP Source Code is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

RTCW MP Source Code is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with RTCW MP Source Code.  If not, see <http://www.gnu.org/licenses/>.

In addition, the RTCW MP Source Code is also subject to certain additional terms. You should have received a copy of these additional terms immediately following the terms and conditions of the GNU General Public License which accompanied the RTCW MP Source Code.  If not, please request a copy in writing from id Software at the address below.

If you have questions concerning this license or the applicable additional terms, you may contact in writing id Software LLC, c/o ZeniMax Media Inc., Suite 120, Rockville, Maryland 20850 USA.

===========================================================================
*/

#define FS_DEMOWRITEBUF_SIZE NETCHAN_UNSENTBUFFER_SIZE


int FS_DemoWrite( const void *buffer, int len, fileHandleData_t* h );
qboolean FS_FOpenDemoFileWrite( const char *filename, fileHandleData_t* h );
qboolean FS_FCloseDemoFile( fileHandleData_t* f );
qboolean FS_DemoFileExists( const char *file );
void FS_DemoForceFlush(fileHandleData_t *fh);
int FS_DemoFlush( fileHandleData_t *fh );
/*
====================
SV_WriteDemoArchive

Addional demo data InfinityWards has added that contains players position and viewangle
The only intention i maybe that the player self can create a demo with higher FPS-rate than server provides
====================
*/

void SV_WriteDemoArchive(client_t *client){

	byte bufData[72];
	msg_t msg;

	MSG_Init(&msg, bufData, sizeof(bufData));

	int archiveIndex;
	playerState_t *ps = SV_GameClientNum(client - svs.clients);
	vec3_t nullvec = {0, 0, 0};

	MSG_WriteByte(&msg, 1);

	archiveIndex = client->demoArchiveIndex % 256;
	MSG_WriteLong(&msg, archiveIndex);
	MSG_WriteVector(&msg, ps->origin);

	MSG_WriteVector(&msg, nullvec);
	MSG_WriteLong(&msg, 0); //Velocity

	MSG_WriteLong(&msg, 0);
	MSG_WriteLong(&msg, ps->commandTime);
	MSG_WriteVector(&msg, ps->viewangles);
	client->demoArchiveIndex++;

	FS_DemoWrite( msg.data, msg.cursize, &client->demofile );
}

/*
====================
SV_WriteDemoMessageForClient

Dumps the current net message, prefixed by the length
====================
*/


void SV_WriteDemoMessageForClient( byte *data, int dataLen, client_t *client ){

	byte bufData[72];
	msg_t msg;

	MSG_Init(&msg, bufData, sizeof(bufData));

	MSG_WriteByte(&msg, 0);

	// write the packet sequence
	MSG_WriteLong(&msg, LittleLong( client->netchan.outgoingSequence ));

	// write the servermessagelength
	MSG_WriteLong(&msg, LittleLong( dataLen ));
	FS_DemoWrite( msg.data, msg.cursize, &client->demofile );

	FS_DemoWrite( data, dataLen, &client->demofile );
//	Com_DPrintf("Writing: %i bytes of demodata\n", dataLen+ msg.cursize);
}


/*
====================
SV_StopRecord

stop recording a demo
====================
*/
void SV_StopRecord( client_t *cl ) {
	int len;
	byte null;
	static char cmdline[1024];

	if ( !cl->demorecording ) {
		Com_Printf( "Not recording a demo.\n" );
		return;
	}
	// finish up

	null = 0;

	FS_DemoWrite( &null, 1, &cl->demofile );

	len = -1;

	FS_DemoWrite( &len, 4, &cl->demofile );
	FS_DemoWrite( &len, 4, &cl->demofile );

	FS_FCloseDemoFile( &cl->demofile );
	cl->demorecording = qfalse;
	Com_Printf( "Stopped demo for: %s\n", cl->name);

	if(!*sv_demoCompletedCmd->string)
		return;

	Com_sprintf(cmdline, sizeof(cmdline), "\"%s/%s\" \"%s/%s\"", fs_homepath->string, sv_demoCompletedCmd->string, fs_homepath->string, cl->demoName);

	Sys_DoStartProcess(cmdline);

	int sta;
	wait(&sta);

}

/*
==================
SV_DemoFilename
==================
*/
void SV_DemoFilename( int number, const char* basename, char *fileName ) {
	int a,b,c,d;

	if ( number < 0 || number > 9999 ) {
		Com_sprintf( fileName, MAX_OSPATH, "demo9999.tga" );
		return;
	}

	a = number / 1000;
	number -= a * 1000;
	b = number / 100;
	number -= b * 100;
	c = number / 10;
	number -= c * 10;
	d = number;

	Com_sprintf( fileName, MAX_OSPATH, "%s%i%i%i%i", basename, a, b, c, d );
}

/*
====================
SV_RecordClient

Begins recording a demo from the current position
====================
*/

void SV_RecordClient( client_t* cl, char* basename ) {
	char name[MAX_OSPATH];
	byte bufData[MAX_MSGLEN];
	msg_t msg;
	int len, compLen, swlen;
	char demoName[MAX_QPATH];

	if ( cl->demorecording ) {
		Com_Printf( "Already recording.\n" );
		return;
	}

	if ( cl->state != CS_ACTIVE ) {
		Com_Printf( "Client must be in a level to record.\n" );
		return;
	}

	int number;

	if(!basename)
	{
		basename = "demo";
	}

	// scan for a free demo name
	for ( number = 0 ; number <= 9999 ; number++ ) {
		SV_DemoFilename( number, basename, demoName );
		Com_sprintf( name, sizeof( name ), "demos/%s.dm_%d", demoName, 1 );

		if ( !FS_DemoFileExists( name ) ) {
			break;  // file doesn't exist
		}
	}

	// open the demo file
	Com_Printf( "recording to %s.\n", name );
	if(!FS_FOpenDemoFileWrite( name, &cl->demofile ))
	{
		Com_Printf( "ERROR: couldn't open.\n" );
		return;
	}

	//For fwrite debug purpose only
	FS_DemoForceFlush(&cl->demofile);


	cl->demorecording = qtrue;
	Q_strncpyz( cl->demoName, name, sizeof( cl->name ));

	// don't start saving messages until a non-delta compressed message is received
	cl->demowaiting = qtrue;
	cl->demoArchiveIndex = 0;
	cl->demoMaxDeltaFrames = 1;
	cl->demoDeltaFrameCount = 0;

	// write out the gamestate message
	MSG_Init( &msg, bufData, sizeof( bufData ) );

	// NOTE, MRE: all server->client messages now acknowledge
	MSG_WriteLong( &msg, cl->lastClientCommand );

	SV_WriteGameState(&msg, cl);

	// write the client num
	MSG_WriteLong( &msg, cl - svs.clients );
	// write the checksum feed
	MSG_WriteLong( &msg, sv.checksumFeed );

	// finished writing the client packet
	MSG_WriteByte( &msg, svc_EOF );

	*(int32_t*)0x13f39080 = *(int32_t*)msg.data;
	compLen = 4 + MSG_WriteBitsCompress( 0, msg.data + 4 ,(byte*)0x13f39084 ,msg.cursize - 4);

	len = 0;
	FS_DemoWrite( &len, 1, &cl->demofile );

	// write it to the demo file

	// write the packet sequence
	len = cl->netchan.outgoingSequence;
	swlen = LittleLong( len );
	FS_DemoWrite( &swlen, 4, &cl->demofile );

	len = LittleLong( compLen );
	FS_DemoWrite( &len, 4, &cl->demofile );
	FS_DemoWrite((byte*)0x13f39080, compLen, &cl->demofile );

	// the rest of the demo file will be copied from net messages
}


/*
====================
SV_DemoSystemShutdown

stop recording of all demos
====================
*/
void SV_DemoSystemShutdown( ) {

	client_t *cl;
	int i;

	for(i = 0, cl = svs.clients; i < sv_maxclients->integer; i++, cl++)
	{
		if(cl->demorecording)
			SV_StopRecord(cl);
	}
}




/*
================
FS_DemoFileExists

Tests if the file exists in the current gamedir, this DOES NOT
search the paths.  This is to determine if opening a file to write
(which always goes into the current gamedir) will cause any overwrites.
NOTE TTimo: this goes with FS_FOpenFileWrite for opening the file afterwards
================
*/
qboolean FS_DemoFileExists( const char *file )
{
	FILE *f;
	char *testpath;

	testpath = FS_BuildOSPath( fs_homepath->string, file, "" );
	testpath[strlen(testpath)-1] = '\0';

	f = fopen( testpath, "rb" );
	if (f) {
		fclose( f );
		return qtrue;
	}
	return qfalse;
}

/*
==============
FS_DemoFileOpened
Returns true if this filehandle is an opened file
==============
*/

qboolean FS_DemoFileOpened( fileHandleData_t *fh ) {
	if (fh->handleFiles.file.o) {
	    return qtrue;
	}
	return qfalse;
}



/*
==============
FS_FCloseDemoFile

If the FILE pointer is an open pak file, leave it open.

For some reason, other dll's can't just cal fclose()
on files returned by FS_FOpenFile...
==============
*/
qboolean FS_FCloseDemoFile( fileHandleData_t *fh ) {
	// we didn't find it as a pak, so close it as a unique file

	if (fh->handleFiles.file.o) {
	    FS_DemoFlush( fh );
	    if(fh->writebuffer){
		Z_Free(fh->writebuffer);
	    }
	    fclose (fh->handleFiles.file.o);
	    Com_Memset( fh, 0, sizeof( fileHandleData_t ) );
	    return qtrue;
	}

	if(fh->writebuffer){
		Z_Free(fh->writebuffer);
	}

	Com_Memset( fh, 0, sizeof( fileHandleData_t ) );
	return qfalse;
}


/*
===========
FS_FOpenDemoFileWrite

===========
*/
qboolean FS_FOpenDemoFileWrite( const char *filename, fileHandleData_t *fh ) {
	char *ospath;

	if ( !fs_searchpaths ) {
		Com_Error( ERR_FATAL, "Filesystem call made without initialization" );
	}

	ospath = FS_BuildOSPath( fs_homepath->string, filename, "" );
	ospath[strlen(ospath)-1] = '\0';

	fh->zipFile = qfalse;

	if ( fs_debug->boolean ) {
		Com_Printf( "FS_SV_FOpenDemoFileWrite: %s\n", ospath );
	}

	if( FS_CreatePath( ospath ) ) {
		return qfalse;
	}

	fh->handleFiles.file.o = fopen( ospath, "wb" );

	Q_strncpyz( fh->name, filename, sizeof( fh->name ) );

	fh->handleSync = qfalse;
	if (!fh->handleFiles.file.o) {
		return qfalse;
	}
	fh->writebuffer = Z_Malloc(FS_DEMOWRITEBUF_SIZE);
	fh->bufferSize = FS_DEMOWRITEBUF_SIZE;
	return qtrue;
}

/*
=================
FS_DemoWrite

Properly handles partial writes
=================
*/
int FS_DemoWrite( const void *buffer, int len, fileHandleData_t *fh ) {

	byte* wb;
	int oldBufferPos;

	if ( !fh || !fh->handleFiles.file.o) {
		return 0;
	}

	wb = (byte*)fh->writebuffer;

	if(wb == NULL){

		fh->writebuffer = (void*)buffer;
		fh->bufferPos = len;
		oldBufferPos = fh->bufferPos;

		if(FS_DemoFlush( fh ) != oldBufferPos){ //Fatal file write error
			Com_Printf("Demo file write error. Closing file %s\n", fh->name);
			FS_FCloseDemoFile( fh );
			return 0;
		}

		fh->writebuffer = NULL;
		return len;
	}

	oldBufferPos = fh->bufferPos;

	if(len + fh->bufferPos > fh->bufferSize){ //If the buffer is too small to take more data flush it
		if(FS_DemoFlush( fh ) != oldBufferPos){ //Fatal file write error
			Com_Printf("Demo file write error. Closing file %s\n", fh->name);
			FS_FCloseDemoFile( fh );
			return 0;
		}
	}

	Com_Memcpy(wb + fh->bufferPos, buffer, len);
	fh->bufferPos += len;

	return len;
}

/*
=================
FS_DemoFlush

Writting buffer to file
=================
*/
int FS_DemoFlush( fileHandleData_t *fh ) {
	int	block, remaining;
	int	written, overallwritten;
	byte	*buf;
	int	tries;
	FILE	*f;
	const void *buffer = fh->writebuffer;
	int len = fh->bufferPos;

	if ( !fh ) {
		return 0;
	}

	f = fh->handleFiles.file.o;
	buf = (byte *)buffer;

	remaining = len;
	tries = 0;
	overallwritten = 0;
	while (remaining) {
		block = remaining;
		written = fwrite (buf, 1, block, f);
		overallwritten += written;
		if (written == 0) {
			if (!tries) {
				tries = 1;
			} else {
				Com_Printf( "FS_DemoFlush: 0 bytes written\n" );
				return 0;
			}
		}

		if (written == -1) {
			Com_Printf( "FS_DemoFlush: -1 bytes written\n" );
			return 0;
		}

		remaining -= written;
		buf += written;
	}

	fh->bufferPos = 0; //Reset the buffer offset to the beginning

	return overallwritten;
}



void FS_DemoForceFlush(fileHandleData_t *fh){

	setvbuf( fh->handleFiles.file.o, NULL, _IONBF, 0 );

}




/*
================
SVC_Info

Responds with a short info message that should be enough to determine
if a user is interested in a server to do a full status
================
*/
void SV_SendAuthRequest() {
	int		i, count, humans;
	char	infostring[MAX_INFO_STRING];
	char	s[16];
	permServerStatic_t* sve = &psvs;

	/*
	 * Check whether Cmd_Argv(1) has a sane length. This was not done in the original Quake3 version which led
	 * to the Infostring bug discovered by Luigi Auriemma. See http://aluigi.altervista.org/ for the advisory.
	 */

	// A maximum challenge length of 128 should be more than plenty.
	if(strlen(SV_Cmd_Argv(1)) > 128)
		return;
	s[4] = 'o';
	s[5] = 'r';

	// don't count privateclients
	count = humans = 0;
	for ( i = 0 ; i < sv_maxclients->integer ; i++ ) {
		if ( svs.clients[i].state >= CS_CONNECTED ) {
			count++;
			if (svs.clients[i].netchan.remoteAddress.type != NA_BOT) {
				humans++;
			}
		}
	}

	s[8] = 's';
	infostring[0] = 0;

	// echo back the parameter to status. so servers can use it as a challenge
	// to prevent timed spoofed reply packets that add ghost servers

	Info_SetValueForKey( infostring, "challenge", va("%i %i", sve->authnum, sve->challenge));
	s[11] = 'n';
	s[12] = 0;

	Info_SetValueForKey(infostring, "protocol", "6");
	s[6] = 'o';
	s[7] = 'p';

	Info_SetValueForKey( infostring, "hostname", sv_hostname->string );
	Info_SetValueForKey( infostring, "mapname", sv_mapname->string );
	Info_SetValueForKey( infostring, "clients", va("%i", count) );
	Info_SetValueForKey( infostring, "sv_maxclients", va("%i", sv_maxclients->integer - sv_privateClients->integer ) );
	Info_SetValueForKey( infostring, "gametype", g_gametype->string );
	Info_SetValueForKey( infostring, "pure", va("%i", sv_pure->boolean ) );
	s[2] = '.';
	s[3] = 'i';

        if(*g_password->string)
	    Info_SetValueForKey( infostring, "pswrd", "1");
	else
	    Info_SetValueForKey( infostring, "pswrd", "0");

	s[9] = '.';
	s[10] = 'i';

        if(g_cvar_valueforkey("scr_team_fftype")){
	    Info_SetValueForKey( infostring, "ff", va("%i", g_cvar_valueforkey("scr_team_fftype")));
	}

        if(g_cvar_valueforkey("scr_game_allowkillcam")){
	    Info_SetValueForKey( infostring, "ki", "1");
	}
	s[4] = 'c';
	s[5] = 'e';

        if(g_cvar_valueforkey("scr_hardcore")){
	    Info_SetValueForKey( infostring, "hc", "1");
	}

        if(g_cvar_valueforkey("scr_oldschool")){
	    Info_SetValueForKey( infostring, "od", "1");
	}
	Info_SetValueForKey( infostring, "hw", "1");

        if(fs_game->string[0] == '\0' || sv_showasranked->boolean){
	    Info_SetValueForKey( infostring, "mod", "0");
	}else{
	    Info_SetValueForKey( infostring, "mod", "1");
	}
	Info_SetValueForKey( infostring, "voice", va("%i", sv_voice->boolean ) );
	Info_SetValueForKey( infostring, "pb", va("%i", sv_punkbuster->boolean) );
	if( sv_maxPing->integer ) {
		Info_SetValueForKey( infostring, "sv_maxPing", va("%i", sv_maxPing->integer) );
	}
	s[0] = 's';
	s[1] = 'v';


	if( fs_game->string[0] != '\0' ) {
		Info_SetValueForKey( infostring, "game", fs_game->string );
	}

	if(sve->sysauthadr.type != NA_IP)
	{
		NET_StringToAdr(s, &sve->sysauthadr, NA_IP);
		sve->sysauthadr.port = BigShort(PORT_AUTHORIZE);
	}
	if(sve->sysauthadr.type == NA_IP)
		NET_OutOfBandPrint( NS_SERVER, &sve->sysauthadr, "infoResponse\n%s", infostring );
}

