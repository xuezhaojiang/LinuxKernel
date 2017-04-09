
/********************************************************************/
/* Copyright (C) SSE@USTCSZ, 2012                                   */
/*                                                                  */
/*  FILE NAME             :  shlibexample.h                         */
/*  PRINCIPAL AUTHOR      :  Mengning                               */
/*  SUBSYSTEM NAME        :                                         */
/*  MODULE NAME           :                                         */
/*  LANGUAGE              :  C                                      */
/*  TARGET ENVIRONMENT    :  ANY                                    */
/*  DATE OF FIRST RELEASE :  2012/5/3                               */
/*  DESCRIPTION           :  Interface of Shared Lib Example        */
/********************************************************************/

/*
 * Revision log:
 *
 * Created by Mengning,2012/5/3
 *
 */

#ifndef _SH_LIB_EXAMPLE_H_
#define _SH_LIB_EXAMPLE_H_

#define SUCCESS 0
#define FAILURE (-1)

#ifdef __cplusplus
extern "C" {
#endif
/*
 * Shared Lib API Example
 * input	: none
 * output	: none
 * return	: SUCCESS(0)/FAILURE(-1)
 *
 */
int SharedLibApi();


#ifdef __cplusplus
}
#endif
#endif /* _SH_LIB_EXAMPLE_H_ */


