
typedef void (__cdecl *tSys_ThreadInit)( void );
tSys_ThreadInit Sys_ThreadInit = (tSys_ThreadInit)(0x81d6c00);

typedef void (__cdecl *tSys_ThreadMain)( void );
tSys_ThreadMain Sys_ThreadMain = (tSys_ThreadMain)(0x8140f5c);

typedef void (__cdecl *tCom_InitParse)( void );
tCom_InitParse Com_InitParse = (tCom_InitParse)(0x81a7a78);

typedef jmp_buf* (__cdecl *tSys_GetValue)( int );
tSys_GetValue Sys_GetValue = (tSys_GetValue)(0x8140e9c);

typedef void (__cdecl *tSys_Error_real)( const char *error);
tSys_Error_real Sys_Error_real = (tSys_Error_real)(0x81d5a14);

typedef qboolean (__cdecl *tPbServerInitialize)(void);
tPbServerInitialize PbServerInitialize = (tPbServerInitialize)(0x810ecde);

typedef void (__cdecl *tPbServerProcessEvents)(void);
tPbServerProcessEvents PbServerProcessEvents = (tPbServerProcessEvents)(0x810ef08);

typedef const char* (__cdecl *tPbAuthClient)( const char* NETAdrString, qboolean cl_punkbuster, const char* pbguid);
tPbAuthClient PbAuthClient = (tPbAuthClient)(0x810e47a);

typedef void (__cdecl *tPbPassConnectString)( const char* NETAdrString, const char* connectstring);
tPbPassConnectString PbPassConnectString = (tPbPassConnectString)(0x810e47a);

typedef void (__cdecl *tPbSvAddEvent)( int event_type, int clientnum, int sizeofstring, char* string);
tPbSvAddEvent PbSvAddEvent = (tPbSvAddEvent)(0x810ea20);

/*typedef void (__cdecl *tCom_Frame)(void);
tCom_Frame Com_Frame = (tCom_Frame)(0x8123f66);
*/
typedef void (__cdecl *tSL_Init)(void);
tSL_Init SL_Init = (tSL_Init)(0x8150928);

typedef void (__cdecl *tSwap_Init)(void);
tSwap_Init Swap_Init = (tSwap_Init)(0x81aa7b6);

typedef void (__cdecl *tCbuf_Init)(void);
tCbuf_Init Cbuf_Init = (tCbuf_Init)(0x81110bc);

typedef void (__cdecl *tCmd_Init)(void);
tCmd_Init Cmd_Init = (tCmd_Init)(0x8111730);

/*
typedef void (__cdecl *tCom_InitCvars)(void);
tCom_InitCvars Com_InitCvars = (tCom_InitCvars)(0x8121cb6);
*/

typedef void (__cdecl *tCom_Restart)(void);
tCom_Restart Com_Restart = (tCom_Restart)(0x8123586);

typedef void (__cdecl *tCSS_InitConstantConfigStrings)(void);
tCSS_InitConstantConfigStrings CSS_InitConstantConfigStrings = (tCSS_InitConstantConfigStrings)(0x8185a72);

typedef void (__cdecl *tMem_Init)(void);
tMem_Init Mem_Init = (tMem_Init)(0x81a75e6);

typedef void (__cdecl *tDB_SetInitializing)(qboolean);
tDB_SetInitializing DB_SetInitializing = (tDB_SetInitializing)(0x820337c);

typedef byte (__cdecl *tDB_FileExists)(const char* filename, int mode);
tDB_FileExists DB_FileExists = (tDB_FileExists)(0x8204424);

typedef void (__cdecl *tMem_BeginAlloc)(const char*, qboolean);
tMem_BeginAlloc Mem_BeginAlloc = (tMem_BeginAlloc)(0x81a74d0);

typedef void (__cdecl *tFS_InitFilesystem)(void);
tFS_InitFilesystem FS_InitFilesystem = (tFS_InitFilesystem)(0x818e980);

typedef void (__cdecl *tCon_InitChannels)(void);
tCon_InitChannels Con_InitChannels = (tCon_InitChannels)(0x82096be);

typedef void (__cdecl *tLiveStorage_Init)(void);
tLiveStorage_Init LiveStorage_Init = (tLiveStorage_Init)(0x81d77ce);

