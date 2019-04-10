ifeq ($(KERNELRELEASE),)  

KERNELDIR ?= /lib/modules/$(shell uname -r)/build 
PWD := $(shell pwd)  

.PHONY: build clean  

###############################################################

CC=gcc
CFLAGS=-O3
EXTRAFLAGS=-lpqxx -lpq

all: sneaky_process

sneaky_process: sneaky_process.c
	$(CC) $(CFLAGS) -o sneaky_process sneaky_process.c $(EXTRAFLAGS)

###############################################################

build:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules  

clean:
	rm -rf *.o *~ core .depend .*.cmd *.order *.symvers *.ko *.mod.c 
else  

$(info Building with KERNELRELEASE = ${KERNELRELEASE}) 
obj-m :=    sneaky_mod.o  

endif
