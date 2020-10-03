

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 05:14:07 2038
 */
/* Compiler settings for ModuleConfig.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        EXTERN_C __declspec(selectany) const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif // !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IModuleCallback,0x486F726E,0x4D45,0x49b9,0x8A,0x0C,0xC2,0x2A,0x2B,0x05,0x24,0xE8);


MIDL_DEFINE_GUID(IID, IID_IParamConfig,0x486F726E,0x5043,0x49b9,0x8A,0x0C,0xC2,0x2A,0x2B,0x05,0x24,0xE8);


MIDL_DEFINE_GUID(IID, IID_IModuleConfig,0x486F726E,0x4D43,0x49b9,0x8A,0x0C,0xC2,0x2A,0x2B,0x05,0x24,0xE8);


MIDL_DEFINE_GUID(IID, LIBID_ElecardModuleConfig,0x72BEEB0A,0x94EC,0x4d7e,0x98,0x9E,0xFF,0x40,0x03,0x14,0x47,0xD4);


MIDL_DEFINE_GUID(CLSID, CLSID_ElercardModuleConfig,0x2F2D8000,0xFD54,0x41f6,0x9E,0x30,0x3B,0x52,0x24,0x3B,0x13,0xBD);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



