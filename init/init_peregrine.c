/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#include <stdio.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

#include "init_msm.h"

void init_msm_properties(unsigned long msm_id, unsigned long msm_ver, char *board_type)
{
    char platform[PROP_VALUE_MAX];
    char radio[PROP_VALUE_MAX];
    char device[PROP_VALUE_MAX];
    char devicename[PROP_VALUE_MAX];
    int rc;

    UNUSED(msm_id);
    UNUSED(msm_ver);
    UNUSED(board_type);

    rc = property_get("ro.board.platform", platform);
    if (!rc || !ISMATCH(platform, ANDROID_TARGET))
        return;

    property_get("ro.boot.radio", radio);

    if (ISMATCH(radio, "0x1")) {
        /* xt1045*/
        property_set("ro.product.device", "peregrine");
        property_set("ro.product.name", "peregrine_retus");
        property_set("ro.product.model", "XT1045");
        property_set("ro.product.display", "Moto G");
        property_set("ro.build.description", "peregrine_retus-user 4.4.3 KXB21.14-L1.23-4 1 release-keys");
        property_set("ro.build.fingerprint", "motorola/peregrine_retus/peregrine:4.4.3/KXB21.14-L1.23-4/1:user/release-keys");
        property_set("ro.mot.build.customerid", "retus");
        property_set("persist.radio.multisim.config", "");

    } else if (ISMATCH(radio, "0x3")) {
        /* xt1039 */
        property_set("ro.product.device", "peregrine");
        property_set("ro.product.name", "peregrine_retbr");
        property_set("ro.product.model", "XT1039");
        property_set("ro.product.display", "Moto G");
        property_set("ro.build.description", "peregrine_retbr-user 4.4.3 KXB21.14-L1.23-4 5 release-keys");
        property_set("ro.build.fingerprint", "motorola/peregrine_retbr/peregrine:4.4.3/KXB21.14-L1.23-4/5:user/release-keys");
        property_set("ro.mot.build.customerid", "retbr");
        property_set("persist.radio.multisim.config", "");

    } else if (ISMATCH(radio, "0x5")) {
        /*xt1042 */
        property_set("ro.product.device", "peregrine");
        property_set("ro.product.name", "peregrine_usc");
        property_set("ro.product.model", "XT1042");
        property_set("ro.product.display", "Moto G");
        property_set("ro.build.description", "peregrine_usc-user 4.4.4 KXB21.14-L1.41 41 release-keys");
        property_set("ro.build.fingerprint", "motorola/peregrine_usc/peregrine:4.4.4/KXB21.14-L1.41/41:user/release-keys");
        property_set("persist.radio.multisim.config", "");
        property_set("ro.mot.build.customerid ","usc");
        property_set("telephony.lteOnCdmaDevice","1");
        property_set("persist.radio.vrte_logic", "2");
        property_set("persist.radio.0x9e_not_callname", "1");
        property_set("persist.radio.skip_data_check", "1");
        property_set("persist.ril.max.crit.qmi.fails", "4");
        property_set("ro.cdma.data_retry_config", "max_retries=infinite,0,0,10000,10000,100000,10000,10000,10000,10000,140000,540000,960000");
        property_set("ro.gsm.data_retry_config", "default_randomization=2000,max_retries=infinite,1000,1000,80000,125000,485000,905000");
        property_set("ro.com.google.clientidbase.ms", "android-uscellular-us");
        property_set("ro.com.google.clientidbase.am", "android-uscellular-us");
        property_set("ro.com.google.clientidbase.yt", "android-motorola");

     } else if (ISMATCH(radio, "0x7")) {
        /* xt1040 */
        property_set("ro.product.device", "peregrine");
        property_set("ro.product.name", "peregrine_reteu");
        property_set("ro.product.model", "XT1040");
        property_set("ro.product.display", "Moto G");
        property_set("ro.build.description", "peregrine_reteu-user 4.4.4 KXB21.14-L1.46 42 release-keys");
        property_set("ro.build.fingerprint", "motorola/peregrine_reteu/peregrine:4.4.4/KXB21.14-L1.46/42:user/release-keys");
        property_set("ro.mot.build.customerid", "reteuall");
        property_set("persist.radio.multisim.config", "");
    }

    property_get("ro.product.device", device);
    strlcpy(devicename, device, sizeof(devicename));
    INFO("Found radio id %s setting build properties for %s device\n", radio, devicename);
}
