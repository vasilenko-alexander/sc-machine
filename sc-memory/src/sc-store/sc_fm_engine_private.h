/*
-----------------------------------------------------------------------------
This source file is part of OSTIS (Open Semantic Technology for Intelligent Systems)
For the latest info, see http://www.ostis.net

Copyright (c) 2010-2014 OSTIS

OSTIS is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

OSTIS is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with OSTIS.  If not, see <http://www.gnu.org/licenses/>.
-----------------------------------------------------------------------------
*/

#ifndef _sc_fm_engine_private_h_
#define _sc_fm_engine_private_h_

#include "sc_fm_engine.h"

//! Pointer to function, that create stream for data reading/witing
typedef sc_result (*fEngineStreamCreate)(const sc_fm_engine *engine, const sc_check_sum *check_sum, sc_uint8 flags, sc_stream **stream);
//! Pointer to function, that appends reference to the sc-addr that designates sc-link with specified data
typedef sc_result (*fEngineAddrRefAppend)(const sc_fm_engine *engine, sc_addr addr, const sc_check_sum *check_sum);
//! Pointer to function, that removes reference to the sc-addr for specified sc-link
typedef sc_result (*fEngineAddrRefRemove)(const sc_fm_engine *engine, sc_addr addr, const sc_check_sum *check_sum);
//! Pointer to function, that finds all links with specified content
typedef sc_result (*fEngineFind)(const sc_fm_engine *engine, const sc_check_sum *check_sum, sc_addr **result, sc_uint32 *result_count);
//! Function to clear file memory
typedef sc_result (*fEngineClear)(const sc_fm_engine *engine);
//! Funciton to save file memory state
typedef sc_result (*fEngineSave)(const sc_fm_engine *engine);
//! Pointer to function, that destroys storage specified data
typedef sc_result (*fEngineDestroyData)(const sc_fm_engine *engine);


/*! Sturcture that provides file memory storage engine object
 */
struct _sc_fm_engine
{
    //! Pointer to storage specified data
    void *storage_info;

    fEngineStreamCreate funcStreamCreate;
    fEngineAddrRefAppend funcAddrRefAppend;
    fEngineAddrRefRemove funcAddrRefRemove;
    fEngineFind funcFind;
    fEngineClear funcClear;
    fEngineSave funcSave;
    fEngineDestroyData funcDestroyData;
};




#endif // _sc_fs_storage_private_h_
