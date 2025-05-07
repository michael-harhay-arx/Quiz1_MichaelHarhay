/***************************************************************************//*!
* \file HelperFunctions.h
* \author 
* \copyright . All Rights Reserved.
* \date 2025-05-07 10:19:48 AM
*******************************************************************************/

#ifndef __HelperFunctions_H__
#define __HelperFunctions_H__

#ifdef __cplusplus
    extern "C" {
#endif

//==============================================================================
// Include files

#include "cvidef.h"
#include "LogStruct.h"

//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// External variables

//==============================================================================
// Global functions

void ParseLogs (char *LogPath, LogStruct *ParsedResults);
void SetTestTimer (void);
void StopTestTimer (double *TimeElapsed);

#ifdef __cplusplus
    }
#endif

#endif  /* ndef __HelperFunctions_H__ */
