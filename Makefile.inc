mkfile_path := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

APPL_COBJS +=

# Shellスクリプトで、moduleディレクトリ中のソースコード名をオブジェクトファイル名に変換している
APPL_CXXOBJS += $(shell echo \
                    `ls ${mkfile_path}module/*.cpp | \
                     sed -r 's/(\/.*)*\/(.*\.)cpp/\2o/g'`)
APPL_CXXOBJS += $(shell echo \
                    `ls ${mkfile_path}module/*/*.cpp | \
                     sed -r 's/(\/.*)*\/(.*\.)cpp/\2o/g'`)

SRCLANG := c++

ifdef CONFIG_EV3RT_APPLICATION

# Include libraries
include $(EV3RT_SDK_LIB_DIR)/libcpp-ev3/Makefile

endif

# ソースコードのあるディレクトリを指定する？
APPL_DIRS += \
	$(mkfile_path)app \
    $(mkfile_path)module \
    $(mkfile_path)module/API \
    $(mkfile_path)module/Motion

# ヘッダファイルのあるディレクトリを指定する？
INCLUDES += \
	-I$(mkfile_path)app \
    -I$(mkfile_path)module \
	-I$(ETROBO_HRP3_WORKSPACE)/etroboc_common \
    -I$(mkfile_path)module/API \
    -I$(mkfile_path)module/Motion
	
#COPTS += -fno-use-cxa-atexit
