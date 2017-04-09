
/********************************************************************/
/* Copyright (C) SSE@USTCSZ, 2012                                   */
/*                                                                  */
/*  FILE NAME             :  main.c                                 */
/*  PRINCIPAL AUTHOR      :  Mengning                               */
/*  SUBSYSTEM NAME        :                                         */
/*  MODULE NAME           :                                         */
/*  LANGUAGE              :  C                                      */
/*  TARGET ENVIRONMENT    :  ANY                                    */
/*  DATE OF FIRST RELEASE :  2012/5/3                               */
/*  DESCRIPTION           :  Main program                           */
/********************************************************************/

/*
 * Revision log:
 *
 * Created by Mengning,2012/5/3
 *
 */


#include <stdio.h>

#include "shlibexample.h" 

#include <dlfcn.h>

/*
 * Main program
 * input	: none
 * output	: none
 * return	: SUCCESS(0)/FAILURE(-1)
 *
 */
int main()
{
    printf("This is a Main program!\n");
    /* Use Shared Lib */
    printf("Calling SharedLibApi() function of libshlibexample.so!\n");
    SharedLibApi();
    /* Use Dynamical Loading Lib */
    void * handle = dlopen("libdllibexample.so",RTLD_NOW);
    if(handle == NULL)
    {
        printf("Open Lib libdllibexample.so Error:%s\n",dlerror());
        return   FAILURE;
    }
    int (*func)(void);
    char * error;
    func = dlsym(handle,"DynamicalLoadingLibApi");
    if((error = dlerror()) != NULL)
    {
        printf("DynamicalLoadingLibApi not found:%s\n",error);
        return   FAILURE;
    }    
    printf("Calling DynamicalLoadingLibApi() function of libdllibexample.so!\n");
    func();  
    dlclose(handle);       
    return SUCCESS;
}




