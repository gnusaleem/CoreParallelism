obj-m = cpu_v1.o
obj-m += kthread_v1.o kthread_v2.o kthread_v3.o

all:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) clean
	rm *~

