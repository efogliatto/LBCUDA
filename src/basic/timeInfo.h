#ifndef TIMEINFO_H
#define TIMEINFO_H

#include <time.h>
#include <sys/time.h>

/**
 * @file timeInfo.h
 * @author Ezequiel O. Fogliatto
 * @date 27 Ene 2020
 * @brief Struct containing simulation parameters
 */

/**
 * @brief Struct containing simulation parameters
 *
 * This struct contains information related to global simulation 
 */

#include <dataTypes.h>


typedef struct {


    time_t st;   /**< Start time (cpu time measurement) */
    
    struct timeval stt;   /**< Time struct (cpu time measurement) */

    
} timeInfo;


#endif // TIMEINFO_H