typedef void (__cdecl *tCom_InitPlayerProfiles)(qboolean);
tCom_InitPlayerProfiles Com_InitPlayerProfiles = (tCom_InitPlayerProfiles)(0x81d77ce);

typedef void (__cdecl *tCbuf_Execute)(int, int);
tCbuf_Execute Cbuf_Execute = (tCbuf_Execute)(0x8111f3c);

typedef void (__cdecl *tCbuf_ExecuteBuffer)(int, int, char* buf);
tCbuf_ExecuteBuffer Cbuf_ExecuteBuffer = (tCbuf_ExecuteBuffer)(0x81120ae);

typedef void (__cdecl *tCbuf_AddText)(int dummy, const char* text);
tCbuf_AddText Cbuf_AddText = (tCbuf_AddText)(0x8110ff8);

typedef void (__cdecl *tSEH_UpdateLanguageInfo)(void);
tSEH_UpdateLanguageInfo SEH_UpdateLanguageInfo = (tSEH_UpdateLanguageInfo)(0x8180432);

typedef void (__cdecl *tCom_InitHunkMemory)(void);
tCom_InitHunkMemory Com_InitHunkMemory = (tCom_InitHunkMemory)(0x8197174);

typedef void (__cdecl *tHunk_InitDebugMemory)(void);
tHunk_InitDebugMemory Hunk_InitDebugMemory = (tHunk_InitDebugMemory)(0x819752a);

typedef void (__cdecl *tCom_ServerPacketEvent)(void);
tCom_ServerPacketEvent Com_ServerPacketEvent = (tCom_ServerPacketEvent)(0x8122166);

typedef void (__cdecl *tCom_WriteConfig_f)(void);
tCom_WriteConfig_f Com_WriteConfig_f = (tCom_WriteConfig_f)(0x8122e82);

typedef void (__cdecl *tCom_WriteDefaults_f)(void);
tCom_WriteDefaults_f Com_WriteDefaults_f = (tCom_WriteDefaults_f)(0x8123bae);

typedef void (__cdecl *tSV_StringUsage_f)(void);
tSV_StringUsage_f SV_StringUsage_f = (tSV_StringUsage_f)(0x814cc7e);

typedef void (__cdecl *tSV_ScriptUsage_f)(void);
tSV_ScriptUsage_f SV_ScriptUsage_f = (tSV_ScriptUsage_f)(0x81557c4);

typedef void (__cdecl *tSys_Init)(void);
tSys_Init Sys_Init = (tSys_Init)(0x81d4f04);

typedef void (__cdecl *tSetAnimCheck)(int);
tSetAnimCheck SetAnimCheck = (tSetAnimCheck)(0x81423f0);

/*
//Netchan and MSG

typedef char* (__cdecl *tMSG_Init)( msg_t *buf, byte *data, int length);
tMSG_Init MSG_Init = (tMSG_Init)(0x8131200);

typedef char* (__cdecl *tMSG_ReadString)( msg_t *msg);
tMSG_ReadString MSG_ReadString = (tMSG_ReadString)(0x81310d6);

typedef char* (__cdecl *tMSG_ReadStringLine)( msg_t *msg);
tMSG_ReadStringLine MSG_ReadStringLine = (tMSG_ReadStringLine)(0x8130f92);

typedef int (__cdecl *tMSG_ReadLong)( msg_t *msg);
tMSG_ReadLong MSG_ReadLong = (tMSG_ReadLong)(0x813099a);

typedef int (__cdecl *tMSG_ReadShort)( msg_t *msg);
tMSG_ReadShort MSG_ReadShort = (tMSG_ReadShort)(0x8130920);

typedef int (__cdecl *tMSG_ReadByte)( msg_t *msg);
tMSG_ReadByte MSG_ReadByte = (tMSG_ReadByte)(0x81308d8);

typedef int (__cdecl *tMSG_ReadData)( msg_t *msg, const void* data, int length);
tMSG_ReadData MSG_ReadData = (tMSG_ReadData)(0x8130bc2);

typedef void (__cdecl *tMSG_BeginReading)( msg_t *msg);
tMSG_BeginReading MSG_BeginReading = (tMSG_BeginReading)(0x81305c6);

typedef void (__cdecl *tMSG_WriteLong)( msg_t *msg, int c);
tMSG_WriteLong MSG_WriteLong = (tMSG_WriteLong)(0x81308aa);

typedef void (__cdecl *tMSG_WriteShort)( msg_t *msg, int c);
tMSG_WriteShort MSG_WriteShort = (tMSG_WriteShort)(0x813087c);

typedef void (__cdecl *tMSG_WriteData)( msg_t *msg, const void* data, int length);
tMSG_WriteData MSG_WriteData = (tMSG_WriteData)(0x8130c88);
*/

