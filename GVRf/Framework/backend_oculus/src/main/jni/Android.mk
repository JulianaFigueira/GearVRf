 #   
 # Copyright 2015 Samsung Electronics Co., LTD
 #
 # Licensed under the Apache License, Version 2.0 (the "License");
 # you may not use this file except in compliance with the License.
 # You may obtain a copy of the License at
 #
 #     http://www.apache.org/licenses/LICENSE-2.0
 #
 # Unless required by applicable law or agreed to in writing, software
 # distributed under the License is distributed on an "AS IS" BASIS,
 # WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 # See the License for the specific language governing permissions and
 # limitations under the License.
 #
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE    := bullet3
LOCAL_SRC_FILES := ../libs/libBullet.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)

ifndef OVR_MOBILE_SDK
	OVR_MOBILE_SDK=../../../../../ovr_sdk_mobile
endif

include $(OVR_MOBILE_SDK)/cflags.mk

LOCAL_MODULE := gvrf-oculus

LOCAL_C_INCLUDES += $(OVR_MOBILE_SDK)/VrApi/Include
LOCAL_C_INCLUDES += $(OVR_MOBILE_SDK)/VrAppSupport/SystemUtils/Include

LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../../framework/src/main/jni/
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../../framework/src/main/jni/util
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../../framework/src/main/jni/contrib
LOCAL_C_INCLUDES +=	$(LOCAL_PATH)/contrib/bullet3/include

LOCAL_C_INCLUDES += $(LOCAL_PATH)/contrib/assimp
LOCAL_C_INCLUDES +=	$(LOCAL_PATH)/contrib/assimp/include
LOCAL_C_INCLUDES +=	$(LOCAL_PATH)/contrib/assimp/include/Compiler

# Uncomment for logs
# LOCAL_CFLAGS += -DANDROID -DJNI_LOG

LOCAL_C_INCLUDES += $(LOCAL_PATH)/src/main/jni
LOCAL_C_INCLUDES += $(LOCAL_PATH)/src/main/jni/util
LOCAL_C_INCLUDES += $(LOCAL_PATH)/src/main/jni/objects

FILE_LIST := $(wildcard $(LOCAL_PATH)/*.cpp)
FILE_LIST := $(wildcard $(LOCAL_PATH)/eglextension/msaa/*.cpp)
LOCAL_SRC_FILES += $(FILE_LIST:$(LOCAL_PATH)/%=%)
FILE_LIST := $(wildcard $(LOCAL_PATH)/eglextension/tiledrendering/*.cpp)
LOCAL_SRC_FILES += $(FILE_LIST:$(LOCAL_PATH)/%=%)
FILE_LIST := $(wildcard $(LOCAL_PATH)/engine/physics/*.cpp)
LOCAL_SRC_FILES += $(FILE_LIST:$(LOCAL_PATH)/%=%)
FILE_LIST := $(wildcard $(LOCAL_PATH)/engine/physics/*/*.cpp)
LOCAL_SRC_FILES += $(FILE_LIST:$(LOCAL_PATH)/%=%)
FILE_LIST := $(wildcard $(LOCAL_PATH)/engine/importer/*.cpp)
LOCAL_SRC_FILES += $(FILE_LIST:$(LOCAL_PATH)/%=%)
FILE_LIST := $(wildcard $(LOCAL_PATH)/engine/exporter/*.cpp)
LOCAL_SRC_FILES += $(FILE_LIST:$(LOCAL_PATH)/%=%)
FILE_LIST := $(wildcard $(LOCAL_PATH)/engine/picker/*.cpp)
LOCAL_SRC_FILES += $(FILE_LIST:$(LOCAL_PATH)/%=%)
FILE_LIST := $(wildcard $(LOCAL_PATH)/engine/renderer/*.cpp)
LOCAL_SRC_FILES += $(FILE_LIST:$(LOCAL_PATH)/%=%)
FILE_LIST := $(wildcard $(LOCAL_PATH)/engine/memory/*.cpp)
LOCAL_SRC_FILES += $(FILE_LIST:$(LOCAL_PATH)/%=%)
FILE_LIST := $(wildcard $(LOCAL_PATH)/gl/*.cpp)
LOCAL_SRC_FILES += $(FILE_LIST:$(LOCAL_PATH)/%=%)
FILE_LIST := $(wildcard $(LOCAL_PATH)/objects/*.cpp)	
LOCAL_SRC_FILES += $(FILE_LIST:$(LOCAL_PATH)/%=%)
FILE_LIST := $(wildcard $(LOCAL_PATH)/objects/components/*.cpp)	
LOCAL_SRC_FILES += $(FILE_LIST:$(LOCAL_PATH)/%=%)
FILE_LIST := $(wildcard $(LOCAL_PATH)/objects/textures/*.cpp)
LOCAL_SRC_FILES += $(FILE_LIST:$(LOCAL_PATH)/%=%)
FILE_LIST := $(wildcard $(LOCAL_PATH)/monoscopic/*.cpp)
LOCAL_SRC_FILES += $(FILE_LIST:$(LOCAL_PATH)/%=%)
FILE_LIST := $(wildcard $(LOCAL_PATH)/shaders/*.cpp)	
LOCAL_SRC_FILES += $(FILE_LIST:$(LOCAL_PATH)/%=%)
FILE_LIST := $(wildcard $(LOCAL_PATH)/shaders/material/*.cpp)
LOCAL_SRC_FILES += $(FILE_LIST:$(LOCAL_PATH)/%=%)
FILE_LIST := $(wildcard $(LOCAL_PATH)/objects/components/*.cpp)
LOCAL_SRC_FILES += $(FILE_LIST:$(LOCAL_PATH)/%=%)
FILE_LIST := $(wildcard $(LOCAL_PATH)/util/*.cpp)
LOCAL_SRC_FILES += $(FILE_LIST:$(LOCAL_PATH)/%=%)
FILE_LIST := $(wildcard $(LOCAL_PATH)/monoscopic/*.cpp)
LOCAL_SRC_FILES += $(FILE_LIST:$(LOCAL_PATH)/%=%)

#LOCAL_STATIC_LIBRARIES += staticAssimp
LOCAL_SHARED_LIBRARIES += bullet3
LOCAL_SHARED_LIBRARIES += assimp
LOCAL_SHARED_LIBRARIES += vrapi
LOCAL_STATIC_LIBRARIES += systemutils

## CPP flags are already defined in cflags.mk.
#LOCAL_CPPFLAGS += -fexceptions -frtti -std=c++11 -D__GXX_EXPERIMENTAL_CXX0X__ -mhard-float -D_NDK_MATH_NO_SOFTFP=1
#for NO_RTTI and softFP
LOCAL_CPPFLAGS += -fexceptions -std=c++11 -D__GXX_EXPERIMENTAL_CXX0X__
LOCAL_CFLAGS := -Wattributes

# include ld libraries defined in oculus's cflags.mk
#LOCAL_LDLIBS += -ljnigraphics -lm_hard
#softFP
LOCAL_LDLIBS += -ljnigraphics -llog -lGLESv3 -lEGL -lz -landroid
LOCAL_LDLIBS += $(LOCAL_PATH)/../../../../framework/src/main/libs/armeabi-v7a/libgvrf.so

include $(BUILD_SHARED_LIBRARY)

$(call import-add-path, $(OVR_MOBILE_SDK))
$(call import-module,VrAppSupport/SystemUtils/Projects/AndroidPrebuilt/jni)
$(call import-module,VrApi/Projects/AndroidPrebuilt/jni)
