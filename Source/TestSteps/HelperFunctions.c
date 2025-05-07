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

#include <utility.h>
#include <ansi_c.h>
#include "HelperFunctions.h"

//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// Static global variables

//==============================================================================
// Static functions

//==============================================================================
// Global variables

#define MAX_LINE_LEN 1024
extern double TestTimer;

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
	if (!fp) 
	{
		perror("Couldn't open file");
	}
	
	char line[MAX_LINE_LEN];
	int count = 0;
	
	// Read file, parse usling delimiter (comma)
	while (count < 5)
	{
		char *token = strtok(line, ",");
		if (!token) continue;
		
		switch (count % 5)
		{
			case 0:
				strncpy(ParsedResults->TestName, token, MAX_LINE_LEN);
			
			case 1:
				ParsedResults->TestNum = atoi(token);
			
			case 2:
				strncpy(ParsedResults->TestVal, token, MAX_LINE_LEN);
			
			case 3:
				strncpy(ParsedResults->TestLoLim, token, MAX_LINE_LEN);
				
			case 4:
				strncpy(ParsedResults->TestHiLim, token, MAX_LINE_LEN);
		}
		
		count++;
	}	
		   
	fclose(fp);
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
	// If the timer has not started, return 0
	if (!TestTimer)
	{
		perror("TestTimer has not been set.");
		return;
	}
	
	*TimeElapsed = Timer() - TestTimer;
}

/***************************************************************************//*!
* \brief 
*******************************************************************************/
void IntArrToCharArr (int *IntArr, int IntArrSize, char **CharArr)
{	
	// Iterate through each int, convert to string
	for (int i = 0; i < IntArrSize; i++)
	{
		char string[128];
		
		sprintf(string, "%d", IntArr[i]);
		
		CharArr[i] = string;
	}
}
//! \cond
/// REGION END
//! \endcond