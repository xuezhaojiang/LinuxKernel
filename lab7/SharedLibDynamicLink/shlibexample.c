
/********************************************************************/
/* Copyright (C) SSE@USTCSZ, 2012                                   */
/*                                                                  */
/*  FILE NAME             :  shlibexample.c                         */
/*  PRINCIPAL AUTHOR      :  Mengning                               */
/*  SUBSYSTEM NAME        :                                         */
/*  MODULE NAME           :                                         */
/*  LANGUAGE              :  C                                      */
/*  TARGET ENVIRONMENT    :  ANY                                    */
/*  DATE OF FIRST RELEASE :  2012/5/3                               */
/*  DESCRIPTION           :  Implement of Shared Lib Example        */
/********************************************************************/

/*
 * Revision log:
 *
 * Created by Mengning,2012/5/3
 *
 */


#include <stdio.h>
#include "shlibexample.h"

/*
 * Shared Lib API Example
 * input	: none
 * output	: none
 * return	: SUCCESS(0)/FAILURE(-1)
 *
 */
int SharedLibApi()
{
    printf("This is a shared libary!\n");
    return SUCCESS;
}