typedef int (__cdecl *tMSG_ReadBits)( msg_t *msg, int numBits);
tMSG_ReadBits MSG_ReadBits = (tMSG_ReadBits)(0x8130730);

typedef int (__cdecl *tGetMinBitCount)( unsigned int number );
tGetMinBitCount GetMinBitCount = (tGetMinBitCount)(0x8130500);

typedef void (__cdecl *tMSG_WriteDeltaClient)(snapshotInfo_t* , msg_t* , int , clientState_s* , clientState_s*, int);
tMSG_WriteDeltaClient MSG_WriteDeltaClient = (tMSG_WriteDeltaClient)(0x813f49c);

typedef void (__regparm3 *tMSG_WriteDeltaField)(snapshotInfo_t* , msg_t* , int, unsigned const char*, unsigned const char*, const void* netfield, int, unsigned char);
tMSG_WriteDeltaField MSG_WriteDeltaField = (tMSG_WriteDeltaField)(0x813e22a);

typedef void (__cdecl *tMSG_WriteDeltaPlayerstate)(snapshotInfo_t* , msg_t* , int , playerState_t* , playerState_t*);
tMSG_WriteDeltaPlayerstate MSG_WriteDeltaPlayerstate = (tMSG_WriteDeltaPlayerstate)(0x813f5a6);

typedef void (__cdecl *tMSG_WriteEntityIndex)(snapshotInfo_t*, msg_t*, int, int);
tMSG_WriteEntityIndex MSG_WriteEntityIndex = (tMSG_WriteEntityIndex)(0x813de54);

typedef void (__cdecl *tMSG_WriteBit1)(msg_t*);
tMSG_WriteBit1 MSG_WriteBit1 = (tMSG_WriteBit1)(0x81306dc);

typedef void (__cdecl *tMSG_WriteBits)(msg_t*, int bits, int bitcount);
tMSG_WriteBits MSG_WriteBits = (tMSG_WriteBits)(0x813061c);

typedef void (__cdecl *tMSG_ReadDeltaUsercmdKey)( msg_t *msg, int key, usercmd_t *from, usercmd_t *to );
tMSG_ReadDeltaUsercmdKey MSG_ReadDeltaUsercmdKey = (tMSG_ReadDeltaUsercmdKey)(0x81392ae);

typedef void (__cdecl *tMSG_SetDefaultUserCmd)( playerState_t *ps, usercmd_t *ucmd );
tMSG_SetDefaultUserCmd MSG_SetDefaultUserCmd = (tMSG_SetDefaultUserCmd)(0x8130ad0);

//typedef int (__cdecl *tMSG_ReadBitsCompress)( const byte *datasrc, byte *buffdest, int bytecount);
//tMSG_ReadBitsCompress MSG_ReadBitsCompress = (tMSG_ReadBitsCompress)(0x8130edc);

typedef int (__cdecl *tMSG_WriteBitsCompress)( char dummy, const byte *datasrc, byte *buffdest, int bytecount);
tMSG_WriteBitsCompress MSG_WriteBitsCompress = (tMSG_WriteBitsCompress)(0x8130f3c);

typedef void (__cdecl *tSV_BeginClientSnapshot)( client_t *cl, msg_t* msg);
tSV_BeginClientSnapshot SV_BeginClientSnapshot = (tSV_BeginClientSnapshot)(0x817a32e);

typedef void (__cdecl *tSV_EndClientSnapshot)( client_t *cl, msg_t* msg);
tSV_EndClientSnapshot SV_EndClientSnapshot = (tSV_EndClientSnapshot)(0x817b488);

