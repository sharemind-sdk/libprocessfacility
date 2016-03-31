/*
 * Copyright (C) 2015 Cybernetica
 *
 * Research/Commercial License Usage
 * Licensees holding a valid Research License or Commercial License
 * for the Software may use this file according to the written
 * agreement between you and Cybernetica.
 *
 * GNU General Public License Usage
 * Alternatively, this file may be used under the terms of the GNU
 * General Public License version 3.0 as published by the Free Software
 * Foundation and appearing in the file LICENSE.GPL included in the
 * packaging of this file.  Please review the following information to
 * ensure the GNU General Public License version 3.0 requirements will be
 * met: http://www.gnu.org/copyleft/gpl-3.0.html.
 *
 * For further information, please contact us at sharemind@cyber.ee.
 */

#ifndef SHAREMIND_LIBPROCESSFACILITY_H
#define SHAREMIND_LIBPROCESSFACILITY_H

#ifdef __cplusplus
#include <cstdint>
#endif
#include <sharemind/extern_c.h>
#include <sharemind/libmodapi/api_0x1.h>
#ifndef __cplusplus
#include <stdint.h>
#endif


#ifndef SHAREMIND_ICONST
#ifdef SHAREMIND_INTERNAL_
#define SHAREMIND_ICONST
#else
#define SHAREMIND_ICONST const
#endif
#endif /* SHAREMIND_ICONST */

SHAREMIND_EXTERN_C_BEGIN

typedef uint64_t SharemindProcessId;

struct SharemindProcessFacility_;
typedef struct SharemindProcessFacility_ SharemindProcessFacility;
struct SharemindProcessFacility_ {

    SharemindProcessId (* SHAREMIND_ICONST get_process_id)(
            SharemindProcessFacility const * facility);

    char const * (* SHAREMIND_ICONST printableId)(
            SharemindProcessFacility const * facility);

};

SHAREMIND_EXTERN_C_END

#endif /* SHAREMIND_LIBPROCESSFACILITY_H */
