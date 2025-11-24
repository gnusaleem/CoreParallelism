#include <linux/init.h>
#include <linux/module.h>
#include <linux/kthread.h>
#include <linux/sched.h>
#include <linux/delay.h>

static struct task_struct *kthread[];

static int thread_func(void *idx) {
	uint32_t i = 0;
	int t_id = *(int *)idx;

	while(!kthread_should_stop()) {
		printk(KERN_INFO "Thread %d is running for %d secs\n", t_id, i);
		i++;

		if (i == 30)
			break;

		msleep(1000);
	}

	printk(KERN_INFO "Thread Stopped %d\n", t_id);

	return 0;
}

static int init_thread(struct task_struct **kth_ptr, int idx) {
	char th_name[20];

	sprintf(th_name, "kthread_%d", idx);

	*kth_ptr = kthread_run(thread_func, &idx, (const char *)th_name);

	if (IS_ERR(*kth_ptr)) {
		printk(KERN_ERR "Thread Not initialized %d\n", idx);
		return -1;
	}

	return 0;
}

static int __init mod_init(void) {
	int i = 0;

	printk(KERN_INFO "Initializing Thread Module\n");

	for (i = 0; i < 4; i++) {
		if (init_thread(&kthread[i], i) == -1) {
			return -1;
		}
	}

	printk(KERN_INFO "All threads are running\n");
	return 0;
}

static void __exit mod_exit(void) {
	int i = 0, ret = 0;

	for (i = 0; i < 4; i++) {
		if(kthread[i]) {
			ret = kthread_stop(kthread[i]);
			if (ret != EINTR)
				printk(KERN_INFO "Thread %d stopped successfully\n", i);
			else
				printk(KERN_ERR "Failed to stop thread %d\n", i);
		}
	}
	printk(KERN_INFO "Stopped all thread\n");
}

MODULE_LICENSE("MIT");
MODULE_AUTHOR("Saleemuddin Shaik");
MODULE_DESCRIPTION("Kthread Version 1");

module_init(mod_init);
module_exit(mod_exit);
