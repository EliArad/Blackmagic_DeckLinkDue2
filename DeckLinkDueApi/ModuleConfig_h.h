

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


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


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __ModuleConfig_h_h__
#define __ModuleConfig_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IModuleCallback_FWD_DEFINED__
#define __IModuleCallback_FWD_DEFINED__
typedef interface IModuleCallback IModuleCallback;

#endif 	/* __IModuleCallback_FWD_DEFINED__ */


#ifndef __IParamConfig_FWD_DEFINED__
#define __IParamConfig_FWD_DEFINED__
typedef interface IParamConfig IParamConfig;

#endif 	/* __IParamConfig_FWD_DEFINED__ */


#ifndef __IModuleConfig_FWD_DEFINED__
#define __IModuleConfig_FWD_DEFINED__
typedef interface IModuleConfig IModuleConfig;

#endif 	/* __IModuleConfig_FWD_DEFINED__ */


#ifndef __ElercardModuleConfig_FWD_DEFINED__
#define __ElercardModuleConfig_FWD_DEFINED__

#ifdef __cplusplus
typedef class ElercardModuleConfig ElercardModuleConfig;
#else
typedef struct ElercardModuleConfig ElercardModuleConfig;
#endif /* __cplusplus */

#endif 	/* __ElercardModuleConfig_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_ModuleConfig_0000_0000 */
/* [local] */ 

//////////////////////////////////////////////////////////////////////////
//
//	original file name: ModuleConfig.idl
//
//////////////////////////////////////////////////////////////////////////
//
//	Copyright (c) 2005 Elecard Ltd.
//	All rights are reserved.  Reproduction in whole or in part is prohibited
//	without the written consent of the copyright owner.
//
//	Elecard Ltd. reserves the right to make changes without
//	notice at any time. Elecard Ltd. makes no warranty, expressed,
//	implied or statutory, including but not limited to any implied
//	warranty of merchantability of fitness for any particular purpose,
//	or that the use will not infringe any third party patent, copyright
//	or trademark.
//
//	Elecard Ltd. must not be liable for any loss or damage arising
//	from its use.
//
//////////////////////////////////////////////////////////////////////////
//
//	author of original IDL file:  Alexander Ivanov
//
//	purpose: ModuleConfig interfaces definitions
//
//////////////////////////////////////////////////////////////////////////


// {486F726E-4D45-49b9-8A0C-C22A2B0524E8}
DEFINE_GUID(IID_IModuleCallback, 0x486F726E, 0x4D45, 0x49b9, 0x8A, 0x0C, 0xC2, 0x2A, 0x2B, 0x05, 0x24, 0xE8);

// {486F726E-4D43-49b9-8A0C-C22A2B0524E8}
DEFINE_GUID(IID_IModuleConfig, 0x486F726E, 0x4D43, 0x49b9, 0x8A, 0x0C, 0xC2, 0x2A, 0x2B, 0x05, 0x24, 0xE8);

// {486F726E-5043-49b9-8A0C-C22A2B0524E8}
DEFINE_GUID(IID_IParamConfig, 0x486F726E, 0x5043, 0x49b9, 0x8A, 0x0C, 0xC2, 0x2A, 0x2B, 0x05, 0x24, 0xE8);



extern RPC_IF_HANDLE __MIDL_itf_ModuleConfig_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ModuleConfig_0000_0000_v0_0_s_ifspec;

#ifndef __IModuleCallback_INTERFACE_DEFINED__
#define __IModuleCallback_INTERFACE_DEFINED__

/* interface IModuleCallback */
/* [unique][uuid][local][object] */ 


