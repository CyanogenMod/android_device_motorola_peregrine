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

#define ISMATCH(a,b)    (!strncmp(a,b,PROP_VALUE_MAX))

void gsm_properties();
void cdma_properties(const char *cdma_sub);

void vendor_load_properties()
{
    char platform[PROP_VALUE_MAX];
    char radio[PROP_VALUE_MAX];
    char device[PROP_VALUE_MAX];
    char devicename[PROP_VALUE_MAX];
    int rc;

    rc = property_get("ro.board.platform", platform);
    if (!rc || !ISMATCH(platform, ANDROID_TARGET))
        return;

    property_get("ro.boot.radio", radio);

    if (ISMATCH(radio, "0x1")) {
        /* xt1045*/
        gsm_properties();
        property_set("ro.product.device", "peregrine");
        property_set("ro.product.model", "XT1045");
        property_set("ro.product.display", "Moto G");
        property_set("ro.build.description", "peregrine_retus-user 5.1 LPB23.13-37 37 release-keys");
        property_set("ro.build.fingerprint", "motorola/peregrine_retus/peregrine:5.1/LPB23.13-37/37:user/release-keys");
        property_set("ro.mot.build.customerid", "retus");
        property_set("persist.radio.multisim.config", "");

    } else if (ISMATCH(radio, "0x3")) {
        /* xt1039 */
        gsm_properties();
        property_set("ro.product.device", "peregrine");
        property_set("ro.product.model", "XT1039");
        property_set("ro.product.display", "Moto G");
        property_set("ro.build.description", "peregrine_reteu-user 5.1 LPB23.13-17 18 release-keys");
        property_set("ro.build.fingerprint", "motorola/peregrine_reteu/peregrine:5.1/LPB23.13-17/18:user/release-keys");
        property_set("ro.mot.build.customerid", "reteu");
        property_set("persist.radio.multisim.config", "");

    } else if (ISMATCH(radio, "0x5")) {
        /*xt1042 */
        cdma_properties("0");
        property_set("ro.product.device", "peregrine");
        property_set("ro.product.model", "XT1042");
        property_set("ro.product.display", "Moto G");
        property_set("ro.build.description", "peregrine_usc-user 4.4.4 KXB21.14-L1.41 41 release-keys");
        property_set("ro.build.fingerprint", "motorola/peregrine_usc/peregrine:4.4.4/KXB21.14-L1.41/41:user/release-keys");
        property_set("persist.radio.multisim.config", "");
        property_set("ro.mot.build.customerid ","usc");
        property_set("ro.com.android.dataroaming","true");
        property_set("ro.mot.ignore_csim_appid","true");
        property_set("persist.radio.mode_pref_nv10","1");
        property_set("persist.radio.skip_data_check","1");
        property_set("persist.radio.0x9e_not_callname","1");
        property_set("persist.radio.vrte_logic","2");
        property_set("persist.data_netmgrd_mtu","1422");
        property_set("ro.cdma.data_retry_config", "max_retries=infinite,0,0,10000,10000,100000,10000,10000,10000,10000,140000,540000,960000");
        property_set("ro.com.google.clientidbase.ms", "android-uscellular-us");
        property_set("ro.com.google.clientidbase.am", "android-uscellular-us");
        property_set("ro.com.google.clientidbase.yt", "android-motorola");
        property_set("ro.cdma.home.operator.alpha", "U.S. Cellular");
        property_set("ro.cdma.home.operator.numeric", "311220");
        property_set("telephony.sms.pseudo_multipart", "1");

     } else if (ISMATCH(radio, "0x7")) {
        /* xt1040 */
        gsm_properties();
        property_set("ro.product.device", "peregrine");
        property_set("ro.product.model", "XT1040");
        property_set("ro.product.display", "Moto G");
        property_set("ro.build.description", "peregrine_retbr-user 5.1 LPB23.13-8 7 release-keys");
        property_set("ro.build.fingerprint", "motorola/peregrine_retbr/peregrine:5.1/LPB23.13-8/7:user/release-keys");
        property_set("ro.mot.build.customerid", "reteuall");
        property_set("persist.radio.multisim.config", "");
    }

    property_get("ro.product.device", device);
    strlcpy(devicename, device, sizeof(devicename));
    INFO("Found radio id %s setting build properties for %s device\n", radio, devicename);
}
void gsm_properties()
{
    property_set("telephony.lteOnGsmDevice", "1");
    property_set("ro.telephony.default_network", "9");
}

void cdma_properties(const char *cdma_sub)
{
    property_set("ro.telephony.default_cdma_sub", cdma_sub);
    property_set("ril.subscription.types","NV,RUIM");
    property_set("DEVICE_PROVISIONED","1");
    property_set("telephony.lteOnCdmaDevice", "1");
    property_set("ro.telephony.default_network", "10");
}