typedef void (__cdecl *tSV_ClientThink)( client_t *cl, usercmd_t * );
tSV_ClientThink SV_ClientThink = (tSV_ClientThink)(0x816df7a);
/*
typedef void (__cdecl *tSV_ExecuteClientMessage)(client_t*, msg_t*);
tSV_ExecuteClientMessage SV_ExecuteClientMessage = (tSV_ExecuteClientMessage)(0x8172990);
*/
typedef void (__cdecl *tSV_SpawnServer)(const char* levelname);
tSV_SpawnServer SV_SpawnServer = (tSV_SpawnServer)(0x8174a68);

typedef void (__cdecl *tSV_SetGametype)( void );
tSV_SetGametype SV_SetGametype = (tSV_SetGametype)(0x817c72c);

typedef void (__cdecl *tSV_InitCvars)( void );
tSV_InitCvars SV_InitCvars = (tSV_InitCvars)(0x819e66c);

typedef void (__cdecl *tSV_RestartGameProgs)( int savepersist );
tSV_RestartGameProgs SV_RestartGameProgs = (tSV_RestartGameProgs)(0x817c68a);

typedef void (__cdecl *tXAnimInit)(void);
tXAnimInit XAnimInit = (tXAnimInit)(0x81b649c);

typedef void (__cdecl *tDObjInit)(void);
tDObjInit DObjInit = (tDObjInit)(0x81acb00);

typedef void (__cdecl *tSV_ResetSekeletonCache)(void);
tSV_ResetSekeletonCache SV_ResetSekeletonCache = (tSV_ResetSekeletonCache)(0x817c602);

typedef void (__cdecl *tSV_PreFrame)(void);
tSV_PreFrame SV_PreFrame = (tSV_PreFrame)(0x8177534);

typedef void (__cdecl *tSV_SendClientMessages)(void);
tSV_SendClientMessages SV_SendClientMessages = (tSV_SendClientMessages)(0x817b71e);

typedef qboolean (__cdecl *tDB_ModFileExists)(void);
tDB_ModFileExists DB_ModFileExists = (tDB_ModFileExists)(0x8204470);

typedef void (__cdecl *tDB_LoadXAssets)(XZoneInfo*, unsigned int assetscount, int);
tDB_LoadXAssets DB_LoadXAssets = (tDB_LoadXAssets)(0x8205e86);

typedef int (__cdecl *tDB_GetXAssetTypeSize)(int type);
tDB_GetXAssetTypeSize DB_GetXAssetTypeSize = (tDB_GetXAssetTypeSize)(0x81da6ce);

typedef void (__cdecl *tCom_DvarDump)(int, int);
tCom_DvarDump Com_DvarDump = (tCom_DvarDump)(0x8126764);

typedef void (__cdecl *tMem_EndAlloc)(const char*, int);
tMem_EndAlloc Mem_EndAlloc = (tMem_EndAlloc)(0x81a750a);

typedef void (__cdecl *tCom_ErrorCleanup)(void);
tCom_ErrorCleanup Com_ErrorCleanup = (tCom_ErrorCleanup)(0x8123c86);

typedef void (__cdecl *tSys_EnterCriticalSection)(int);
tSys_EnterCriticalSection Sys_EnterCriticalSection = (tSys_EnterCriticalSection)(0x81d6be4);

typedef void (__cdecl *tSys_LeaveCriticalSection)(int);
tSys_LeaveCriticalSection Sys_LeaveCriticalSection = (tSys_LeaveCriticalSection)(0x81d6bc8);

typedef void (__cdecl *tHunk_ClearTempMemory)(void);
tHunk_ClearTempMemory Hunk_ClearTempMemory = (tHunk_ClearTempMemory)(0x81968a8);

typedef void (__cdecl *tHunk_ClearTempMemoryHigh)(void);
tHunk_ClearTempMemoryHigh Hunk_ClearTempMemoryHigh = (tHunk_ClearTempMemoryHigh)(0x81968b8);

/*
typedef void (__cdecl *tSV_Shutdown)(const char* reason);
tSV_Shutdown SV_Shutdown = (tSV_Shutdown)(0x817452e);
*/

