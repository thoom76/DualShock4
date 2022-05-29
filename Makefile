TARGET:=dual_shock_4

CC = g++

src = 	$(wildcard *.cpp) \
		$(wildcard Driver/*.cpp) \
		$(wildcard Driver/DataPacket/*.cpp) \
		$(wildcard *.h) \
		$(wildcard Driver/*.h) \
		$(wildcard Driver/DataPacket/*.h)
obj = $(src:.c=.o)

LDFLAGS = -lhidapi-hidraw

# If we running by kernel building system
ifneq ($(KERNELRELEASE),)
	$(TARGET)-objs := main.o DualShock4.o Driver/DualShock4.o Driver/DataPacket/*.o
	obj-m := $(TARGET).o

# If we are running without kernel build system
else
	BUILDSYSTEM_DIR:=/lib/modules/$(shell uname -r)/build
	PWD:=$(shell pwd)

$(TARGET): $(obj)
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(obj) $(TARGET)

load:
	insmod ./$(TARGET).ko

unload:
	rmmod ./$(TARGET).ko

.PHONY: clean

endif