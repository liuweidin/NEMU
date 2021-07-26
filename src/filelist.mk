SRCS-y += src/nemu-main.c
DIRS-y = src/cpu src/monitor src/utils
DIRS-$(CONFIG_MODE_SYSTEM) += src/memory

ifdef CONFIG_SHARE
SHARE = 1
else
LIBS += $(if $(CONFIG_AM),,-lreadline -ldl -pie)
endif

ifdef mainargs
ASFLAGS += -DBIN_PATH=\"$(mainargs)\"
endif
SRCS-$(CONFIG_AM) += src/am-bin.S
.PHONY: src/am-bin.S
