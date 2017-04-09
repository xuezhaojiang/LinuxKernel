
/********************************************************************/
/* Copyright (C) SSE@USTCSZ, 2012                                   */
/*                                                                  */
/*  FILE NAME             :  dllibexample.c                         */
/*  PRINCIPAL AUTHOR      :  Mengning                               */
/*  SUBSYSTEM NAME        :                                         */
/*  MODULE NAME           :                                         */
/*  LANGUAGE              :  C                                      */
/*  TARGET ENVIRONMENT    :  ANY                                    */
/*  DATE OF FIRST RELEASE :  2012/5/3                               */
/*  DESCRIPTION           :  Implement of Dynamical Loading         */
/*                           Lib Example                            */
/********************************************************************/

/*
 * Revision log:
 *
 * Created by Mengning,2012/5/3
 *
 */

#include <stdio.h>
#include "dllibexample.h"

#define SUCCESS 0
#define FAILURE (-1)

/*
 * Dynamical Loading Lib API Example
 * input	: none
 * output	: none
 * return	: SUCCESS(0)/FAILURE(-1)
 *
 */
int DynamicalLoadingLibApi()
{
    printf("This is a Dynamical Loading libary!\n");
    return SUCCESS;
}
