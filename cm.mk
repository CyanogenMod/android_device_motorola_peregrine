## Specify phone tech before including full_phone
$(call inherit-product, vendor/cm/config/gsm.mk)

# Release name
PRODUCT_RELEASE_NAME := peregrine

# Inherit some common CM stuff.
$(call inherit-product, vendor/cm/config/common_full_phone.mk)

# Inherit device configuration
$(call inherit-product, device/motorola/peregrine/device_peregrine.mk)

## Device identifier. This must come after all inclusions
PRODUCT_DEVICE := peregrine
PRODUCT_NAME := cm_peregrine
PRODUCT_BRAND := motorola
PRODUCT_MODEL := peregrine
PRODUCT_MANUFACTURER := motorola