typedef void (__cdecl *tSV_SetServerStaticHeader)(void);
tSV_SetServerStaticHeader SV_SetServerStaticHeader = (tSV_SetServerStaticHeader)(0x8178fd4);

typedef void (__cdecl *tSV_ShutdownGameProgs)(void);
tSV_ShutdownGameProgs SV_ShutdownGameProgs = (tSV_ShutdownGameProgs)(0x817c818);

typedef void (__cdecl *tSV_FreeClients)(void);
tSV_FreeClients SV_FreeClients = (tSV_FreeClients)(0x81720c6);

typedef void (__cdecl *tCom_Close)(void);
tCom_Close Com_Close = (tCom_Close)(0x8121b82);

typedef void (__cdecl *tFS_Shutdown)(qboolean);
tFS_Shutdown FS_Shutdown = (tFS_Shutdown)(0x818733a);

typedef void (__cdecl *tFS_ShutdownIwdPureCheckReferences)(void);
tFS_ShutdownIwdPureCheckReferences FS_ShutdownIwdPureCheckReferences = (tFS_ShutdownIwdPureCheckReferences)(0x81866b6);

typedef void (__cdecl *tFS_ShutdownServerIwdNames)(void);
tFS_ShutdownServerIwdNames FS_ShutdownServerIwdNames = (tFS_ShutdownServerIwdNames)(0x8186cfe);

typedef void (__cdecl *tFS_ShutdownServerReferencedIwds)(void);
tFS_ShutdownServerReferencedIwds FS_ShutdownServerReferencedIwds = (tFS_ShutdownServerReferencedIwds)(0x818789c);

typedef void (__cdecl *tFS_ShutdownServerReferencedFFs)(void);
tFS_ShutdownServerReferencedFFs FS_ShutdownServerReferencedFFs = (tFS_ShutdownServerReferencedFFs)(0x8187850);

typedef const char* (__cdecl *tFS_LoadedIwdPureChecksums)(void);
tFS_LoadedIwdPureChecksums FS_LoadedIwdPureChecksums = (tFS_LoadedIwdPureChecksums)(0x81283f2);


/*typedef void (__cdecl *tG_LogPrintf)( const char *text);
tG_LogPrintf G_LogPrintf = (tG_LogPrintf)(0x80b43c4);
*/

typedef void (__cdecl *tG_RunFrame)( int time );
tG_RunFrame G_RunFrame = (tG_RunFrame)(0x80b61fc);

typedef void (QDECL *tCom_Error)( int level, const char *error, ...);
tCom_Error Com_Error = (tCom_Error)(0x812257c);

typedef qboolean (__regparm1 *tIs_Banned)(const char* guid);
tIs_Banned Is_Banned = (tIs_Banned)(0x816ece4);

typedef void (__cdecl *tSV_GameSendServerCommand)(int clientnum, int svscmd_type, const char *text);
tSV_GameSendServerCommand SV_GameSendServerCommand = (tSV_GameSendServerCommand)(0x817ce42);

typedef void (__cdecl *tSV_SetConfigstring)(int index, const char *text);
tSV_SetConfigstring SV_SetConfigstring = (tSV_SetConfigstring)(0x8173fda);

typedef void (__cdecl *tSV_AddServerCommand_old)(client_t *client, int unkownzeroorone, const char *);
tSV_AddServerCommand_old SV_AddServerCommand_old = (tSV_AddServerCommand_old)(0x817664c);

//typedef void (__cdecl *tSV_DropClient)(client_t *drop, const char* reason);
//tSV_DropClient SV_DropClient = (tSV_DropClient)(0x8170a26);

typedef void (__cdecl *tSV_FreeClient)(client_t* drop);
tSV_FreeClient SV_FreeClient = (tSV_FreeClient)(0x81708bc);

typedef qboolean (__cdecl *tSV_BanClient)( unsigned int *clientstatusptr);
tSV_BanClient SV_BanClient = (tSV_BanClient)(0x8171410);

typedef void (__cdecl *tCmd_TokenizeString)(const char* string);
tCmd_TokenizeString Cmd_TokenizeString = (tCmd_TokenizeString)(0x811142c);

