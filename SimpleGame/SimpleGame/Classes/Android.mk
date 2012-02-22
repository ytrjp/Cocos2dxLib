LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE := game_logic

LOCAL_SRC_FILES := AppDelegate.cpp \
                   HelloWorldScene.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../libs/cocos2dx \
                    $(LOCAL_PATH)/../libs/cocos2dx/platform \
                    $(LOCAL_PATH)/../libs/cocos2dx/include \
                    $(LOCAL_PATH)/../libs/CocosDenshion/include \

LOCAL_LDLIBS := -L$(call host-path, $(LOCAL_PATH)/../android/libs/$(TARGET_ARCH_ABI)) \
                -lcocosdenshion -lcocos2d  \
                -L$(call host-path, $(LOCAL_PATH)/../libs/cocos2dx/platform/third_party/android/libraries/$(TARGET_ARCH_ABI)) 

include $(BUILD_STATIC_LIBRARY)