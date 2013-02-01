#ifndef SC_SEARCH_SYSTEM_H
#define SC_SEARCH_SYSTEM_H

extern "C"
{
#include "sc_memory.h"
}
#include <map>
#include <vector>

struct sc_addr_comparator
{
    bool operator()(const sc_addr s1, const sc_addr s2) const
    {
        return (SC_ADDR_LOCAL_TO_INT(s1) < SC_ADDR_LOCAL_TO_INT(s2));
    }
};

typedef std::map<sc_addr,sc_addr,sc_addr_comparator> sc_type_result;
typedef std::map<int,sc_addr> sc_type_hash;
typedef std::vector<sc_type_result*> sc_type_result_vector;
typedef std::vector<sc_addr> sc_addr_vector;
typedef std::pair<sc_addr,sc_addr> sc_addr_pair;
typedef std::pair<int,sc_addr> sc_hash_pair;

/*! Search fully isomorfic construction, if impossible -
 *  the closest to fully isomorfic construction
 * @param pattern Search pattern
 * @param params Search parameters. Can be empty
 * @param result Set of results. Number depends on possible
 * isomorfic construction count. If fully isomorfic construction
 * can't be found the best results by element count are given.
 * @return If input params are correct and search completed without errors, then return SC_OK;
 * otherwise return SC_ERROR
 */
sc_result system_sys_search(sc_addr pattern, sc_type_result params, sc_type_result_vector *result);

/*! Search fully isomorfic construction just to check such a construction existence
 * @param pattern Search pattern
 * @param params Search parameters. Can be empty
 * @param result Boolean result. SC_TRUE if fully isomorfic construction exists. SC_FALSE otherwise.
 * @return If input params are correct and search completed without errors, then return SC_OK;
 * otherwise return SC_ERROR
 */
sc_result system_sys_search_single(sc_addr pattern, sc_type_result params, sc_bool *result);

/*! Search only fully isomorfic construction to given pattern
 * @param pattern Search pattern
 * @param params Search parameters. Can be empty
 * @param result Set of results. Number depends on possible isomorfic construction count.
 * @return If input params are correct and search completed without errors, then return SC_OK;
 * otherwise return SC_ERROR
 */
sc_result system_sys_search_only_full(sc_addr pattern, sc_type_result params, sc_type_result_vector *result);

/*! Search only fully isomorfic construction to given pattern, leaving correspondences only for requested elements
 * @param pattern Search pattern
 * @param params Search parameters. Can be empty
 * @param requested_values Variables, for which correspondence pairs will be built
 * @param result Set of results. Number depends on possible isomorfic construction count.
 * Contains only correspondences for requested elements
 * @return If input params are correct and search completed without errors, then return SC_OK;
 * otherwise return SC_ERROR
 */
sc_result system_sys_search_for_variables(sc_addr pattern, sc_type_result params, sc_addr_vector requested_values, sc_type_result_vector *result);


#endif // SC_SEARCH_SYSTEM_H