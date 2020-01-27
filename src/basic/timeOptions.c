#include <timeInfo.h>


// Comienzo de medicion de tiempo

void startTime( timeInfo* info ) {

    info->st = time( NULL );

    gettimeofday( &info->stt, NULL );

}


// Elapsed time

scalar elapsedTime ( timeInfo* info ) {

    struct timeval _end;
    
    gettimeofday( &_end, NULL );
	
    return (scalar)(((double)_end.tv_sec + (double)_end.tv_usec / 1000000)  - ((double)info->stt.tv_sec + (double)info->stt.tv_usec / 1000000));

}
