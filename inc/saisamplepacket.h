/**
* Copyright (c) 2015 Dell Inc.
*
*    Licensed under the Apache License, Version 2.0 (the "License"); you may
*    not use this file except in compliance with the License. You may obtain
*    a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
*
*    THIS CODE IS PROVIDED ON AN  *AS IS* BASIS, WITHOUT WARRANTIES OR
*    CONDITIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT
*    LIMITATION ANY IMPLIED WARRANTIES OR CONDITIONS OF TITLE, FITNESS
*    FOR A PARTICULAR PURPOSE, MERCHANTABLITY OR NON-INFRINGEMENT.
*
*    See the Apache Version 2.0 License for specific language governing
*    permissions and limitations under the License.
*
*/
/**
* Module Name:
*
* saisamplepacket.h
*
* Abstract:
*
* This module defines SAI samplepacket Interface
*
*/

#if !defined (__SAISAMPLEPACKET_H_)
#define __SAISAMPLEPACKET_H_

#include "saitypes.h"
#include "saistatus.h"

/** \defgroup SAISAMPLEPACKET SAI - samplepacket specific public APIs and datastructures
 *
 *  \{
 */

/**
 * @brief SAI type of samplepacket sampling
 */
typedef enum _sai_samplepacket_type_t
{
    /** Copy the sample packets to CPU */
    SAI_SAMPLEPACKET_SLOW_PATH,

} sai_samplepacket_type_t;

/**
  * @brief SAI mode of samplepacket sampling
  */
typedef enum _sai_samplepacket_mode_t
{
    /** A profile defining sample packet attributes. 
      * The profile can be configured on a port or as ACL entry action,
      * in which case, an actual session is instantiated which is private
      * for that port or ACL.
      * In case multiple ports or ACL entries are configured with the same
      * profile, sampling is independently done per port / ACL. */
    SAI_SAMPLEPACKET_MODE_EXCLUSIVE,
    
    /** An instance of sample packet session. 
      * This session can be attached to multiple ports and ACL entries.
      * Traffic going through these ports or matching these ACL entries
      * is merged from a sampling point of view. */
    SAI_SAMPLEPACKET_MODE_SHARED,
    
} sai_samplepacket_mode_t;

/**
 * @brief SAI attributes of samplepacket session
 */
typedef enum _sai_samplepacket_attr_t
{

    /** READ-ONLY */

    /** READ-WRITE */

    /** MANDATORY_ON_CREATE|CREATE_AND_SET */
    /** Sampling rate of type uint32_t. The sampling rate specifies 
      * random sampling probability as the ratio of packets observed 
      * to samples generated. For example a sampling rate of 100 specifies 
      * that, on average, 1 sample will be generated for every 100 packets 
      * observed. */   
    SAI_SAMPLEPACKET_ATTR_SAMPLE_RATE,

    /** CREATE_ONLY */
    /** samplepacket switching type sai_samplepacket_type_t. 
    Default would be SAI_SAMPLEPACKET_SLOW_PATH */
    SAI_SAMPLEPACKET_ATTR_TYPE,
    
    /** CREATE ONLY */
    /** samplepacket mode sai_samplepacket_mode_t. 
    Default would be SAI_SAMPLEPACKET_MODE_EXCLUSIVE */
    SAI_SAMPLEPACKET_ATTR_MODE,

} sai_samplepacket_attr_t;

/**
 * @brief Create samplepacket session.
 *
 * @param[out] session_id samplepacket session id
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Value of attributes
 * @return SAI_STATUS_SUCCESS if operation is successful otherwise a different
 *  error code is returned.
 */
typedef sai_status_t (*sai_create_samplepacket_session_fn)(
        _Out_ sai_object_id_t *session_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);


/**
 * @brief Remove samplepacket session.
 *
 * @param[in] session_id samplepacket session id
 * @return SAI_STATUS_SUCCESS if operation is successful otherwise a different
 *  error code is returned.
 */
typedef sai_status_t (*sai_remove_samplepacket_session_fn)(
        _In_ sai_object_id_t session_id);

/**
 * @brief Set samplepacket session attributes.
 *
 * @param[in] session_id samplepacket session id
 * @param[in] attr Value of attribute
 * @return SAI_STATUS_SUCCESS if operation is successful otherwise a different
 *  error code is returned.
 */
typedef sai_status_t (*sai_set_samplepacket_attribute_fn)(
        _In_ sai_object_id_t session_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get samplepacket session attributes.
 *
 * @param[in] session_id samplepacket session id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Value of attribute
 * @return SAI_STATUS_SUCCESS if operation is successful otherwise a different
 *  error code is returned.
 */
typedef sai_status_t (*sai_get_samplepacket_attribute_fn)(
        _In_ sai_object_id_t session_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief samplepacket method table retrieved with sai_api_query()
 */
typedef struct _sai_samplepacket_api_t
{
    sai_create_samplepacket_session_fn create_samplepacket_session;
    sai_remove_samplepacket_session_fn remove_samplepacket_session;
    sai_set_samplepacket_attribute_fn set_samplepacket_attribute;
    sai_get_samplepacket_attribute_fn get_samplepacket_attribute;
} sai_samplepacket_api_t;

/**
 * \}
 */
#endif // __SAISAMPLEPACKET_H_