EXTERN_C const IID IID_IModuleCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("486F726E-4D45-49b9-8A0C-C22A2B0524E8")
    IModuleCallback : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnModuleNotify( 
            /* [in] */ const long cParams,
            /* [in] */ GUID *pParamIDs) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IModuleCallbackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IModuleCallback * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IModuleCallback * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IModuleCallback * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OnModuleNotify )( 
            IModuleCallback * This,
            /* [in] */ const long cParams,
            /* [in] */ GUID *pParamIDs);
        
        END_INTERFACE
    } IModuleCallbackVtbl;

    interface IModuleCallback
    {
        CONST_VTBL struct IModuleCallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IModuleCallback_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IModuleCallback_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IModuleCallback_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IModuleCallback_OnModuleNotify(This,cParams,pParamIDs)	\
    ( (This)->lpVtbl -> OnModuleNotify(This,cParams,pParamIDs) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IModuleCallback_INTERFACE_DEFINED__ */


#ifndef __IParamConfig_INTERFACE_DEFINED__
#define __IParamConfig_INTERFACE_DEFINED__

/* interface IParamConfig */
/* [unique][uuid][local][object] */ 


EXTERN_C const IID IID_IParamConfig;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("486F726E-5043-49b9-8A0C-C22A2B0524E8")
    IParamConfig : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetValue( 
            /* [in] */ const VARIANT *pValue,
            /* [in] */ BOOL bSetAndCommit) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetValue( 
            /* [out] */ VARIANT *pValue,
            /* [in] */ BOOL bGetCommitted) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetVisible( 
            BOOL bVisible) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetVisible( 
            BOOL *bVisible) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetParamID( 
            GUID *pParamID) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetName( 
            /* [out] */ BSTR *pName) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetReadOnly( 
            BOOL *bReadOnly) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetFullInfo( 
            /* [out] */ VARIANT *pValue,
            /* [out] */ BSTR *pMeaning,
            /* [out] */ BSTR *pName,
            /* [out] */ BOOL *bReadOnly,
            /* [out] */ BOOL *pVisible) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetDefValue( 
            /* [out] */ VARIANT *pValue) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetValidRange( 
            /* [out] */ VARIANT *pMinValue,
            /* [out] */ VARIANT *pMaxValue,
            /* [out] */ VARIANT *pDelta) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE EnumValidValues( 
            /* [out][in] */ long *pNumValidValues,
            /* [out][in] */ VARIANT *pValidValues,
            /* [out][in] */ BSTR *pValueNames) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ValueToMeaning( 
            /* [in] */ const VARIANT *pValue,
            /* [out] */ BSTR *pMeaning) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE MeaningToValue( 
            /* [in] */ const BSTR pMeaning,
            /* [out] */ VARIANT *pValue) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IParamConfigVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IParamConfig * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IParamConfig * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IParamConfig * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetValue )( 
            IParamConfig * This,
            /* [in] */ const VARIANT *pValue,
            /* [in] */ BOOL bSetAndCommit);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetValue )( 
            IParamConfig * This,
            /* [out] */ VARIANT *pValue,
            /* [in] */ BOOL bGetCommitted);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetVisible )( 
            IParamConfig * This,
            BOOL bVisible);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetVisible )( 
            IParamConfig * This,
            BOOL *bVisible);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetParamID )( 
            IParamConfig * This,
            GUID *pParamID);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IParamConfig * This,
            /* [out] */ BSTR *pName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetReadOnly )( 
            IParamConfig * This,
            BOOL *bReadOnly);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetFullInfo )( 
            IParamConfig * This,
            /* [out] */ VARIANT *pValue,
            /* [out] */ BSTR *pMeaning,
            /* [out] */ BSTR *pName,
            /* [out] */ BOOL *bReadOnly,
            /* [out] */ BOOL *pVisible);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetDefValue )( 
            IParamConfig * This,
            /* [out] */ VARIANT *pValue);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetValidRange )( 
            IParamConfig * This,
            /* [out] */ VARIANT *pMinValue,
            /* [out] */ VARIANT *pMaxValue,
            /* [out] */ VARIANT *pDelta);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *EnumValidValues )( 
            IParamConfig * This,
            /* [out][in] */ long *pNumValidValues,
            /* [out][in] */ VARIANT *pValidValues,
            /* [out][in] */ BSTR *pValueNames);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ValueToMeaning )( 
            IParamConfig * This,
            /* [in] */ const VARIANT *pValue,
            /* [out] */ BSTR *pMeaning);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *MeaningToValue )( 
            IParamConfig * This,
            /* [in] */ const BSTR pMeaning,
            /* [out] */ VARIANT *pValue);
        
        END_INTERFACE
    } IParamConfigVtbl;

    interface IParamConfig
    {
        CONST_VTBL struct IParamConfigVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IParamConfig_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IParamConfig_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IParamConfig_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IParamConfig_SetValue(This,pValue,bSetAndCommit)	\
    ( (This)->lpVtbl -> SetValue(This,pValue,bSetAndCommit) ) 

#define IParamConfig_GetValue(This,pValue,bGetCommitted)	\
    ( (This)->lpVtbl -> GetValue(This,pValue,bGetCommitted) ) 

#define IParamConfig_SetVisible(This,bVisible)	\
    ( (This)->lpVtbl -> SetVisible(This,bVisible) ) 

#define IParamConfig_GetVisible(This,bVisible)	\
    ( (This)->lpVtbl -> GetVisible(This,bVisible) ) 

#define IParamConfig_GetParamID(This,pParamID)	\
    ( (This)->lpVtbl -> GetParamID(This,pParamID) ) 

#define IParamConfig_GetName(This,pName)	\
    ( (This)->lpVtbl -> GetName(This,pName) ) 

#define IParamConfig_GetReadOnly(This,bReadOnly)	\
    ( (This)->lpVtbl -> GetReadOnly(This,bReadOnly) ) 

#define IParamConfig_GetFullInfo(This,pValue,pMeaning,pName,bReadOnly,pVisible)	\
    ( (This)->lpVtbl -> GetFullInfo(This,pValue,pMeaning,pName,bReadOnly,pVisible) ) 

#define IParamConfig_GetDefValue(This,pValue)	\
    ( (This)->lpVtbl -> GetDefValue(This,pValue) ) 

#define IParamConfig_GetValidRange(This,pMinValue,pMaxValue,pDelta)	\
    ( (This)->lpVtbl -> GetValidRange(This,pMinValue,pMaxValue,pDelta) ) 

#define IParamConfig_EnumValidValues(This,pNumValidValues,pValidValues,pValueNames)	\
    ( (This)->lpVtbl -> EnumValidValues(This,pNumValidValues,pValidValues,pValueNames) ) 

#define IParamConfig_ValueToMeaning(This,pValue,pMeaning)	\
    ( (This)->lpVtbl -> ValueToMeaning(This,pValue,pMeaning) ) 

#define IParamConfig_MeaningToValue(This,pMeaning,pValue)	\
    ( (This)->lpVtbl -> MeaningToValue(This,pMeaning,pValue) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IParamConfig_INTERFACE_DEFINED__ */


#ifndef __IModuleConfig_INTERFACE_DEFINED__
#define __IModuleConfig_INTERFACE_DEFINED__

/* interface IModuleConfig */
/* [unique][uuid][local][object] */ 


EXTERN_C const IID IID_IModuleConfig;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("486F726E-4D43-49b9-8A0C-C22A2B0524E8")
    IModuleConfig : public IPersistStream
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetValue( 
            /* [in] */ const GUID *pParamID,
            /* [in] */ const VARIANT *pValue) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetValue( 
            /* [in] */ const GUID *pParamID,
            /* [out] */ VARIANT *pValue) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetParamConfig( 
            /* [in] */ const GUID *pParamID,
            /* [out] */ IParamConfig **pValue) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE IsSupported( 
            /* [in] */ const GUID *pParamID) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetDefState( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE EnumParams( 
            /* [out][in] */ long *pNumParams,
            /* [out][in] */ GUID *pParamIDs) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CommitChanges( 
            /* [out] */ VARIANT *pReason) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE DeclineChanges( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SaveToRegistry( 
            /* [in] */ HKEY hKeyRoot,
            /* [in] */ const BSTR pszKeyName,
            /* [in] */ const BOOL bPreferReadable) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE LoadFromRegistry( 
            /* [in] */ HKEY hKeyRoot,
            /* [in] */ const BSTR pszKeyName,
            /* [in] */ const BOOL bPreferReadable) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RegisterForNotifies( 
            /* [in] */ IModuleCallback *pModuleCallback) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE UnregisterFromNotifies( 
            /* [in] */ IModuleCallback *pModuleCallback) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IModuleConfigVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IModuleConfig * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IModuleConfig * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IModuleConfig * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetClassID )( 
            IModuleConfig * This,
            /* [out] */ CLSID *pClassID);
        
        HRESULT ( STDMETHODCALLTYPE *IsDirty )( 
            IModuleConfig * This);
        
        HRESULT ( STDMETHODCALLTYPE *Load )( 
            IModuleConfig * This,
            /* [unique][in] */ IStream *pStm);
        
        HRESULT ( STDMETHODCALLTYPE *Save )( 
            IModuleConfig * This,
            /* [unique][in] */ IStream *pStm,
            /* [in] */ BOOL fClearDirty);
        
        HRESULT ( STDMETHODCALLTYPE *GetSizeMax )( 
            IModuleConfig * This,
            /* [out] */ ULARGE_INTEGER *pcbSize);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetValue )( 
            IModuleConfig * This,
            /* [in] */ const GUID *pParamID,
            /* [in] */ const VARIANT *pValue);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetValue )( 
            IModuleConfig * This,
            /* [in] */ const GUID *pParamID,
            /* [out] */ VARIANT *pValue);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetParamConfig )( 
            IModuleConfig * This,
            /* [in] */ const GUID *pParamID,
            /* [out] */ IParamConfig **pValue);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *IsSupported )( 
            IModuleConfig * This,
            /* [in] */ const GUID *pParamID);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetDefState )( 
            IModuleConfig * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *EnumParams )( 
            IModuleConfig * This,
            /* [out][in] */ long *pNumParams,
            /* [out][in] */ GUID *pParamIDs);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CommitChanges )( 
            IModuleConfig * This,
            /* [out] */ VARIANT *pReason);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *DeclineChanges )( 
            IModuleConfig * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SaveToRegistry )( 
            IModuleConfig * This,
            /* [in] */ HKEY hKeyRoot,
            /* [in] */ const BSTR pszKeyName,
            /* [in] */ const BOOL bPreferReadable);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *LoadFromRegistry )( 
            IModuleConfig * This,
            /* [in] */ HKEY hKeyRoot,
            /* [in] */ const BSTR pszKeyName,
            /* [in] */ const BOOL bPreferReadable);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RegisterForNotifies )( 
            IModuleConfig * This,
            /* [in] */ IModuleCallback *pModuleCallback);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *UnregisterFromNotifies )( 
            IModuleConfig * This,
            /* [in] */ IModuleCallback *pModuleCallback);
        
        END_INTERFACE
    } IModuleConfigVtbl;

    interface IModuleConfig
    {
        CONST_VTBL struct IModuleConfigVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IModuleConfig_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IModuleConfig_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IModuleConfig_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IModuleConfig_GetClassID(This,pClassID)	\
    ( (This)->lpVtbl -> GetClassID(This,pClassID) ) 


#define IModuleConfig_IsDirty(This)	\
    ( (This)->lpVtbl -> IsDirty(This) ) 

#define IModuleConfig_Load(This,pStm)	\
    ( (This)->lpVtbl -> Load(This,pStm) ) 

#define IModuleConfig_Save(This,pStm,fClearDirty)	\
    ( (This)->lpVtbl -> Save(This,pStm,fClearDirty) ) 

#define IModuleConfig_GetSizeMax(This,pcbSize)	\
    ( (This)->lpVtbl -> GetSizeMax(This,pcbSize) ) 


#define IModuleConfig_SetValue(This,pParamID,pValue)	\
    ( (This)->lpVtbl -> SetValue(This,pParamID,pValue) ) 

#define IModuleConfig_GetValue(This,pParamID,pValue)	\
    ( (This)->lpVtbl -> GetValue(This,pParamID,pValue) ) 

#define IModuleConfig_GetParamConfig(This,pParamID,pValue)	\
    ( (This)->lpVtbl -> GetParamConfig(This,pParamID,pValue) ) 

#define IModuleConfig_IsSupported(This,pParamID)	\
    ( (This)->lpVtbl -> IsSupported(This,pParamID) ) 

#define IModuleConfig_SetDefState(This)	\
    ( (This)->lpVtbl -> SetDefState(This) ) 

#define IModuleConfig_EnumParams(This,pNumParams,pParamIDs)	\
    ( (This)->lpVtbl -> EnumParams(This,pNumParams,pParamIDs) ) 

#define IModuleConfig_CommitChanges(This,pReason)	\
    ( (This)->lpVtbl -> CommitChanges(This,pReason) ) 

#define IModuleConfig_DeclineChanges(This)	\
    ( (This)->lpVtbl -> DeclineChanges(This) ) 

#define IModuleConfig_SaveToRegistry(This,hKeyRoot,pszKeyName,bPreferReadable)	\
    ( (This)->lpVtbl -> SaveToRegistry(This,hKeyRoot,pszKeyName,bPreferReadable) ) 

#define IModuleConfig_LoadFromRegistry(This,hKeyRoot,pszKeyName,bPreferReadable)	\
    ( (This)->lpVtbl -> LoadFromRegistry(This,hKeyRoot,pszKeyName,bPreferReadable) ) 

#define IModuleConfig_RegisterForNotifies(This,pModuleCallback)	\
    ( (This)->lpVtbl -> RegisterForNotifies(This,pModuleCallback) ) 

#define IModuleConfig_UnregisterFromNotifies(This,pModuleCallback)	\
    ( (This)->lpVtbl -> UnregisterFromNotifies(This,pModuleCallback) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IModuleConfig_INTERFACE_DEFINED__ */



#ifndef __ElecardModuleConfig_LIBRARY_DEFINED__
#define __ElecardModuleConfig_LIBRARY_DEFINED__

/* library ElecardModuleConfig */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_ElecardModuleConfig;

EXTERN_C const CLSID CLSID_ElercardModuleConfig;

#ifdef __cplusplus

class DECLSPEC_UUID("2F2D8000-FD54-41f6-9E30-3B52243B13BD")
ElercardModuleConfig;
#endif
#endif /* __ElecardModuleConfig_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


