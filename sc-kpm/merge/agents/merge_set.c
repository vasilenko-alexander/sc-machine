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
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with OSTIS. If not, see <http://www.gnu.org/licenses/>.
-----------------------------------------------------------------------------
 */
#include "merge_keynodes.h"
#include "merge_utils.h"

#include <sc_helper.h>
#include <glib.h>
#include <sc_memory_headers.h>

#define MAKE_SC_ADDR_HASH(elem) GINT_TO_POINTER(SC_ADDR_LOCAL_TO_INT(elem))

sc_result agent_set_cantorization(const sc_event *event, sc_addr arg)
{
    sc_addr question, stored_arc;
    sc_iterator3 *it1, *it2;
    gpointer value;
    GHashTable *table;
    //sc_iterator5 *it5, *it_order;

    if (!sc_memory_get_arc_end(arg, &question))
        return SC_RESULT_ERROR_INVALID_PARAMS;

    // check question type
    if (sc_helper_check_arc(keynode_question_set_cantorization, question, sc_type_arc_pos_const_perm) == SC_FALSE)
        return SC_RESULT_ERROR_INVALID_TYPE;

    // get operation argument
    it1 = sc_iterator3_f_a_a_new(question, sc_type_arc_pos_const_perm, 0);
    if (sc_iterator3_next(it1) == SC_TRUE)
    {
        table = g_hash_table_new(nullptr, nullptr);
        // iterate set elements
        it2 = sc_iterator3_f_a_a_new(sc_iterator3_value(it1, 2), sc_type_arc_pos_const_perm, 0);
        while (sc_iterator3_next(it2) == SC_TRUE)
        {
            value = g_hash_table_lookup(table, MAKE_SC_ADDR_HASH(sc_iterator3_value(it2, 2)));
            if (value == NULL)
            {
                g_hash_table_insert(table, MAKE_SC_ADDR_HASH(sc_iterator3_value(it2, 2)), MAKE_SC_ADDR_HASH(sc_iterator3_value(it2, 1)));
            }
            else
            {
                stored_arc = resolve_sc_addr_from_pointer(value);
                merge_sc_elements(stored_arc, sc_iterator3_value(it2, 1));
            }
        }
        sc_iterator3_free(it2);
        g_hash_table_destroy(table);
    }
    sc_iterator3_free(it1);

    finish_question(question);

    return SC_RESULT_OK;
}
