//
// MATLAB Compiler: 7.0.1 (R2019a)
// Date: Mon Jun 10 17:59:18 2019
// Arguments:
// "-B""macro_default""-W""cpplib:xid,all""-T""link:lib""-d""C:\temp\Matlab\wave
// let\Cpp\xid\for_testing""-v""C:\temp\Matlab\wavelet\TVL1denoise.m""C:\temp\Ma
// tlab\wavelet\xid.m"
//

#ifndef __xid_h
#define __xid_h 1

#if defined(__cplusplus) && !defined(mclmcrrt_h) && defined(__linux__)
#  pragma implementation "mclmcrrt.h"
#endif
#include "mclmcrrt.h"
#include "mclcppclass.h"
#ifdef __cplusplus
extern "C" {
#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_xid_C_API 
#define LIB_xid_C_API /* No special import/export declaration */
#endif

/* GENERAL LIBRARY FUNCTIONS -- START */

extern LIB_xid_C_API 
bool MW_CALL_CONV xidInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_xid_C_API 
bool MW_CALL_CONV xidInitialize(void);

extern LIB_xid_C_API 
void MW_CALL_CONV xidTerminate(void);

extern LIB_xid_C_API 
void MW_CALL_CONV xidPrintStackTrace(void);

/* GENERAL LIBRARY FUNCTIONS -- END */

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

extern LIB_xid_C_API 
bool MW_CALL_CONV mlxTVL1denoise(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_xid_C_API 
bool MW_CALL_CONV mlxXid(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */

#ifdef __cplusplus
}
#endif


/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

#ifdef __cplusplus

/* On Windows, use __declspec to control the exported API */
#if defined(_MSC_VER) || defined(__MINGW64__)

#ifdef EXPORTING_xid
#define PUBLIC_xid_CPP_API __declspec(dllexport)
#else
#define PUBLIC_xid_CPP_API __declspec(dllimport)
#endif

#define LIB_xid_CPP_API PUBLIC_xid_CPP_API

#else

#if !defined(LIB_xid_CPP_API)
#if defined(LIB_xid_C_API)
#define LIB_xid_CPP_API LIB_xid_C_API
#else
#define LIB_xid_CPP_API /* empty! */ 
#endif
#endif

#endif

extern LIB_xid_CPP_API void MW_CALL_CONV TVL1denoise(int nargout, mwArray& newim, const mwArray& im, const mwArray& lambda, const mwArray& niter);

extern LIB_xid_CPP_API void MW_CALL_CONV xid(int nargout, mwArray& wavelet_denoised_image, const mwArray& input_image, const mwArray& max_Lambda);

/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */
#endif

#endif
