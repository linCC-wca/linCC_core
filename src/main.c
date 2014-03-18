#include "varTag.h"
#include "libPLC.h"
#include "commInfo.h"
#include "db_tagsPack.h"
#include "PLCComm.h"
#include "linCC.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "threads.h"
#include <signal.h>

TAG_VAR* VarTags;
PLCData* addressPacked;


void exitMsg( int signNo ){
	printf("\n\n ----------------------------- \n ");
	printf("\n\n linCC now exit. Goodbye ;) \n ");
	exit(0);
}

int main(void) {
        
    unsigned long rowCount;// = malloc( sizeof( unsigned long ));
    unsigned int packCount;
    printf( "Packing address...\n" );
    getPack( &packCount );
    printf( "Package count: %d\n", packCount );
    for( int i = 0; i < packCount; i++)
        printf( "DB: %d : StrtByte: %d : Length: %d\n", addressPacked[i].db, addressPacked[i].startByte, addressPacked[i].dataLength );
    
    
    printf( "Reading tags dabase... \n" );
    if( loadTags( &rowCount ) ) {
        printf( "Impossibile leggere lista tag da DB" );
        exit(1);
    }
    
    printf( "Number of tags: %d\n", rowCount );
   
    printf( "Reading database of PLC connections...\n" );
   	PLC_CONN_INFO* plcInfo;
   	plcInfo = linCCPLCgetInfo();	
   	
   	printf( "PLC Connection info:\n" );
   	printf( "PLC IP ADDRESS   : %s\n", plcInfo->ip );
   	printf( "PLC RACK         : %d\n", plcInfo->rack );
   	printf( "PLC SLOT         : %d\n", plcInfo->slot );
   	printf( "Try to connect to PLC...\n" );
   	
   	S7Object client;
	if( PLCConnect( &client, plcInfo->ip , &plcInfo->rack, &plcInfo->slot )) {
		free( plcInfo );
		exit(50);
	}
	free( plcInfo );
	int qryCount = 0;
	printf( "Comunication started...\n" );
	
	//prova( &packCount, &client );
	
    PLCThread plcData;
    plcData.packCount = &packCount;
    plcData.client = &client;
    
    pthread_t thread;
    threadPLCRead( &thread, &plcData );
	unsigned long tagUpdateCount;
	
	//unsigned int* tagDB, unsigned int* startByte, unsigned int* dataLength, unsigned char* data)
	signal( SIGINT, exitMsg );
	
	while( 1 ) {
        sleep(1);		
		U_TAG_VAR* tagUpdate;
		//for( int l = 0; l < packCount; l++ )
		//	PLCReadTags( &client, &addressPacked[l].db, &addressPacked[l].startByte, &addressPacked[l].dataLength, addressPacked[l].data );
				//for( int i = 0; i < addressPacked[l].dataLength; i++ )
					//printf( "DB: %d -- DATA BYTE %d -- VALUE: %d \n", addressPacked[l].db, i, addressPacked[l].data[i] );
	   // prova( &packCount, &client);				
		varTagGetValues( VarTags, &tagUpdate, addressPacked, &rowCount, &tagUpdateCount, &packCount );
		//for( int i = 0; i < rowCount; i++ ){
		  //  printf( "Write on dabase <--- DB: %d -- ADDR: %d -- TYPE: %d -- Values: %f\n", VarTags[i].db, VarTags[i].address, VarTags[i].type, VarTags[i].tagValue );
		   // float tempFl = VarTags[i].tagValue;
		   printf("TAG update count: %d\n", tagUpdateCount);
		    writeTag( tagUpdate, &tagUpdateCount );
		//}
		qryCount++;
		printf("\rCounter : %d", qryCount );
		fflush( stdout );
		free(tagUpdate);
	}
}

 
