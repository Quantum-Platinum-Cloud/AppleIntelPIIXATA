/*
 * Copyright (c) 1998-2003 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * Copyright (c) 1999-2003 Apple Computer, Inc.  All Rights Reserved.
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */

#ifndef _APPLEINTELPIIXATACHANNEL_H
#define _APPLEINTELPIIXATACHANNEL_H

#include <IOKit/IOService.h>

class AppleIntelPIIXATAChannel : public IOService
{
    OSDeclareDefaultStructors( AppleIntelPIIXATAChannel )

protected:
    IOService *    _provider;
    UInt16         _cmdBlock;
    UInt16         _ctrBlock;
    UInt8          _irq;
    UInt8          _pioModeMask;
    UInt8          _dmaModeMask;
    UInt8          _udmaModeMask;
    UInt32         _channelNum;
    UInt32         _channelMode;
    const char *   _controllerName;
    bool           _hasSharedDriveTimings;

    virtual bool   getNumberValue( const char * propKey,
                                   void       * outValue,
                                   UInt32       outBits );

    virtual bool   setupInterrupt( IOService * provider, UInt32 line );

    virtual void   mergeProperties( OSDictionary * properties );

public:
    virtual bool   init( IOService *       provider,
                         OSDictionary *    properties,
                         IORegistryEntry * dtEntry = 0 );

    virtual bool   matchPropertyTable( OSDictionary * table,
                                       SInt32 *       score );

    virtual UInt16 getCommandBlockAddress( void ) const;

    virtual UInt16 getControlBlockAddress( void ) const;

    virtual UInt8  getInterruptVector( void ) const;

    virtual UInt8  getPIOModeMask( void ) const;

    virtual UInt8  getDMAModeMask( void ) const;

    virtual UInt8  getUltraDMAModeMask( void ) const;

    virtual UInt32 getChannelNumber( void ) const;

    virtual UInt32 getChannelMode( void ) const;

    virtual bool   hasSharedDriveTimings( void ) const;

    virtual const char * getControllerName( void ) const;

    virtual bool   isSerialATAChannel( void ) const;

    virtual UInt32 getMaxDriveUnits( void ) const;

    virtual UInt32 getSerialATAPortForDrive( UInt32 unit ) const;

    virtual bool   handleOpen( IOService *  client,
                               IOOptionBits options,
                               void *       arg );

    virtual void   handleClose( IOService *  client,
                                IOOptionBits options );

    virtual void   pciConfigWrite8( UInt8 offset,
                                    UInt8 data,
                                    UInt8 mask = 0xff );

    virtual void   pciConfigWrite16( UInt8  offset,
                                     UInt16 data,
                                     UInt16 mask = 0xffff );
};

#endif /* !_APPLEINTELPIIXATACHANNEL_H */