typedef void (__cdecl *tSV_Cmd_TokenizeString)(const char* string);
tSV_Cmd_TokenizeString SV_Cmd_TokenizeString = (tSV_Cmd_TokenizeString)(0x811139c);

typedef void (__cdecl *tCmd_EndTokenizeString)();
tCmd_EndTokenizeString Cmd_EndTokenizeString = (tCmd_EndTokenizeString)(0x8110d54);

typedef void (__cdecl *tSV_Cmd_EndTokenizeString)();
tSV_Cmd_EndTokenizeString SV_Cmd_EndTokenizeString = (tSV_Cmd_EndTokenizeString)(0x8110d8c);

/*
typedef qboolean (__regparm3 *tSV_ClientCommand)( client_t*, msg_t*, int);
tSV_ClientCommand SV_ClientCommand = (tSV_ClientCommand)(0x8170d22);
*/

typedef void (__cdecl *tClientCommand)( int );
tClientCommand ClientCommand = (tClientCommand)(0x80b070c);

/*
typedef void (__cdecl *tClientUserinfoChanged)( int );
tClientUserinfoChanged ClientUserinfoChanged = (tClientUserinfoChanged)(0x80a8068);
*/

//typedef sharedEntity_t* (__cdecl *tSV_GentityNum)(int clnum);
//tSV_GentityNum SV_GentityNum = (tSV_GentityNum)(0x817c586);

typedef void (__cdecl *tSV_FreeClientScriptId)(client_t *cl);
tSV_FreeClientScriptId SV_FreeClientScriptId = (tSV_FreeClientScriptId)(0x8175c5e);

//typedef void (__cdecl *tSV_SendClientGameState)(client_t *cl);
//tSV_SendClientGameState SV_SendClientGameState = (tSV_SendClientGameState)(0x816e1ba);

/*typedef void (__cdecl *tSV_ClientEnterWorld)(client_t *cl, usercmd_t* ucmd);
tSV_ClientEnterWorld SV_ClientEnterWorld = (tSV_ClientEnterWorld)(0x816e136);*/

//typedef void (__cdecl *tSV_UserinfoChanged)(client_t *cl);
//tSV_UserinfoChanged SV_UserinfoChanged = (tSV_UserinfoChanged)(0x81703d6);

typedef void (__cdecl *tSV_LinkEntity)(gentity_t*);
tSV_LinkEntity SV_LinkEntity = (tSV_LinkEntity)(0x817eb20);

typedef void (__cdecl *tSV_UnlinkEntity)(gentity_t*);
tSV_UnlinkEntity SV_UnlinkEntity = (tSV_UnlinkEntity)(0x817d5e0);

//Check for ban or PunkBuster is turned on at client

typedef const char* (__cdecl *tClientConnect)(int clnum, short clscriptid);  //Something simular to VM_Call
tClientConnect ClientConnect = (tClientConnect)(0x80a83d4);

typedef void (__cdecl *tG_Say)(gentity_t *ent, gentity_t *other, int mode, const char *message);
tG_Say G_Say = (tG_Say)(0x80ae962);
/*
typedef void (__cdecl *tCom_BeginRedirect)(char *buffer, int buffersize, void ( *flush )( char* ) );
tCom_BeginRedirect Com_BeginRedirect = (tCom_BeginRedirect)(0x81218a0);

typedef void (__cdecl *tCom_EndRedirect)();
tCom_EndRedirect Com_EndRedirect = (tCom_EndRedirect)(0x81218ce);
*/

typedef void (__cdecl *tPbCapatureConsoleOutput)(char *msg, int size);
tPbCapatureConsoleOutput PbCapatureConsoleOutput = (tPbCapatureConsoleOutput)(0x810e66a);

typedef void (__cdecl *tCmd_ExecuteSingleCommand)(int unk, int unk2, const char *cmd );
tCmd_ExecuteSingleCommand Cmd_ExecuteSingleCommand = (tCmd_ExecuteSingleCommand)(0x8111bea);

typedef void (__cdecl *tPbServerForceProcess)();
tPbServerForceProcess PbServerForceProcess = (tPbServerForceProcess)(0x810ee36);

