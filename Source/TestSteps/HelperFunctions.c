/***************************************************************************//*!
* \file HelperFunctions.c
* \author Michael Harhay
* \copyright Arxtron Technologies Inc.. All Rights Reserved.
* \date 11/10/2022 11:34:01 PM
* \brief This contains all the test steps used for this project.
* 
* This project compiles into a DLL file and is meant to be used as a CVI module
* 	within TestStand.
* 
* This Library was created using
* * Template version 1.0.0
* * ArxtronToolslib version 1.1.0
* * DebugToolslib version 0.0.0
* * GUIToolslib version 0.0.0
*******************************************************************************/

//! \cond
/// REGION START Header
//! \endcond
//==============================================================================
// Include files

#include "LogStruct.h"

//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// Static global variables

//==============================================================================
// Static functions

//==============================================================================
// External variables

double TestTimer;

//==============================================================================
// Global variables

//==============================================================================
// Global functions

void SetTestTimer (void);
void StopTestTimer (double *TimeElapsed);

//! \cond
/// REGION END

/// REGION START Code Body
//! \endcond
/***************************************************************************//*!
* \brief 
*******************************************************************************/
void ParseLogs (char *LogPath, LogStruct *ParsedResults)
{
	FILE* fp = fopen (LogPath, "r");
	
	
	
Error:
	return error;
}


/***************************************************************************//*!
* \brief 
*******************************************************************************/
void SetTestTimer (void)
{
	TestTimer = Timer();
}

/***************************************************************************//*!
* \brief 
*******************************************************************************/
void StopTestTimer (double *TimeElapsed)
{
	*TimeElapsed = Timer() - TestTimer;
}
//! \cond
/// REGION END
//! \endcond