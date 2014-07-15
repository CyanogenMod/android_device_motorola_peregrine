# Inherit some common CM stuff.
$(call inherit-product, vendor/cm/config/common_full_phone.mk)

# Boot animation
TARGET_SCREEN_WIDTH := 720
TARGET_SCREEN_HEIGHT := 1280

# Inherit device configuration
$(call inherit-product, device/motorola/peregrine/full_peregrine.mk)

## Device identifier. This must come after all inclusions
PRODUCT_RELEASE_NAME := peregrine
PRODUCT_NAME := cm_peregrine