typedef void* (__cdecl *tHunk_AllocateTempMemory)(int size);
tHunk_AllocateTempMemory Hunk_AllocateTempMemory = (tHunk_AllocateTempMemory)(0x8196fea);

typedef void (__cdecl *tHunk_FreeTempMemory)(void *buffer);
tHunk_FreeTempMemory Hunk_FreeTempMemory = (tHunk_FreeTempMemory)(0x81969d4);

typedef void* (__cdecl *tZ_Malloc)( int size);
tZ_Malloc Z_Malloc = (tZ_Malloc)(0x8196d6e);

#define Z_Free free

typedef int (__cdecl *tCom_Filter)( char* filter, char *name, int casesensitive);
tCom_Filter Com_Filter = (tCom_Filter)(0x819837e);

typedef qboolean (__cdecl *tBG_IsWeaponValid)( playerState_t *ps, unsigned int index);
tBG_IsWeaponValid BG_IsWeaponValid = (tBG_IsWeaponValid)(0x805f4fe);

typedef char* (__cdecl *tFS_GetMapBaseName)( const char* mapname );
tFS_GetMapBaseName FS_GetMapBaseName = (tFS_GetMapBaseName)(0x8127e0c);

/*typedef cvar_t* (__cdecl *tCvar_SetBool)(cvar_bool_t *var_name,int var_value);
tCvar_SetBool Cvar_SetBool = (tCvar_SetBool)(0x81a20c4); Does not work like expected !
*/

//G_Say 80ae962

typedef void (__cdecl *tClientBegin)( int clientNum );
tClientBegin ClientBegin = (tClientBegin)(0x80a7700);

typedef void (__cdecl *tMSG_WriteReliableCommandToBuffer)( const char* source, char* destination,int length);
tMSG_WriteReliableCommandToBuffer MSG_WriteReliableCommandToBuffer = (tMSG_WriteReliableCommandToBuffer)(0x813e162);

typedef qboolean (__cdecl *tSEH_StringEd_GetString)( const char* input );
tSEH_StringEd_GetString SEH_StringEd_GetString = (tSEH_StringEd_GetString)(0x817fbe0);


typedef qboolean (__cdecl *tCM_TraceBox)(const float*, const float*, const float*, float);
tCM_TraceBox CM_TraceBox = (tCM_TraceBox)(0x811a5a2);

typedef clipHandle_t (__cdecl *tCM_TempBoxModel)(const float* mins, const float* maxs, int capsule);
tCM_TempBoxModel CM_TempBoxModel = (tCM_TempBoxModel)(0x811c442);

typedef void (__cdecl *tCM_TransformedBoxTrace)(trace_t* trace, const float* start, const float* end, const float* mins, const float* maxs,
			clipHandle_t cliphandle, int contentmask, const float* origin, const float* angle);
tCM_TransformedBoxTrace CM_TransformedBoxTrace = (tCM_TransformedBoxTrace)(0x811e3c2);


/*
typedef void (__cdecl *tHuff_offsetReceive)( node_t *node, int *ch, byte *fin, int *offset );
tHuff_offsetReceive Huff_offsetReceive = (tHuff_offsetReceive)(0x812a0a2);*/
/*
typedef void (__cdecl *tHuff_offsetReceive)( node_t *node, int *ch, byte *fin, int *offset );
tHuff_offsetReceive Huff_offsetReceive = (tHuff_offsetReceive)(0x812a0a2);*/

int MSG_WriteBitsNoCompress( int d, byte* src, byte* dst , int size){
	Com_Memcpy(dst, src, size);
	return size;
}


typedef void (__cdecl *tStopFollowing)( gentity_t* ent );
tStopFollowing StopFollowing = (tStopFollowing)(0x80af24c);

typedef unsigned int (__cdecl *tScr_LoadScript_o)(const char* scriptname, void *precache, int iarg_02);
tScr_LoadScript_o Scr_LoadScript_o = (tScr_LoadScript_o)(0x814bef0);
/*
typedef char* (__cdecl *tSL_ConvertToString)(unsigned int index);
tSL_ConvertToString SL_ConvertToString = (tSL_ConvertToString)(0x8150340);
*/