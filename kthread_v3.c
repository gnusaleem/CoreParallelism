#include <linux/module.h>
#include <linux/init.h>
#include <linux/sched.h>

struct task_struct *task;

static int __init thread_init(void) {
	int count = 0;

	for_each_process(task) {
		pr_info("PID = %d | Name = %s | state = %s\n", task->pid, task->comm, task_is_running(task));
			count++;
	}
	pr_info("Total no of processes %d\n", count);
	return 0;
}

static void __exit thread_exit(void) {
	pr_info("Module unloaded\n");
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Saleemuddin Shaik");
MODULE_DESCRIPTION("Kthread_v3");

module_init(thread_init);
module_exit(thread_exit);
